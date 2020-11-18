// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogs/Dialogs.h"
#include "Editor.h"
#include "UObject/ConstructorHelpers.h"
#include "MazeBuilderStrokeInfo.h"
#include "MazeBuilderBrushTemplate.h"
#include "MazeBuilderUltility.h"

/**
 *
 */
class MAZEBUILDER_API FMazeBuilderMapData : public TSharedFromThis<FMazeBuilderMapData>
{
private:

public:
	FMazeBuilderMapData();
	~FMazeBuilderMapData();
	FString ToString();
	void Clear();
	FString GetOldStrokeName(int r, int c);
	void ReadMapData(AActor mapRoot);
	void SaveMapData();
	TSharedPtr<FMazeBuilderStrokeInfo> GetStrokeInfoAt(int row, int col);
	AMazeBuilderBrushTemplate* GetStrokeAt(int row, int col);
	TSharedPtr<TArray<TSharedPtr<FMazeBuilderStrokeInfo>>> strokeTable = MakeShareable(new TArray<TSharedPtr<FMazeBuilderStrokeInfo>>());
	int max_row = 0;
	int max_col = 0;
	int min_row = 0;
	int min_col = 0;
	int MAX_LEVEL = 1;
	//Bounds bounds = new Bounds();
};
