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

void FMazeBuilderLogic::InitMazeBuilder(int gridWidth, int gridLength, int gridSize, int cornerSize, int levelHeight, float style)
{
	UWorld* world = GEditor->GetEditorWorldContext().World();
	if (world)
	{
		for (int i = 0; i < gridLength; i++)
		{
			for (int j = 0; j < gridWidth; j++)
			{
				FVector strokePos = FVector((i + 0.5) * gridSize, (j + 0.5) * gridSize, 0.0f);
				AMazeBuilderBrushTemplate* obj = FMazeBuilderLogic::CreateStrokeByPattern(world, "T_0");
				obj->SetActorLocation(strokePos);
				//obj->Rename(TEXT("0"));
				FString parentName = obj->GetClass()->GetSuperClass()->GetName();
				if (parentName == "AMazeBuilderBrushTemplate")
				{
					obj->gridSize = gridSize;
					obj->cornerSize = cornerSize;
					obj->levelHeight = levelHeight;
				}

				TSharedPtr<FMazeBuilderStrokeInfo> MBSI = MakeShareable(new FMazeBuilderStrokeInfo("0",i,j));
				MBSI->obj = obj;
			}
		}
		//FMazeBuilderLogic::CreateStrokeByPattern(world, "T_a");
	}
}

void FMazeBuilderLogic::DrawStroke(int gridWidth, int gridLength, int gridSize,float x,float y,float style)
{
	FMazeBuilderUltility::FormatPos(FVector(x, y, 0), gridSize);
}

void FMazeBuilderLogic::ReplaceStroke(int gridWidth, int gridLength, int gridSize, AMazeBuilderBrushTemplate* stroke, float style)
{

}

AMazeBuilderBrushTemplate* FMazeBuilderLogic::CreateStrokeByPattern(UWorld *world,FString pattern)
{
	//Blueprint'/Game/BrushTemplate/T_0.T_0'
	FString BrushTemplatePath = "/Game/BrushTemplate/";
	UClass * BlueprintVar = StaticLoadClass(AMazeBuilderBrushTemplate::StaticClass(), nullptr, *("Blueprint\'"+ BrushTemplatePath + pattern + "." + pattern + "_C\'"));
	//UClass * BlueprintVar2 = StaticLoadClass(AMazeBuilderBrushTemplate::StaticClass(), nullptr, *FString("Blueprint\'/Game/BrushTemplate/T_aa.T_aa_C\'"));
	//UClass * BlueprintVar3 = StaticLoadClass(AMazeBuilderBrushTemplate::StaticClass(), nullptr, TEXT("Blueprint'/Game/BrushTemplate/T_aaa.T_aaa_C'"));
	if (BlueprintVar != nullptr)
	{
		// 向场景中添加新生成的蓝图实例
		AMazeBuilderBrushTemplate* MBT = world->SpawnActor<AMazeBuilderBrushTemplate>(BlueprintVar);
		if (MBT)
		{
			// 这样，场景中就会动态生成一个蓝图类实例
			// 测试代码
			// 我们也会得到一个蓝图类基类的实例指针，并可以调用基类"AMyActor"中的函数
			FString HexStr = FMazeBuilderUltility::BinToHex("1110"); // 函数功能测试
			FString BinStr = FMazeBuilderUltility::HexToBin('A');
			UE_LOG(LogTemp, Log, TEXT("Spawn blueprint actor! %s,%s"), *HexStr, *BinStr);
			//MBT->SetActorLocation(FVector(100, 100, 0));
		}
		return MBT;
	}
	return NULL;
}
