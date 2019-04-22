// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerAvi_CPP.h"


// Sets default values
APlayerAvi_CPP::APlayerAvi_CPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AvatarAimingComponent = CreateDefaultSubobject<UAvatarAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void APlayerAvi_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerAvi_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerAvi_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerAvi_CPP::AimAt(FVector HitLocation)
{
	AvatarAimingComponent->AimAt(HitLocation);
}

void APlayerAvi_CPP::SetSwordReference(USkeletalMeshComponent* SwordToSet)
{
	AvatarAimingComponent->SetSwordReference(SwordToSet);
}

