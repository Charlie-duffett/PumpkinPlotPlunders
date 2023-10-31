// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterTroughStaticMeshActor.h"

#include "Interfaces/Waterable.h"


// Sets default values
AWaterTroughStaticMeshActor::AWaterTroughStaticMeshActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AWaterTroughStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();

	Register();
}

void AWaterTroughStaticMeshActor::Register()
{
	const TObjectPtr<APumpkinPlotPlundersCharacter> Player = Cast<APumpkinPlotPlundersCharacter>(
		GetWorld()->GetFirstPlayerController()->GetCharacter());

	Player->RegisterInteractable(this);
}

void AWaterTroughStaticMeshActor::Interact(TWeakObjectPtr<AActor> InteractingActor)
{
	using PlayerType = APumpkinPlotPlundersCharacter;
	TWeakObjectPtr<PlayerType> Player = Cast<PlayerType>(InteractingActor);

	if (!Player.IsValid())
	{
		return;
	}

	if (Player->IsHoldingItem())
	{
		IWaterable* WaterableActor = Cast<IWaterable>(Player->GetHeldItem());

		if (WaterableActor != nullptr)
		{
			WaterableActor->Water(WaterAddedPerSecond * GetWorld()->GetDeltaSeconds());
		}
	}
	
}
