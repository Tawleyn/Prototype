// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerAviController_CPP.h"

void APlayerAviController_CPP::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledPlayerAvi = GetControlledPlayerAvi();
	if (!ControlledPlayerAvi)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing an Avatar"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledPlayerAvi->GetName()));
	}
}

void APlayerAviController_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAwayFromCamera();
}

APlayerAvi_CPP* APlayerAviController_CPP::GetControlledPlayerAvi() const
{

	return Cast<APlayerAvi_CPP>(GetPawn());
}

void APlayerAviController_CPP::AimAwayFromCamera()
{
	if (!GetControlledPlayerAvi()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		//TODO tell controlled player to aim at this point
	}
}

bool APlayerAviController_CPP::GetSightRayHitLocation(FVector& OnHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * AimXLocation, ViewportSizeY * AimYLocation);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());

	return true;
}