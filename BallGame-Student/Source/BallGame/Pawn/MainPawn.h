// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MainPawn.generated.h"


UCLASS()
class BALLGAME_API AMainPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player")
	class USphereComponent* CollisionSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player")
	USceneComponent* VisualMeshRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player")
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent* MainCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	class USpringArmComponent* SpringArm;

	void MoveForward(float Amount);
	void MoveRight(float Amount);
	void Turn(float Amount);
	void Pause();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UFloatingPawnMovement* FloatingPawnMovement;

	float CurrentVelocity = 0;

	UFUNCTION()
	void OnActorOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnActorOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnHitActor(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	/**/

	/**  Method 2. Subscribe to Collision Shapes Collision Events	*/
	
	UFUNCTION()
	void  OnCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnCollisionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnCollisionSphereHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	bool bPaused;
};
