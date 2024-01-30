// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ring.generated.h"

UCLASS()
class BALLGAME_API ARing : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARing();

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Root;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere)
	float RotationSpeed;

	UPROPERTY(EditAnywhere)
	float FloatingSpeed;

	UPROPERTY(EditAnywhere)
	float FloatingDistance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Spin(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
