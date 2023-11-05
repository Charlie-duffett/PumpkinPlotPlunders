// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interfaces/Interact.h"
#include "WaterTroughStaticMeshActor.generated.h"

UCLASS()
class PUMPKINPLOTPLUNDERS_API AWaterTroughStaticMeshActor : public AStaticMeshActor,
	public IInteract
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWaterTroughStaticMeshActor();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Water")
	float WaterAddedPerSecond = 10.0f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Register();

public:
	virtual void Interact(TWeakObjectPtr<AActor> InteractingActor) override;
};
