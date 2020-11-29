#include "MazeBuilderLogic.h"

FMazeBuilderLogic::FMazeBuilderLogic()
{
	
}


FMazeBuilderLogic::~FMazeBuilderLogic()
{
}

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
				AMazeBuilderBrushTemplate* obj = FMazeBuilderLogic::CreateStrokeByPattern("T_0");
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
				mapData->strokeTable->Add(MBSI);
			}
		}
		//TArray<FAssetData> clses = FMazeBuilderLogic::GetAllBrushBPData();
	}
}

//���level�����,���Ƿ��ص�����level����
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

	int r = pos.X;
	int c = pos.Y;
	// ��ʼ�����Ʋ�
	if (startPaint == false)
	{
		FString code = mapData->GetOldStrokeName(r, c);
		startLevel = FMazeBuilderUltility::GetCharCount(code, 'f');
		// ƥ����ײ��ĸ߶�
		//FVector map_pos = mc.transform.position;
		//map_pos.y = startLevel * propLevelHeight.floatValue;
		//mc.transform.position = map_pos;

		if (startLevel >= mapData->MAX_LEVEL)
			mapData->MAX_LEVEL = startLevel + 1;
		//Utility.DebugText("init startLevel:" + startLevel);
		startPaint = true;
	}
	return pos;
}

//���㵱ǰ��ˢ�������߱�ˢ���ϣ�Բ�ε����߷�ʽ
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
			else if (i == -new_num + 1)
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
			else if (i == new_num)
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
			else if (i == new_num - 1)
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
	//Utility.DebugText("���߶ȣ�" + startLevel);
	int layer_count = (int)(error_code.Len() / 3);
	if (layer_count > 0)
	{
		for (int i = layer_count; i > 0; i--)
		{
			int lv = (layer_count - i) * 3 + 2;
			TArray<FIntVector> outline_brush = GetOutCircleBrush(BasicBrush, i);
			//Utility.DebugText("��������Ϊ��" + i + "���Ƹ߶�Ϊ��" + lv);
			DrawStroke(outline_brush, row, col, lv, true);
		}
		DrawStroke(BasicBrush, row, col, startLevel, false);
	}
	//        Vector3[] outline_brush = GetOutCircleBrush(basicBrush, 0);
	//        DrawStroke(outline_brush, (int)(pos.x), (int)(pos.y), startLevel);
}

