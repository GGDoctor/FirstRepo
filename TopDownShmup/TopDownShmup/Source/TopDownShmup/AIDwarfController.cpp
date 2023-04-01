// Fill out your copyright notice in the Description page of Project Settings.


#include "AIDwarfController.h"

void AAIDwarfController::BeginPlay()
{
	Super::BeginPlay();
	SetCurrentState(EDwarfState::EStart);
	MoveDwarf();
	Player = Cast<ATopDownShmupCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)); //possesed pawn cast to character
}


void AAIDwarfController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetCurrentState() == EDwarfState::EStart)
	{
		SetCurrentState(EDwarfState::EChasing);
	}
    if ((PlayerActor->GetDistanceTo(MyPawn) <= DwarfRange)) // when dwarf is attacking
    {
        SetCurrentState(EDwarfState::EAttacking);
        DwarfChar->StartAttack(); //make dwarf chase character again
    }

	if (GetCurrentState() == EDwarfState::EAttacking &&
		(PlayerActor->GetDistanceTo(MyPawn) > DwarfRange)) // when dwarf is attacking and player runs away
	{
		SetCurrentState(EDwarfState::EChasing); //make dwarf chase character again
	}
	if (Player)
	{
		if ((Player->isDead()))
		{
			if (GetCurrentState() == EDwarfState::EAttacking)
			{
				DwarfChar->StopAttack();
				SetCurrentState(EDwarfState::EUnknown); //default state. player is dead game over
			}
			return;
		}
	}
}

void AAIDwarfController::MoveDwarf()
{
	if (DwarfChar)
	{
		DwarfChar->StopAttack();
		PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		MoveToActor(PlayerActor);
	}
}

void AAIDwarfController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	MyPawn = InPawn;
	DwarfChar = Cast<ADwarfCharacter>(MyPawn);
}


void AAIDwarfController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (!Player->isDead())
	{
		SetCurrentState(EDwarfState::EAttacking);
        DwarfChar->StartAttack(); 
	}
	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Yellow, FString::Printf(TEXT("move completed")));
}

EDwarfState AAIDwarfController::GetCurrentState() const
{
	return CurrentState;
}


void AAIDwarfController::SetCurrentState(EDwarfState NewState)
{
	/*Set Current State*/
	CurrentState = NewState;
	/*Handle the new current state*/
	HandleNewState(CurrentState);
}


void AAIDwarfController::HandleNewState(EDwarfState NewState)
{
	switch (NewState)
    {
        case EDwarfState::EStart:
            break;

        case EDwarfState::EChasing:
        {
            if (this)
            {
                MoveDwarf();
            }
        }
        break;
        case EDwarfState::EAttacking:
        {
            if (DwarfChar)
            {
                DwarfChar->StartAttack();
            }
        }
        break;
        case EDwarfState::EDead:
        {
            //kill the dwarf
        }
        default:
        case EDwarfState::EUnknown:
        {
            DwarfChar->StopAttack();
        }
        break;
	}
}

void AAIDwarfController::OnUnPossess()
{
	Super::OnUnPossess();
	PrimaryActorTick.bCanEverTick = false;

}
