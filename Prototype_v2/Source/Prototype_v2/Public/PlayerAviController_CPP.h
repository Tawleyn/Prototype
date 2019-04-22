// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerAvi_CPP.h"
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
	APlayerAvi_CPP* GetControlledPlayerAvi() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimAwayFromCamera();
};
