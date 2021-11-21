#include "MazeBuilderLogic.h"

FMazeBuilderLogic::FMazeBuilderLogic()
{
	
}


FMazeBuilderLogic::~FMazeBuilderLogic()
{
}
PRAGMA_DISABLE_OPTIMIZATION
void FMazeBuilderLogic::InitMazeBuilder()
{
	world = GEditor->GetEditorWorldContext().World();
	if (world)
	{
		for (int i = 0; i < gridLength; i++)
		{
			for (int j = 0; j < gridWidth; j++)
			{
				FVector strokePos = FVector((i + 0.5) * gridSize, (j + 0.5) * gridSize, 0.0f);
				AMazeBuilderBrushTemplate* obj = CreateStrokeByPattern("0");
				obj->SetActorLocation(strokePos);
				//obj->Rename(TEXT("0"));
				FString parentName = obj->GetClass()->GetSuperClass()->GetName();
				if (parentName == "MazeBuilderBrushTemplate")
				{
					obj->gridSize = gridSize;
					obj->cornerSize = cornerSize;
					obj->levelHeight = levelHeight;
					obj->name = "0";
					obj->UpdateMesh();
				}

				TSharedPtr<FMazeBuilderStrokeInfo> stroke_info = MakeShareable(new FMazeBuilderStrokeInfo("0",0,0));
				stroke_info->row = i;
				stroke_info->col = j;
				stroke_info->obj = obj;

				//mapData->strokeTable->Insert(stroke_info,0);
				mapData->AddStrokeInfo(FIntPoint(i, j), stroke_info);
				//mapData->strokeTable->Add(stroke_info);
				//mapData->max_col = FMath::Max<int>(j, mapData->max_col);
				//mapData->max_row = FMath::Max<int>(i, mapData->max_row);
				//mapData->min_col = mapData->min_col == 0 ? j : FMath::Min<int>(mapData->min_col, j);
				//mapData->min_row = mapData->min_row == 0 ? i : FMath::Min<int>(mapData->min_row, i);
				//mapData->strokeTable->Add(stroke_info);
			}
		}
		//TArray<FAssetData> clses = FMazeBuilderLogic::GetAllBrushBPData();
	}
	mapData->max_row = gridLength;
	mapData->max_col = gridWidth;
}

//获得level层的码,就是返回倒数第level个码
int FMazeBuilderLogic::GetLevelCode(FString code, int level)
{
	int result = 0;
	//int lv = str.Length - level + 1;
	int lv = code.Len() - level - 1;
	if (lv >= 0)
	{
		result = FMazeBuilderUltility:: HexToInt((*code)[lv]);
	}
	return result;
}

FIntPoint FMazeBuilderLogic::InitPaintLevel(FVector point)
{
	FIntPoint pos = FMazeBuilderUltility::FormatPos(point, gridSize);
	// 初始化绘制层
	if (startPaint == false)
	{
		FString code = mapData->GetOldStrokeName(pos);
		startLevel = FMazeBuilderUltility::GetCharCount(code, 'f');
		// 匹配碰撞面的高度
		//FVector map_pos = mc.transform.position;
		//map_pos.y = startLevel * propLevelHeight.floatValue;
		//mc.transform.position = map_pos;

		if (startLevel >= mapData->MAX_LEVEL)
			mapData->MAX_LEVEL = startLevel + 1;
		UE_LOG(LogTemp, Warning, TEXT("start Level is:%d"), startLevel);
		//Utility.DebugText("init startLevel:" + startLevel);
		startPaint = true;
	}
	return pos;
}

