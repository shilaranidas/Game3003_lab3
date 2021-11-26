// Copyright Epic Games, Inc. All Rights Reserved.

#include "Lab_Das_ShilaCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ALab_Das_ShilaCharacter::ALab_Das_ShilaCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ALab_Das_ShilaCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALab_Das_ShilaCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ALab_Das_ShilaCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ALab_Das_ShilaCharacter::TouchStopped);
	/*CurrentHealth = 100;
	NumberOfCoins = 0;
	NumberOfTrapsSet = 0;*/
}

void ALab_Das_ShilaCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void ALab_Das_ShilaCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void ALab_Das_ShilaCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

//void ALab_Das_ShilaCharacter::DecHealth()
//{
//	if (GEngine)
//	{
//		if (CurrentHealth > 10)
//			CurrentHealth -= 10;
//		else
//			CurrentHealth = 0;
//		//GEngine->AddOnScreenDebugMessage(2, 1.0f, FColor::Red, FString::Printf(TEXT("CharacterFunction: CurrentHealth= %d"), CurrentHealth));
//	}
//}
//
//void ALab_Das_ShilaCharacter::CoinPickUp()
//{
//	if (GEngine)
//	{
//		if (ActiveLevelNo == 1)
//		{
//			if (NumberOfCoins < 10)
//				NumberOfCoins++;
//		}
//		else if (ActiveLevelNo == 2)
//		{
//			if (NumberOfCoins < 20)
//				NumberOfCoins++;
//		}
//		else if (ActiveLevelNo == 3)
//		{
//			if (NumberOfCoins < 30)
//				NumberOfCoins++;
//		}
//		//GEngine->AddOnScreenDebugMessage(2, 1.0f, FColor::Red, FString::Printf(TEXT("CharacterFunction: NumberOfCoins= %d"), NumberOfCoins));
//	}
//}
//
//void ALab_Das_ShilaCharacter::TrapSet()
//{
//	if (GEngine)
//	{
//		if (ActiveLevelNo == 1)
//		{
//			if (NumberOfCoins >= 5)
//				NumberOfCoins -= 5;
//		}
//		else if (ActiveLevelNo == 2)
//		{
//			if (NumberOfCoins >= 10)
//				NumberOfCoins -= 10;
//		}
//		else if (ActiveLevelNo == 3)
//		{
//			if (NumberOfCoins >= 15)
//				NumberOfCoins -= 15;
//		}
//		//GEngine->AddOnScreenDebugMessage(2, 1.0f, FColor::Red, FString::Printf(TEXT("CharacterFunction: NumberOfCoins= %d"), NumberOfCoins));
//	}
//}
//void ALab_Das_ShilaCharacter::AddTrapNo()
//{
//	if (GEngine)
//	{
//		NumberOfTrapsSet++;
//		//GEngine->AddOnScreenDebugMessage(2, 1.0f, FColor::Red, FString::Printf(TEXT("CharacterFunction: NumberOfTrapsSet= %d"), NumberOfTrapsSet));
//	}
//}
