// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "MazeBuilderLogic.h"
//#include "ToolkitControlRemember.h"
//#include "GridDataRecorder.h"
#include "Dialogs/Dialogs.h"
#include "Editor.h"
/**
 * 
 */
class MAZEBUILDER_API MazeBuilderInspector : public TSharedFromThis<MazeBuilderInspector>
{
private:
	//int32 gridWidth;
	TOptional<int32> GetCurrentGridWidth() const;
	void OnCurrentGridWidthChanged(int32 GridWidthValue);

	//int32 gridLength;
	TOptional<int32> GetCurrentGridLength() const;
	void OnCurrentGridLengthChanged(int32 GridLengthValue);

	//float gridSize;
	TOptional<float> GetCurrentGridSize() const;
	void OnCurrentGridSizeChanged(float GridSizeValue);

	//float cornerSize;
	TOptional<float> GetCurrentCornerSize() const;
	void OnCurrentCornerSizeChanged(float CornerSizeValue);

	//float levelHeight;
	TOptional<float> GetCurrentLevelHeight() const;
	void OnCurrentLevelHeightChanged(float LevelHeightValue);

	//float style;
	TOptional<int> GetCurrentStyle() const;
	void OnCurrentStyleChanged(int StyleValue);
public:
	MazeBuilderInspector();
	~MazeBuilderInspector();
	TSharedRef<SWidget> InitInspector();
	FReply OnInitMazeBuilderBtnClick();
	//TSharedPtr<FMazeBuilderLogic> logic;
};
