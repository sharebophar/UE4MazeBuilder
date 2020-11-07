// Fill out your copyright notice in the Description page of Project Settings.


#pragma once
#include "MazeBuilderInspector.h"
#include "MazeBuilderLogic.h"
//#include "CenterProcess.h"

MazeBuilderInspector::MazeBuilderInspector()
{
}

MazeBuilderInspector::~MazeBuilderInspector()
{
}

#define LOCTEXT_NAMESPACE "FMazeBuilderEdModeToolkit"
TSharedRef<SWidget> MazeBuilderInspector::InitInspector()
{
	gridWidth = 100;
	gridLength = 100;
	gridSize = 100;
	cornerSize = 50;
	levelHeight = 50;
	style = 0;
	FMargin StandardPadding(6.f, 3.f);
	FMargin StandardLeftPadding(6.f, 3.f, 3.f, 3.f);
	FMargin StandardRightPadding(3.f, 3.f, 6.f, 3.f);
	logic = MakeShareable(new FMazeBuilderLogic());
	//controlRemember = TSharedPtr<ToolkitControlRemember>(new ToolkitControlRemember());
	return  SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Center)
		.Padding(5)
		[
			SNew(SButton)
			.Text(LOCTEXT("InitWorldBtn", "初始化世界"))
			.ToolTipText(FText::FromString(L"根据参数初始化世界"))
			.OnClicked(this, &MazeBuilderInspector::OnInitMazeBuilderBtnClick)
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Top)
		.Padding(5, 0)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			//.FillWidth(3.0f)
			.MaxWidth(300.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				//.FillWidth(1.0f)
				.MaxWidth(100.f)
				.Padding(StandardLeftPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("GridWidth", "横向格数: "))
				]
				+SHorizontalBox::Slot()
				//.FillWidth(2.0f)
				.MaxWidth(200.f)
				.Padding(StandardRightPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(SNumericEntryBox<int32>)
					.AllowSpin(true)
					.MinValue(1)
					.MaxValue(99999)
					.MinSliderValue(1)
					.MaxSliderValue(99999)
					.Value(this, &MazeBuilderInspector::GetCurrentGridWidth)
					.OnValueChanged(this, &MazeBuilderInspector::OnCurrentGridWidthChanged)
					
				]
			]
			+ SHorizontalBox::Slot()
			//.FillWidth(3.0f)
			.MaxWidth(300.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				//.FillWidth(1.0f)
				.MaxWidth(100.f)
				.Padding(StandardLeftPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("GridLength", "纵向格数: "))
				]
				+ SHorizontalBox::Slot()
				//.FillWidth(2.0f)
				.MaxWidth(200.f)
				.Padding(StandardRightPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(SNumericEntryBox<int32>)
					.AllowSpin(true)
					.MinValue(1)
					.MaxValue(99999)
					.MinSliderValue(1)
					.MaxSliderValue(99999)
					.Value(this, &MazeBuilderInspector::GetCurrentGridLength)
					.OnValueChanged(this, &MazeBuilderInspector::OnCurrentGridLengthChanged)
				]
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Top)
		.Padding(5, 0)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.MaxWidth(300.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.MaxWidth(100.f)
				.Padding(StandardLeftPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("GridSize", "格子尺寸: "))
				]
				+SHorizontalBox::Slot()
				//.FillWidth(2.0f)
				.MaxWidth(200.f)
				.Padding(StandardRightPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(SNumericEntryBox<float>)
					.AllowSpin(true)
					.MinValue(1)
					.MaxValue(99999)
					.MinSliderValue(1)
					.MaxSliderValue(99999)
					.Value(this, &MazeBuilderInspector::GetCurrentGridSize)
					.OnValueChanged(this, &MazeBuilderInspector::OnCurrentGridSizeChanged)
					
				]
			]
			+ SHorizontalBox::Slot()
			.MaxWidth(300.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.MaxWidth(100.f)
				.Padding(StandardLeftPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("CornerSize", "边角尺寸: "))
				]
			+ SHorizontalBox::Slot()
				// .FillWidth(2.0f)
				.MaxWidth(200.f)
				.Padding(StandardRightPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(SNumericEntryBox<float>)
					.AllowSpin(true)
					.MinValue(1)
					.MaxValue(99999)
					.MinSliderValue(1)
					.MaxSliderValue(99999)
					.Value(this, &MazeBuilderInspector::GetCurrentCornerSize)
					.OnValueChanged(this, &MazeBuilderInspector::OnCurrentCornerSizeChanged)
				]
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Top)
		.Padding(5, 0)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.MaxWidth(300.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.MaxWidth(100.f)
				.Padding(StandardLeftPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("LevelHeight", "格子层高: "))
				]
				+ SHorizontalBox::Slot()
				//.FillWidth(2.0f)
				.MaxWidth(200.f)
				.Padding(StandardRightPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(SNumericEntryBox<float>)
					.AllowSpin(true)
					.MinValue(1)
					.MaxValue(99999)
					.MinSliderValue(1)
					.MaxSliderValue(99999)
					.Value(this, &MazeBuilderInspector::GetCurrentLevelHeight)
					.OnValueChanged(this, &MazeBuilderInspector::OnCurrentLevelHeightChanged)

				]
			]
			+ SHorizontalBox::Slot()
			.MaxWidth(300.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.MaxWidth(100.f)
				.Padding(StandardLeftPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Style", "格子风格: "))
				]
				+ SHorizontalBox::Slot()
				//.FillWidth(2.0f)
				.MaxWidth(200.f)
				.Padding(StandardRightPadding)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Center)
				[
					SNew(SNumericEntryBox<int>)
					.AllowSpin(true)
					.MinValue(1)
					.MaxValue(9)
					.MinSliderValue(1)
					.MaxSliderValue(9)
					.Value(this, &MazeBuilderInspector::GetCurrentStyle)
					.OnValueChanged(this, &MazeBuilderInspector::OnCurrentStyleChanged)
				]
			]
		];
}

