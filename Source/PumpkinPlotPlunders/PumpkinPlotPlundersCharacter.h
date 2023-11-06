// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Damageable.h"
#include "Logging/LogMacros.h"
#include "PumpkinPlotPlundersCharacter.generated.h"

class UBoxComponent;
class IInteract;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class APumpkinPlotPlundersCharacter : public ACharacter,
	public IDamageable
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* InteractionCollisionBox;
	
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Options|Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Options|Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* InteractAction;
	
	/** Use Item Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Options|Input", meta = (AllowPrivateAccess = "true"))
    UInputAction* UseItemAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Options|Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Options|Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;
	
	TArray<TWeakObjectPtr<AActor>> InteractableActors;

	UPROPERTY(BlueprintReadOnly, Category = "ClosestActor", meta = (AllowPrivateAccess = "true"))
	TWeakObjectPtr<AActor> ClosestActor = nullptr;

	bool bIsHoldingItem = false;

	TWeakObjectPtr<AActor> HeldItem = nullptr;

	FTransform HeldItemTransform;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Options|Health", meta = (AllowPrivateAccess = "true"))
	float MaxHealth = 100.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Options|Health", meta = (AllowPrivateAccess = "true"))
	float CurrentHealth = 100.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Options|Health", meta = (AllowPrivateAccess = "true"))
	bool IsAlive = true;
public:
	APumpkinPlotPlundersCharacter();
	
	void RegisterInteractable(AActor* Interactable);
	void UnRegisterInteractable(AActor* Interactable);
	
	virtual void Tick(float DeltaSeconds) override;

	bool HoldItem(TWeakObjectPtr<AActor> Item, bool IsRake);

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void Interact();

	void UseItem();

	void CheckInteractables();
	
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	void UpdateClosestActor(TWeakObjectPtr<AActor> NewActor, float DistanceToPlayer, float& ClosetActorDist,
		float& ClosestActorDotProduct);

public:
	virtual void DealDamage(float DamageAmount) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	TWeakObjectPtr<AActor> GetClosestActor() const { return ClosestActor; }

	bool IsHoldingItem() const { return bIsHoldingItem; }

	TWeakObjectPtr<AActor> GetHeldItem() const { return HeldItem; }

	UFUNCTION()
	void OnBeginInteractionOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndInteractionOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};

