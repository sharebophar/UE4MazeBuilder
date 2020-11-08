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
	//'A'Ϊ65��'a'Ϊ97��'0'Ϊ48
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
* ��ȡstrokeCode��ԭ����Ϊ strokeCode_pathCode_styleCode
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
* ��ȡpathCode��ԭ����Ϊ strokeCode_pathCode_styleCode
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
* ��ȡcsv�ļ���������
*/
bool FMazeBuilderUltility::LoadTextToArray(FString FileName, TArray<FString> &OutTextArray)
{
	if (!FFileHelper::LoadFileToStringArray(OutTextArray, *(FPaths::ProjectDir() + FileName)))//�ļ����
	{
		//UE_LOG(LogTemp, Warning, TEXT("�ļ�·������ȷ����ȡʧ��"));
		return false;
	}
	if (OutTextArray.Num() < 4)//�ļ����ȼ��
	{
		//UE_LOG(LogTemp, Warning, TEXT("�ļ����̣������ļ�"));
		return false;
	}
	return true;
}
