// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogs/Dialogs.h"
#include "Editor.h"
#include "UObject/ConstructorHelpers.h"
#include "MazeBuilderUltility.h"
#include "MazeBuilderBrushTemplate.h"
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
	static void InitMazeBuilder(int gridWidth,int gridLength,int gridSize,int cornerSize,int levelHeight,int style);
};
