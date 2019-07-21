// Fill out your copyright notice in the Description page of Project Settings.

#include "LapinScript.h"
#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ALapinScript::ALapinScript()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALapinScript::BeginPlay()
{
	//GetController<AIController>();
	Super::BeginPlay();

}




// Called every frame
void ALapinScript::Tick(float DeltaTime)
{
	if (!joueur) {
		return;
	}
	FVector jtransform = joueur->GetActorLocation();
	FVector ltransform = GetActorLocation();
	FVector vectorBetween = jtransform - ltransform;
	float distance = vectorBetween.Size();
	//UE_LOG(LogTemp, Display, TEXT("Distance : %f"),distance);
	vectorBetween.Z = 0;

	if (distance <= 100) {
		//destroy
		UE_LOG(LogTemp, Display, TEXT("Score + 1"));

		Destroy();
	}
	if (distance < 400) {
		vectorBetween.Normalize();
		FVector direction = ltransform - vectorBetween * 300 * DeltaTime;
		FHitResult HitResult;
		SetActorLocation(direction, true,&HitResult); // le true sert a voir si il y'a collision , si oui il s'arrette.
		if (HitResult.bBlockingHit && HitResult.Actor != joueur) {
			FVector reflect = UKismetMathLibrary::GetReflectionVector(-vectorBetween,HitResult.ImpactNormal);
			direction = ltransform +  reflect * 300 * DeltaTime;
			SetActorLocation(direction,true);
		}
		//AVEC LOOKAT
		SetActorRotation((-vectorBetween).ToOrientationQuat());
	}
	Super::Tick(DeltaTime);

}



// Called to bind functionality to input
void ALapinScript::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}



