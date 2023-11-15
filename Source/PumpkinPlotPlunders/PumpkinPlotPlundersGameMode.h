// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PumpkinPlotPlundersGameMode.generated.h"

DECLARE_DELEGATE_TwoParams(FTimeUpdatedDelegate, int, int);
DECLARE_DELEGATE_OneParam(FPointsUpdatedDelegate, int);

UCLASS(minimalapi)
class APumpkinPlotPlundersGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APumpkinPlotPlundersGameMode();

	void AddOneSecondToTime();

	void AddPoints(int AmountToAdd);

	UPROPERTY(BlueprintReadOnly)
	int Points = 0;

	UPROPERTY(BlueprintReadOnly)
	int Seconds = 0;

	UPROPERTY(BlueprintReadOnly)
	int Minutes = 0;

	FTimeUpdatedDelegate OnTimeUpdated;

	FPointsUpdatedDelegate OnPointsUpdated;
protected:
	virtual void BeginPlay() override;

private:
	FTimerHandle SecondTimer;
};



