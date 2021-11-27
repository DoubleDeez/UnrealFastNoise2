// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class FastNoise2 : ModuleRules
{
	public FastNoise2(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));

		// Add the import library
		if (Target.Configuration == UnrealTargetConfiguration.Debug)
		{
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "Debug", "FastNoiseD.lib"));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("FastNoiseD.dll");

			// Ensure that the DLL is staged along with the executable
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/FastNoise2/Win64/FastNoiseD.dll");
		}
		else
		{
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "Release", "FastNoise.lib"));

			// Delay-load the DLL, so we can load it from the right place first
			PublicDelayLoadDLLs.Add("FastNoise.dll");

			// Ensure that the DLL is staged along with the executable
			RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/FastNoise2/Win64/FastNoise.dll");
		}
	}
}
