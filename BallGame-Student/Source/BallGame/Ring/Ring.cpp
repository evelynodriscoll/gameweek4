// Fill out your copyright notice in the Description page of Project Settings.


#include "Ring.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ARing::ARing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USphereComponent>(TEXT("RootSphereComponent"));
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	SetRootComponent(Root);
	//RootComponent = Root;
	VisualMesh->SetupAttachment(RootComponent);

	//STEP 2
	VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

// Called when the game starts or when spawned
void ARing::BeginPlay()
{
	Super::BeginPlay();
}

// Spinning and floating visual effect
void ARing::Spin(float DeltaTime)
{
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();

	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = FMath::Sin(RunningTime * FloatingSpeed) - FMath::Sin((RunningTime - DeltaTime) * FloatingSpeed);

	// Scale the height by the FloatingDistance
	NewLocation.Z += DeltaHeight * FloatingDistance;

	// Rotate by DeltaRotation degrees per second
	float DeltaRotation = DeltaTime * RotationSpeed;
	NewRotation.Yaw += DeltaRotation;

	SetActorLocationAndRotation(NewLocation, NewRotation);
}

// Called every frame
void ARing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Spin(DeltaTime);
}

