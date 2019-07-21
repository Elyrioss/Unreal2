// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTriggerBox.h"
#include "Components/ShapeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "LapinScript.h"



bool IsActive;

AMyTriggerBox::AMyTriggerBox() {
	GetCollisionComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
}



void AMyTriggerBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	if (OtherActor == joueur){
		UE_LOG(LogTemp, Display, TEXT("COUCOUCUDOUEOCE"));
		spawn();
		Destroy();
	}
}


void AMyTriggerBox::spawn() {
	UWorld* world = GetWorld();
	if (world) {
		FActorSpawnParameters params;
		FRotator rotation = GetActorRotation();
		FVector location = GetActorLocation();
		ALapinScript* lapScript = world->SpawnActor<ALapinScript>(Lapin,location, rotation,params);
		lapScript->joueur = joueur;
		
		
	}
}
