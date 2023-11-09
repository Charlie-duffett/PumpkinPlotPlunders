// Copyright Epic Games, Inc. All Rights Reserved.

#include "PumpkinPlotPlundersCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Components/BoxComponent.h"
#include "Interfaces/Interact.h"
#include "Interfaces/Useable.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// APumpkinPlotPlundersCharacter

APumpkinPlotPlundersCharacter::APumpkinPlotPlundersCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	InteractionCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Interation Collision Box"));
	InteractionCollisionBox->SetupAttachment(RootComponent);

	Tags.AddUnique(TEXT("PumpkinDamageable"));
}

void APumpkinPlotPlundersCharacter::RegisterInteractable(AActor* Interactable)
{
	const IInteract* InteractableActor = Cast<IInteract>(Interactable);
	if (InteractableActor != nullptr)
	{
		InteractableActors.Add(Interactable);
		UE_LOG(LogTemp, Warning, TEXT("Added Interactable"))
		// Interactable->OnDestroyed.AddDynamic(this, &ThisClass::UnRegisterInteractable);
	}
}

void APumpkinPlotPlundersCharacter::UnRegisterInteractable(AActor* Interactable)
{
	const IInteract* InteractableActor = Cast<IInteract>(Interactable);
	if (InteractableActor != nullptr)
	{
		InteractableActors.Remove(Interactable);
		UE_LOG(LogTemp, Warning, TEXT("Removed Interactable"))
	}
}

void APumpkinPlotPlundersCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CheckInteractables();
}

bool APumpkinPlotPlundersCharacter::HoldItem(TWeakObjectPtr<AActor> Item, bool IsRake)
{
	if (bIsHoldingItem)
	{
		bIsHoldingItem = false;
		HeldItem->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		HeldItem->SetActorTransform(HeldItemTransform);
	}

	HeldItemTransform = Item->GetActorTransform();
	
	bool bHeldSuccessfully = false;
	if (IsRake)
	{
		bHeldSuccessfully = Item->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, "HoldRake");
	}
	else
	{
		bHeldSuccessfully = Item->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, "HoldWateringCan");
	}
	

	if (bHeldSuccessfully)
	{
		bIsHoldingItem = true;
		HeldItem = Item;
		UE_LOG(LogTemp, Warning, TEXT("Holding item!"))
		return true;
	}
	return false;
}

void APumpkinPlotPlundersCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	if (InteractionCollisionBox)
	{
		InteractionCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginInteractionOverlap);
		InteractionCollisionBox->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndInteractionOverlap);
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void APumpkinPlotPlundersCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ThisClass::Interact);

		// Use held item
		EnhancedInputComponent->BindAction(UseItemAction, ETriggerEvent::Triggered, this, &ThisClass::UseItem);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APumpkinPlotPlundersCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APumpkinPlotPlundersCharacter::Look);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void APumpkinPlotPlundersCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void APumpkinPlotPlundersCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void APumpkinPlotPlundersCharacter::Interact()
{
	if (!ClosestActor.IsValid())
	{
		return;
	}
	IInteract* InteractableActor = Cast<IInteract>(ClosestActor);
	if (InteractableActor != nullptr)
	{
		InteractableActor->Interact(this);
	}
}

void APumpkinPlotPlundersCharacter::UseItem()
{
	if (bIsHoldingItem)
	{
		IUseable* Item = Cast<IUseable>(HeldItem);
		if (Item == nullptr)
		{
			return;
		}

		Item->Activate();
	}
}

void APumpkinPlotPlundersCharacter::UpdateClosestActor(TWeakObjectPtr<AActor> NewActor, float DistanceToPlayer,
	float& ClosetActorDist, float& ClosestActorDotProduct)
{
	// We dont want to interact with the item we are holding!
	if (bIsHoldingItem && NewActor == HeldItem)
	{
		return;
	}
	const float DotProduct = this->GetDotProductTo(NewActor.Get());
	
	if (DotProduct >= 0.0f && DotProduct > ClosestActorDotProduct)
	{
		ClosestActor = NewActor;
		ClosetActorDist = DistanceToPlayer;
		ClosestActorDotProduct = DotProduct;
	}
}

void APumpkinPlotPlundersCharacter::DealDamage(float DamageAmount)
{
	CurrentHealth -= DamageAmount;

	if (CurrentHealth <= 0.0f)
	{
		IsAlive = false;
		// Trigger on death event
		this->Destroy();
	}
}

void APumpkinPlotPlundersCharacter::OnBeginInteractionOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->ComponentHasTag(TEXT("InteractionCollision")))
	{
		RegisterInteractable(OtherActor);
	}
}

void APumpkinPlotPlundersCharacter::OnEndInteractionOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp->ComponentHasTag(TEXT("InteractionCollision")))
	{
		UnRegisterInteractable(OtherActor);
	}
}

void APumpkinPlotPlundersCharacter::CheckInteractables()
{
	TWeakObjectPtr<AActor> OldClosestActor = ClosestActor;
	ClosestActor = nullptr;
	float ClosestActorDotProduct = -1.0f;
	float ClosestActorDist = FLT_MAX;
	
	for (const auto Interactable : InteractableActors)
	{
		if (!Interactable.IsValid())
		{
			continue;
		}
		
		const float DistToInteractable = FVector::Dist(GetActorLocation(), Interactable->GetActorLocation());
		
		if (DistToInteractable < ClosestActorDist)
		{

			UpdateClosestActor(Interactable, DistToInteractable, ClosestActorDist, ClosestActorDotProduct);
		}
	}

	if (ClosestActor != OldClosestActor)
	{
		IInteract* OldInteractClosestActor = Cast<IInteract>(OldClosestActor);
		IInteract* InteractClosestActor = Cast<IInteract>(ClosestActor);

		if (OldClosestActor.IsValid())
		{
			OldInteractClosestActor->Execute_OnDeselected(OldClosestActor.Get());
		}
		
		if (ClosestActor.IsValid())
		{
			InteractClosestActor->Execute_OnSelected(ClosestActor.Get());
		}
	}
}