FReply MazeBuilderInspector::OnInitMazeBuilderBtnClick()
{
	UWorld* world = GEditor->GetEditorWorldContext().World();
	TArray<ULevel *> levels = world->GetLevels();
	bool bHasInit = false;
	for (int i = 0; i < levels.Max(); i++)
	{
		if (levels[i]->GetName() == "MazeLevel")
		{
			bHasInit = true;
			break;
		}
	}
	if (bHasInit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Map has been initialized!"));
	}
	else
	{
		if (logic == NULL)
		{
			logic = MakeShareable(new FMazeBuilderLogic());
		}
		logic->InitMazeBuilder();
	}
	//world->PersistentLevel->SetWorldSettings();
	return FReply::Handled();
}
#undef LOCTEXT_NAMESPACE

TOptional<int32> MazeBuilderInspector::GetCurrentGridWidth() const
{
	return gridWidth;
}

void MazeBuilderInspector::OnCurrentGridWidthChanged(int32 GridWidthValue)
{
	gridWidth = GridWidthValue;
}

TOptional<int32> MazeBuilderInspector::GetCurrentGridLength() const
{
	return gridLength;
}

void MazeBuilderInspector::OnCurrentGridLengthChanged(int32 GridLengthValue)
{
	gridLength = GridLengthValue;
}

TOptional<float> MazeBuilderInspector::GetCurrentGridSize() const
{
	return gridSize;
}

void MazeBuilderInspector::OnCurrentGridSizeChanged(float GridSizeValue)
{
	gridSize = GridSizeValue;
}

TOptional<float> MazeBuilderInspector::GetCurrentCornerSize() const
{
	return cornerSize;
}

void MazeBuilderInspector::OnCurrentCornerSizeChanged(float CornerSizeValue)
{
	cornerSize = CornerSizeValue;
}

TOptional<float> MazeBuilderInspector::GetCurrentLevelHeight() const
{
	return levelHeight;
}

void MazeBuilderInspector::OnCurrentLevelHeightChanged(float LevelHeightValue)
{
	levelHeight = LevelHeightValue;
}

TOptional<int> MazeBuilderInspector::GetCurrentStyle() const
{
	return style;
}

void MazeBuilderInspector::OnCurrentStyleChanged(int StyleValue)
{
	style = StyleValue;
}
