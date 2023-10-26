// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Damageable.h"
#include "Interfaces/Interact.h"
#include "Interfaces/Waterable.h"
#include "PumpkinActor.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class PumpkinState
{
	Growing,
	Harvestable,
	Evil,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHarvestDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEvilDelegate);

UCLASS()
class PUMPKINPLOTPLUNDERS_API APumpkinActor
	: public AActor
	, public IInteract
	, public IDamageable
	, public IWaterable
{

private:
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	APumpkinActor();

	virtual void Tick(float DeltaSeconds) override;

	virtual void Interact(TObjectPtr<AActor> InteractingActor) override;

	virtual void Destroyed() override;

	virtual void DealDamage(float DamageAmount) override;

	virtual void Water(float WaterIncrease) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Register();
	void UnRegister();
	
public:
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> PumpkinStaticMeshComponent;
	

	// State of the Pumpkin
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=PumpkinSettings)
	PumpkinState CurrentPumpkinState = PumpkinState::Growing;	
	// Location and rotation of pumpkin when it is on the Enemy Team
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=PumpkinSettings)
	FVector EnemyPumpkinLocation = FVector();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=PumpkinSettings)
	FRotator EnemyPumpkinRotation = FRotator();

	// Location and rotation of pumpkin when it is on the Allied Team
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=PumpkinSettings)
	FVector AlliedPumpkinLocation = FVector();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=PumpkinSettings)
	FRotator AlliedPumpkinRotation = FRotator();
	
	/* ----- Water Settings ----- */
	bool bDecayWater = false;

	// Delay before water decays randomly selected between these 2 numbers
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=PumpkinWater)
	FVector2f WaterDecayDelay = {0.0f, 3.0f};
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=PumpkinWater)
	float MaxWater = 100.0f;

	UPROPERTY(BlueprintReadOnly)
	float CurrentWater = 0.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=PumpkinWater)
	float WaterDecayPerSecond = 1.0f;

	/* ----- Water settings end ----- */

	// Max health of the pumpkin
	UPROPERTY(BlueprintReadOnly, Category=PumpkinHealth)
	float MaxHealth = 100.0f;
	
	// How much health the evil pumpkin has
	UPROPERTY(BlueprintReadOnly, Category=PumpkinHealth)
	float CurrentHealth = 100.0f;

	// Time required (in seconds) for the pumpkin to full grow
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=PumpkinTimers)
	float GrowingTime = 15.0f;

	// Time limit (in seconds) for the pumpkin being harvested
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=PumpkinTimers)
	float HarvestTime = 15.0f;

	// Time limit (in seconds) for the pumpkin to be destroyed before causing failure condition
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=PumpkinTimers)
	float EvilTime = 15.0f;

	// Time limit (in seconds) for the pumpkin to be reset after being harvested
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=PumpkinTimers)
	float ResetTime = 5.0f;

	// Harvest Delegate instance
	FHarvestDelegate OnPumpkinHarvested;

	// Evil state end Delegate instance
	FEvilDelegate OnPumpkinEvilStateEnd;
	
	// Update transform of pumpkin (called when team changes)
	void UpdatePumpkinTransform();
	

private:
	bool bCanDamage = true;
	
	// Timers for all states
	FTimerHandle StateTimer;
	
	FTimerHandle WaterDelayTimer;

	FTimerHandle DamageCooldownTimer;
	
	void ClearTimers();
	
	void DecayWater(float DeltaSeconds);

	void ChangeState(enum PumpkinState NewState);

	void StartGrowingState();

	void StartHarvestableState();

	void StartEvilState();

	void EndGrowingState();

	void EndHarvestableState();

	void EndEvilState();

	void StartWaterDecay();

	void DelayWaterDecay();

	void Harvest();

	void InitPumpkin();

	void DisablePumpkin();

	void EnableDamage();

	TWeakObjectPtr<APumpkinPlotPlundersCharacter> GetPumpkinCharacter();
};


