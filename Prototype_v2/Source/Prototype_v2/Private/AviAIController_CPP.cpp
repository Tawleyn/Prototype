// Fill out your copyright notice in the Description page of Project Settings.

#include "AviAIController_CPP.h"

void AAviAIController_CPP::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerAvatar = GetPlayerAvi();
	if (!PlayerAvatar)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerAvatar->GetName()));
	}
}

APlayerAvi_CPP* AAviAIController_CPP::GetControlledPlayerAvi() const
{

	return Cast<APlayerAvi_CPP>(GetPawn());
}

APlayerAvi_CPP* AAviAIController_CPP::GetPlayerAvi() const
{

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<APlayerAvi_CPP>(PlayerPawn);
}

// Called every frame
void AAviAIController_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerAvi())
	{
		// TODO Move toward the player

		// Aim toward player
		GetControlledPlayerAvi()->AimAt(GetPlayerAvi()->GetActorLocation());

		// Swing if in range and ready
	}
}

