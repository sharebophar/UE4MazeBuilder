#include "MazeBuilderPathInfo.h"

FMazeBuilderPathInfo::FMazeBuilderPathInfo(bool top = false, bool right = false, bool bottom = false, bool left = false)
{
	this->bottom = bottom;
	this->right = right;
	this->top = top;
	this->left = left;
}

FMazeBuilderPathInfo::~FMazeBuilderPathInfo()
{
}

// -y,x,y,-x
FString FMazeBuilderPathInfo::ToString()
{
	FString binCode = FString(top ? "1" : "0") + FString(right ? "1" : "0")+ FString(bottom ? "1" : "0")+ FString(left ? "1" : "0");
	FString pathCode = FMazeBuilderUltility::BinToHex(binCode);
	//pathCode = FString("0"); // ≤‚ ‘¥˙¬Î
	return pathCode;
}

FMazeBuilderPathInfo::FMazeBuilderPathInfo(FString name)
{
	TArray<FString> *infoArr = new TArray<FString>();
	name.ParseIntoArray(*infoArr, TEXT("_"), false);
	if (infoArr->Num() > 1)
	{
		FString pathStr = (*infoArr)[1];
		pathStr = FMazeBuilderUltility::HexToBin(pathStr[0]);
		this->top = pathStr[0] == '1' ? true : false;
		this->right = pathStr[1] == '1' ? true : false;
		this->bottom = pathStr[2] == '1' ? true : false;
		this->left = pathStr[3] == '1' ? true : false;
	}
	else
	{
		this->bottom = false;
		this->right = false;
		this->top = false;
		this->left = false;
	}
}