// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interfaces/Interact.h"
#include "Interfaces/Useable.h"
#include "Interfaces/Waterable.h"
#include "WateringCanStaticMeshActor.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class PUMPKINPLOTPLUNDERS_API AWateringCanStaticMeshActor : public AStaticMeshActor
	,public IInteract
	,public IUseable
	,public IWaterable
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	USphereComponent* InteractionCollisionSphere;

public:
	AWateringCanStaticMeshActor();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Interact(TWeakObjectPtr<AActor> InteractingActor) override;
	
	virtual void Activate() override;

	virtual void Water(float WaterIncrease) override;

	UPROPERTY(EditDefaultsOnly, Category="Water")
	float WaterIncreasePerSecond = 1000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Water")
	float MaxWater = 100.0f;

	UPROPERTY(BlueprintReadOnly)
	float CurrentWater = 0.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Water")
	float WaterUsePerSecond = 50.0f;
private:
	TWeakObjectPtr<APumpkinPlotPlundersCharacter> PlayerCharacter = nullptr;
};