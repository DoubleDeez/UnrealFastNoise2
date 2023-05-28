// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class FastNoise2 : ModuleRules
{
	public FastNoise2(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));

		string libName = Target.Configuration == UnrealTargetConfiguration.Debug ? "FastNoiseD" : "FastNoise";
		string configName = Target.Configuration == UnrealTargetConfiguration.Debug ? "Debug" : "Release";
		string platformString = Target.Platform.ToString();

		PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, platformString, configName, libName + StaticLibExtension));

		// Delay-load the DLL, so we can load it from the right place first
		// TODO - Is this needed for non-dll platforms?
		PublicDelayLoadDLLs.Add(libName + DynamicLibExtension);

		// Ensure that the DLL is staged along with the executable
		RuntimeDependencies.Add(Path.Combine("$(PluginDir)", "Binaries", "ThirdParty", "FastNoise2", platformString, libName + DynamicLibExtension));
	}

	private string StaticLibExtension
	{
		get
		{
			if (Target.Platform == UnrealTargetPlatform.Mac ||
			    Target.Platform == UnrealTargetPlatform.IOS ||
			    Target.Platform == UnrealTargetPlatform.Android ||
			    Target.Platform == UnrealTargetPlatform.Linux ||
			    Target.Platform == UnrealTargetPlatform.LinuxArm64)
			{
				return ".a";
			}
			else if (Target.Platform.IsInGroup(UnrealPlatformGroup.Microsoft))
			{
				return ".lib";
			}

			throw new BuildException("Unsupported platform");
		}
	}

	private string DynamicLibExtension
	{
		get
		{
			if (Target.Platform == UnrealTargetPlatform.Mac)
			{
				return ".dylib";
			}
			else if (Target.Platform == UnrealTargetPlatform.IOS)
			{
				return ".framework";
			}
			else if (Target.Platform == UnrealTargetPlatform.Android ||
			         Target.Platform == UnrealTargetPlatform.Linux ||
			         Target.Platform == UnrealTargetPlatform.LinuxArm64)
			{
				return ".so";
			}
			else if (Target.Platform.IsInGroup(UnrealPlatformGroup.Microsoft))
			{
				return ".dll";
			}

			throw new BuildException("Unsupported platform");
		}
	}
}
