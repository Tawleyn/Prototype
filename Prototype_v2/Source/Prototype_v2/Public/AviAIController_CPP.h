// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerAvi_CPP.h"
#include "AIController.h"
#include "AviAIController_CPP.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_V2_API AAviAIController_CPP : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	
	APlayerAvi_CPP* GetControlledPlayerAvi() const;

	APlayerAvi_CPP* GetPlayerAvi() const;
};
