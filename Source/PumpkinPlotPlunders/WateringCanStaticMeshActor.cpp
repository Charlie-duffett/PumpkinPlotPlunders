// Fill out your copyright notice in the Description page of Project Settings.


#include "WateringCanStaticMeshActor.h"
#include "Interfaces/Waterable.h"

// Sets default values
AWateringCanStaticMeshActor::AWateringCanStaticMeshActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AWateringCanStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();

	Register();
}

void AWateringCanStaticMeshActor::Register()
{
	const TObjectPtr<APumpkinPlotPlundersCharacter> Player = Cast<APumpkinPlotPlundersCharacter>(
		GetWorld()->GetFirstPlayerController()->GetCharacter());

	Player->RegisterInteractable(this);
}

void AWateringCanStaticMeshActor::Interact(TObjectPtr<AActor> InteractingActor)
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
	if (!PlayerCharacter.IsValid())
	{
		return;
	}

	IWaterable* ActorToWater = Cast<IWaterable>(PlayerCharacter->GetClosestActor());

	if (ActorToWater == nullptr)
	{
		return;
	}

	ActorToWater->Water(WaterIncreasePerSecond * GetWorld()->GetDeltaSeconds());
}

