// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Weapon.generated.h"

UCLASS()
class TOPDOWNSHMUP_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	//When starting Unreal it says this does not work and both the VisibleDefault and BlueprintReadOnly are issues.
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category=Weapon)
	USkeletalMeshComponent* WeaponMesh;
    
    UPROPERTY(EditDefaultsOnly, Category=Sound)
    USoundCue* FireLoopSound;
    
    UPROPERTY(EditDefaultsOnly, Category=Sound)
    USoundCue* FireFinishSound;
    
    UPROPERTY(EditDefaultsOnly, Category=Effects)
    UParticleSystem* MuzzleFX;
    
    APawn* MyPawn;
    
	// Sets default values for this actor's properties
	AWeapon();

	virtual void OnStartFire();
	virtual void OnStopFire();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    UPROPERTY(Transient)
    UAudioComponent* FireAC;
    
    UPROPERTY(Transient)
    UParticleSystemComponent* MuzzleVC; 
    
    UAudioComponent* PlayWeaponSound(USoundCue* Sound);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
