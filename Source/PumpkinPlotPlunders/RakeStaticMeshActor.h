// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interfaces/Interact.h"
#include "Interfaces/Useable.h"
#include "RakeStaticMeshActor.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class PUMPKINPLOTPLUNDERS_API ARakeStaticMeshActor : public AStaticMeshActor
	,public IInteract
	,public IUseable
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	USphereComponent* InteractionCollisionSphere;
	
public:
	ARakeStaticMeshActor();
	
protected:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Interact(TWeakObjectPtr<AActor> InteractingActor) override;
	
	virtual void Activate() override;

	UPROPERTY(EditDefaultsOnly, Category="RakeSettings")
	float DamagePerSecond = 50.0f;
private:
	TWeakObjectPtr<APumpkinPlotPlundersCharacter> PlayerCharacter = nullptr;

	void ApplyDamage();
	
};
