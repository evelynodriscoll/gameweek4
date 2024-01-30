// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPawn.h"
#include "BallGameGameModeBase.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "UObject/UObjectGlobals.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/EngineBaseTypes.h"

#include "Math/UnrealMathUtility.h"

// Sets default values
AMainPawn::AMainPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	VisualMeshRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VisualMeshRoot"));
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	//CollisionSphere->SetSimulatePhysics(true);//
	SetRootComponent(CollisionSphere);
	SpringArm->SetupAttachment(RootComponent);
	VisualMeshRoot->SetupAttachment(RootComponent);
	VisualMesh->SetupAttachment(VisualMeshRoot);
	MainCamera->SetupAttachment(SpringArm);

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;
	//AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Disable collision on the visual static mesh in favor of a sphere collider
	VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	VisualMesh->SetCollisionProfileName(TEXT("IgnoreAll"));

	bPaused = false;

}

// Called when the game starts or when spawned
void AMainPawn::BeginPlay()
{
	Super::BeginPlay();
	//method one actoroverlap
	OnActorBeginOverlap.AddDynamic(this, &AMainPawn::OnActorOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AMainPawn::OnActorOverlapEnd);
	
}

void AMainPawn::OnActorOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{

}

void AMainPawn::OnActorOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
}

void AMainPawn::OnHitActor(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
}

void AMainPawn::OnCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AMainPawn::OnCollisionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AMainPawn::OnCollisionSphereHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

// Called every frame
void AMainPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector lastInputVector = GetLastMovementInputVector() + FloatingPawnMovement->Velocity;
	lastInputVector.Normalize(0.0001f);

	float circumference = CollisionSphere->GetScaledSphereRadius() * 2 * PI;

	FVector direction = lastInputVector * DeltaTime * circumference;
	
	FRotator rotation(direction.X * -1, 0, direction.Y);

	VisualMeshRoot->AddWorldRotation(rotation);
}

void AMainPawn::MoveForward(float Amount)
{
	if(!bPaused)
		FloatingPawnMovement->AddInputVector(GetActorForwardVector() * Amount);
	/*CurrentVelocity += 100 * FApp::GetDeltaTime();
	FloatingPawnMovement->Velocity = GetActorForwardVector()* CurrentVelocity;*/
}

void AMainPawn::MoveRight(float Amount)
{
	if (!bPaused)
		FloatingPawnMovement->AddInputVector(GetActorRightVector() * Amount);
}

void AMainPawn::Turn(float Amount)
{
	if (!bPaused)
	  AddControllerYawInput(Amount);
}

void AMainPawn::Pause()
{
	//UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("MainMenu")));
	bPaused = !bPaused;
	
}

// Called to bind functionality to input
void AMainPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMainPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainPawn::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMainPawn::Turn);
	//PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &AMainPawn::Pause);
}