//计算当前笔刷集的扩边笔刷集合，圆形点扩边方式
TArray<FIntVector> FMazeBuilderLogic::GetOutCircleBrush(TArray<FIntVector> brushTable, int size)
{
	if (size == 0)
	{
		return brushTable;
	}
	TArray<FIntVector> new_table;
	int cell_num = (int)FMath::Sqrt(brushTable.Num()*1.0);
	int new_num = cell_num / 2 + size;
	for (int i = -new_num; i <= new_num; i++)
	{
		for (int j = -new_num; j <= new_num; j++)
		{
			if (i == -new_num)
			{
				if (j == -new_num)
				{
					new_table.Add(FIntVector(i, j, 0x0));
				}
				else if (j == -new_num + 1)
				{
					new_table.Add(FIntVector(i, j, 0x8));
				}
				else if (j == new_num)
				{
					new_table.Add(FIntVector(i, j, 0x0));
				}
				else if (j == new_num - 1)
				{
					new_table.Add(FIntVector(i, j, 0x1));
				}
				else
				{
					new_table.Add(FIntVector(i, j, 0x9));
				}
			}
			else if (i == -new_num + 1)
			{
				if (j == -new_num)
				{
					new_table.Add(FIntVector(i, j, 0x8));
				}
				else if (j == -new_num + 1)
				{
					new_table.Add(FIntVector(i, j, 0xD));
				}
				else if (j == new_num)
				{
					new_table.Add(FIntVector(i, j, 0x1));
				}
				else if (j == new_num - 1)
				{
					new_table.Add(FIntVector(i, j, 0xB));
				}
				else
				{
					new_table.Add(FIntVector(i, j, 0xF));
				}
			}
			else if (i == new_num)
			{
				if (j == -new_num)
				{
					new_table.Add(FIntVector(i, j, 0x0));
				}
				else if (j == -new_num + 1)
				{
					new_table.Add(FIntVector(i, j, 0x4));
				}
				else if (j == new_num)
				{
					new_table.Add(FIntVector(i, j, 0x0));
				}
				else if (j == new_num - 1)
				{
					new_table.Add(FIntVector(i, j, 0x2));
				}
				else
				{
					new_table.Add(FIntVector(i, j, 0x6));
				}
			}
			else if (i == new_num - 1)
			{
				if (j == -new_num)
				{
					new_table.Add(FIntVector(i, j, 0x4));
				}
				else if (j == -new_num + 1)
				{
					new_table.Add(FIntVector(i, j, 0xE));
				}
				else if (j == new_num)
				{
					new_table.Add(FIntVector(i, j, 0x2));
				}
				else if (j == new_num - 1)
				{
					new_table.Add(FIntVector(i, j, 0x7));
				}
				else
				{
					new_table.Add(FIntVector(i, j, 0xF));
				}
			}
			else
			{
				if (j == -new_num)
				{
					new_table.Add(FIntVector(i, j, 0xC));
				}
				else if (j == new_num)
				{
					new_table.Add(FIntVector(i, j, 0x3));
				}
				else
				{
					new_table.Add(FIntVector(i, j, 0xF));
				}
			}
		}
	}
	return new_table;
}

void FMazeBuilderLogic::Paint(AMazeBuilderBrushTemplate* stroke)
{
	/*
	if (mc.brushTemplates == null) {
		Debug.LogError("brushTemplates is null!");
		return;
	}
	*/

	FVector point = stroke->GetActorLocation();

	FIntPoint pos = InitPaintLevel(point);
	int row = pos.X;
	int col = pos.Y;
	FString error_code = DrawStroke(BasicBrush, row, col, startLevel, false);
	//Utility.DebugText("最大高度：" + startLevel);
	int layer_count = (int)(error_code.Len() / 3);
	if (layer_count > 0)
	{
		for (int i = layer_count; i > 0; i--)
		{
			int lv = (layer_count - i) * 3 + 2;
			TArray<FIntVector> outline_brush = GetOutCircleBrush(BasicBrush, i);
			//Utility.DebugText("扩边数量为：" + i + "绘制高度为：" + lv);
			DrawStroke(outline_brush, row, col, lv, true);
		}
		DrawStroke(BasicBrush, row, col, startLevel, false);
	}
	//        Vector3[] outline_brush = GetOutCircleBrush(basicBrush, 0);
	//        DrawStroke(outline_brush, (int)(pos.x), (int)(pos.y), startLevel);
}

