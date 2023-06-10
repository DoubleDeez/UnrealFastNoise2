// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealFastNoise2.h"
#include "HAL/PlatformProcess.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"

void FUnrealFastNoise2Module::StartupModule()
{
	const FString BaseDir = IPluginManager::Get().FindPlugin("UnrealFastNoise2")->GetBaseDir();
	const FString LibraryPath = FPaths::Combine(*BaseDir, TEXT(FASTNOISE_LIBRARY_PATH));

	FastNoiseHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (FastNoiseHandle == nullptr)
	{
		const FText ErrorFormat = NSLOCTEXT("UnrealFastNoise2Module", "ThirdPartyLibraryError", "Failed to load FastNoise library at path [{0}]");
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(ErrorFormat, FText::FromString(LibraryPath)));
	}
}

void FUnrealFastNoise2Module::ShutdownModule()
{
	FPlatformProcess::FreeDllHandle(FastNoiseHandle);
	FastNoiseHandle = nullptr;
}

IMPLEMENT_MODULE(FUnrealFastNoise2Module, UnrealFastNoise2)
