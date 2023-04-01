// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyCharacter.h"
#include "DwarfCharacter.generated.h"

/*
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API ADwarfCharacter : public AEnemyCharacter
{
	GENERATED_BODY()
public:
	ADwarfCharacter();
    
	void StartAttack();//basically just calling the anim functions for the variables below 
    void StopAttack();

	FTimerHandle TimerHandle;
	FTimerHandle CountdownTimerHandle;
	FTimerHandle AttackTimer;
	APawn* PlayerActor;

    
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;
    
    
	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* AttackAnim; //UAnim is a sequence of one or more animations which you can invoke through code
    
	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* DeathAnim;
    
	UPROPERTY(EditAnywhere)
		float Health = 20.f;
    
	UPROPERTY(EditAnywhere)
		float Damage = 10.f;

	float AttackLength = 0.f;
	float deathLength = 0.f;
	void DestroyAfterAnim();
};