/** 按笔刷样式绘制地图块
* brushStyle 为笔刷样式，默认为basicBrush
* r 地图块行号
* c 地图块列号
* drawLevel 当前绘制层，由鼠标落点高度决定
* isMulti 是否叠层绘制，叠层绘制时不考虑更高层数的减层
*/
FString FMazeBuilderLogic::DrawStroke(TArray<FIntVector> brushStyle, int r, int c, int drawLevel, bool isMulti)
{
	//UE_LOG(LogTemp, Warning, TEXT("Begin to draw!r: %d and c:%d "), r, c);
	for (int i = 0; i < brushStyle.Num(); i++)
	{

		FIntVector brush = brushStyle[i];
		if (r > 0 && r < gridWidth && c>0 && c < gridLength)
		{

			int fix_code = brush[2]; //当前层级应该填充的值，后面的全部用0填充
			//local fix_code = brush[3] as Integer
			//UE_LOG(LogTemp, Warning, TEXT("row num: %d and col num:%d "), r + brush[0],c + brush[1]);
			 FString curr_code = mapData->GetOldStrokeName(FIntPoint(r + brush[0], c + brush[1]));
			 FString target_name = "";

			 //前面各层级的值都应该填充该层级的值，后面的层级消除当前层级的值
			 for (int level = 0; level < mapData->MAX_LEVEL; level++)
			 {
				 int curr_level_code = GetLevelCode(curr_code, level);
				 //UE_LOG(LogTemp, Warning, TEXT("old_stroke_name: %s ,curr_level_code:%d,fix_code:%d,level:%d,drawLevel:%d"), *curr_code,curr_level_code,fix_code,level,drawLevel);
				 if (level <= drawLevel)
				 {
					 curr_level_code = curr_level_code | fix_code;
					 if (curr_level_code > 15)
					 {
						 curr_level_code = 15;
					 }
				 }
				 else
				 {
					 if (!isMulti) curr_level_code = curr_level_code & (~fix_code);
				 }

				 if (curr_level_code != 0)
					 target_name = FMazeBuilderUltility::IntToHex(curr_level_code) + target_name;
				 if (target_name == "")
					 target_name = "0";
				 //Utility.DebugText("curr_level_code:" + curr_level_code + " target_name:" + target_name + " curr_code:" + curr_code + " fix_code:" + IntAsHex(fix_code) + " level:" + level + " drawLevel：" + drawLevel+ "\n");
			 }

			//提前获取当前格子的笔刷，当绘制时计算出来的新笔刷无法获得源笔刷时，将该格子笔刷的Path信息更新，方便查错
			 int row = r + brush[0];
			 int col = c + brush[1];
			 FIntPoint pos2d = FIntPoint(row, col);
			 AMazeBuilderBrushTemplate* old_obj = mapData->GetStrokeAt(pos2d);

			 //表现填充
			 TSharedPtr<FMazeBuilderStrokeInfo> stroke_info = GetSourceStroke(target_name);
			 if (stroke_info != nullptr)
			 {
				 //UE_LOG(LogTemp, Warning, TEXT("drawLevel:%d targetName:%s sourceStroke:%s transType:%d level%d"), drawLevel,*target_name,*(stroke_info->name),stroke_info->trans_type,stroke_info->level);
				 int change_type = stroke_info->trans_type; // 笔刷变换方式
				 // 左边是x的正半轴，下边是z的正半轴
				 float fix_x = (r + brush[0] + 0.5f)*gridSize;
				 float fix_y = (c + brush[1] + 0.5f)*gridSize;

				 FVector stroke_pos = FVector(fix_x, fix_y, stroke_info->level*levelHeight);// 注意通用单位到米的转换，max里1点通用单位对应0.254米
				// Utility.DebugText("stroke_pos:" + stroke_pos.ToString() + " row:" + brush[0] + " colum:" + brush[2] + " target_name:" + target_name + " fix_x:" + fix_x + "fix_z:" + fix_z + "\n");
				 AMazeBuilderBrushTemplate* stroke = CreateStrokeByPattern(stroke_info->name); // stroke_info中存储的是原生模板
				 if (stroke == nullptr) return "0";
				 //stroke->Tags[0] = FName(target_name);
				 stroke->name = target_name; // target_name为衍生模板
				 stroke->path = FMazeBuilderUltility::GetDebugPathInfo(target_name, true);
				 //stroke.transform.Rotate(Vector3.right, -90f);
				 //stroke.transform.Rotate(Vector3.up, change_type * 90f);
				 //obj->Rename(TEXT("0"));
				 FString parentName = stroke->GetClass()->GetSuperClass()->GetName();
				 if (parentName == "MazeBuilderBrushTemplate")
				 {
					 stroke->gridSize = gridSize;
					 stroke->cornerSize = cornerSize;
					 stroke->levelHeight = levelHeight;
					 stroke->UpdateMesh();
				 }
				 stroke->SetActorRotation(FQuat(FVector(0, 0, 1), change_type * PI / 2));
				 stroke->SetActorLocation(stroke_pos);
 ////////////////////////////////////////////////////////////
				 if (old_obj != nullptr)
				 {
					 //world->DestroyActor(old_obj);
					 //UE_LOG(LogTemp, Warning, TEXT("stroke %s should be remove!"), *(old_obj->GetName()));
					 world->EditorDestroyActor(old_obj,true);
				 }
				 stroke_info->row = row;
				 stroke_info->col = col;
				 stroke_info->obj = stroke;

				 mapData->AddStrokeInfo(pos2d,stroke_info);
				 //mapData->strokeTable->Add(stroke_info);
				 mapData->max_col = FMath::Max<int>(col, mapData->max_col);
				 mapData->max_row = FMath::Max<int>(row, mapData->max_row);
				 mapData->min_col = mapData->min_col == 0 ? col : FMath::Min<int>(mapData->min_col, col);
				 mapData->min_row = mapData->min_row == 0 ? row : FMath::Min<int>(mapData->min_row, row);
				 //stroke.transform.parent = mc.mapRoot.transform;
			 }
			 else
			 {
				 UE_LOG(LogTemp, Warning, TEXT("target name %s stroke cannot calculate the source stroke"), *target_name);
				 old_obj->path = FMazeBuilderUltility::GetDebugPathInfo(target_name, false);
				 return target_name;
			 }

			 //stroke.layer.name = "0"
		 }
	 }
	//Utility.DebugText("------------------");
	return "0";
	// 测试代码
	//format "%\t%\t%\n" (strokeTable[r-1][c-1].name) (strokeTable[r-1][c].name) (strokeTable[r-1][c+1].name)
	//format "%\t%\t%\n" (strokeTable[r][c-1].name)   (strokeTable[r][c].name)   (strokeTable[r][c+1].name)
	//format "%\t%\t%\n" (strokeTable[r+1][c-1].name) (strokeTable[r+1][c].name) (strokeTable[r+1][c+1].name)
	// 表现填充
}

