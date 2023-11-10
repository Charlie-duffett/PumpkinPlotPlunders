// Fill out your copyright notice in the Description page of Project Settings.


#include "WateringCanStaticMeshActor.h"

#include "WaterTroughStaticMeshActor.h"
#include "Components/SphereComponent.h"
#include "Interfaces/Waterable.h"

// Sets default values
AWateringCanStaticMeshActor::AWateringCanStaticMeshActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	InteractionCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Interation Collision Sphere"));
	InteractionCollisionSphere->SetupAttachment(RootComponent);
	InteractionCollisionSphere->ComponentTags.AddUnique(TEXT("InteractionCollision"));
}

// Called when the game starts or when spawned
void AWateringCanStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();

	CurrentWater = MaxWater;
}

void AWateringCanStaticMeshActor::Interact(TWeakObjectPtr<AActor> InteractingActor)
{
	using PlayerType = APumpkinPlotPlundersCharacter;
	TWeakObjectPtr<PlayerType> Player = Cast<PlayerType>(InteractingActor);

	if (Player.IsValid())
	{
		// Attach to player etc
		Player->HoldItem(this, true);
		PlayerCharacter = Player;
	}
}

void AWateringCanStaticMeshActor::Activate()
{
	if (!PlayerCharacter.IsValid() )
	{
		return;
	}

	IWaterable* ActorToWater = Cast<IWaterable>(PlayerCharacter->GetClosestActor());

	if (ActorToWater != nullptr && CurrentWater > UE_FLOAT_NORMAL_THRESH)
	{
		UE_LOG(LogTemp, Warning, TEXT("Water Level: %f"), CurrentWater)
		if (!ActorToWater->IsWaterable())
		{
			return;
		}
		CurrentWater -= WaterUsePerSecond * GetWorld()->GetDeltaSeconds();

		CurrentWater = FMath::Max(CurrentWater, 0.0f);
		
		
		ActorToWater->Water(WaterIncreasePerSecond * GetWorld()->GetDeltaSeconds());
	}

	using WaterTroughType = AWaterTroughStaticMeshActor;

	TWeakObjectPtr<WaterTroughType> WaterTroughActor = Cast<WaterTroughType>(PlayerCharacter->GetClosestActor());

	if (WaterTroughActor != nullptr)
	{
		WaterTroughActor->Interact(PlayerCharacter);
	}
}

void AWateringCanStaticMeshActor::Water(float WaterIncrease)
{
	// Adding the decay to counter the fact we are also removing the decay each tick
	CurrentWater += WaterIncrease;
	CurrentWater = FMath::Min(CurrentWater, MaxWater);
	UE_LOG(LogTemp, Warning, TEXT("Water Level: %f"), CurrentWater)
}

