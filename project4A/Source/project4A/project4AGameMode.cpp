// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "project4AGameMode.h"
#include "project4ACharacter.h"
#include "UObject/ConstructorHelpers.h"

Aproject4AGameMode::Aproject4AGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
