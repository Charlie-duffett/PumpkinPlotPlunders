// Fill out your copyright notice in the Description page of Project Settings.


#include "RakeStaticMeshActor.h"
#include "Interfaces/Damageable.h"

ARakeStaticMeshActor::ARakeStaticMeshActor()
{
}

// Called when the game starts or when spawned
void ARakeStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();

	Register();
	
}

void ARakeStaticMeshActor::Register()
{
	const TObjectPtr<APumpkinPlotPlundersCharacter> Player = Cast<APumpkinPlotPlundersCharacter>(
		GetWorld()->GetFirstPlayerController()->GetCharacter());

	Player->RegisterInteractable(this);
}

void ARakeStaticMeshActor::Interact(TWeakObjectPtr<AActor> InteractingActor)
{
	using PlayerType = APumpkinPlotPlundersCharacter;
	TWeakObjectPtr<PlayerType> Player = Cast<PlayerType>(InteractingActor);

	if (Player.IsValid())
	{
		// Attach to player etc
		Player->HoldItem(this, false);
		PlayerCharacter = Player;
	}
}

void ARakeStaticMeshActor::Activate()
{
	// Play Damage animation
	ApplyDamage();
}


// This function should be called when animation triggers!
void ARakeStaticMeshActor::ApplyDamage()
{
	if (!PlayerCharacter.IsValid())
	{
		return;
	}

	IDamageable* ActorToDamage = Cast<IDamageable>(PlayerCharacter->GetClosestActor());

	if (ActorToDamage == nullptr)
	{
		return;
	}

	ActorToDamage->DealDamage(DamagePerSecond * GetWorld()->GetDeltaSeconds());
}

