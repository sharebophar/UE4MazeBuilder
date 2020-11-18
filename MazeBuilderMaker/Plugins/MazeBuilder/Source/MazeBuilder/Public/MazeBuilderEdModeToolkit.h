// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/BaseToolkit.h"
#include "MazeBuilderInspector.h"
#include "MazeBuilderBrushTemplate.h"

class FMazeBuilderEdModeToolkit : public FModeToolkit
{
public:

	FMazeBuilderEdModeToolkit();
	
	/** FModeToolkit interface */
	virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual class FEdMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override { return ToolkitWidget; }

	void DrawStroke(float x, float y);
	void ReplaceStroke(AMazeBuilderBrushTemplate stroke);
private:

	TSharedPtr<SWidget> ToolkitWidget;
	TSharedPtr<MazeBuilderInspector> inspector;
};