TArray<FIntVector> FMazeBuilderLogic::GetBasicBrush()
{
	TArray<FIntVector> basicBrush;
	basicBrush.Add(FIntVector(-1, -1, 0x8)); basicBrush.Add(FIntVector(0, -1, 0xC)); basicBrush.Add(FIntVector(1, -1, 0x4));
	basicBrush.Add(FIntVector(-1,  0, 0x9)); basicBrush.Add(FIntVector(0,  0, 0xF)); basicBrush.Add(FIntVector(1,  0, 0x6));
	basicBrush.Add(FIntVector(-1,  1, 0x1)); basicBrush.Add(FIntVector(0,  1, 0x3)); basicBrush.Add(FIntVector(1,  1, 0x2));
	//确定绘制笔刷组,列偏移，行偏移，基础模型码
	return basicBrush;
}

// 获取原始笔刷和翻转后的笔刷
TArray<FCollectCode> FMazeBuilderLogic::GetSrcTable()
{
	TArray<FCollectCode> srcTable;
	srcTable.Add(FCollectCode(0x0, 0x0, 0x0, 0x0));
	srcTable.Add(FCollectCode(0x2, 0x4, 0x8, 0x1));
	srcTable.Add(FCollectCode(0x3, 0x6, 0xC, 0x9));
	srcTable.Add(FCollectCode(0x7, 0xE, 0xD, 0xB));
	srcTable.Add(FCollectCode(0x5, 0xA, 0x5, 0xA));
	srcTable.Add(FCollectCode(0xF, 0xF, 0xF, 0xF));
	return srcTable;
}

