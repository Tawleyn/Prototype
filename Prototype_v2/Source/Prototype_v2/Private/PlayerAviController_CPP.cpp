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
		GetControlledPlayerAvi()->AimAt(HitLocation);
		//TODO tell controlled player to aim at this point
	}
}

bool APlayerAviController_CPP::GetSightRayHitLocation(FVector& OnHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * AimXLocation, ViewportSizeY * AimYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, OnHitLocation);
	}

	return true;
}

bool APlayerAviController_CPP::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = /*PlayerCameraManager->GetCameraLocation()*/ (GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor(255, 0, 0), false, -1, 0, 12.33);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

bool APlayerAviController_CPP::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}