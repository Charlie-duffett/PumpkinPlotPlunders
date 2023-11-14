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
		FString Seconds;
		FString Minutes;

		if (NewSeconds >= 10)
		{
			Seconds = FString::Printf(TEXT("%d"), NewSeconds);
		}
		else
		{
			Seconds = FString::Printf(TEXT("0%d"), NewSeconds);
		}

		if (NewMinutes >= 10)
		{
			Minutes = FString::Printf(TEXT("%d"), NewMinutes);
		}
		else
		{
			Minutes = FString::Printf(TEXT("0%d"), NewMinutes);
		}
		
		const FString TimeString = FString::Printf(TEXT("%s:%s"), *Minutes, *Seconds);

		SurvivalTime->SetText(FText::FromString(TimeString));
	}
}

void UOverlayWidget::UpdatePoints(int NewPoints)
{
	if (IsValid(Points))
	{
		const FString PointString = FString::Printf(TEXT("%d"), NewPoints);

		Points->SetText(FText::FromString(PointString));
	}
}
