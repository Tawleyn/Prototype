// Fill out your copyright notice in the Description page of Project Settings.

#include "AvatarAimingComponent.h"


// Sets default values for this component's properties
UAvatarAimingComponent::UAvatarAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UAvatarAimingComponent::SetSwordReference(USkeletalMeshComponent* SwordToSet)
{
	Sword = SwordToSet;
}

// Called when the game starts
void UAvatarAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAvatarAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAvatarAimingComponent::AimAt(FVector HitLocation)
{
	auto MyAvatarName = GetOwner()->GetName();
	auto SwordLocation = Sword->GetComponentLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *MyAvatarName, *HitLocation.ToString(), *SwordLocation);
}

