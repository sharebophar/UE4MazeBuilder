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
	/*
	FMazeBuilderLogic::gridWidth = 10;
	FMazeBuilderLogic::gridLength = 10;
	FMazeBuilderLogic::gridSize = 100;
	FMazeBuilderLogic::cornerSize = 50;
	FMazeBuilderLogic::levelHeight = 50;
	FMazeBuilderLogic::style = 0;
	*/
	//controlRemember = TSharedPtr<ToolkitControlRemember>(new ToolkitControlRemember());
	return  SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Center)
		.Padding(5)
		[
			CreatePathSelectorUI(FMazeBuilderLogic::BrushTemplatePath)
		]
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
					SNew(SEditableText)
					.Text(this, &MazeBuilderInspector::GetCurrentStyle)
					.OnTextChanged(this, &MazeBuilderInspector::OnCurrentStyleChanged)
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
					.Text(LOCTEXT("PaintStroke", "格子绘制: "))
				]
				+ SHorizontalBox::Slot()
				//.FillWidth(2.0f)
				.MaxWidth(40.f)
				.Padding(StandardRightPadding)
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				[
					CreatePaintTypeButton(EPaintType::PaintStroke)
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
			+SHorizontalBox::Slot()
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
					.Text(LOCTEXT("PaintPath", "路径绘制: "))
				]
				+ SHorizontalBox::Slot()
				//.FillWidth(2.0f)
				.MaxWidth(40.0f)
				.Padding(StandardRightPadding)
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Center)
				[
					CreatePaintTypeButton(EPaintType::PaintPath)
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
		/*
		if (logic == NULL)
		{
			logic = MakeShareable(new FMazeBuilderLogic());
		}
		*/
		//logic->InitMazeBuilder();
		FMazeBuilderLogic::InitMazeBuilder();
	}
	//world->PersistentLevel->SetWorldSettings();
	return FReply::Handled();
}

FReply MazeBuilderInspector::OnSelectPathBtnClicked()
{
	
	return FReply::Handled();
}

TSharedRef<SWidget> MazeBuilderInspector::CreatePaintTypeButton(EPaintType paintType)
{
	return SNew(SCheckBox)
		.Style(FCoreStyle::Get(), "RadioButton")
		.IsChecked(this, &MazeBuilderInspector::PaintTypeIsChecked, paintType)
		.OnCheckStateChanged(this, &MazeBuilderInspector::OnPaintTypeChanged, paintType);
}

TSharedRef<SWidget> MazeBuilderInspector::CreatePathSelectorUI(FString defaultPath)
{
	return 	SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.MaxWidth(800.f)
		.Padding(StandardLeftPadding)
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(SEditableTextBox)
			.Text(FText::FromString(defaultPath))
			.OnTextChanged(this,&MazeBuilderInspector::OnBrushPathChanged)
		]
		+ SHorizontalBox::Slot()
		//.FillWidth(2.0f)
		.MaxWidth(50.0f)
		.Padding(StandardRightPadding)
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.Text(LOCTEXT("SelectPath","..."))
			.OnClicked(this,&MazeBuilderInspector::OnSelectPathBtnClicked)
		];
		
}

// Callback for determining whether a radio button is checked.
ECheckBoxState MazeBuilderInspector::PaintTypeIsChecked(EPaintType paintType) const
{
	return (FMazeBuilderLogic::paintType == paintType)
		? ECheckBoxState::Checked
		: ECheckBoxState::Unchecked;
}
// Callback for checking a radio button.
void MazeBuilderInspector::OnPaintTypeChanged(ECheckBoxState NewRadioState, EPaintType paintType)
{
	if (NewRadioState == ECheckBoxState::Checked)
	{
		FMazeBuilderLogic::paintType = paintType;
	}
}

#undef LOCTEXT_NAMESPACE

TOptional<int32> MazeBuilderInspector::GetCurrentGridWidth() const
{
	return FMazeBuilderLogic::gridWidth;
}

void MazeBuilderInspector::OnCurrentGridWidthChanged(int32 GridWidthValue)
{
	FMazeBuilderLogic::gridWidth = GridWidthValue;
}

TOptional<int32> MazeBuilderInspector::GetCurrentGridLength() const
{
	return FMazeBuilderLogic::gridLength;
}

void MazeBuilderInspector::OnCurrentGridLengthChanged(int32 GridLengthValue)
{
	FMazeBuilderLogic::gridLength = GridLengthValue;
}

TOptional<float> MazeBuilderInspector::GetCurrentGridSize() const
{
	return FMazeBuilderLogic::gridSize;
}

void MazeBuilderInspector::OnCurrentGridSizeChanged(float GridSizeValue)
{
	FMazeBuilderLogic::gridSize = GridSizeValue;
}

TOptional<float> MazeBuilderInspector::GetCurrentCornerSize() const
{
	return FMazeBuilderLogic::cornerSize;
}

void MazeBuilderInspector::OnCurrentCornerSizeChanged(float CornerSizeValue)
{
	FMazeBuilderLogic::cornerSize = CornerSizeValue;
}

TOptional<float> MazeBuilderInspector::GetCurrentLevelHeight() const
{
	return FMazeBuilderLogic::levelHeight;
}

void MazeBuilderInspector::OnCurrentLevelHeightChanged(float LevelHeightValue)
{
	FMazeBuilderLogic::levelHeight = LevelHeightValue;
}

FText MazeBuilderInspector::GetCurrentStyle() const
{
	return FText::FromString(FMazeBuilderLogic::style);
}

void MazeBuilderInspector::OnCurrentStyleChanged(const FText & StyleValue)
{
	FMazeBuilderLogic::style = StyleValue.ToString();
}

void MazeBuilderInspector::OnBrushPathChanged(const FText &brushPath)
{
	FMazeBuilderLogic::BrushTemplatePath = brushPath.ToString();
}


