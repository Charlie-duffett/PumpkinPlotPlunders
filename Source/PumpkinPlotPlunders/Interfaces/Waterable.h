// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Waterable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWaterable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PUMPKINPLOTPLUNDERS_API IWaterable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Water(float WaterIncrease);

	virtual bool IsWaterable();
};