//通过变换获得新的相位码
FString FMazeBuilderLogic::GetStrokeByTransfer(FString name_str, int transfer)
{
	FString result="";
	for (int i = 0; i < name_str.Len(); i++)
	{
		int cur_code = FMazeBuilderUltility::HexToInt((*name_str)[i]);
		FIntPoint pos_code = GetStrokeTransfer(cur_code);
		int x = pos_code[0];
		int z = pos_code[1];
		int new_z = (z + transfer) % 4;
		//if(new_z == 0)
		//    new_z = 3;
		int new_code = SrcTable[x][new_z];
		result = result + FMazeBuilderUltility::IntToHex(new_code);
		//UE_LOG(LogTemp, Warning, TEXT("i:%d,cur_code:%d,new_code:%d,x,%d,z,%d,transer:%d,new_z:%d,result:%s"),i,cur_code,new_code,x,z,transfer,new_z,*result);
	}
	//UE_LOG(LogTemp, Warning, TEXT("%s transter to %s by %d"), *name_str, *result,transfer);
	return result;
}

//获得当前层级相位码的变换,0为不变,1为旋转90度,2为旋转180度,3为旋转270度
FIntPoint FMazeBuilderLogic::GetStrokeTransfer(int level_code)
{
	for (int i = 0; i < SrcTable.Num(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//UE_LOG(LogTemp, Warning, TEXT("SrcTable[%d][%d]=%d,level_code:%d"), i, j, SrcTable[i][j],level_code);
			if (SrcTable[i][j] == level_code)
			{
				return FIntPoint(i, j);
			}
		}
	}
	return FIntPoint(0,0);
}

//获得笔刷的原始模板和变换规则
TSharedPtr<FMazeBuilderStrokeInfo> FMazeBuilderLogic::GetSourceStroke(FString full_name)
{
	FString target_name = FMazeBuilderUltility::GetStrokeCode(full_name);
	//有几个f就有几层，层数高度决定了原始笔刷上移的高度
	int level = FMazeBuilderUltility::GetCharCount(target_name, 'f');
	FString fix_name = target_name;
	if (level > 0)
	{
		if (target_name.Len() > level)
			fix_name = fix_name.Mid(0, (target_name.Len() - level));
		else
			fix_name = "0";
	}
	//UE_LOG(LogTemp, Warning, TEXT("full name is:%s,level is:%d,the fix_name of %s is :%s"), *full_name,level, *target_name,*fix_name);
	TArray<FAssetData>  assetData = GetAllBrushBPData();
	for (int j = 0; j < 4; j++)
	{
		FString curr_name = GetStrokeByTransfer(fix_name, j);
		for (int index = 0; index < assetData.Num(); index++)
		{
			if ("T_" + curr_name == assetData[index].AssetName.ToString()) // 针对抬头T_要针对编辑器选笔刷目录时做相应逻辑
			{
				TSharedPtr<FMazeBuilderStrokeInfo> stroke_info = MakeShareable(new FMazeBuilderStrokeInfo(curr_name, j, level));
				return stroke_info; //原始模板，旋转次数，高度层数
			}
		}
	}
	return nullptr;
}

UClass* FMazeBuilderLogic::LoadBrushClass(FString pattern)
{
	FString szPattern = FMazeBuilderLogic::style + "_" + pattern;
	UClass * BlueprintVar = StaticLoadClass(AMazeBuilderBrushTemplate::StaticClass(), nullptr, *("Blueprint\'" + BrushTemplatePath + "/" + szPattern + "." + szPattern + "_C\'"));
	return BlueprintVar;
}

