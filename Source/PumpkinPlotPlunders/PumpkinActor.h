// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PumpkinActor.generated.h"

class UStaticMeshComponent;

enum class AlliedPumpkinState
{
	Growing,
	Harvestable,
};

UCLASS()
class PUMPKINPLOTPLUNDERS_API APumpkinActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APumpkinActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* PumpkinStaticMeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=PumpkinSettings)
	bool bIsEnemyTeam = false;

	// State of the Allied Pumpkin. Should be ignored if the pumpkin is on the enemy team
	AlliedPumpkinState PumpkinState = AlliedPumpkinState::Growing;
	
	// Location and rotation of pumpkin when it is on the Enemy Team
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=PumpkinSettings)
	FVector EnemyPumpkinLocation = FVector();
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=PumpkinSettings)
	FRotator EnemyPumpkinRotation = FRotator();

	// Location and rotation of pumpkin when it is on the Allied Team
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=PumpkinSettings)
	FVector AlliedPumpkinLocation = FVector();
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=PumpkinSettings)
	FRotator AlliedPumpkinRotation = FRotator();

	// When pumpkin Evil state is changed in editor set the location and rotation variables
	UFUNCTION(BlueprintCallable)
	void UpdatePumpkinTransform();

	void SwitchPumpkinTeam();
private:

};
