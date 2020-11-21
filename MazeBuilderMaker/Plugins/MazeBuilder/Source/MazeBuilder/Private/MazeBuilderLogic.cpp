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

void FMazeBuilderLogic::DrawStroke(float x,float y)
{
	FMazeBuilderUltility::FormatPos(FVector(x, y, 0), gridSize);
}

void FMazeBuilderLogic::ReplaceStroke(AMazeBuilderBrushTemplate* stroke)
{
	UE_LOG(LogTemp, Log, TEXT("Target stroke is: %s"), *(stroke->GetName()));
}

TArray<FIntVector> FMazeBuilderLogic::GetBasicBrush()
{
	TArray<FIntVector> basicBrush;
	basicBrush.Add(FIntVector(1, -1, 0x8)); basicBrush.Add(FIntVector(0, -1, 0xC)); basicBrush.Add(FIntVector(-1, -1, 0x4));
	basicBrush.Add(FIntVector(1, -1, 0x9)); basicBrush.Add(FIntVector(0, -1, 0xF)); basicBrush.Add(FIntVector(-1, -1, 0x6));
	basicBrush.Add(FIntVector(1, -1, 0x1)); basicBrush.Add(FIntVector(0, -1, 0x3)); basicBrush.Add(FIntVector(-1, -1, 0x2));
	//确定绘制笔刷组,列偏移，行偏移，基础模型码
	return basicBrush;
}

AMazeBuilderBrushTemplate* FMazeBuilderLogic::CreateStrokeByPattern(UWorld *world,FString pattern)
{
	//Blueprint'/Game/BrushTemplate/T_0.T_0'
	FString BrushTemplatePath = "/Game/BrushTemplate/";
	UClass * BlueprintVar = StaticLoadClass(AMazeBuilderBrushTemplate::StaticClass(), nullptr, *("Blueprint\'"+ BrushTemplatePath + pattern + "." + pattern + "_C\'"));
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

int FMazeBuilderLogic::gridWidth = 10;
int FMazeBuilderLogic::gridLength = 10;
float FMazeBuilderLogic::gridSize = 100;
float FMazeBuilderLogic::cornerSize = 50;
float FMazeBuilderLogic::levelHeight = 50;
float FMazeBuilderLogic::style = 0;