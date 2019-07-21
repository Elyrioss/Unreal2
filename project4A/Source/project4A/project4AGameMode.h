// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "project4AGameMode.generated.h"

UCLASS(minimalapi)
class Aproject4AGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	Aproject4AGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMusicSkill)
	int32 ScoreJoueur;

};



