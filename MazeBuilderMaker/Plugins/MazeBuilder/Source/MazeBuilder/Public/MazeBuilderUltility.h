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
	static FString IntToBin(int n);
	static FString IntToHex(int n);
	static int HexToInt(TCHAR hexChar);
	static int BinToInt(FString binStr);
	static FString HexToBin(TCHAR hexChar);
	static FString BinToHex(FString binStr);
	static FString GetStrokeCode(FString name);
	static FString GetPathCode(FString name);
	static FString FormatPattern(FString name);
	static bool LoadTextToArray(FString FileName, TArray<FString> &OutTextArray);
};
