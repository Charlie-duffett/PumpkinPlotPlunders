// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Damageable.h"
#include "Interfaces/Interact.h"
#include "Interfaces/Waterable.h"
#include "PumpkinActor.generated.h"

class APumpkinPlotPlundersGameMode;
class USphereComponent;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class PumpkinState : uint8
{
	Growing		UMETA(DisplayName="Growing"),
	Harvestable	UMETA(DisplayName="Harvestable"),
	Evil		UMETA(DisplayName="Evil"),
};

UCLASS()
class PUMPKINPLOTPLUNDERS_API APumpkinActor
	: public ACharacter
	, public IInteract
	, public IDamageable
	, public IWaterable
{

private:
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	USphereComponent* InteractionCollisionSphere;

	// Anything inside of this that can be damaged by a pumpkin will be!
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	USphereComponent* DamageRangeSphere;

public:	
	// Sets default values for this actor's properties
	APumpkinActor();

	virtual void Tick(float DeltaSeconds) override;

	virtual void Interact(TWeakObjectPtr<AActor> InteractingActor) override;

	virtual void Destroyed() override;

	virtual void DealDamage(float DamageAmount) override;

	virtual void Water(float WaterIncrease) override;

	virtual bool IsWaterable() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void UnRegister();
	
public:
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> PumpkinStaticMeshComponent;

	UPROPERTY(BlueprintReadOnly)
	bool bIsDamagable = false;
	
	// State of the Pumpkin
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PumpkinSettings")
	PumpkinState CurrentPumpkinState = PumpkinState::Growing;	
	// Location and rotation of pumpkin when it is on the Enemy Team
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PumpkinSettings|Location")
	FVector EnemyPumpkinLocation = FVector();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PumpkinSettings|Location")
	FRotator EnemyPumpkinRotation = FRotator();

	// Location and rotation of pumpkin when it is on the Allied Team
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PumpkinSettings|Location")
	FVector AlliedPumpkinLocation = FVector();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PumpkinSettings|Location")
	FRotator AlliedPumpkinRotation = FRotator();
	
	/* ----- Water Settings ----- */
	bool bDecayWater = false;

	UPROPERTY(BlueprintReadOnly)
	bool bCanWater = false;

	// Delay before water decays randomly selected between these 2 numbers
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PumpkinSettings|Water")
	FVector2f WaterDecayDelay = {0.0f, 3.0f};
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PumpkinSettings|Water")
	float MaxWater = 100.0f;

	UPROPERTY(BlueprintReadOnly)
	float CurrentWater = 0.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PumpkinSettings|Water")
	float WaterDecayPerSecond = 1.0f;

	/* ----- Water settings end ----- */

	// Max health of the pumpkin
	UPROPERTY(BlueprintReadOnly, Category="PumpkinSettings|Health")
	float MaxHealth = 100.0f;
	
	// How much health the evil pumpkin has
	UPROPERTY(BlueprintReadOnly, Category="PumpkinSettings|Health")
	float CurrentHealth = 100.0f;

	// How much damage should the pumpkin do when evil per hit
	UPROPERTY(BlueprintReadOnly, Category="PumpkinSettings|Damage")
	float DamagePerHit = 50.0f;

	// Time required (in seconds) for the pumpkin to full grow
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PumpkinSettings|Timers")
	float GrowingTime = 15.0f;

	// Time limit (in seconds) for the pumpkin being harvested
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PumpkinSettings|Timers")
	float HarvestTime = 15.0f;

	// Time limit (in seconds) for the pumpkin to be destroyed before causing failure condition
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PumpkinSettings|Timers")
	float EvilTime = 15.0f;

	// Time limit (in seconds) for the pumpkin to be reset after being harvested
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PumpkinSettings|Timers")
	float ResetTime = 5.0f;

	// Time between each pulse of damage when the pumpkin is in an evil state
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PumpkinSettings|Timers")
	float TimeBetweenDamage = 2.0f;

	// Time it takes for the pumpkin to initially spawn in
	UPROPERTY(EditAnywhere, Category="PumpkinSettings|Timers")
	float PumpkinSpawnDelay = 0.0f;

	// Harvest state started Delegate instance
	UFUNCTION(BlueprintImplementableEvent)
	void OnPumpkinHarvestStateStarted();

	// Harvest state started Delegate instance
	UFUNCTION(BlueprintImplementableEvent)
	void OnPumpkinGrowingStateStarted();
	
	// Harvest Delegate instance
	UFUNCTION(BlueprintImplementableEvent)
	void OnPumpkinHarvested();

	// Evil state end Delegate instance
	UFUNCTION(BlueprintImplementableEvent)
	void OnPumpkinEvilStateStarted();
	
	// Evil state end Delegate instance
	UFUNCTION(BlueprintImplementableEvent)
	void OnPumpkinEvilStateEnd();
	
	// Update transform of pumpkin (called when team changes)
	void UpdatePumpkinTransform();

	UPROPERTY(BlueprintReadOnly)
	bool bIsRegistered = false;

	UPROPERTY(BlueprintReadOnly)
	bool bIsDisabled = false;

	UPROPERTY(BlueprintReadOnly)
	bool bIsEvil = false;

	// How many points should be given when the player harvests this pumpkin
	UPROPERTY(EditDefaultsOnly, Category="PumpkinSettings|Points")
	int PointsForHarvesting = 0;

	// How many points should be given when the player kills this pumpkin
	UPROPERTY(EditDefaultsOnly, Category="PumpkinSettings|Points")
	int PointsForKilling = 0;

	// How many points should be given when the pumpkin becomes harvestable
	UPROPERTY(EditDefaultsOnly, Category="PumpkinSettings|Points")
	int PointsForBeingHarvestable = 0;
private:
	// Timers for all states
	FTimerHandle StateTimer;
	
	FTimerHandle WaterDelayTimer;

	FTimerHandle DamageDelayTimer;

	FTimerHandle SpawnDelayTimer;

	TObjectPtr<APumpkinPlotPlundersGameMode> GameMode = nullptr;

	FTransform StartingTransform;
	
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
	
	void ResetPumpkin();

	void DisablePumpkin();
	
	void EnableDamage();

	void AttackLoop();

	TWeakObjectPtr<APumpkinPlotPlundersCharacter> GetPumpkinCharacter();
};


