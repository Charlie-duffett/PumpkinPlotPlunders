// Fill out your copyright notice in the Description page of Project Settings.


#include "PumpkinActor.h"
#include "PumpkinPlotPlundersCharacter.h"
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
	
	StateTimer.Invalidate();
	WaterDelayTimer.Invalidate();
}

void APumpkinActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (PumpkinState == PumpkinState::Growing)
	{
		DecayWater(DeltaSeconds);
	}
}

void APumpkinActor::Interact(TObjectPtr<AActor> InteractingActor)
{
	UE_LOG(LogTemp, Log, TEXT("Interacting"))
	Harvest();
}

void APumpkinActor::Destroyed()
{
	Super::Destroyed();
	UnRegister();
}

void APumpkinActor::DealDamage(float DamageAmount)
{
	if (PumpkinState == PumpkinState::Evil)
	{
		CurrentHealth -= DamageAmount;

		if (CurrentHealth <= 0)
		{
			DisablePumpkin();
		}
	}
}

void APumpkinActor::Register()
{
	const TObjectPtr<APumpkinPlotPlundersCharacter> Player = Cast<APumpkinPlotPlundersCharacter>(
		GetWorld()->GetFirstPlayerController()->GetCharacter());

	Player->RegisterInteractable(this);
}

void APumpkinActor::UnRegister()
{
	const TObjectPtr<APumpkinPlotPlundersCharacter> Player = Cast<APumpkinPlotPlundersCharacter>(
		GetWorld()->GetFirstPlayerController()->GetCharacter());

	Player->UnRegisterInteractable(this);
}

// Called when the game starts or when spawned
void APumpkinActor::BeginPlay()
{
	Super::BeginPlay();
	// Setup pumpkin
	UpdatePumpkinTransform();

	InitPumpkin();
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
	if (PumpkinState == PumpkinState::Evil)
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
	switch (PumpkinState)
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

	PumpkinState = PumpkinState::Growing;
	
	// Reset water variables
	bDecayWater = false;
	CurrentWater = MaxWater;
	
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
	PumpkinState = PumpkinState::Harvestable;
	GetWorldTimerManager().SetTimer(StateTimer, this, &ThisClass::EndHarvestableState, HarvestTime,
		false);

	UpdatePumpkinTransform();
	
	UE_LOG(LogTemp, Display, TEXT("Started Harvestable State"))
}

void APumpkinActor::StartEvilState()
{
	ClearTimers();
	
	PumpkinState = PumpkinState::Evil;
	
	GetWorldTimerManager().SetTimer(StateTimer, this, &ThisClass::EndEvilState, EvilTime,
		false);

	UpdatePumpkinTransform();
	
	UE_LOG(LogTemp, Display, TEXT("Started Evil State"))
}

void APumpkinActor::EndGrowingState()
{
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
	if (PumpkinState == PumpkinState::Harvestable)
	{
		ClearTimers();
		OnPumpkinHarvested.Broadcast();

		DisablePumpkin();
		
		UE_LOG(LogTemp, Warning, TEXT("Harvested!"))
	}
}

void APumpkinActor::InitPumpkin()
{
	Register();
	StartGrowingState();
	
	PumpkinStaticMeshComponent->SetVisibility(true);
	PumpkinStaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	CurrentHealth = MaxHealth;
}

void APumpkinActor::DisablePumpkin()
{
	// Disable pumpkin for a set time before "resetting it"
	UnRegister();
		
	PumpkinStaticMeshComponent->SetVisibility(false);
	PumpkinStaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	GetWorldTimerManager().SetTimer(StateTimer, this, &ThisClass::InitPumpkin, ResetTime,
	false);
}