/** ����ˢ��ʽ���Ƶ�ͼ��
* brushStyle Ϊ��ˢ��ʽ��Ĭ��ΪbasicBrush
* r ��ͼ���к�
* c ��ͼ���к�
* drawLevel ��ǰ���Ʋ㣬��������߶Ⱦ���
* isMulti �Ƿ������ƣ��������ʱ�����Ǹ��߲����ļ���
*/
FString FMazeBuilderLogic::DrawStroke(TArray<FIntVector> brushStyle, int r, int c, int drawLevel, bool isMulti)
{
	//Utility.DebugText("���ƿ�ʼ");
	for (int i = 0; i < brushStyle.Num(); i++)
	{
		
		FIntVector brush = brushStyle[i];
		if (r > 0 && r < gridWidth && c>0 && c < gridLength)
		{

			int fix_code = brush[2]; //��ǰ�㼶Ӧ������ֵ�������ȫ����0���
			//local fix_code = brush[3] as Integer
		   // Utility.DebugText("row num:" + (r + brush[0]) + " col num:" + (c + brush[1])+"\n");
			FString curr_code = mapData->GetOldStrokeName(r + brush[0], c + brush[1]);
			FString target_name = "";

			//ǰ����㼶��ֵ��Ӧ�����ò㼶��ֵ������Ĳ㼶������ǰ�㼶��ֵ
			for (int level = 0; level < mapData->MAX_LEVEL; level++)
			{
				int curr_level_code = GetLevelCode(curr_code, level);
				//Utility.DebugText("curr_code :" + curr_code + " curr_level_code:" + curr_level_code + "level:" + level + "drawLevel��" + drawLevel);

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
				//Utility.DebugText("curr_level_code:" + curr_level_code + " target_name:" + target_name + " curr_code:" + curr_code + " fix_code:" + IntAsHex(fix_code) + " level:" + level + " drawLevel��" + drawLevel+ "\n");
			}

			//Utility.DebugText(" drawLevel:" + drawLevel + " curr_code:" + curr_code + " target_name:"+target_name+" \n");

			//�������
			TSharedPtr<FMazeBuilderStrokeInfo> stroke_info = GetSourceStroke(target_name);
			if (stroke_info != nullptr)
			{
				//Utility.DebugText("���Ʋ�" + drawLevel + "\t������ƣ�" + target_name + "\tԭʼ��ˢ��" + stroke_info.name + "\t�任��ʽ:" + stroke_info.trans_type + "\ţ�߲�����" + stroke_info.level + " \n");
				//GameObject source_stroke = FindChildByName(mc.brushTemplates, stroke_info.name); // ��ˢԭʼģ��
				int change_type = stroke_info->trans_type; // ��ˢ�任��ʽ
				// �����x�������ᣬ�±���z��������
				float fix_x = (r + brush[0] + 0.5f)*gridSize;
				float fix_z = (c + brush[1] + 0.5f)*gridSize;

				FVector stroke_pos = FVector(fix_x, stroke_info->level*levelHeight, fix_z);// ע��ͨ�õ�λ���׵�ת����max��1��ͨ�õ�λ��Ӧ0.254��
			   // Utility.DebugText("stroke_pos:" + stroke_pos.ToString() + " row:" + brush[0] + " colum:" + brush[2] + " target_name:" + target_name + " fix_x:" + fix_x + "fix_z:" + fix_z + "\n");
				AMazeBuilderBrushTemplate* stroke = CreateStrokeByPattern(stroke_info->name);
				//stroke->name = target_name;
				//stroke.transform.Rotate(Vector3.right, -90f);
				//stroke.transform.Rotate(Vector3.up, change_type * 90f);
				stroke->SetActorLocation(stroke_pos);
				//obj->Rename(TEXT("0"));
				FString parentName = stroke->GetClass()->GetSuperClass()->GetName();
				if (parentName == "AMazeBuilderBrushTemplate")
				{
					stroke->gridSize = gridSize;
					stroke->cornerSize = cornerSize;
					stroke->levelHeight = levelHeight;
				}
				//mapData->strokeTable->Add(MBSI);
////////////////////////////////////////////////////////////
				int row = r + brush[0];
				int col = c + brush[1];
				AMazeBuilderBrushTemplate* old_obj = mapData->GetStrokeAt(row, col);
				if (old_obj != nullptr)
					old_obj->Destroy();
				stroke_info->row = row;
				stroke_info->col = col;
				stroke_info->obj = stroke;

				mapData->strokeTable->Insert(stroke_info,0);
				mapData->max_col = FMath::Max(col, mapData->max_col);
				mapData->max_row = FMath::Max(row, mapData->max_row);
				mapData->min_col = mapData->min_col == 0 ? col : FMath::Min(mapData->min_col, col);
				mapData->min_row = mapData->min_row == 0 ? row : FMath::Min(mapData->min_row, row);
				//stroke.transform.parent = mc.mapRoot.transform;
			}
			else
			{
				//Utility.DebugText(target_name+"û�м�������õ�Դģ��");
				return target_name;
			}

			//stroke.layer.name = "0"
		}
	}
	//Utility.DebugText("------------------");
	return "0";
	// ���Դ���
	//format "%\t%\t%\n" (strokeTable[r-1][c-1].name) (strokeTable[r-1][c].name) (strokeTable[r-1][c+1].name)
	//format "%\t%\t%\n" (strokeTable[r][c-1].name)   (strokeTable[r][c].name)   (strokeTable[r][c+1].name)
	//format "%\t%\t%\n" (strokeTable[r+1][c-1].name) (strokeTable[r+1][c].name) (strokeTable[r+1][c+1].name)
	// �������
}

TArray<FIntVector> FMazeBuilderLogic::GetBasicBrush()
{
	TArray<FIntVector> basicBrush;
	basicBrush.Add(FIntVector(1, -1, 0x8)); basicBrush.Add(FIntVector(0, -1, 0xC)); basicBrush.Add(FIntVector(-1, -1, 0x4));
	basicBrush.Add(FIntVector(1, -1, 0x9)); basicBrush.Add(FIntVector(0, -1, 0xF)); basicBrush.Add(FIntVector(-1, -1, 0x6));
	basicBrush.Add(FIntVector(1, -1, 0x1)); basicBrush.Add(FIntVector(0, -1, 0x3)); basicBrush.Add(FIntVector(-1, -1, 0x2));
	//ȷ�����Ʊ�ˢ��,��ƫ�ƣ���ƫ�ƣ�����ģ����
	return basicBrush;
}

// ��ȡԭʼ��ˢ�ͷ�ת��ı�ˢ
TArray<Vector4> FMazeBuilderLogic::GetSrcTable()
{
	TArray<Vector4> srcTable;
	srcTable.Add(Vector4(0x0, 0x0, 0x0, 0x0));
	srcTable.Add(Vector4(0x2, 0x4, 0x8, 0x1));
	srcTable.Add(Vector4(0x3, 0x6, 0xC, 0x9));
	srcTable.Add(Vector4(0x7, 0xE, 0xD, 0xB));
	srcTable.Add(Vector4(0x5, 0xA, 0x5, 0xA));
	srcTable.Add(Vector4(0xF, 0xF, 0xF, 0xF));
	return srcTable;
}

