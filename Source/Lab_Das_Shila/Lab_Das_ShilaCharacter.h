// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Lab_Das_ShilaCharacter.generated.h"

UCLASS(config=Game)
class ALab_Das_ShilaCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


public:
	ALab_Das_ShilaCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/*How much health value is and Starts at 100*/
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "My Category", meta = (ALlowPrivateAccess = "true"))
	//	int CurrentHealth;
	///*How many coin*/
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "My Category", meta = (ALlowPrivateAccess = "true"))
	//	int NumberOfCoins;
	///*How many trap*/
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "My Category", meta = (ALlowPrivateAccess = "true"))
	//	int NumberOfTrapsSet;
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "My Category", meta = (ALlowPrivateAccess = "true"))
	//	int ActiveLevelNo;
	///* Decrements by 10 when hit by trap*/
	//UFUNCTION(BlueprintCallable, Category = "My Category")
	//	void DecHealth();
	///*Increments by 1 when coin picked up*/
	//UFUNCTION(BlueprintCallable, Category = "My Category")
	//	void CoinPickUp();
	///*Uses up 5 Coins for one trap*/
	//UFUNCTION(BlueprintCallable, Category = "My Category")
	//	void TrapSet();
	///*Increments by 1 when trap collide*/
	//UFUNCTION(BlueprintCallable, Category = "My Category")
	//	void AddTrapNo();
};
