// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogs/Dialogs.h"
#include "Editor.h"
#include "UObject/ConstructorHelpers.h"
#include "MazeBuilderPathInfo.h"
#include "MazeBuilderBrushTemplate.h"

/**
 *
 */
class MAZEBUILDER_API FMazeBuilderStrokeInfo : public TSharedFromThis<FMazeBuilderStrokeInfo>
{
private:
	//FString p = "0";
	//int i = 0;
	//int l = 0;
public:
	~FMazeBuilderStrokeInfo();
	FMazeBuilderStrokeInfo(FString p, int i, int l);
	//原生模板名称
	FString name;
	int trans_type;
	int level;
	int row;
	int col;
	AMazeBuilderBrushTemplate* obj;
	TSharedPtr<FMazeBuilderPathInfo> path;
	FString ToString();
};
