// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogs/Dialogs.h"
#include "Editor.h"
#include "Vector4.h"
#include "UObject/ConstructorHelpers.h"
#include "MazeBuilderUltility.h"
#include "MazeBuilderBrushTemplate.h"
#include "MazeBuilderMapData.h"
#include "MazeBuilderStrokeInfo.h"
#include "AssetRegistryModule.h"
#include "Kismet2/KismetEditorUtilities.h"
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
	FString static style;
	TSharedPtr<FMazeBuilderMapData> static mapData;
	FString static BrushTemplatePath;
	static UWorld* world;
	static TArray<FIntVector> GetBasicBrush();
	static TArray<FIntVector> BasicBrush;
	static TArray<Vector4> GetSrcTable();
	static TArray<Vector4> SrcTable;
	static bool startPaint;
	static int startLevel;
	static FVector curPoint;
public:
	void static InitMazeBuilder();
	static UClass* LoadBrushClass(FString pattern);
	//void static DrawStroke(float x, float y);
	static int GetLevelCode(FString code, int level);
	static FString DrawStroke(TArray<FIntVector> brushStyle, int r, int c, int drawLevel, bool isMulti);
	//void static ReplaceStroke(AMazeBuilderBrushTemplate* stroke);
	static FString GetStrokeByTransfer(FString name_str, int transfer);
	//获得当前层级相位码的变换,0为不变,1为旋转90度,2为旋转180度,3为旋转270度
	static FIntPoint GetStrokeTransfer(int level_code);
	//获得笔刷的原始模板和变换规则
	static TSharedPtr<FMazeBuilderStrokeInfo> GetSourceStroke(FString full_name);
	static TArray<FIntVector> GetOutCircleBrush(TArray<FIntVector> brushTable, int size);
	static AMazeBuilderBrushTemplate* CreateStrokeByPattern(FString pattern);
	static TArray<FAssetData> GetAllBrushBPData();
	static FIntPoint InitPaintLevel(FVector point);
	static void Paint(AMazeBuilderBrushTemplate* stroke);
	//
	static TArray<FVector> GetPathPointList(FVector thePoint);
	static float GetGizmoHeight(FVector thePoint);
	static void ReplacePathStroke(TSharedPtr<FMazeBuilderStrokeInfo> stroke_info);
	static FString GetSourcePath(TSharedPtr<FMazeBuilderStrokeInfo> stroke_info);
	static void DrawPath(FVector point);
};
