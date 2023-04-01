// Fill out your copyright notice in the Description page of Project Settings.

#include "AssaultWeapon.h"
#include "DwarfCharacter.h"


AAssaultWeapon::AAssaultWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    FireRate = 0.5f;
    WeaponRange = 10000.0f;
    
}

void AAssaultWeapon::OnStartFire()
{
	Super::OnStartFire();
    GetWorldTimerManager().SetTimer(Timer, this,
        &AAssaultWeapon::WeaponTrace, FireRate, true);
}
void AAssaultWeapon::OnStopFire()
{
	Super::OnStopFire();
    GetWorldTimerManager().ClearTimer(Timer);
}

void AAssaultWeapon::WeaponTrace(){
    static FName WeaponFireTag = FName(TEXT("WeaponTrace"));
    static FName MuzzleSocket = FName(TEXT("MuzzleFlashSocket"));
    
    // Start from the muzzle's position
    FVector StartPos = WeaponMesh->GetSocketLocation(MuzzleSocket);
    
    // Get forward vector of MyPawn
    FVector Forward = MyPawn->GetActorForwardVector();
    
    // Calculate end position
    FVector EndPos = StartPos + (Forward * WeaponRange);
    
    // Perform line trace to retrieve hit info
    FCollisionQueryParams TraceParams(WeaponFireTag, true, GetInstigator());
    
    // This fires the ray and checks against all objects w/ collision
    FHitResult Hit(ForceInit);
    GetWorld()->LineTraceSingleByObjectType(Hit, StartPos,EndPos,
    FCollisionObjectQueryParams::AllObjects, TraceParams);
    // Did this hit anything?
    if (Hit.bBlockingHit)
   {
       UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitEffect, Hit.ImpactPoint);
       
       ADwarfCharacter* Dwarf = Cast <ADwarfCharacter>(Hit.GetActor());
       if (Dwarf)
       {
           GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Purple, FString::Printf(TEXT("HIT")));
           Dwarf->TakeDamage(1, FDamageEvent(), GetInstigatorController(), this);
       }
   }
}
