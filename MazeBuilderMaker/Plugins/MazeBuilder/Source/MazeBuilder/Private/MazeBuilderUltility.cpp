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
	if (m == 0) return "0";
	FString result="";
	while (m > 0)
	{
		int modVar = m % 16;
		m = m / 16;
		TCHAR modChar = '0';
		if (modVar >= 0 && modVar <= 9)
			result.AppendInt(modVar);
		else
			result.AppendChar(static_cast<TCHAR>(modVar - 10 + 'a')); // 16进制一律用小写字母
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
	else if (hexChar >= '0' && hexChar <= '9')
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
	FString strokeCode = name;
	name.ParseIntoArray(*infoArr, TEXT("_"), false);
	if (infoArr->Num() > 1)
	{
		strokeCode = (*infoArr)[1];
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
	if (infoArr->Num() > 2)
	{
		pathCode = (*infoArr)[2];
	}
	return pathCode;
}

//BrushTemplate内部调用
FString FMazeBuilderUltility::FormatPattern(FString name)
{
	TArray<FString>* infoArr = new TArray<FString>();
	name.ParseIntoArray(*infoArr, TEXT(" "), false);
	int arrLen = infoArr->Num();
	FString tempCode = arrLen > 0 ? (*infoArr)[0] : "T";
	FString strokeCode = arrLen > 1 ? (*infoArr)[1] : "0";
	FString pathCode = arrLen > 2 ? (*infoArr)[2] : "0";
	FString styleCode = arrLen > 3 ? (*infoArr)[3] : "0";
	return tempCode + " " + strokeCode + " " + pathCode + " " + styleCode;
}

/**获得当前点最近的地块中心点坐标*/
FIntPoint FMazeBuilderUltility::FormatPos(FVector pos, float val)
{
	float x = pos.X;
	float y = pos.Y;
	// format "obj pre Pos %\n" obj.pos
	if (x > 0)
	{ //x轴正半轴
		x = (int)(x / val); //如果x值靠右，则右移
	}
	else
	{ //x轴负半轴
		x = (int)(x / val) - 1; //否则左移
	}

	if (y > 0)
	{ //z轴正半轴
		y = (int)(y / val);
	}
	else
	{ //y轴负半轴
		y = (int)(y / val) - 1;
	}
	return FIntPoint(x, y);
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

int FMazeBuilderUltility::GetCharCount(FString str, char chr)
{
	int count = 0;
	for (int i = 0; i < str.Len(); i++)
	{
		if (str[i] == chr)
		{
			count = count + 1;
		}
	}
	return count;
}

