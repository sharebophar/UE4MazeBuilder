// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogs/Dialogs.h"
#include "Editor.h"
#include "UObject/ConstructorHelpers.h"
#include "MazeBuilderUltility.h"
#include "MazeBuilderBrushTemplate.h"
#include "MazeBuilderStrokeInfo.h"
/**
 *
 */
class MAZEBUILDER_API FMazeBuilderLogic : public TSharedFromThis<FMazeBuilderLogic>
{
private:

public:
	FMazeBuilderLogic();
	//FMazeBuilderLogic();
	~FMazeBuilderLogic();
	void static InitMazeBuilder(int gridWidth,int gridLength,int gridSize,int cornerSize,int levelHeight,float style);
	void static DrawStroke(int gridWidth,int gridLength, int gridSize,float x, float y,float style);
	void static ReplaceStroke(int gridWidth,int gridLength,int gridSize,AMazeBuilderBrushTemplate* stroke,float style);
	static TArray<FIntVector> GetBasicBrush();
	static AMazeBuilderBrushTemplate* CreateStrokeByPattern(UWorld* world, FString pattern);
};
