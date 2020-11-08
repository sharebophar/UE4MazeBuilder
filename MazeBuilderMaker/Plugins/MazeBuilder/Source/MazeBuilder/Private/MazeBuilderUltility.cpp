#include "MazeBuilderUltility.h"

FMazeBuilderUltility::FMazeBuilderUltility()
{
}

FMazeBuilderUltility::~FMazeBuilderUltility()
{
}

FString FMazeBuilderUltility::HexToBin(FString hexStr)
{
	FString Bits;
	int32 pathInt = FCString::Atoi(*hexStr);
	return Bits;
	/*
	if (e >= 'A'&&e <= 'F')
	{
		int a = static_cast<int>(e - 'A' + 10);
		*/
}

FString FMazeBuilderUltility::BinToHex(FString binStr,bool bIsUpper)
{
	FString strHex;
	//strHex.resize(binStr.size() * 2);
	for (size_t i = 0; i < binStr.Len(); i++)
	{
		uint8_t cTemp = binStr[i];
		for (size_t j = 0; j < 2; j++)
		{
			uint8_t cCur = (cTemp & 0x0f);
			if (cCur < 10)
			{
				cCur += '0';
			}
			else
			{
				cCur += ((bIsUpper ? 'A' : 'a') - 10);
			}
			strHex[2 * i + 1 - j] = cCur;
			cTemp >>= 4;
		}
	}

	return strHex;
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
