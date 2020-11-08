// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogs/Dialogs.h"
#include "Editor.h"
#include "UObject/ConstructorHelpers.h"
#include "Misc/FileHelper.h"
#include "Paths.h"
/**
 *
 */
class MAZEBUILDER_API FMazeBuilderUltility : public TSharedFromThis<FMazeBuilderUltility>
{
private:

public:
	FMazeBuilderUltility();
	~FMazeBuilderUltility();
	static FString HexToBin(FString hexStr);
	static FString BinToHex(FString binStr, bool bIsUpper);
	static FString GetStrokeCode(FString name);
	static FString GetPathCode(FString name);
	static bool LoadTextToArray(FString FileName, TArray<FString> &OutTextArray);
};
