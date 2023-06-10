// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealFastNoise2 : ModuleRules
{
	public UnrealFastNoise2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.AddRange(
			new string[] {
			}
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Engine",
				"Projects",
				"FastNoise2"
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject"
			}
		);
	}
}
