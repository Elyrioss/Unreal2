// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MyTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT4A_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:
	AMyTriggerBox();

	UPROPERTY(EditAnywhere, Category = "TOTO")
	AActor* joueur;
	

	UPROPERTY(EditAnywhere, Category = "TOTO")
	TSubclassOf<class ALapinScript> Lapin;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);
	

	UFUNCTION()
	void spawn();
};
