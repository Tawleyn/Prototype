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

void UAvatarAimingComponent::SetAvatarReference(USkeletalMeshComponent* AvatarToSet)
{
	Avatar = AvatarToSet;
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
	if (!Avatar) { return; }
	auto MyAvatarName = GetOwner()->GetName();
	auto AvatarLocation = Avatar->GetComponentLocation().ToString();

	MoveAvatarToward(HitLocation);

	//Start a trace from the hilt of the sword
	auto TraceStart = Avatar->GetSocketLocation(FName("SwingSocket"));

	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *MyAvatarName, *HitLocation.ToString(), *AvatarLocation);
}

void UAvatarAimingComponent::MoveAvatarToward(FVector AimDirection)
{
	auto AvatarRotator = Avatar->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
}