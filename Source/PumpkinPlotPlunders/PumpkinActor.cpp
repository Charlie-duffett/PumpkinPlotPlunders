// Fill out your copyright notice in the Description page of Project Settings.


#include "PumpkinActor.h"
#include "PumpkinPlotPlundersCharacter.h"
#include "Components/SphereComponent.h"
#include "Iris/Core/IrisDebugging.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
APumpkinActor::APumpkinActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	
 	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent->SetMobility(EComponentMobility::Movable);
	PumpkinStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PumpkinStaticMesh"));
	PumpkinStaticMeshComponent->SetupAttachment(RootComponent);

	InteractionCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Interation Collision Sphere"));
	InteractionCollisionSphere->SetupAttachment(RootComponent);
	InteractionCollisionSphere->ComponentTags.AddUnique(TEXT("InteractionCollision"));

	DamageRangeSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Damage Range Sphere"));
	DamageRangeSphere->SetupAttachment(RootComponent);
	
	StateTimer.Invalidate();
	WaterDelayTimer.Invalidate();
	DamageDelayTimer.Invalidate();
	SpawnDelayTimer.Invalidate();
}

void APumpkinActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (CurrentPumpkinState == PumpkinState::Growing)
	{
		DecayWater(DeltaSeconds);
	}
}

void APumpkinActor::Interact(TWeakObjectPtr<AActor> InteractingActor)
{
	// UE_LOG(LogTemp, Log, TEXT("Interacting"))
	Harvest();
}

void APumpkinActor::Destroyed()
{
	Super::Destroyed();
	UnRegister();
}

void APumpkinActor::DealDamage(float DamageAmount)
{
	if (CurrentPumpkinState == PumpkinState::Evil && bIsDamagable)
	{
		CurrentHealth -= DamageAmount;

		if (CurrentHealth <= 0)
		{
			ResetPumpkin();
		}
	}
}

void APumpkinActor::Water(float WaterIncrease)
{
	if (CurrentPumpkinState == PumpkinState::Growing && IsWaterable())
	{
		// Adding the decay to counter the fact we are also removing the decay each tick
		CurrentWater += WaterIncrease + (WaterDecayPerSecond * GetWorld()->GetDeltaSeconds());

		CurrentWater = FMath::Min(CurrentWater, MaxWater);

		if (CurrentWater + UE_FLOAT_NORMAL_THRESH >= MaxWater)
		{
			DelayWaterDecay();
		}
	}
}

bool APumpkinActor::IsWaterable()
{
	return CurrentWater + UE_FLOAT_NORMAL_THRESH < MaxWater && bCanWater;
}

void APumpkinActor::UnRegister()
{
	const TWeakObjectPtr<APumpkinPlotPlundersCharacter> Player = GetPumpkinCharacter();


	if (Player.IsValid() && bIsRegistered)
	{
		Player->UnRegisterInteractable(this);
		bIsRegistered = false;
	}
}

// Called when the game starts or when spawned
void APumpkinActor::BeginPlay()
{
	Super::BeginPlay();
	// Setup pumpkin
	UpdatePumpkinTransform();

	if (PumpkinSpawnDelay > UE_FLOAT_NORMAL_THRESH)
	{
		DisablePumpkin();
	
		GetWorldTimerManager().SetTimer(SpawnDelayTimer, this, &ThisClass::InitPumpkin, PumpkinSpawnDelay,
			false);
	}
	else
	{
		InitPumpkin();
	}
}

void APumpkinActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (PumpkinStaticMeshComponent && RootComponent)
	{
		PumpkinStaticMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	}
	UpdatePumpkinTransform();
}

void APumpkinActor::UpdatePumpkinTransform()
{
	if (!IsValid(PumpkinStaticMeshComponent))
	{
		return;
	}
	
	if (CurrentPumpkinState == PumpkinState::Evil)
	{
		PumpkinStaticMeshComponent->SetRelativeLocation(EnemyPumpkinLocation);
		PumpkinStaticMeshComponent->SetRelativeRotation(EnemyPumpkinRotation);
	}
	else
	{
		PumpkinStaticMeshComponent->SetRelativeLocation(AlliedPumpkinLocation);
		PumpkinStaticMeshComponent->SetRelativeRotation(AlliedPumpkinRotation);
	}
}

void APumpkinActor::ClearTimers()
{
	GetWorldTimerManager().ClearTimer(StateTimer);
	GetWorldTimerManager().ClearTimer(WaterDelayTimer);
	GetWorldTimerManager().ClearTimer(DamageDelayTimer);
	GetWorldTimerManager().ClearTimer(SpawnDelayTimer);
}

void APumpkinActor::DecayWater(float DeltaSeconds)
{
	if (bDecayWater)
	{
		CurrentWater -= DeltaSeconds * WaterDecayPerSecond;;

		if (CurrentWater <= 0)
		{
			// No more water so pumpkin is now evil!
			bDecayWater = false;
			ChangeState(PumpkinState::Evil);
		}
	}
}

void APumpkinActor::ChangeState(enum PumpkinState NewState)
{
	switch (NewState)
	{
	case PumpkinState::Growing :
		{
			StartGrowingState();
			break;
		}
	case PumpkinState::Harvestable :
		{
			StartHarvestableState();
			break;
		}
	case PumpkinState::Evil :
		{
			StartEvilState();
			break;
		}
	default:
		{
			checkf(false, TEXT("Invalid state given when trying to switch state."));
			break;
		}
	}
}

