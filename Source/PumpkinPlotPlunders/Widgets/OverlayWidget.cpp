// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayWidget.h"
#include "Components/TextBlock.h"
#include "PumpkinPlotPlunders/PumpkinPlotPlundersGameMode.h"

void UOverlayWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	GameMode = Cast<APumpkinPlotPlundersGameMode>(GetWorld()->GetAuthGameMode());

	if (IsValid(GameMode))
	{
		GameMode->OnTimeUpdated.BindUObject(this, &ThisClass::UpdateTimer);
		GameMode->OnPointsUpdated.BindUObject(this, &ThisClass::UpdatePoints);
	}
}

void UOverlayWidget::UpdateTimer(int NewSeconds, int NewMinutes)
{
	if (IsValid(SurvivalTime))
	{
		const FString TimeString = FString::Printf(TEXT("%d:%d"), NewMinutes, NewSeconds);

		SurvivalTime->SetText(FText::FromString(TimeString));
	}
}

void UOverlayWidget::UpdatePoints(int NewPoints)
{
	if (IsValid(Points))
	{
		const FString PointString = FString::Printf(TEXT("%d"), Points);

		SurvivalTime->SetText(FText::FromString(PointString));
	}
}
