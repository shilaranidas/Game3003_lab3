// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameC.h"

// Sets default values
AMyGameC::AMyGameC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyGameC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyGameC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyGameC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

