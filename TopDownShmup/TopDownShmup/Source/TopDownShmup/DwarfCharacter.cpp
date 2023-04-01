// Fill out your copyright notice in the Description page of Project Settings.

#include "DwarfCharacter.h"
#include "AIDwarfController.h"
//Added last include to fix line 44


ADwarfCharacter::ADwarfCharacter()
{
	AIControllerClass = AAIDwarfController::StaticClass();
}


float ADwarfCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent,
		EventInstigator, DamageCauser);
	if (ActualDamage > 0.0f)
	{
		//TODO: Add a debug message on screen to know dwarf got hit
		//Reduce health points
		Health -= ActualDamage;
		if (Health <= 0.0f)
		{

			// We're dead
			SetCanBeDamaged(false); // Don't allow further damage
			// Stop attack animation
			StopAttack();
			//play death anim
			deathLength = PlayAnimMontage(DeathAnim);
            //PlayerActor->GetController()->UnPossess();
            //this->DestroyAfterAnim(); // might b wrong
            
		}
	}
	return ActualDamage;
}


void ADwarfCharacter::StartAttack()
{
	PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//looping timer
	AttackLength = PlayAnimMontage(AttackAnim);

	GetWorldTimerManager().SetTimer(CountdownTimerHandle,
		[this]() { PlayerActor->TakeDamage(Damage, FDamageEvent(),
			GetInstigatorController(), this); }, AttackLength, true);
}




void ADwarfCharacter::StopAttack()
{

	StopAnimMontage();
	GetWorldTimerManager().ClearTimer(CountdownTimerHandle);

}


void ADwarfCharacter::DestroyAfterAnim()
{
	Destroy();
	this->RemoveFromRoot();
	GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
}
