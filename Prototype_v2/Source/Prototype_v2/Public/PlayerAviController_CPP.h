// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerAvi_CPP.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/PlayerController.h"
#include "PlayerAviController_CPP.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_V2_API APlayerAviController_CPP : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	APlayerAvi_CPP* GetControlledPlayerAvi() const;

	void AimAwayFromCamera();

	bool GetSightRayHitLocation(FVector& OnHitLocation) const;

	UPROPERTY(EditAnywhere)
	float AimXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float AimYLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 2000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
