// Copyright Epic Games, Inc. All Rights Reserved.

#include "AchievementLabGameMode.h"
#include "AchievementLabCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAchievementLabGameMode::AAchievementLabGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
