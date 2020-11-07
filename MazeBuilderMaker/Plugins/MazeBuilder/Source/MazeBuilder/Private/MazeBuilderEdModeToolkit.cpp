// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MazeBuilderEdModeToolkit.h"
#include "MazeBuilderEdMode.h"
#include "Engine/Selection.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "FMazeBuilderEdModeToolkit"

FMazeBuilderEdModeToolkit::FMazeBuilderEdModeToolkit()
{
}

void FMazeBuilderEdModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost)
{
	inspector = MakeShareable(new MazeBuilderInspector()) ;
	SAssignNew(ToolkitWidget, SBorder)
		.HAlign(HAlign_Center)
		.Padding(25)
		//.IsEnabled_Static(&Locals::IsWidgetEnabled)
		.IsEnabled(true)
		[
			inspector->InitInspector()
		];
		
	FModeToolkit::Init(InitToolkitHost);
}

FName FMazeBuilderEdModeToolkit::GetToolkitFName() const
{
	return FName("MazeBuilderEdMode");
}

FText FMazeBuilderEdModeToolkit::GetBaseToolkitName() const
{
	return NSLOCTEXT("MazeBuilderEdModeToolkit", "DisplayName", "MazeBuilderEdMode Tool");
}

class FEdMode* FMazeBuilderEdModeToolkit::GetEditorMode() const
{
	return GLevelEditorModeTools().GetActiveMode(FMazeBuilderEdMode::EM_MazeBuilderEdModeId);
}

#undef LOCTEXT_NAMESPACE
