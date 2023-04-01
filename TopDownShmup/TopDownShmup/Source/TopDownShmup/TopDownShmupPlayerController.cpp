// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TopDownShmupPlayerController.h"
#include "TopDownShmup.h"
#include "Weapon.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

ATopDownShmupPlayerController::ATopDownShmupPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATopDownShmupPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	UpdateMouseLook();

}

void ATopDownShmupPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATopDownShmupPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATopDownShmupPlayerController::MoveRight);

	//InputComponent->BindAction("SetDestination", IE_Pressed, this,  &ATopDownShmupPlayerController::OnSetDestinationPressed);
    //**also delete these for firing effect pg9**
	//InputComponent->BindAction("SetDestination", IE_Released, this, &ATopDownShmupPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ATopDownShmupPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ATopDownShmupPlayerController::MoveToTouchLocation);
    
    InputComponent->BindAction("Fire", IE_Pressed, this,  &ATopDownShmupPlayerController::OnStartFire);
    InputComponent->BindAction("Fire", IE_Released, this,  &ATopDownShmupPlayerController::OnStopFire);
    
    
}

void ATopDownShmupPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void ATopDownShmupPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void ATopDownShmupPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
        if (Distance > 120.0f)
		{
            UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

/*void ATopDownShmupPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void ATopDownShmupPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}*/

void ATopDownShmupPlayerController::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		APawn* const Pawn = GetPawn();
		if (Pawn)
		{
			Pawn->AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
		}
	}
}

void ATopDownShmupPlayerController::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		APawn* const Pawn = GetPawn();
		if (Pawn)
		{
			Pawn->AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
		}
	}
}
void ATopDownShmupPlayerController::UpdateMouseLook()
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	
		if (Hit.bBlockingHit)
		{
			float x = Hit.ImpactPoint.X - Pawn->GetActorLocation().X;
			float y = Hit.ImpactPoint.Y - Pawn->GetActorLocation().Y;;
			
			FVector newVec;
			newVec.X = x;
			newVec.Y = y;
			newVec.Z = 0.0f;
			newVec.Normalize();
			Pawn->SetActorRotation(newVec.Rotation());
		}
	}
}

void ATopDownShmupPlayerController::OnStartFire(){
    APawn* const Pawn = GetPawn();
    if (Pawn)
    {
        ATopDownShmupCharacter *MyCharacter = Cast<ATopDownShmupCharacter>(Pawn);
        MyCharacter->OnStartFire();
    }
}

void ATopDownShmupPlayerController::OnStopFire(){
    APawn* const Pawn = GetPawn();
    if (Pawn)
    {
        ATopDownShmupCharacter *MyCharacter = Cast<ATopDownShmupCharacter>(Pawn);
        MyCharacter->OnStopFire();
    }
}
