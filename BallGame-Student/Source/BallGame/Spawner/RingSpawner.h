#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RingSpawner.generated.h"

UCLASS()
class BALLGAME_API ARingSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARingSpawner();

	// Called every frame
	virtual void Tick(float const DeltaTime) override;

	//STEP 2

	void SpawnRing();

	UPROPERTY(Transient)
		class ARing* RingObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};