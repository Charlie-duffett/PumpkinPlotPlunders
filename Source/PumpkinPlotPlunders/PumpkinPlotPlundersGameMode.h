// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PumpkinPlotPlundersGameMode.generated.h"

UCLASS(minimalapi)
class APumpkinPlotPlundersGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APumpkinPlotPlundersGameMode();

	void AddOneSecondToTime();

	void AddPoints(int AmountToAdd);
	
	int Points = 0;

	int Seconds = 0;

	int Minutes = 0;
protected:
	virtual void BeginPlay() override;

private:
	FTimerHandle SecondTimer;
};



