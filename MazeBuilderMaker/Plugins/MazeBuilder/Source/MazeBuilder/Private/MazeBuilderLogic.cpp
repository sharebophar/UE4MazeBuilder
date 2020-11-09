#include "MazeBuilderLogic.h"

FMazeBuilderLogic::FMazeBuilderLogic()
{
	
}

/*
FMazeBuilderLogic::FMazeBuilderLogic()
{
}
*/

FMazeBuilderLogic::~FMazeBuilderLogic()
{
}

void FMazeBuilderLogic::InitMazeBuilder(int gridWidth, int gridLength, int gridSize, int cornerSize, int levelHeight, int style)
{
	UWorld* world = GEditor->GetEditorWorldContext().World();
	if (world)
	{
		// 使用基类获取到蓝图类的资源
		UClass* BlueprintVar = StaticLoadClass(AMazeBuilderBrushTemplate::StaticClass(), nullptr, TEXT("Blueprint'/Game/BrushTemplate/T0_0.T0_0_C'"));
		if (BlueprintVar != nullptr)
		{
			// 向场景中添加新生成的蓝图实例
			AMazeBuilderBrushTemplate* pMyActor = world->SpawnActor<AMazeBuilderBrushTemplate>(BlueprintVar);
			if (pMyActor)
			{
				// 这样，场景中就会动态生成一个蓝图类实例
				// 我们也会得到一个蓝图类基类的实例指针，并可以调用基类"AMyActor"中的函数
				FString HexStr = FMazeBuilderUltility::BinToHex("1110"); // 函数功能测试
				FString BinStr = FMazeBuilderUltility::HexToBin('A');
				UE_LOG(LogTemp, Log, TEXT("Spawn blueprint actor! %s,%s"),*HexStr,*BinStr);
			}
		}
	}
}