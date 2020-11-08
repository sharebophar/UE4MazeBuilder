#include "MazeBuilderUltility.h"

FMazeBuilderUltility::FMazeBuilderUltility()
{
}

FMazeBuilderUltility::~FMazeBuilderUltility()
{
}

FString FMazeBuilderUltility::IntToBin(int n)
{
	int m = n;
	FString result;
	while (m > 0)
	{
		int modVar = m % 2;
		m = m / 2;
		result += FString::FromInt(modVar);
	}
	result = result.Reverse();
	return result;
}

FString FMazeBuilderUltility::IntToHex(int n)
{
	int m = n;
	FString result;
	while (m > 0)
	{
		int modVar = m % 16;
		m = m / 16;
		TCHAR modChar = '0';
		if (modVar >= 0 && modVar <= 9)
			result.AppendInt(modVar);
		else
			result.AppendChar(static_cast<TCHAR>(modVar - 10 + 'A'));
	}
	result = result.Reverse();
	return result;
}

int FMazeBuilderUltility::HexToInt(TCHAR hexChar)
{
	//'A'为65，'a'为97，'0'为48
	if (hexChar >= 'A' && hexChar <= 'F')
	{
		int a = static_cast<int>(hexChar - 'A' + 10);
		return a;
	}
	else if (hexChar >= '0' && hexChar <= 9)
	{
		int a = static_cast<int>(hexChar - '0');
		return a;
	}
	else if (hexChar >= 'a' && hexChar <= 'f')
	{
		int a = static_cast<int>(hexChar - 'a' + 10);
		return a;
	}
	return 0;
}

int FMazeBuilderUltility::BinToInt(FString binStr)
{
	int result = 0;
	int len = binStr.Len();
	for (int i = 0; i < len; i++)
	{
		result += static_cast<int>(binStr[i] - '0')*FMath::Pow(2,(len-i-1));
	}
	return result;
}

FString FMazeBuilderUltility::HexToBin(TCHAR hexChar)
{
	int a = HexToInt(hexChar);
	return IntToBin(a);
}

FString FMazeBuilderUltility::BinToHex(FString binStr)
{
	int a = BinToInt(binStr);
	return IntToHex(a);
}

/*
* 获取strokeCode，原名字为 strokeCode_pathCode_styleCode
*/
FString FMazeBuilderUltility::GetStrokeCode(FString name)
{
	TArray<FString> *infoArr = new TArray<FString>();
	FString strokeCode = "0";
	name.ParseIntoArray(*infoArr, TEXT("_"), false);
	if (infoArr->Num() > 0)
	{
		strokeCode = (*infoArr)[0];
	}
	return strokeCode;
}

/*
* 获取pathCode，原名字为 strokeCode_pathCode_styleCode
*/
FString FMazeBuilderUltility::GetPathCode(FString name)
{
	TArray<FString> *infoArr = new TArray<FString>();
	name.ParseIntoArray(*infoArr, TEXT("_"), false);
	FString pathCode = "0";
	if (infoArr->Num() > 1)
	{
		pathCode = (*infoArr)[1];
	}
	return pathCode;
}

/**
* 读取csv文件到数组中
*/
bool FMazeBuilderUltility::LoadTextToArray(FString FileName, TArray<FString> &OutTextArray)
{
	if (!FFileHelper::LoadFileToStringArray(OutTextArray, *(FPaths::ProjectDir() + FileName)))//文件检查
	{
		//UE_LOG(LogTemp, Warning, TEXT("文件路径不正确，读取失败"));
		return false;
	}
	if (OutTextArray.Num() < 4)//文件长度检查
	{
		//UE_LOG(LogTemp, Warning, TEXT("文件过短，请检查文件"));
		return false;
	}
	return true;
}
