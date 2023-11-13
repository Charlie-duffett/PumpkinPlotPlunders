// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverlayWidget.generated.h"

class UTextBlock;
class APumpkinPlotPlundersGameMode;
/**
 * 
 */
UCLASS()
class PUMPKINPLOTPLUNDERS_API UOverlayWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> SurvivalTime;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> Points;
	
private:
	TObjectPtr<APumpkinPlotPlundersGameMode> GameMode = nullptr;
	
protected:
	virtual void NativePreConstruct() override;

public:
	void UpdateTimer(int NewSeconds, int NewMinutes);

	void UpdatePoints(int NewPoints);
};
