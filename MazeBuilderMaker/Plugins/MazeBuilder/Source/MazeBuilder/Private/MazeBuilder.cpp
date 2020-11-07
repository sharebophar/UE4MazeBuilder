// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MazeBuilder.h"
#include "MazeBuilderEdMode.h"

#define LOCTEXT_NAMESPACE "FMazeBuilderModule"

void FMazeBuilderModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FMazeBuilderEdMode>(FMazeBuilderEdMode::EM_MazeBuilderEdModeId, LOCTEXT("MazeBuilderEdModeName", "Maze Builder"), FSlateIcon(), true);
}

void FMazeBuilderModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FMazeBuilderEdMode::EM_MazeBuilderEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMazeBuilderModule, MazeBuilder)