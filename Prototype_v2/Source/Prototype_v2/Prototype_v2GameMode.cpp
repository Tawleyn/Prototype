// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Prototype_v2GameMode.h"
#include "Prototype_v2Character.h"
#include "UObject/ConstructorHelpers.h"

APrototype_v2GameMode::APrototype_v2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