void APumpkinActor::StartGrowingState()
{
	ClearTimers();

	CurrentPumpkinState = PumpkinState::Growing;
	
	// Reset water variables
	bDecayWater = false;
	CurrentWater = MaxWater;
	bCanWater = true;
	
	GetWorldTimerManager().SetTimer(StateTimer, this, &ThisClass::EndGrowingState, GrowingTime,
		false);

	const float DelayToStart = FMath::RandRange(WaterDecayDelay.X, WaterDecayDelay.Y);

	GetWorldTimerManager().SetTimer(WaterDelayTimer, this, &ThisClass::StartWaterDecay, DelayToStart,
		false);

	UpdatePumpkinTransform();
	
	UE_LOG(LogTemp, Display, TEXT("Started Growing State"))
}

void APumpkinActor::StartHarvestableState()
{
	ClearTimers();
	CurrentPumpkinState = PumpkinState::Harvestable;
	GetWorldTimerManager().SetTimer(StateTimer, this, &ThisClass::EndHarvestableState, HarvestTime,
		false);

	UpdatePumpkinTransform();
	
	UE_LOG(LogTemp, Display, TEXT("Started Harvestable State"))
}

void APumpkinActor::StartEvilState()
{
	ClearTimers();

	bIsDamagable = true;
	
	CurrentPumpkinState = PumpkinState::Evil;
	
	UpdatePumpkinTransform();

	AttackLoop();
	
	UE_LOG(LogTemp, Display, TEXT("Started Evil State"))
}

void APumpkinActor::EndGrowingState()
{
	bCanWater = false;
	UE_LOG(LogTemp, Display, TEXT("Ended Growing State"))
	StartHarvestableState();
}

void APumpkinActor::EndHarvestableState()
{
	UE_LOG(LogTemp, Display, TEXT("Ended Harvestable State"))
	StartEvilState();
}

void APumpkinActor::EndEvilState()
{
	bIsDamagable = false;
	UE_LOG(LogTemp, Display, TEXT("Game over! Evil state has been ended"))
	OnPumpkinEvilStateEnd.Broadcast();
}

void APumpkinActor::StartWaterDecay()
{
	bDecayWater = true;
	UE_LOG(LogTemp, Display, TEXT("Started Water Decay"))
}

void APumpkinActor::DelayWaterDecay()
{
	bDecayWater = false;

	const float DelayToStart = FMath::RandRange(WaterDecayDelay.X, WaterDecayDelay.Y);

	GetWorldTimerManager().SetTimer(WaterDelayTimer, this, &ThisClass::StartWaterDecay, DelayToStart,
		false);
}

void APumpkinActor::Harvest()
{
	if (CurrentPumpkinState == PumpkinState::Harvestable)
	{
		ClearTimers();
		OnPumpkinHarvested.Broadcast();

		ResetPumpkin();
		
		UE_LOG(LogTemp, Warning, TEXT("Harvested!"))
	}
}

void APumpkinActor::InitPumpkin()
{
	StartGrowingState();
	
	PumpkinStaticMeshComponent->SetVisibility(true);
	PumpkinStaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	CurrentHealth = MaxHealth;

	bIsDisabled = false;
}

void APumpkinActor::ResetPumpkin()
{
	// Disable pumpkin for a set time before "resetting it"
	DisablePumpkin();
	
	GetWorldTimerManager().SetTimer(StateTimer, this, &ThisClass::InitPumpkin, ResetTime,
	false);
}

void APumpkinActor::DisablePumpkin()
{
	UnRegister();

	ClearTimers();

	bIsDisabled = true;
	PumpkinStaticMeshComponent->SetVisibility(false);
	PumpkinStaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void APumpkinActor::EnableDamage()
{
	bIsDamagable = true;
}

void APumpkinActor::AttackLoop()
{
	TArray<AActor*> OverlappingActors;

	DamageRangeSphere->GetOverlappingActors(OverlappingActors);

	for (const auto Actor : OverlappingActors)
	{
		if (Actor->ActorHasTag("PumpkinDamageable"))
		{
			IDamageable* DamagableActor = Cast<IDamageable>(Actor);

			if (DamagableActor != nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("Dealing Damage"));
				DamagableActor->DealDamage(DamagePerHit);
			}
		}
	}

	GetWorldTimerManager().SetTimer(DamageDelayTimer, this, &ThisClass::AttackLoop, TimeBetweenDamage,
	false);
}

TWeakObjectPtr<APumpkinPlotPlundersCharacter> APumpkinActor::GetPumpkinCharacter()
{
	const TWeakObjectPtr<UWorld> World = GetWorld();
	if (!World.IsValid())
	{
		return nullptr;
	}
	
	const TWeakObjectPtr<APlayerController> Controller = World->GetFirstPlayerController();
	if (!Controller.IsValid())
	{
		return nullptr;
	}
	
	const TWeakObjectPtr<ACharacter> Character = Controller->GetCharacter();
	if (!Character.IsValid())
	{
		return nullptr;
	}
	
	return Cast<APumpkinPlotPlundersCharacter>(Character);
}
