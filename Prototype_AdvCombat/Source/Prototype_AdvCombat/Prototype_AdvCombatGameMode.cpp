// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Prototype_AdvCombatGameMode.h"
#include "Prototype_AdvCombatCharacter.h"
#include "UObject/ConstructorHelpers.h"

APrototype_AdvCombatGameMode::APrototype_AdvCombatGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
