// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIEnemyController.h"
#include "Kismet/GameplayStatics.h"
#include "TopDownShmupCharacter.h"
#include "DwarfCharacter.h"
#include "AIDwarfController.generated.h"

/**
 * 
 */
enum class EDwarfState : short
{
	EStart, EChasing, EAttacking, EDead, EUnknown
};

UCLASS()
class TOPDOWNSHMUP_API AAIDwarfController : public AAIEnemyController
{
	GENERATED_BODY()
	
	APawn* MyPawn;
	APawn* PlayerActor;
	ADwarfCharacter* DwarfChar;
	ATopDownShmupCharacter* Player;

    //Dwarf getter/setters
	EDwarfState GetCurrentState() const;
	void SetCurrentState(EDwarfState NewState);

    //range for the ai to start attacking player
	UPROPERTY(EditAnywhere)
		float DwarfRange = 150.0f;

    //overriden functions
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;

	virtual void Tick(float DeltaTime) override;
	virtual void OnUnPossess() override;
    
private:
	/*Keeps Track of the current state*/
	EDwarfState CurrentState;
	/*Handle any function calls that rely on changing the play state of our game*/
	void HandleNewState(EDwarfState NewState);
    
	void MoveDwarf();
};