AMazeBuilderBrushTemplate* FMazeBuilderLogic::CreateStrokeByPattern(FString pattern)
{
	//Blueprint'/Game/BrushTemplate/T_0.T_0'
	UClass* BlueprintVar = LoadBrushClass(pattern);
	if (BlueprintVar != nullptr && world)
	{
		// 向场景中添加新生成的蓝图实例
		AMazeBuilderBrushTemplate* MBT = world->SpawnActor<AMazeBuilderBrushTemplate>(BlueprintVar);
		if (MBT)
		{
			// 这样，场景中就会动态生成一个蓝图类实例
			// 测试代码
			// 我们也会得到一个蓝图类基类的实例指针，并可以调用基类"AMyActor"中的函数
			FString BinToHexStr = FMazeBuilderUltility::BinToHex("1110"); // 函数功能测试
			FString HexToBinStr = FMazeBuilderUltility::HexToBin('A');
			FString IntToHexStr = FMazeBuilderUltility::IntToHex(0);
			FString IntToHexStr2 = FMazeBuilderUltility::IntToHex(15);
			//UE_LOG(LogTemp, Log, TEXT("BinToHexStr:%s,HexToBinStr:%s,IntToHexStr:%s,IntToHexStr2:%s"), *BinToHexStr, *HexToBinStr,*IntToHexStr,*IntToHexStr2);
			//MBT->SetActorLocation(FVector(100, 100, 0));
		}
		return MBT;
	}
	return NULL;
}

// 获取场景中的所有 AMazeBuilderBrushTemplate 的子蓝图类，但是无法获得编辑器中的蓝图类
TArray<FAssetData> FMazeBuilderLogic::GetAllBrushBPData()
{
	TArray<FAssetData> arrayAssetData;
	FAssetRegistryModule& assetRegistryModule = FModuleManager::GetModuleChecked<FAssetRegistryModule>("AssetRegistry");
	FARFilter filter;
	filter.PackagePaths.Add(*BrushTemplatePath);
	filter.ClassNames.Add(UBlueprint::StaticClass()->GetFName());
	//filter.bRecursivePaths = true;
	filter.bRecursiveClasses = true;
	assetRegistryModule.Get().GetAssets(filter, arrayAssetData);
	for (int index = 0; index < arrayAssetData.Num(); ++index)
	{
		//UE_LOG(LogTemp, Warning, TEXT("asset name is %s"), *arrayAssetData[index].AssetName.ToString());
	}
	return arrayAssetData;
}

/*
* 绘制路径
*/
void FMazeBuilderLogic::DrawPath(FVector point)
{
	// 根据当前点与下个点的坐标判定路径方位，并写入对应地块中，暂时显示Gizmo路径线条，之后再考虑使用地块表现
	FIntPoint grid_pos = InitPaintLevel(gridPoint);
	TSharedPtr<FMazeBuilderStrokeInfo>  grid_stroke_info = mapData->GetStrokeInfoAt(grid_pos);

	if (grid_stroke_info == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("grid stroke is null"));
		return;
	}

	FIntPoint next_pos = InitPaintLevel(nextPoint);
	TSharedPtr<FMazeBuilderStrokeInfo> next_stroke_info = mapData->GetStrokeInfoAt(next_pos);

	if (next_stroke_info == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("next stroke is null"));
		return;
	}

	if (nextPoint.X < gridPoint.X)
	{
		grid_stroke_info->path->left = true;
		next_stroke_info->path->right = true;
	}
	else if (nextPoint.X > gridPoint.X)
	{
		grid_stroke_info->path->right = true;
		next_stroke_info->path->left = true;
	}

	if (nextPoint.Y < gridPoint.Y)
	{
		grid_stroke_info->path->top = true;
		next_stroke_info->path->bottom = true;
	}
	else if (nextPoint.Y > gridPoint.Y)
	{
		grid_stroke_info->path->bottom = true;
		next_stroke_info->path->top = true;
	}

	// 根据当前位置的笔刷，找到其原始笔刷和变换规则，然后通过原始笔刷的带楼梯笔刷进行变换后再替换，无法找到时则不替换
	ReplacePathStroke(grid_stroke_info);
	ReplacePathStroke(next_stroke_info);
}

