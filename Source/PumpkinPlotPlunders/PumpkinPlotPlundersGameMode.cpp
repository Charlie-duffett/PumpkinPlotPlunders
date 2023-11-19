// Copyright Epic Games, Inc. All Rights Reserved.

#include "PumpkinPlotPlundersGameMode.h"
#include "PumpkinPlotPlundersCharacter.h"
#include "UObject/ConstructorHelpers.h"

APumpkinPlotPlundersGameMode::APumpkinPlotPlundersGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_PlayerController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}

	SecondTimer.Invalidate();
}

void APumpkinPlotPlundersGameMode::AddOneSecondToTime()
{
	++Seconds;

	if (Seconds >= 60)
	{
		Seconds = 0;
		++Minutes;
	}
	OnTimeUpdated.ExecuteIfBound(Seconds, Minutes);
}

void APumpkinPlotPlundersGameMode::AddPoints(int AmountToAdd)
{
	Points += AmountToAdd;

	OnPointsUpdated.ExecuteIfBound(Points);
}

void APumpkinPlotPlundersGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SecondTimer, this, &ThisClass::AddOneSecondToTime, 1.0f,
			true);
}
