// Fill out your copyright notice in the Description page of Project Settings.


#include "RingSpawner.h"
#include "Ring.h"
// Sets default values
ARingSpawner::ARingSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARingSpawner::BeginPlay()
{
	Super::BeginPlay();
	//STEP 2

}

// Called every frame
void ARingSpawner::Tick(float const DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARingSpawner::SpawnRing()
{
	if (!IsValid(RingObject))
	{
		//STEP 2

	}
}

