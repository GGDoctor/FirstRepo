// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyCharacter.h"
#include "DwarfCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API ADwarfCharacter : public AEnemyCharacter
{
	GENERATED_BODY()
public:
	ADwarfCharacter();
	void StartAttack();

	FTimerHandle TimerHandle;
	FTimerHandle CountdownTimerHandle;
	FTimerHandle attackTimer;
	APawn* PlayerActor;

	void StopAttack();
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;
	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* AttackAnim;
	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* DeathAnim;
	UPROPERTY(EditAnywhere)
		float Health = 20.f;
	UPROPERTY(EditAnywhere)
		float damage = 10.f;

	float attackLength = 0.f;
	float deathLength = 0.f;
	void DestroyAfterAnim();
};
