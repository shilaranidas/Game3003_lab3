// Copyright Epic Games, Inc. All Rights Reserved.

#include "Lab_Das_ShilaGameMode.h"
#include "Lab_Das_ShilaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALab_Das_ShilaGameMode::ALab_Das_ShilaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
//void ALab_Das_ShilaGameMode::CoinPickUp()
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
