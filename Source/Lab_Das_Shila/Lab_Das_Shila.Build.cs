// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Lab_Das_Shila : ModuleRules
{
	public Lab_Das_Shila(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