//ͨ���任����µ���λ��
FString FMazeBuilderLogic::GetStrokeByTransfer(FString name_str, int transfer)
{
	FString result="";
	for (int i = 0; i < name_str.Len(); i++)
	{
		int cur_code = FMazeBuilderUltility::HexToInt((*name_str)[i]);
		FIntPoint pos_code = GetStrokeTransfer(cur_code);
		int x = (int)(pos_code[0]);
		int z = (int)(pos_code[1]);
		int new_z = (z + transfer) % 4;
		//if(new_z == 0)
		//    new_z = 3;
		int new_code = (int)SrcTable[x][new_z];
		result = result + FMazeBuilderUltility::IntToHex(new_code);
	}
	//Utility.DebugText(name_str + "��" + transfer + "����ת�ƺ�õ�" + result);
	return result;
}

//��õ�ǰ�㼶��λ��ı任,0Ϊ����,1Ϊ��ת90��,2Ϊ��ת180��,3Ϊ��ת270��
FIntPoint FMazeBuilderLogic::GetStrokeTransfer(int level_code)
{
	for (int i = 0; i < SrcTable.Num(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (SrcTable[i][j] == level_code)
			{
				return FIntPoint(i, j);
			}
		}
	}
	return FIntPoint(0,0);
}

//��ñ�ˢ��ԭʼģ��ͱ任����
TSharedPtr<FMazeBuilderStrokeInfo> FMazeBuilderLogic::GetSourceStroke(FString full_name)
{
	FString target_name = FMazeBuilderUltility::GetStrokeCode(full_name);
	//�м���f���м��㣬�����߶Ⱦ�����ԭʼ��ˢ���Ƶĸ߶�
	int level = FMazeBuilderUltility::GetCharCount(target_name, 'f');
	FString fix_name = target_name;
	if (level > 0)
	{
		if (target_name.Len() > level)
			fix_name = fix_name.Mid(0, (target_name.Len() - level));
		else
			fix_name = "0";
	}

	TArray<FAssetData>  assetData = GetAllBrushBPData();
	for (int j = 0; j < 4; j++)
	{
		FString curr_name = GetStrokeByTransfer(fix_name, j);
		for (int index = 0; index < assetData.Num(); index++)
		{
			if (curr_name == assetData[index].AssetName.ToString())
			{
				TSharedPtr<FMazeBuilderStrokeInfo> stroke_info = MakeShareable(new FMazeBuilderStrokeInfo(curr_name, j, level));
				return stroke_info; //ԭʼģ�壬��ת�������߶Ȳ���
			}
			UE_LOG(LogTemp, Warning, TEXT("asset name is %s"), *assetData[index].AssetName.ToString());
		}
	}
	return nullptr;
}

AMazeBuilderBrushTemplate* FMazeBuilderLogic::CreateStrokeByPattern(FString pattern)
{
	//Blueprint'/Game/BrushTemplate/T_0.T_0'
	UClass * BlueprintVar = StaticLoadClass(AMazeBuilderBrushTemplate::StaticClass(), nullptr, *("Blueprint\'"+ BrushTemplatePath +"/"+ pattern + "." + pattern + "_C\'"));
	if (BlueprintVar != nullptr && world)
	{
		// �򳡾�����������ɵ���ͼʵ��
		AMazeBuilderBrushTemplate* MBT = world->SpawnActor<AMazeBuilderBrushTemplate>(BlueprintVar);
		if (MBT)
		{
			// �����������оͻᶯ̬����һ����ͼ��ʵ��
			// ���Դ���
			// ����Ҳ��õ�һ����ͼ������ʵ��ָ�룬�����Ե��û���"AMyActor"�еĺ���
			FString HexStr = FMazeBuilderUltility::BinToHex("1110"); // �������ܲ���
			FString BinStr = FMazeBuilderUltility::HexToBin('A');
			//UE_LOG(LogTemp, Log, TEXT("Spawn blueprint actor! %s,%s"), *HexStr, *BinStr);
			//MBT->SetActorLocation(FVector(100, 100, 0));
		}
		return MBT;
	}
	return NULL;
}

// ��ȡ�����е����� AMazeBuilderBrushTemplate ������ͼ�࣬�����޷���ñ༭���е���ͼ��
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
		UE_LOG(LogTemp, Warning, TEXT("asset name is %s"), *arrayAssetData[index].AssetName.ToString());
	}
	return arrayAssetData;
}

bool FMazeBuilderLogic::startPaint = false;
int FMazeBuilderLogic::startLevel = 0;
int FMazeBuilderLogic::gridWidth = 10;
int FMazeBuilderLogic::gridLength = 10;
float FMazeBuilderLogic::gridSize = 100;
float FMazeBuilderLogic::cornerSize = 50;
float FMazeBuilderLogic::levelHeight = 50;
float FMazeBuilderLogic::style = 0;
TSharedPtr<FMazeBuilderMapData> FMazeBuilderLogic::mapData = MakeShareable(new FMazeBuilderMapData());
TArray<FIntVector> FMazeBuilderLogic::BasicBrush = FMazeBuilderLogic::GetBasicBrush();
TArray<Vector4> FMazeBuilderLogic::SrcTable = FMazeBuilderLogic::GetSrcTable();
FString FMazeBuilderLogic::BrushTemplatePath = "/Game/BrushTemplate";
UWorld* FMazeBuilderLogic::world = nullptr;
