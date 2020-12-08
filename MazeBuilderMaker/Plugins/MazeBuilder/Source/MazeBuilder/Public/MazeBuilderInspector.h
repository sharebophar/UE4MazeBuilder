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
	FMargin StandardPadding = FMargin(6.f, 3.f);
	FMargin StandardLeftPadding = FMargin(6.f, 3.f, 3.f, 3.f);
	FMargin StandardRightPadding = FMargin(3.f, 3.f, 6.f, 3.f);
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

	//FString style;
	FText GetCurrentStyle() const;
	void OnCurrentStyleChanged(const FText &StyleValue);

	void OnBrushPathChanged(const FText &brushPath);
public:
	MazeBuilderInspector();
	~MazeBuilderInspector();
	TSharedRef<SWidget> InitInspector();
	FReply OnInitMazeBuilderBtnClick();
	FReply OnSelectPathBtnClicked();
	TSharedRef<SWidget> CreatePaintTypeButton(EPaintType paintType);
	TSharedRef<SWidget> CreatePathSelectorUI(FString defaultPath);
	// Callback for determining whether a radio button is checked.
	ECheckBoxState PaintTypeIsChecked(EPaintType paintType) const;
	// Callback for checking a radio button.
	void OnPaintTypeChanged(ECheckBoxState NewRadioState, EPaintType paintType);
	FColor CheckColor = FColor::Yellow;
	FColor UnCheckColor = FColor::Cyan;
	//TSharedPtr<FMazeBuilderLogic> logic;
};
