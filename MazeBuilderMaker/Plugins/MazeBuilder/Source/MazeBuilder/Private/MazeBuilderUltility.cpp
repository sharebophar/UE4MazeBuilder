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
			result.AppendChar(static_cast<TCHAR>(modVar - 10 + 'a')); // 16����һ����Сд��ĸ
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
* ��ȡstrokeCode��ԭ����Ϊ strokeCode_pathCode_styleCode
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
* ��ȡpathCode��ԭ����Ϊ strokeCode_pathCode_styleCode
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

//BrushTemplate�ڲ�����
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

/**��õ�ǰ������ĵؿ����ĵ�����*/
FIntPoint FMazeBuilderUltility::FormatPos(FVector pos, float val)
{
	float x = pos.X;
	float y = pos.Y;
	// format "obj pre Pos %\n" obj.pos
	if (x > 0)
	{ //x��������
		x = (int)(x / val); //���xֵ���ң�������
	}
	else
	{ //x�Ḻ����
		x = (int)(x / val) - 1; //��������
	}

	if (y > 0)
	{ //z��������
		y = (int)(y / val);
	}
	else
	{ //y�Ḻ����
		y = (int)(y / val) - 1;
	}
	return FIntPoint(x, y);
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

