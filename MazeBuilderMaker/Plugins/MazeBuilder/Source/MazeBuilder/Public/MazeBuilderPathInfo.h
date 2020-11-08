// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogs/Dialogs.h"
#include "Editor.h"
#include "UObject/ConstructorHelpers.h"
#include "MazeBuilderUltility.h"
/**
 *
 */
class MAZEBUILDER_API FMazeBuilderPathInfo : public TSharedFromThis<FMazeBuilderPathInfo>
{
private:

public:
	FMazeBuilderPathInfo(bool top, bool right, bool bottom, bool left);
	FMazeBuilderPathInfo(FString name);
	~FMazeBuilderPathInfo();
	bool bottom = false;
	bool right = false;
	bool left = false;
	bool top = false;
	FString ToString();
};
