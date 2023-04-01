// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealFastNoise2.h"
#include "HAL/PlatformProcess.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"

void FUnrealFastNoise2Module::StartupModule()
{
	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("UnrealFastNoise2")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
#if UE_BUILD_DEBUG
	FString LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/FastNoise2/Win64/FastNoiseD.dll"));
#else
	FString LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/FastNoise2/Win64/FastNoise.dll"));
#endif

	FastNoiseHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (FastNoiseHandle == nullptr)
	{
		FMessageDialog::Open(EAppMsgType::Ok, NSLOCTEXT("UnrealFastNoise2Module", "ThirdPartyLibraryError", "Failed to load FastNoise library"));
	}
}

void FUnrealFastNoise2Module::ShutdownModule()
{
	FPlatformProcess::FreeDllHandle(FastNoiseHandle);
	FastNoiseHandle = nullptr;
}
	
IMPLEMENT_MODULE(FUnrealFastNoise2Module, UnrealFastNoise2)