void FMazeBuilderLogic::ReplacePathStroke(TSharedPtr<FMazeBuilderStrokeInfo> stroke_info)
{
	if (!world) return;
	FString replaceName = stroke_info->name + "_" + GetSourcePath(stroke_info);
	UE_LOG(LogTemp, Warning, TEXT("replaceName is:%s"),*replaceName);

	UClass* brushClass = LoadBrushClass(replaceName);
	if (brushClass == nullptr)
	{
		int index = FMath::RandRange(0, 2);
		replaceName += "_" + FString::FromInt(index); // 原生模板的码
		brushClass = LoadBrushClass(replaceName);
	}
	if (brushClass == nullptr)
	{
		// 资源找不到时，提示path信息
		stroke_info->obj->path = FMazeBuilderUltility::GetDebugPathInfo(replaceName, false);
		return;
	}

	AMazeBuilderBrushTemplate* stroke = world->SpawnActor<AMazeBuilderBrushTemplate>(brushClass);
	//GameObject stroke = GameObject.Instantiate(child.gameObject);
	//Undo.RegisterCreatedObjectUndo(stroke, "Replace Path stroke");
	UE_LOG(LogTemp, Warning, TEXT("path is:%s"), *(stroke_info->path->ToString()));
	FString realName = FMazeBuilderUltility::GetStrokeCode(stroke_info->obj->name); 
	stroke->name = realName + "_" + stroke_info->path->ToString(); //衍生模板码，但style是多少已经无所谓了，不处理了
	stroke->path = FMazeBuilderUltility::GetDebugPathInfo(stroke->name, true);
	FString parentName = stroke->GetClass()->GetSuperClass()->GetName();
	if (parentName == "MazeBuilderBrushTemplate")
	{
		stroke->gridSize = gridSize;
		stroke->cornerSize = cornerSize;
		stroke->levelHeight = levelHeight;
		stroke->UpdateMesh();
	}
	stroke->SetActorLocation(stroke_info->obj->GetActorLocation());
	stroke->SetActorRotation(FQuat::MakeFromEuler(FVector(0, 0, stroke_info->trans_type*90.0f)));
	world->EditorDestroyActor(stroke_info->obj,true);
	stroke_info->obj = stroke;
	//Undo.undoRedoPerformed += UndoReplacePathStroke;
}

// 根据当前旋转角度和路径，获得原笔刷应该具有的连通方向
FString FMazeBuilderLogic::GetSourcePath(TSharedPtr<FMazeBuilderStrokeInfo> stroke_info)
{
	//当前笔刷为pow(2,n)时，顺时针旋转x个90度后的path值为pow(2,(n-x)%4),这里就是根据path求n(n%4)
	//UE4就应该改为逆时针旋转x个90度
	int x = stroke_info->trans_type;
	FString pathHexStr = stroke_info->path->ToString();
	FString pathBinStr = FMazeBuilderUltility::HexToBin(pathHexStr[0]);
	int result = 0;
	for (int i = 0; i < pathBinStr.Len(); i++)
	{
		if (pathBinStr[i] == '1')
		{
			int pow = ((pathBinStr.Len() - i - 1) + x + 400) % 4;
			result += (int)FMath::Pow(2.0f, pow*1.0f);
		}
	}
	FString sourcePath = FMazeBuilderUltility::IntToHex(result);
	UE_LOG(LogTemp, Warning, TEXT("pathHexStr:%s pathBinStr:%s sourcePath:%s x:%d"), *pathHexStr, *pathBinStr, *sourcePath,x);
	//Utility.DebugText("pathHexStr:" + pathHexStr + "\t pathBinStr:" + pathBinStr + "\t sourcePath is:" + sourcePath + "\t x:" + x.ToString());
	return sourcePath;
}

