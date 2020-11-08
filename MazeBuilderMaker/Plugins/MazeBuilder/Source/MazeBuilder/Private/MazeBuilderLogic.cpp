#include "MazeBuilderLogic.h"

FMazeBuilderLogic::FMazeBuilderLogic()
{
}

FMazeBuilderLogic::~FMazeBuilderLogic()
{
}

void FMazeBuilderLogic::InitMazeBuilder()
{
	UWorld* world = GEditor->GetEditorWorldContext().World();
	if (world)
	{
		// ʹ�û����ȡ����ͼ�����Դ
		UClass* BlueprintVar = StaticLoadClass(AActor::StaticClass(), nullptr, TEXT("Blueprint'/Game/BrushTemplate/T0_0.T0_0_C'"));
		if (BlueprintVar != nullptr)
		{
			// �򳡾�����������ɵ���ͼʵ��
			AActor* pMyActor = world->SpawnActor<AActor>(BlueprintVar);
			if (pMyActor)
			{
				// �����������оͻᶯ̬����һ����ͼ��ʵ��
				// ����Ҳ��õ�һ����ͼ������ʵ��ָ�룬�����Ե��û���"AMyActor"�еĺ���
				FString HexStr = FMazeBuilderUltility::BinToHex("1110"); // �������ܲ���
				FString BinStr = FMazeBuilderUltility::HexToBin('A');
				UE_LOG(LogTemp, Log, TEXT("Spawn blueprint actor! %s,%s"),*HexStr,*BinStr);
			}
		}
	}
}