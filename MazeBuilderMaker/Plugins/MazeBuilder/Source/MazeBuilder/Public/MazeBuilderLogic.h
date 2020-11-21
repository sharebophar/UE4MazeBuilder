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
	int static gridWidth;
	int static gridLength;
	float static gridSize;
	float static cornerSize;
	float static levelHeight;
	float static style;
	void static InitMazeBuilder();
	void static DrawStroke(float x, float y);
	void static ReplaceStroke(AMazeBuilderBrushTemplate* stroke);
	static TArray<FIntVector> GetBasicBrush();
	static AMazeBuilderBrushTemplate* CreateStrokeByPattern(UWorld* world, FString pattern);
};
