// Fill out your copyright notice in the Description page of Project Settings.


#include "PumpkinActor.h"

// Sets default values
APumpkinActor::APumpkinActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PumpkinStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PumpkinStaticMesh"));
	PumpkinStaticMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APumpkinActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void APumpkinActor::UpdatePumpkinTransform()
{
	if (bIsEnemyTeam)
	{
		PumpkinStaticMeshComponent->SetRelativeLocation(EnemyPumpkinLocation);
		PumpkinStaticMeshComponent->SetRelativeRotation(EnemyPumpkinRotation);
	}
	else
	{
		PumpkinStaticMeshComponent->SetRelativeLocation(AlliedPumpkinLocation);
		PumpkinStaticMeshComponent->SetRelativeRotation(AlliedPumpkinRotation);
	}
	
}

void APumpkinActor::SwitchPumpkinTeam()
{
	bIsEnemyTeam = !bIsEnemyTeam;
	// note we also need to kill any timers on this actor aswell!
}