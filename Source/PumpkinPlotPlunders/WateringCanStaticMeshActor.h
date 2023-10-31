// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interfaces/Interact.h"
#include "Interfaces/Useable.h"
#include "WateringCanStaticMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class PUMPKINPLOTPLUNDERS_API AWateringCanStaticMeshActor : public AStaticMeshActor
	,public IInteract
	,public IUseable
{
	GENERATED_BODY()

public:
	AWateringCanStaticMeshActor();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Register();

public:	
	virtual void Interact(TObjectPtr<AActor> InteractingActor) override;
	
	virtual void Activate() override;

	UPROPERTY(EditDefaultsOnly)
	float WaterIncreasePerSecond = 1000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=PumpkinWater)
	float MaxWater = 100.0f;

	UPROPERTY(BlueprintReadOnly)
	float CurrentWater = 0.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=PumpkinWater)
	float WaterUsePerSecond = 50.0f;
private:
	TWeakObjectPtr<APumpkinPlotPlundersCharacter> PlayerCharacter = nullptr;
};