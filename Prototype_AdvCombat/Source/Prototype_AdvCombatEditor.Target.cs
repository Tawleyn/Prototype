// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Prototype_AdvCombatEditorTarget : TargetRules
{
	public Prototype_AdvCombatEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("Prototype_AdvCombat");
	}
}