/*
* 获取道路的顶点列表，返回开始点和结束点到一个List中
* @thePoint
*
*/
void FMazeBuilderLogic::GetPathPointList(FVector thePoint)
{
	gridPoint = FVector(FMazeBuilderUltility::FormatPos(thePoint, gridSize)*gridSize);
	gridPoint.X = gridPoint.X + 0.5f * gridSize;
	gridPoint.Y = gridPoint.Y + 0.5f * gridSize;
	gridPoint.Z = 0;
	curPoint.Z = 0;
	//DrawStrokeRect(gridPoint, 0.1f, gridPoint.y);
	//Vector3.SignedAngle 的低版本实现
	FVector v1 = FVector(1.0f,0.0f,0.0f);
	FVector v2 = gridPoint - curPoint;
	float angle = FMath::Acos(v2.CosineAngle2D(v1));
	angle = angle * 180.0f / PI;
	//float angle = Vector3.Angle(v1, v2);
	//angle *= Mathf.Sign(Vector3.Cross(v1, v2).y);
	angle *= FMath::Sign(FVector::CrossProduct(v1, v2).Z);
	//float angle = Vector3.SignedAngle(Vector3.right,gridPoint-curPoint,Vector3.up);
	nextPoint = FVector(gridPoint.X, gridPoint.Y, gridPoint.Z);
	if (angle > 135 || angle < -135)
	{
		// 向x正半轴延伸
		nextPoint.X = nextPoint.X + gridSize;
	}
	else if (angle > 45 && angle < 135)
	{
		// 向z正半轴延伸
		nextPoint.Y = nextPoint.Y - gridSize;
	}
	else if (angle > -45 && angle < 45)
	{
		// 向x负半轴延伸
		nextPoint.X = nextPoint.X - gridSize;
	}
	else if (angle > -135 && angle < -45)
	{
		// 向z负半轴延伸
		nextPoint.Y = nextPoint.Y + gridSize;
	}

	gridPoint.Z = GetGizmoHeight(gridPoint);
	nextPoint.Z = GetGizmoHeight(nextPoint);
	//TArray<FVector> pointList;
	//pointList.Add(gridPoint);
	//pointList.Add(nextPoint);
	//return pointList;
}

float FMazeBuilderLogic::GetGizmoHeight(FVector thePoint)
{
	FIntPoint pos = FMazeBuilderUltility::FormatPos(thePoint, gridSize);
	AMazeBuilderBrushTemplate* obj = mapData->GetStrokeAt(pos);
	if (obj == nullptr) return 0;
	int level = FMazeBuilderUltility::GetStrokeCode(obj->pattern).Len();
	level = level > 0 ? level : obj->name.Len();
	return level * levelHeight;
}

FVector FMazeBuilderLogic::gridPoint = FVector::ZeroVector;
FVector FMazeBuilderLogic::nextPoint = FVector::ZeroVector;
bool FMazeBuilderLogic::startPaint = false;
EPaintType FMazeBuilderLogic::paintType = EPaintType::PaintStroke;
FVector FMazeBuilderLogic::curPoint = FVector::ZeroVector;
int FMazeBuilderLogic::startLevel = 0;
int FMazeBuilderLogic::gridWidth = 25;
int FMazeBuilderLogic::gridLength = 25;
float FMazeBuilderLogic::gridSize = 100;
float FMazeBuilderLogic::cornerSize = 50;
float FMazeBuilderLogic::levelHeight = 50;
FString FMazeBuilderLogic::style = "T";
TSharedPtr<FMazeBuilderMapData> FMazeBuilderLogic::mapData = MakeShareable(new FMazeBuilderMapData());
TArray<FIntVector> FMazeBuilderLogic::BasicBrush = FMazeBuilderLogic::GetBasicBrush();
TArray<FCollectCode> FMazeBuilderLogic::SrcTable = FMazeBuilderLogic::GetSrcTable();
FString FMazeBuilderLogic::BrushTemplatePath = "/Game/MeshBrushTemplate1";
UWorld* FMazeBuilderLogic::world = nullptr;
PRAGMA_ENABLE_OPTIMIZATION