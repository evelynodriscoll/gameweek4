#include "MainPlayerController.h"

#include "MainPawn.h"

// Sets default values
AMainPlayerController::AMainPlayerController()
{

}

void AMainPlayerController::AcknowledgePossession(APawn* P)
{
	Super::AcknowledgePossession(P);

	TheMainPawn = Cast<AMainPawn>(P);

}

void AMainPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	//TheMainPawn = Cast<AMainPawn>(aPawn); //NOPE
}

void AMainPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//if(InputComponent)
	//{

	//	InputComponent->BindAxis("MoveForward", TheMainPawn, &AMainPawn::MoveForward);
	//	InputComponent->BindAxis("MoveRight", TheMainPawn, &AMainPawn::MoveRight);
	//	InputComponent->BindAxis("Turn", TheMainPawn, &AMainPawn::Turn);
	//	//PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	//	InputComponent->BindAction("Pause", IE_Pressed, TheMainPawn, &AMainPawn::Pause);
	//}
}

