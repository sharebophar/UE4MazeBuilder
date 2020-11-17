// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeBuilderBrushTemplate.h"

// Sets default values
AMazeBuilderBrushTemplate::AMazeBuilderBrushTemplate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("MazeBulderBrushMesh"));
	RootComponent = mesh;
	// New in UE 4.17, multi-threaded PhysX cooking.
	mesh->bUseAsyncCooking = true;
	Tags = { "GridDataRecorder" };
	ColorArr.Add(FColor::White);
	ColorArr.Add(FColor::Green);
	//Material = CreateEditorOnlyDefaultSubobject<UMaterialInterface>("recorderMaterial");
	/*
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> RecorderMaterialAsset(TEXT("Material'/Game/Material/VertexColorMat'"));
	if (RecorderMaterialAsset.Succeeded())
	{
		Material = RecorderMaterialAsset.Object;
	}
	*/
}

void AMazeBuilderBrushTemplate::OnConstruction(const FTransform& Transform)
{
	// 会在打开场景时和初始化材质时调用
	CreateMesh(pattern);
	//FlushPersistentDebugLines(GetWorld()); // 清除debugline
	//CreateGridMesh();
	//LoadClientData();
	// 绘制外框
	//DrawWorldBounds();
}



void AMazeBuilderBrushTemplate::CollectMeshData(FString szPattern)
{
	if (szPattern[0] == '0')
	{
		CollectBaseMeshData(szPattern);
	}
	else
	{
		CollectCompleteMeshData(szPattern);
	}
}

void AMazeBuilderBrushTemplate::CollectBaseMeshData(FString szPattern)
{
	if (szPattern == "0_0")
		CollVertData(Lv(LU, 0, 0), Lv(RU, 0, 0), Lv(CTR, 0, 0), Lv(RU, 0, 0), Lv(RD, 0, 0), Lv(CTR, 0, 0), Lv(RD, 0, 0), Lv(LD, 0, 0), Lv(CTR, 0, 0), Lv(LD, 0, 0), Lv(LU, 0, 0), Lv(CTR, 0, 0));
	else if (szPattern == "0_1") {
		CollVertData(Lv(LU, 0, 0), Lv(RU, 0, 0), Lv(CTR, 0, 0), Lv(RU, 0, 0), Lv(RD, 0, 0), Lv(CTR, 0, 0), Lv(RD, 0, 0), Lv(LD, 0, 0), Lv(CTR, 0, 0), Lv(LD, 0, 1), Lv(LU, 0, 1), Lv(CTR, 0, 1));
	}
	else if (szPattern == "0_2") {
		CollVertData(Lv(LU, 0, 0), Lv(RU, 0, 0), Lv(CTR, 0, 0), Lv(RU, 0, 0), Lv(RD, 0, 0), Lv(CTR, 0, 0), Lv(RD, 0, 1), Lv(LD, 0, 1), Lv(CTR, 0, 1), Lv(LD, 0, 0), Lv(LU, 0, 0), Lv(CTR, 0, 0));
	}
	else if (szPattern == "0_3") {
		CollVertData(Lv(LU, 0, 0), Lv(RU, 0, 0), Lv(CTR, 0, 0), Lv(RU, 0, 0), Lv(RD, 0, 0), Lv(CTR, 0, 0), Lv(RD, 0, 1), Lv(LD, 0, 1), Lv(CTR, 0, 1), Lv(LD, 0, 1), Lv(LU, 0, 1), Lv(CTR, 0, 1));
	}
	else if (szPattern == "0_4") {
		CollVertData(Lv(LU, 0, 0), Lv(RU, 0, 0), Lv(CTR, 0, 0), Lv(RU, 0, 1), Lv(RD, 0, 1), Lv(CTR, 0, 1), Lv(RD, 0, 0), Lv(LD, 0, 0), Lv(CTR, 0, 0), Lv(LD, 0, 0), Lv(LU, 0, 0), Lv(CTR, 0, 0));
	}
	else if (szPattern == "0_5") {
		CollVertData(Lv(LU, 0, 0), Lv(RU, 0, 0), Lv(CTR, 0, 0), Lv(RU, 0, 1), Lv(RD, 0, 1), Lv(CTR, 0, 1), Lv(RD, 0, 0), Lv(LD, 0, 0), Lv(CTR, 0, 0), Lv(LD, 0, 1), Lv(LU, 0, 1), Lv(CTR, 0, 1));
	}
	else if (szPattern == "0_6") {
		CollVertData(Lv(LU, 0, 0), Lv(RU, 0, 0), Lv(CTR, 0, 0), Lv(RU, 0, 1), Lv(RD, 0, 1), Lv(CTR, 0, 1), Lv(RD, 0, 1), Lv(LD, 0, 1), Lv(CTR, 0, 1), Lv(LD, 0, 0), Lv(LU, 0, 0), Lv(CTR, 0, 0));
	}
	else if (szPattern == "0_7") {
		CollVertData(Lv(LU, 0, 0), Lv(RU, 0, 0), Lv(CTR, 0, 0), Lv(RU, 0, 1), Lv(RD, 0, 1), Lv(CTR, 0, 1), Lv(RD, 0, 1), Lv(LD, 0, 1), Lv(CTR, 0, 1), Lv(LD, 0, 1), Lv(LU, 0, 1), Lv(CTR, 0, 1));
	}
	else if (szPattern == "0_8") {
		CollVertData(Lv(LU, 0, 1), Lv(RU, 0, 1), Lv(CTR, 0, 1), Lv(RU, 0, 0), Lv(RD, 0, 0), Lv(CTR, 0, 0), Lv(RD, 0, 0), Lv(LD, 0, 0), Lv(CTR, 0, 0), Lv(LD, 0, 0), Lv(LU, 0, 0), Lv(CTR, 0, 0));
	}
	else if (szPattern == "0_9") {
		CollVertData(Lv(LU, 0, 1), Lv(RU, 0, 1), Lv(CTR, 0, 1), Lv(RU, 0, 0), Lv(RD, 0, 0), Lv(CTR, 0, 0), Lv(RD, 0, 0), Lv(LD, 0, 0), Lv(CTR, 0, 0), Lv(LD, 0, 1), Lv(LU, 0, 1), Lv(CTR, 0, 1));
	}
	else if (szPattern == "0_a") {
		CollVertData(Lv(LU, 0, 1), Lv(RU, 0, 1), Lv(CTR, 0, 1), Lv(RU, 0, 0), Lv(RD, 0, 0), Lv(CTR, 0, 0), Lv(RD, 0, 1), Lv(LD, 0, 1), Lv(CTR, 0, 1), Lv(LD, 0, 0), Lv(LU, 0, 0), Lv(CTR, 0, 0));
	}
	else if (szPattern == "0_b") {
		CollVertData(Lv(LU, 0, 1), Lv(RU, 0, 1), Lv(CTR, 0, 1), Lv(RU, 0, 0), Lv(RD, 0, 0), Lv(CTR, 0, 0), Lv(RD, 0, 1), Lv(LD, 0, 1), Lv(CTR, 0, 1), Lv(LD, 0, 1), Lv(LU, 0, 1), Lv(CTR, 0, 1));
	}
	else if (szPattern == "0_c") {
		CollVertData(Lv(LU, 0, 1), Lv(RU, 0, 1), Lv(CTR, 0, 1), Lv(RU, 0, 1), Lv(RD, 0, 1), Lv(CTR, 0, 1), Lv(RD, 0, 0), Lv(LD, 0, 0), Lv(CTR, 0, 0), Lv(LD, 0, 0), Lv(LU, 0, 0), Lv(CTR, 0, 0));
	}
	else if (szPattern == "0_d") {
		CollVertData(Lv(LU, 0, 1), Lv(RU, 0, 1), Lv(CTR, 0, 1), Lv(RU, 0, 1), Lv(RD, 0, 1), Lv(CTR, 0, 1), Lv(RD, 0, 0), Lv(LD, 0, 0), Lv(CTR, 0, 0), Lv(LD, 0, 1), Lv(LU, 0, 1), Lv(CTR, 0, 1));
	}
	else if (szPattern == "0_e") {
		CollVertData(Lv(LU, 0, 1), Lv(RU, 0, 1), Lv(CTR, 0, 1), Lv(RU, 0, 1), Lv(RD, 0, 1), Lv(CTR, 0, 1), Lv(RD, 0, 1), Lv(LD, 0, 1), Lv(CTR, 0, 1), Lv(LD, 0, 0), Lv(LU, 0, 0), Lv(CTR, 0, 0));
	}
	else if (szPattern == "0_f") {
		CollVertData(Lv(LU, 0, 1), Lv(RU, 0, 1), Lv(CTR, 0, 1), Lv(RU, 0, 1), Lv(RD, 0, 1), Lv(CTR, 0, 1), Lv(RD, 0, 1), Lv(LD, 0, 1), Lv(CTR, 0, 1), Lv(LD, 0, 1), Lv(LU, 0, 1), Lv(CTR, 0, 1));
	}
	else
	{
		CollVertData(LU, RU, LD, LD, RU, RD);
	}
}

void AMazeBuilderBrushTemplate::CollectCompleteMeshData(FString szPattern)
{
	if (szPattern == "13_0") {
		CollVertData(Lv(RIU, 2), Lv(RU, 2), Lv(RIUI, 2), Lv(RIUI, 2), Lv(RU, 2), Lv(RUI, 2),
			Lv(RIU, 2), Lv(RIUI, 2), Lv(RIU), Lv(RIU), Lv(RIUI, 2), Lv(RIUI),
			Lv(RIUI, 2), Lv(RUI, 2), Lv(RIUI), Lv(RIUI), Lv(RUI, 2), Lv(RUI),
			Lv(LU), Lv(RIU), Lv(LUI), Lv(LUI), Lv(RIU), Lv(RIUI),
			Lv(LUI), Lv(RUI), LUI, LUI, Lv(RUI), RUI,
			LUI, RUI, LD, LD, RUI, RD
		);
	}
	else if (szPattern == "113_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RIUI, 3), Lv(RIUI, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(RIU, 3), Lv(RIUI, 3), Lv(RIU), Lv(RIU), Lv(RIUI, 3), Lv(RIUI),
			Lv(RIUI, 3), Lv(RUI, 3), Lv(RIUI), Lv(RIUI), Lv(RUI, 3), Lv(RUI),
			Lv(LU), Lv(RIU), Lv(LUI), Lv(LUI), Lv(RIU), Lv(RIUI),
			Lv(LUI), Lv(RUI), LUI, LUI, Lv(RUI), RUI,
			LUI, RUI, LD, LD, RUI, RD
		);
	}
	else if (szPattern == "133_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RIUI, 3), Lv(RIUI, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(RIU, 3), Lv(RIUI, 3), Lv(RIU), Lv(RIU), Lv(RIUI, 3), Lv(RIUI),
			Lv(RIUI, 3), Lv(RUI, 3), Lv(RIUI), Lv(RIUI), Lv(RUI, 3), Lv(RUI),
			Lv(LU), Lv(RIU), Lv(LUI), Lv(LUI), Lv(RIU), Lv(RIUI),
			Lv(LUI), Lv(RUI), LUI, LUI, Lv(RUI), RUI,
			LUI, RUI, LD, LD, RUI, RD
		);
	}
	else if (szPattern == "137_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RIUI, 3), Lv(RIUI, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(RIU, 3), Lv(RIUI, 3), Lv(RIU, 2), Lv(RIU, 2), Lv(RIUI, 3), Lv(RIUI, 2),
			Lv(RIUI, 3), Lv(RUI, 3), Lv(RIUI, 2), Lv(RIUI, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LU, 2), Lv(RIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(RIU, 2), Lv(RIUI, 2),
			Lv(LUI, 2), Lv(RUI, 2), Lv(LUI), Lv(LUI), Lv(RUI, 2), Lv(RUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(LID),
			Lv(LIUI), Lv(RUI), Lv(LID), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "13b_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RIUI, 3), Lv(RIUI, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(RIU, 3), Lv(RIUI, 3), Lv(RIU, 2), Lv(RIU, 2), Lv(RIUI, 3), Lv(RIUI, 2),
			Lv(RIUI, 3), Lv(RUI, 3), Lv(RIUI, 2), Lv(RIUI, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LU, 2), Lv(RIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(RIU, 2), Lv(RIUI, 2),
			Lv(LUI, 2), Lv(RUI, 2), Lv(LUI), Lv(LUI), Lv(RUI, 2), Lv(RUI),
			Lv(RIUI), Lv(RUI), Lv(RID), Lv(RID), Lv(RUI), Lv(RD),
			Lv(LUI), Lv(RIUI), Lv(RID), Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID,
			LUI, RID, LD
		);
	}
	else if (szPattern == "133b_0") {
		CollVertData(Lv(RIU, 4), Lv(RU, 4), Lv(RIUI, 4), Lv(RIUI, 4), Lv(RU, 4), Lv(RUI, 4),
			Lv(RIU, 4), Lv(RIUI, 4), Lv(RIU, 3), Lv(RIU, 3), Lv(RIUI, 4), Lv(RIUI, 3),
			Lv(RIUI, 4), Lv(RUI, 4), Lv(RIUI, 3), Lv(RIUI, 3), Lv(RUI, 4), Lv(RUI, 3),
			Lv(LU, 3), Lv(RIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(RIU, 3), Lv(RIUI, 3),
			Lv(LUI, 3), Lv(RUI, 3), Lv(LUI), Lv(LUI), Lv(RUI, 3), Lv(RUI),
			Lv(RIUI), Lv(RUI), Lv(RID), Lv(RID), Lv(RUI), Lv(RD),
			Lv(LUI), Lv(RIUI), Lv(RID), Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID,
			LUI, RID, LD
		);
	}
	else if (szPattern == "13bb_0") {
		CollVertData(Lv(RIU, 4), Lv(RU, 4), Lv(RIUI, 4), Lv(RIUI, 4), Lv(RU, 4), Lv(RUI, 4),
			Lv(RIU, 4), Lv(RIUI, 4), Lv(RIU, 3), Lv(RIU, 3), Lv(RIUI, 4), Lv(RIUI, 3),
			Lv(RIUI, 4), Lv(RUI, 4), Lv(RIUI, 3), Lv(RIUI, 3), Lv(RUI, 4), Lv(RUI, 3),
			Lv(LU, 3), Lv(RIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(RIU, 3), Lv(RIUI, 3),
			Lv(LUI, 3), Lv(RUI, 3), Lv(LUI, 2), Lv(LUI, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(RIUI, 2), Lv(RUI, 2), Lv(RID, 2), Lv(RID, 2), Lv(RUI, 2), Lv(RD, 2),
			Lv(LUI, 2), Lv(RIUI, 2), Lv(RID, 2), Lv(LUI, 2), Lv(RID, 2), LUI, LUI, Lv(RID, 2), RID,
			LUI, RID, LD
		);
	}
	else if (szPattern == "15_0") {
		CollVertData(Lv(RIU, 2), Lv(RU, 2), Lv(RUI, 2), Lv(LDI), Lv(LID), Lv(LD),
			Lv(RIU), Lv(RUI), Lv(LDI), Lv(LDI), Lv(RUI), Lv(LID),
			Lv(RIU, 2), Lv(RUI, 2), Lv(RIU), Lv(RIU), Lv(RUI, 2), Lv(RUI),
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI,
			Lv(RIU), Lv(LDI), RIU, RIU, Lv(LDI), LDI,
			LU, RIU, LDI, LID, RUI, RD
		);
	}
	else if (szPattern == "115_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RUI, 3), Lv(LDI), Lv(LID), Lv(LD),
			Lv(RIU), Lv(RUI), Lv(LDI), Lv(LDI), Lv(RUI), Lv(LID),
			Lv(RIU, 3), Lv(RUI, 3), Lv(RIU), Lv(RIU), Lv(RUI, 3), Lv(RUI),
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI,
			Lv(RIU), Lv(LDI), RIU, RIU, Lv(LDI), LDI,
			LU, RIU, LDI, LID, RUI, RD
		);
	}
	else if (szPattern == "155_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RUI, 3), Lv(LDI, 2), Lv(LID, 2), Lv(LD, 2),
			Lv(RIU, 2), Lv(RUI, 2), Lv(LDI, 2), Lv(LDI, 2), Lv(RUI, 2), Lv(LID, 2),
			Lv(RIU, 3), Lv(RUI, 3), Lv(RIU, 2), Lv(RIU, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LID, 2), Lv(RUI, 2), LID, LID, Lv(RUI, 2), RUI,
			Lv(RIU, 2), Lv(LDI, 2), RIU, RIU, Lv(LDI, 2), LDI,
			LU, RIU, LDI, LID, RUI, RD
		);
	}
	else if (szPattern == "157_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RUI, 3), Lv(LDI, 2), Lv(LID, 2), Lv(LD, 2),
			Lv(RIU, 2), Lv(RUI, 2), Lv(LDI, 2), Lv(LDI, 2), Lv(RUI, 2), Lv(LID, 2),
			Lv(RIU, 3), Lv(RUI, 3), Lv(RIU, 2), Lv(RIU, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LID, 2), Lv(RUI, 2), LID, LID, Lv(RUI, 2), RUI,
			Lv(RIU, 2), Lv(LDI, 2), Lv(RIU), Lv(RIU), Lv(LDI, 2), Lv(LDI),
			Lv(LU), Lv(RIU), Lv(LDI), LID, RUI, RD
		);
	}
	else if (szPattern == "15d_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RUI, 3), Lv(LDI, 2), Lv(LID, 2), Lv(LD, 2),
			Lv(RIU, 2), Lv(RUI, 2), Lv(LDI, 2), Lv(LDI, 2), Lv(RUI, 2), Lv(LID, 2),
			Lv(RIU, 3), Lv(RUI, 3), Lv(RIU, 2), Lv(RIU, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LID, 2), Lv(RUI, 2), Lv(LID), Lv(LID), Lv(RUI, 2), Lv(RUI),
			Lv(RIU, 2), Lv(LDI, 2), RIU, RIU, Lv(LDI, 2), LDI,
			LU, RIU, LDI, Lv(LID), Lv(RUI), Lv(RD)
		);
	}
	else if (szPattern == "17_0") {
		CollVertData(Lv(RIU, 2), Lv(RU, 2), Lv(RIUI, 2), Lv(RIUI, 2), Lv(RU, 2), Lv(RUI, 2),
			Lv(RIU, 2), Lv(RIUI, 2), Lv(RIU), Lv(RIU), Lv(RIUI, 2), Lv(RIUI),
			Lv(RIUI, 2), Lv(RUI, 2), Lv(RIUI), Lv(RIUI), Lv(RUI, 2), Lv(RUI),
			Lv(LU), Lv(RIU), Lv(LUI), Lv(LUI), Lv(RIU), Lv(RIUI),
			Lv(RIUI), Lv(RUI), Lv(RID), Lv(RID), Lv(RUI), Lv(RD),
			Lv(LUI), Lv(RIUI), Lv(RID), LUI, RID, LD,
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID
		);
	}
	else if (szPattern == "117_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RIUI, 3), Lv(RIUI, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(RIU, 3), Lv(RIUI, 3), Lv(RIU), Lv(RIU), Lv(RIUI, 3), Lv(RIUI),
			Lv(RIUI, 3), Lv(RUI, 3), Lv(RIUI), Lv(RIUI), Lv(RUI, 3), Lv(RUI),
			Lv(LU), Lv(RIU), Lv(LUI), Lv(LUI), Lv(RIU), Lv(RIUI),
			Lv(RIUI), Lv(RUI), Lv(RID), Lv(RID), Lv(RUI), Lv(RD),
			Lv(LUI), Lv(RIUI), Lv(RID), LUI, RID, LD,
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID
		);
	}
	else if (szPattern == "177_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RIUI, 3), Lv(RIUI, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(RIU, 3), Lv(RIUI, 3), Lv(RIU, 2), Lv(RIU, 2), Lv(RIUI, 3), Lv(RIUI, 2),
			Lv(RIUI, 3), Lv(RUI, 3), Lv(RIUI, 2), Lv(RIUI, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LU, 2), Lv(RIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(RIU, 2), Lv(RIUI, 2),
			Lv(RIUI, 2), Lv(RUI, 2), Lv(RID, 2), Lv(RID, 2), Lv(RUI, 2), Lv(RD, 2),
			Lv(LUI, 2), Lv(RIUI, 2), Lv(RID, 2), LUI, RID, LD,
			Lv(LUI, 2), Lv(RID, 2), LUI, LUI, Lv(RID, 2), RID
		);
	}
	else if (szPattern == "2_0") {
		CollVertData(Lv(LU), Lv(LIU), Lv(LUI), Lv(LUI), Lv(LIU), Lv(LIUI),
			Lv(LUI), Lv(LIUI), LUI, LUI, Lv(LIUI), LIUI,
			Lv(LIUI), Lv(LIU), LIU, Lv(LIUI), LIU, LIUI,
			LUI, LIUI, LD, LD, LIUI, LID,
			LIUI, RUI, LID, LID, RUI, RD,
			LIU, RU, LIUI, LIUI, RU, RUI
		);
	}
	else if (szPattern == "2_1") {
		CollVertData(Lv(LU, 1, 1), Lv(LIU, 1, 1), Lv(LD, 0, 1), Lv(LD, 0, 1), Lv(LIU, 1, 1), Lv(LID, 0, 1),
			Lv(LIU), LIU, LID,
			LIU, RU, LID,
			LID, RU, RD
		);
	}
	else if (szPattern == "2_2") {
		CollVertData(Lv(LU), Lv(LIU), Lv(LUI), Lv(LUI), Lv(LIU), Lv(LIUI),
			Lv(LUI), Lv(LIUI), LUI, LUI, Lv(LIUI), LIUI,
			Lv(LIUI), Lv(LIU), LIU, Lv(LIUI), LIU, LIUI,

			LUI, LIUI, LD, LD, LIUI, CTR,
			Lv(LD, 0, 1), Lv(CTR, 0, 1), Lv(RD, 0, 1), CTR, RU, RD,
			LIUI, RU, CTR, LIU, RU, LIUI
		);
	}
	else if (szPattern == "2_3") {
		CollVertData(Lv(LU), Lv(LIU), Lv(LIUI), Lv(LU), Lv(LIUI), LIUI,
			Lv(LIUI), Lv(LIU), LIU, Lv(LIUI), LIU, LIUI,
			Lv(LU, 1, 1), Lv(LIUI, 0, 1), Lv(LD, 0, 1), Lv(LD, 0, 1), Lv(LIU, 0, 1), Lv(LID, 0, 1),
			Lv(LIUI, 0, 1), Lv(RD, 0, 1), Lv(LID, 0, 1), LIUI, RUI, RD,
			LIU, RU, LIUI, LIUI, RU, RUI
		);
	}
	else if (szPattern == "2_4") {
		CollVertData(Lv(LU), Lv(LIU), Lv(LUI), Lv(LUI), Lv(LIU), Lv(LIUI),
			Lv(LUI), Lv(LIUI), LUI, LUI, Lv(LIUI), LIUI,
			Lv(LIUI), Lv(LIU), LIU, Lv(LIUI), LIU, LIUI,

			LUI, LIUI, LD, LD, LIUI, CTR,
			LD, CTR, RD, Lv(CTR, 0, 1), Lv(RU, 0, 1), Lv(RD, 0, 1),
			LIUI, RU, CTR, LIU, RU, LIUI
		);
	}
	else if (szPattern == "2_6") {
		CollVertData(Lv(LU), Lv(LIU), Lv(LUI), Lv(LUI), Lv(LIU), Lv(LIUI),
			Lv(LUI), Lv(LIUI), LUI, LUI, Lv(LIUI), LIUI,
			Lv(LIUI), Lv(LIU), LIU, Lv(LIUI), LIU, LIUI,

			LUI, LIUI, LD, LD, LIUI, CTR,
			Lv(LD, 0, 1), Lv(CTR, 0, 1), Lv(RD, 0, 1), Lv(CTR, 0, 1), Lv(RU, 0, 1), Lv(RD, 0, 1),
			LIUI, RU, CTR, LIU, RU, LIUI
		);
	}
	else if (szPattern == "2_8") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(LUI, 1, 1), Lv(LUI, 1, 1), Lv(RU, 0, 1), Lv(RUI, 0, 1),
			Lv(LUI), RUI, LUI,
			LUI, RUI, LD, LD, RUI, RD
		);
	}
	else if (szPattern == "2_9") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(LD, 0, 1), LD, RU, RD);
	}
	// 可能没有存在的必要
	else if (szPattern == "2_5" || szPattern == "2_7" || szPattern == "2_a" || szPattern == "2_b" || szPattern == "2_d" || szPattern == "2_e" || szPattern == "2_f") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(LD, 0, 1), Lv(LD, 0, 1), Lv(RU, 0, 1), Lv(RD, 0, 1));
	}
	else if (szPattern == "2_c") {
		CollVertData(Lv(LU), Lv(LIUI), Lv(LUI), Lv(LU), LIUI, Lv(LIUI),
			Lv(LUI), Lv(LIUI), LUI, LUI, Lv(LIUI), LIUI,
			Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(LIUI, 0, 1), Lv(LIUI, 0, 1), Lv(RU, 0, 1), Lv(RD, 0, 1),
			LUI, LIUI, LD, LD, LIUI, RD
		);
	}
	else if (szPattern == "22_0") {
		CollVertData(Lv(LU, 2), Lv(LIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), LUI, LUI, Lv(LIUI, 2), LIUI,
			Lv(LIUI, 2), Lv(LIU, 2), LIU, Lv(LIUI, 2), LIU, LIUI,
			LUI, LIUI, LD, LD, LIUI, LID,
			LIUI, RUI, LID, LID, RUI, RD,
			LIU, RU, LIUI, LIUI, RU, RUI
		);
	}
	else if (szPattern == "23_0") {
		CollVertData(Lv(LU, 2), Lv(LIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LUI), Lv(LUI), Lv(LIUI, 2), Lv(LIUI),
			Lv(LIUI, 2), Lv(LIU, 2), Lv(LIUI), Lv(LIUI), Lv(LIU, 2), Lv(LIU),
			Lv(LUI), Lv(RUI), LUI, LUI, Lv(RUI), RUI,
			Lv(LIUI), Lv(LIU), Lv(RUI), Lv(RUI), Lv(LIU), Lv(RU),
			LUI, LIUI, LD, LD, LIUI, LID,
			LIUI, RUI, LID, LID, RUI, RD
		);
	}
	else if (szPattern == "223_0") {
		CollVertData(Lv(LU, 3), Lv(LIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LUI), Lv(LUI), Lv(LIUI, 3), Lv(LIUI),
			Lv(LIUI, 3), Lv(LIU, 3), Lv(LIUI), Lv(LIUI), Lv(LIU, 3), Lv(LIU),
			Lv(LUI), Lv(RUI), LUI, LUI, Lv(RUI), RUI,
			Lv(LIUI), Lv(LIU), Lv(RUI), Lv(RUI), Lv(LIU), Lv(RU),
			LUI, LIUI, LD, LD, LIUI, LID,
			LIUI, RUI, LID, LID, RUI, RD
		);
	}
	else if (szPattern == "233_0") {
		CollVertData(Lv(LU, 3), Lv(LIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LUI, 2), Lv(LUI, 2), Lv(LIUI, 3), Lv(LIUI, 2),
			Lv(LIUI, 3), Lv(LIU, 3), Lv(LIUI, 2), Lv(LIUI, 2), Lv(LIU, 3), Lv(LIU, 2),
			Lv(LUI, 2), Lv(RUI, 2), LUI, LUI, Lv(RUI, 2), RUI,
			Lv(LIUI, 2), Lv(LIU, 2), Lv(RUI, 2), Lv(RUI, 2), Lv(LIU, 2), Lv(RU, 2),
			LUI, LIUI, LD, LD, LIUI, LID,
			LIUI, RUI, LID, LID, RUI, RD
		);
	}
	else if (szPattern == "237_0") {
		CollVertData(Lv(LU, 3), Lv(LIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LUI, 2), Lv(LUI, 2), Lv(LIUI, 3), Lv(LIUI, 2),
			Lv(LIUI, 3), Lv(LIU, 3), Lv(LIUI, 2), Lv(LIUI, 2), Lv(LIU, 3), Lv(LIU, 2),
			Lv(LUI, 2), Lv(RUI, 2), Lv(LUI), Lv(LUI), Lv(RUI, 2), Lv(RUI),
			Lv(LIUI, 2), Lv(LIU, 2), Lv(RUI, 2), Lv(RUI, 2), Lv(LIU, 2), Lv(RU, 2),
			Lv(LUI), Lv(LID), Lv(LD), Lv(LUI), Lv(RUI), Lv(LID),
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI, LID, RUI, RD
		);
	}
	else if (szPattern == "27_0") {
		CollVertData(Lv(LU, 2), Lv(LIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LUI), Lv(LUI), Lv(LIUI, 2), Lv(LIUI),
			Lv(LIUI, 2), Lv(LIU, 2), Lv(LIU), Lv(LIUI, 2), Lv(LIU), Lv(LIUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(LID), Lv(LIUI), Lv(RUI), Lv(LID),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(RUI), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "27_1") {
		CollVertData(Lv(LU, 2), Lv(LIU, 2), Lv(LIUI, 2), Lv(LIUI, 2), Lv(LIU, 2), Lv(LIUI), Lv(LIUI), Lv(LIU, 2), Lv(LIU), Lv(LU, 2), Lv(LIUI, 2), Lv(LIUI),
			Lv(LU, 2, 1), Lv(LIUI, 1, 1), Lv(LD, 1, 1), Lv(LD), Lv(LIUI), Lv(LID), Lv(LIUI), Lv(RUI), Lv(LID), Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(RUI),
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI, LID, RUI, RD
		);
	}
	else if (szPattern == "27_2") {
		CollVertData(Lv(LU, 2), Lv(LIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LUI), Lv(LUI), Lv(LIUI, 2), Lv(LIUI),
			Lv(LIUI, 2), Lv(LIU, 2), Lv(LIU), Lv(LIUI, 2), Lv(LIU), Lv(LIUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(RU), Lv(LIU), Lv(RU), Lv(LIUI),
			Lv(LD, 1, 1), Lv(CTR, 1, 1), Lv(RD, 0, 1), Lv(CTR), Lv(RI2DI2), Mh3(RI2DI2), RD, Mh3(RI2DI2), RI2DI2,
			Lv(CTR), Lv(RU), Lv(RUI), Lv(CTR), Lv(RUI), Lv(RI2DI2), RI2DI2, RUI, RD,
			Lv(RI2DI2), Lv(RUI), RI2DI2, RI2DI2, Lv(RUI), RUI
		);
	}
	else if (szPattern == "27_3") {
		CollVertData(Lv(LU, 2, 1), Lv(LIUI, 1, 1), Lv(LD, 1, 1), Lv(LD, 1, 1), Lv(LIUI, 1, 1), Lv(CTR, 1, 1),
			Lv(LD, 1, 1), Lv(CTR, 1, 1), Lv(RD, 0, 1), Lv(CTR), Lv(RI2DI2), Mh3(RI2DI2), RD, Mh3(RI2DI2), RI2DI2,
			Lv(LU, 2), Lv(LIU, 2), Lv(LIUI, 2), Lv(LU, 2), Lv(LIUI, 2), Lv(LIUI),
			Lv(LIUI, 2), Lv(LIU, 2), Lv(LIUI), Lv(LIUI), Lv(LIU, 2), Lv(LIU),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(CTR),
			Lv(RU), Lv(RUI), Lv(CTR), Lv(CTR), Lv(RUI), Lv(RI2DI2),
			Lv(RI2DI2), Lv(RUI), RI2DI2, RI2DI2, Lv(RUI), RUI, RI2DI2, RUI, RD
		);
	}
	else if (szPattern == "27_4") {
		CollVertData(Lv(LU, 2), Lv(LIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LUI), Lv(LUI), Lv(LIUI, 2), Lv(LIUI),
			Lv(LIUI, 2), Lv(LIU, 2), Lv(LIU), Lv(LIUI, 2), Lv(LIU), Lv(LIUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(LID), Lv(LIUI), Lv(RI2DI2), Lv(LID),
			Lv(LID), Lv(RI2DI2), LID, LID, Lv(RI2DI2), RI2DI2, LID, RI2DI2, RD,
			Mh3(RI2DI2), RD, RI2DI2, Lv(RI2DI2), Lv(CTR), Mh3(RI2DI2),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(CTR), Lv(CTR, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1)
		);
	}
	else if (szPattern == "27_5") {
		CollVertData(Lv(LU, 2, 1), Lv(LIUI, 1, 1), Lv(LD, 1, 1), Lv(LD), Lv(LIUI), Lv(CTR),
			Lv(LD), Lv(CTR), Lv(LID), Lv(LID), Lv(CTR), Lv(RI2DI2), LID, RI2DI2, RD,
			Lv(LID), Lv(RI2DI2), LID, LID, Lv(RI2DI2), RI2DI2,
			Lv(RI2DI2), Lv(CTR), Mh3(RI2DI2), Mh3(RI2DI2), RD, RI2DI2,
			Lv(LU, 2), Lv(LIU, 2), Lv(LIUI, 2), Lv(LU, 2), Lv(LIUI, 2), Lv(LIUI),
			Lv(LIUI, 2), Lv(LIU, 2), Lv(LIUI), Lv(LIUI), Lv(LIU, 2), Lv(LIU),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(CTR),
			Lv(CTR, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1)
		);
	}
	else if (szPattern == "27_6") {
		CollVertData(Lv(LU, 2), Lv(LIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LUI), Lv(LUI), Lv(LIUI, 2), Lv(LIUI),
			Lv(LIUI, 2), Lv(LIU, 2), Lv(LIU), Lv(LIUI, 2), Lv(LIU), Lv(LIUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(RU), Lv(LIU), Lv(RU), Lv(LIUI),
			Lv(LD, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1)
		);
	}
	else if (szPattern == "27_7") {
		CollVertData(Lv(LU, 2, 1), Lv(LIUI, 1, 1), Lv(LD, 1, 1), Lv(LD), Lv(LIUI), Lv(CTR),
			Lv(LD, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1),
			Lv(LU, 2), Lv(LIU, 2), Lv(LIUI, 2), Lv(LU, 2), Lv(LIUI, 2), Lv(LIUI),
			Lv(LIUI, 2), Lv(LIU, 2), Lv(LIUI), Lv(LIUI), Lv(LIU, 2), Lv(LIU),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(CTR),
			Lv(CTR, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1)
		);
	}
	else if (szPattern == "27_8") {
		CollVertData(Lv(LU, 2), Lv(LIUI, 2), Lv(LUI, 2), Lv(LIUI, 2), Lv(LU, 2), Lv(LIUI, 1),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LUI), Lv(LUI), Lv(LIUI, 2), Lv(LIUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(CTR), Lv(LD), Lv(CTR), Lv(LID), Lv(LID), Lv(CTR), Lv(RUI), Lv(RUI), Lv(CTR), Lv(RU),
			Lv(LU, 2, 1), Lv(RU, 1, 1), Lv(LIUI, 1, 1), Lv(LIUI), Lv(RU), Lv(CTR), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "27_9") {
		CollVertData(Lv(LU, 2, 1), Lv(LIUI, 1, 1), Lv(LD, 1, 1), Lv(LD), Lv(LIUI), Lv(LID), Lv(LIUI), Lv(RUI), Lv(LID),
			Lv(LU, 2, 1), Lv(RU, 1, 1), Lv(LIUI, 1, 1), Lv(LIUI), Lv(RU), Lv(RUI), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "27_a") {
		CollVertData(Lv(LU, 2, 1), Lv(RU, 1, 1), Lv(LIUI, 1, 1), Lv(LD, 1, 1), Lv(CTR, 1, 1), Lv(RD, 0, 1),
			Lv(LIUI), Lv(RU), Lv(CTR), Lv(CTR), Lv(RU), Lv(RUI), Lv(CTR), Lv(RUI), Lv(RI2DI2), RI2DI2, RUI, RD,
			Lv(RI2DI2), Lv(RUI), RI2DI2, RI2DI2, Lv(RUI), RUI, Lv(LIUI, 2), Lv(LU, 2), Lv(LIUI),
			Lv(CTR), Lv(RI2DI2), Mh3(RI2DI2), RD, Mh3(RI2DI2), RI2DI2,
			Lv(LU, 2), Lv(LIUI, 2), Lv(LUI, 2), Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(CTR),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LUI), Lv(LUI), Lv(LIUI, 2), Lv(LIUI)
		);
	}
	else if (szPattern == "27_b") {
		CollVertData(Lv(LU, 2, 1), Lv(LIUI, 1, 1), Lv(LD, 1, 1), Lv(LU, 2, 1), Lv(RU, 1, 1), Lv(LIUI, 1, 1),
			Lv(LIUI), Lv(RU), Lv(LD), Lv(LD, 1, 1), Lv(CTR, 1, 1), Lv(RD, 0, 1),
			Lv(CTR, 1, 1), Lv(RI2DI2, 1, 1), Mh3(RI2DI2), RD, Mh3(RI2DI2), RI2DI2,
			Lv(CTR), Lv(RU), Lv(RUI), Lv(CTR), Lv(RUI), Lv(RI2DI2), RI2DI2, RUI, RD,
			Lv(RI2DI2), Lv(RUI), RI2DI2, RI2DI2, Lv(RUI), RUI
		);
	}
	else if (szPattern == "27_c") {
		CollVertData(Lv(LU, 2, 1), Lv(RU, 1, 1), Lv(LIUI, 1, 1), Lv(LIUI), Lv(RU), Lv(CTR), Lv(CTR, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1),
			Lv(LIUI, 2), Lv(LU, 2), Lv(LIUI), Lv(RI2DI2), Lv(CTR), Mh3(RI2DI2), Mh3(RI2DI2), RD, RI2DI2,
			Lv(LU, 2), Lv(LIUI, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(LIUI, 2), Lv(LUI), Lv(LUI), Lv(LIUI, 2), Lv(LIUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(CTR), Lv(LD), Lv(CTR), Lv(LID), Lv(LID), Lv(CTR), Lv(RI2DI2),
			LID, RI2DI2, RD, Lv(LID), Lv(RI2DI2), LID, LID, Lv(RI2DI2), RI2DI2
		);
	}
	else if (szPattern == "27_d") {
		CollVertData(Lv(LU, 2, 1), Lv(RU, 1, 1), Lv(LIUI, 1, 1), Lv(LU, 2, 1), Lv(LIUI, 1, 1), Lv(LD, 1, 1),
			Lv(LIUI), Lv(RU), Lv(LD), Lv(CTR, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1),
			Lv(LD), Lv(CTR), Lv(LID), Lv(CTR), Lv(RI2DI2), Lv(LID), LID, RI2DI2, RD,
			Lv(LID), Lv(RI2DI2), LID, LID, Lv(RI2DI2), RI2DI2,
			Lv(RI2DI2), Lv(CTR), Mh3(RI2DI2), Mh3(RI2DI2), RD, RI2DI2
		);
	}
	else if (szPattern == "27_e") {
		CollVertData(Lv(LU, 2, 1), Lv(RU, 1, 1), Lv(LIUI, 1, 1), Lv(LIUI), Lv(RU), Lv(CTR), Lv(LD, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1),
			Lv(LU, 2), Lv(LIUI, 2), Lv(LUI, 2), Lv(LIUI, 2), Lv(LU, 2), Lv(LIUI),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LUI), Lv(LUI), Lv(LIUI, 2), Lv(LIUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LIUI), Lv(CTR), Lv(LD)
		);
	}
	else if (szPattern == "27_f") {
		CollVertData(Lv(LU, 2, 1), Lv(RU, 1, 1), Lv(LIUI, 1, 1), Lv(LU, 2, 1), Lv(LIUI, 1, 1), Lv(LD, 1, 1),
			Lv(LIUI, 1, 1), Lv(RU, 1, 1), Lv(LD, 1, 1), Lv(LD, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1)
		);
	}
	else if (szPattern == "227_0") {
		CollVertData(Lv(LU, 3), Lv(LIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LUI), Lv(LUI), Lv(LIUI, 3), Lv(LIUI),
			Lv(LIUI, 3), Lv(LIU, 3), Lv(LIU), Lv(LIUI, 3), Lv(LIU), Lv(LIUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(LID), Lv(LIUI), Lv(RUI), Lv(LID),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(RUI), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "277_0") {
		CollVertData(Lv(LU, 3), Lv(LIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LUI, 2), Lv(LUI, 2), Lv(LIUI, 3), Lv(LIUI, 2),
			Lv(LIUI, 3), Lv(LIU, 3), Lv(LIU, 2), Lv(LIUI, 3), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LD, 2), Lv(LD, 2), Lv(LIUI, 2), Lv(LID, 2), Lv(LIUI, 2), Lv(RUI, 2), Lv(LID, 2),
			Lv(LIU, 2), Lv(RU, 2), Lv(LIUI, 2), Lv(LIUI, 2), Lv(RU, 2), Lv(RUI, 2), LID, RUI, RD,
			Lv(LID, 2), Lv(RUI, 2), LID, LID, Lv(RUI, 2), RUI
		);
	}

	else if (szPattern == "222_0") {
		CollVertData(Lv(LU, 3), Lv(LIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), LUI, LUI, Lv(LIUI, 3), LIUI,
			Lv(LIUI, 3), Lv(LIU, 3), LIU, Lv(LIUI, 3), LIU, LIUI,
			LUI, LIUI, LD, LD, LIUI, LID,
			LIUI, RUI, LID, LID, RUI, RD,
			LIU, RU, LIUI, LIUI, RU, RUI
		);
	}
	else if (szPattern == "2227_0") {
		CollVertData(Lv(LU, 4), Lv(LIU, 4), Lv(LUI, 4), Lv(LUI, 4), Lv(LIU, 4), Lv(LIUI, 4),
			Lv(LUI, 4), Lv(LIUI, 4), Lv(LUI), Lv(LUI), Lv(LIUI, 4), Lv(LIUI),
			Lv(LIUI, 4), Lv(LIU, 4), Lv(LIU), Lv(LIUI, 4), Lv(LIU), Lv(LIUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(LID), Lv(LIUI), Lv(RUI), Lv(LID),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(RUI), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "2237_0") {
		CollVertData(Lv(LU, 4), Lv(LIU, 4), Lv(LUI, 4), Lv(LUI, 4), Lv(LIU, 4), Lv(LIUI, 4),
			Lv(LUI, 4), Lv(LIUI, 4), Lv(LUI, 2), Lv(LUI, 2), Lv(LIUI, 4), Lv(LIUI, 2),
			Lv(LIUI, 4), Lv(LIU, 4), Lv(LIU, 2), Lv(LIUI, 4), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(RUI, 2), Lv(LUI), Lv(LUI), Lv(RUI, 2), Lv(RUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(LID), Lv(LIUI), Lv(RUI), Lv(LID),
			Lv(LIU, 2), Lv(RU, 2), Lv(LIUI, 2), Lv(LIUI, 2), Lv(RU, 2), Lv(RUI, 2), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "2267_0") {
		CollVertData(Lv(LU, 4), Lv(LIU, 4), Lv(LUI, 4), Lv(LUI, 4), Lv(LIU, 4), Lv(LIUI, 4),
			Lv(LUI, 4), Lv(LIUI, 4), Lv(LUI, 2), Lv(LUI, 2), Lv(LIUI, 4), Lv(LIUI, 2),
			Lv(LIUI, 4), Lv(LIU, 4), Lv(LIU, 2), Lv(LIUI, 4), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LD, 2), Lv(LD, 2), Lv(LIUI, 2), Lv(LID, 2), Lv(LIUI), Lv(RUI), Lv(LID),
			Lv(LID, 2), Lv(LIU, 2), Lv(LID), Lv(LID), Lv(LIU, 2), Lv(LIU),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(RUI), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "2277_0") {
		CollVertData(Lv(LU, 4), Lv(LIU, 4), Lv(LUI, 4), Lv(LUI, 4), Lv(LIU, 4), Lv(LIUI, 4),
			Lv(LUI, 4), Lv(LIUI, 4), Lv(LUI, 2), Lv(LUI, 2), Lv(LIUI, 4), Lv(LIUI, 2),
			Lv(LIUI, 4), Lv(LIU, 4), Lv(LIU, 2), Lv(LIUI, 4), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LD, 2), Lv(LD, 2), Lv(LIUI, 2), Lv(LID, 2), Lv(LIUI, 2), Lv(RUI, 2), Lv(LID, 2),
			Lv(LIU, 2), Lv(RU, 2), Lv(LIUI, 2), Lv(LIUI, 2), Lv(RU, 2), Lv(RUI, 2), LID, RUI, RD,
			Lv(LID, 2), Lv(RUI, 2), LID, LID, Lv(RUI, 2), RUI
		);
	}
	else if (szPattern == "2337_0") {
		CollVertData(Lv(LU, 4), Lv(LIU, 4), Lv(LUI, 4), Lv(LUI, 4), Lv(LIU, 4), Lv(LIUI, 4),
			Lv(LUI, 4), Lv(LIUI, 4), Lv(LUI, 3), Lv(LUI, 3), Lv(LIUI, 4), Lv(LIUI, 3),
			Lv(LIUI, 4), Lv(LIU, 4), Lv(LIU, 3), Lv(LIUI, 4), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(RUI, 3), Lv(LUI), Lv(LUI), Lv(RUI, 3), Lv(RUI),
			Lv(LUI), Lv(LIUI), Lv(LD), Lv(LD), Lv(LIUI), Lv(LID), Lv(LIUI), Lv(RUI), Lv(LID),
			Lv(LIU, 3), Lv(RU, 3), Lv(LIUI, 3), Lv(LIUI, 3), Lv(RU, 3), Lv(RUI, 3), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "2377_0") {
		CollVertData(Lv(LU, 4), Lv(LIU, 4), Lv(LUI, 4), Lv(LUI, 4), Lv(LIU, 4), Lv(LIUI, 4),
			Lv(LUI, 4), Lv(LIUI, 4), Lv(LUI, 3), Lv(LUI, 3), Lv(LIUI, 4), Lv(LIUI, 3),
			Lv(LIUI, 4), Lv(LIU, 4), Lv(LIU, 3), Lv(LIUI, 4), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(RUI, 3), Lv(LUI, 2), Lv(LUI, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LD, 2), Lv(LD, 2), Lv(LIUI, 2), Lv(LID, 2), Lv(LIUI, 2), Lv(RUI, 2), Lv(LID, 2),
			Lv(LIU, 3), Lv(RU, 3), Lv(LIUI, 3), Lv(LIUI, 3), Lv(RU, 3), Lv(RUI, 3), LID, RUI, RD,
			Lv(LID, 2), Lv(RUI, 2), LID, LID, Lv(RUI, 2), RUI
		);
	}
	else if (szPattern == "2777_0") {
		CollVertData(Lv(LU, 4), Lv(LIU, 4), Lv(LUI, 4), Lv(LUI, 4), Lv(LIU, 4), Lv(LIUI, 4),
			Lv(LUI, 4), Lv(LIUI, 4), Lv(LUI, 3), Lv(LUI, 3), Lv(LIUI, 4), Lv(LIUI, 3),
			Lv(LIUI, 4), Lv(LIU, 4), Lv(LIU, 3), Lv(LIUI, 4), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LD, 3), Lv(LD, 3), Lv(LIUI, 3), Lv(LID, 3), Lv(LIUI, 3), Lv(RUI, 3), Lv(LID, 3),
			Lv(LIU, 3), Lv(RU, 3), Lv(LIUI, 3), Lv(LIUI, 3), Lv(RU, 3), Lv(RUI, 3), LID, RUI, RD,
			Lv(LID, 3), Lv(RUI, 3), LID, LID, Lv(RUI, 3), RUI
		);
	}
	else if (szPattern == "22277_0") {
		CollVertData(Lv(LU, 5), Lv(LIU, 5), Lv(LUI, 5), Lv(LUI, 5), Lv(LIU, 5), Lv(LIUI, 5),
			Lv(LUI, 5), Lv(LIUI, 5), Lv(LUI, 2), Lv(LUI, 2), Lv(LIUI, 5), Lv(LIUI, 2),
			Lv(LIUI, 5), Lv(LIU, 5), Lv(LIU, 2), Lv(LIUI, 5), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LD, 2), Lv(LD, 2), Lv(LIUI, 2), Lv(LID, 2), Lv(LIUI, 2), Lv(RUI, 2), Lv(LID, 2),
			Lv(LIU, 2), Lv(RU, 2), Lv(LIUI, 2), Lv(LIUI, 2), Lv(RU, 2), Lv(RUI, 2), LID, RUI, RD,
			Lv(LID, 2), Lv(RUI, 2), LID, LID, Lv(RUI, 2), RUI
		);
	}
	else if (szPattern == "22377_0") {
		CollVertData(Lv(LU, 5), Lv(LIU, 5), Lv(LUI, 5), Lv(LUI, 5), Lv(LIU, 5), Lv(LIUI, 5),
			Lv(LUI, 5), Lv(LIUI, 5), Lv(LUI, 3), Lv(LUI, 3), Lv(LIUI, 5), Lv(LIUI, 3),
			Lv(LIUI, 5), Lv(LIU, 5), Lv(LIU, 3), Lv(LIUI, 5), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(RUI, 3), Lv(LUI, 2), Lv(LUI, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LD, 2), Lv(LD, 2), Lv(LIUI, 2), Lv(LID, 2), Lv(LIUI, 2), Lv(RUI, 2), Lv(LID, 2),
			Lv(LIU, 3), Lv(RU, 3), Lv(LIUI, 3), Lv(LIUI, 3), Lv(RU, 3), Lv(RUI, 3), LID, RUI, RD,
			Lv(LID, 2), Lv(RUI, 2), LID, LID, Lv(RUI, 2), RUI
		);
	}
	else if (szPattern == "22677_0") {
		CollVertData(Lv(LU, 5), Lv(LIU, 5), Lv(LUI, 5), Lv(LUI, 5), Lv(LIU, 5), Lv(LIUI, 5),
			Lv(LUI, 5), Lv(LIUI, 5), Lv(LUI, 3), Lv(LUI, 3), Lv(LIUI, 5), Lv(LIUI, 3),
			Lv(LIUI, 5), Lv(LIU, 5), Lv(LIU, 3), Lv(LIUI, 5), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LID, 3), Lv(LIU, 3), Lv(LID, 2), Lv(LID, 2), Lv(LIU, 3), Lv(LIU, 2),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LD, 3), Lv(LD, 3), Lv(LIUI, 3), Lv(LID, 3), Lv(LIUI, 2), Lv(RUI, 2), Lv(LID, 2),
			Lv(LIU, 2), Lv(RU, 2), Lv(LIUI, 2), Lv(LIUI, 2), Lv(RU, 2), Lv(RUI, 2), LID, RUI, RD,
			Lv(LID, 2), Lv(RUI, 2), LID, LID, Lv(RUI, 2), RUI
		);
	}
	else if (szPattern == "22777_0") {
		CollVertData(Lv(LU, 5), Lv(LIU, 5), Lv(LUI, 5), Lv(LUI, 5), Lv(LIU, 5), Lv(LIUI, 5),
			Lv(LUI, 5), Lv(LIUI, 5), Lv(LUI, 3), Lv(LUI, 3), Lv(LIUI, 5), Lv(LIUI, 3),
			Lv(LIUI, 5), Lv(LIU, 5), Lv(LIU, 3), Lv(LIUI, 5), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LD, 3), Lv(LD, 3), Lv(LIUI, 3), Lv(LID, 3), Lv(LIUI, 3), Lv(RUI, 3), Lv(LID, 3),
			Lv(LIU, 3), Lv(RU, 3), Lv(LIUI, 3), Lv(LIUI, 3), Lv(RU, 3), Lv(RUI, 3), LID, RUI, RD,
			Lv(LID, 3), Lv(RUI, 3), LID, LID, Lv(RUI, 3), RUI
		);
	}
	else if (szPattern == "222777_0") {
		CollVertData(Lv(LU, 6), Lv(LIU, 6), Lv(LUI, 6), Lv(LUI, 6), Lv(LIU, 6), Lv(LIUI, 6),
			Lv(LUI, 6), Lv(LIUI, 6), Lv(LUI, 3), Lv(LUI, 3), Lv(LIUI, 6), Lv(LIUI, 3),
			Lv(LIUI, 6), Lv(LIU, 6), Lv(LIU, 3), Lv(LIUI, 6), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LD, 3), Lv(LD, 3), Lv(LIUI, 3), Lv(LID, 3), Lv(LIUI, 3), Lv(RUI, 3), Lv(LID, 3),
			Lv(LIU, 3), Lv(RU, 3), Lv(LIUI, 3), Lv(LIUI, 3), Lv(RU, 3), Lv(RUI, 3), LID, RUI, RD,
			Lv(LID, 3), Lv(RUI, 3), LID, LID, Lv(RUI, 3), RUI
		);
	}
	else if (szPattern == "2b_0") {
		CollVertData(Lv(LU, 2), Lv(LIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LUI, 2), Lv(LIUI, 2), Lv(LUI), Lv(LUI), Lv(LIUI, 2), Lv(LIUI),
			Lv(LIUI, 2), Lv(LIU, 2), Lv(LIU), Lv(LIUI, 2), Lv(LIU), Lv(LIUI),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(RUI),
			Lv(RIUI), Lv(RUI), Lv(RID), Lv(RID), Lv(RUI), Lv(RD),
			Lv(LUI), Lv(RIUI), Lv(RID), LUI, RID, LD,
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID
		);
	}
	else if (szPattern == "22b_0") {
		CollVertData(Lv(LU, 3), Lv(LIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LUI), Lv(LUI), Lv(LIUI, 3), Lv(LIUI),
			Lv(LIUI, 3), Lv(LIU, 3), Lv(LIU), Lv(LIUI, 3), Lv(LIU), Lv(LIUI),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(RUI),
			Lv(RIUI), Lv(RUI), Lv(RID), Lv(RID), Lv(RUI), Lv(RD),
			Lv(LUI), Lv(RIUI), Lv(RID), LUI, RID, LD,
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID
		);
	}
	else if (szPattern == "23b_0") {
		CollVertData(Lv(LU, 3), Lv(LIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LUI, 2), Lv(LUI, 2), Lv(LIUI, 3), Lv(LIUI, 2),
			Lv(LIUI, 3), Lv(LIU, 3), Lv(LIU, 2), Lv(LIUI, 3), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LIU, 2), Lv(RU, 2), Lv(LIUI, 2), Lv(LIUI, 2), Lv(RU, 2), Lv(RUI, 2),
			Lv(LUI, 2), Lv(RUI, 2), Lv(LUI), Lv(LUI), Lv(RUI, 2), Lv(RUI),
			Lv(RIUI), Lv(RUI), Lv(RID), Lv(RID), Lv(RUI), Lv(RD),
			Lv(LUI), Lv(RIUI), Lv(RID), LUI, RID, LD,
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID
		);
	}
	else if (szPattern == "2bb_0") {
		CollVertData(Lv(LU, 3), Lv(LIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(LIU, 3), Lv(LIUI, 3),
			Lv(LUI, 3), Lv(LIUI, 3), Lv(LUI, 2), Lv(LUI, 2), Lv(LIUI, 3), Lv(LIUI, 2),
			Lv(LIUI, 3), Lv(LIU, 3), Lv(LIU, 2), Lv(LIUI, 3), Lv(LIU, 2), Lv(LIUI, 2),
			Lv(LIU, 2), Lv(RU, 2), Lv(LIUI, 2), Lv(LIUI, 2), Lv(RU, 2), Lv(RUI, 2),
			Lv(RIUI, 2), Lv(RUI, 2), Lv(RID, 2), Lv(RID, 2), Lv(RUI, 2), Lv(RD, 2),
			Lv(LUI, 2), Lv(RIUI, 2), Lv(RID, 2), LUI, RID, LD,
			Lv(LUI, 2), Lv(RID, 2), LUI, LUI, Lv(RID, 2), RID
		);
	}
	else if (szPattern == "3_0") {
		CollVertData(Lv(LU), Lv(RU), Lv(LUI), Lv(LUI), Lv(RU), Lv(RUI),
			Lv(LUI), Lv(RUI), LUI, LUI, Lv(RUI), RUI,
			LUI, RUI, LD, LD, RUI, RD);
	}
	else if (szPattern == "3_1") {
		CollVertData(Lv(LU, 1, 1), Lv(LIU, 1, 1), Lv(LD, 0, 1), Lv(LD, 0, 1), Lv(LIU, 1, 1), Lv(LID, 0, 1),
			Lv(LIU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(RUI),
			Lv(LIUI), Lv(RUI), LIUI, LIUI, Lv(RUI), RUI,
			Lv(LIU), Lv(LIUI), Mh3(LIUI), LID, Mh3(LIUI), LIUI,
			LIUI, RUI, LID, LID, RUI, RD);
	}
	else if (szPattern == "3_2") {
		CollVertData(Lv(LU), Lv(RU), Lv(LUI), Lv(LUI), Lv(RU), Lv(RUI),
			Lv(LUI), Lv(RUI), LUI, LUI, Lv(RUI), RUI,
			LUI, LIUI, LDI, LDI, LIUI, LIDI,
			LDI, LIDI, LD, Lv(LD, 0, 1), Lv(LIDI, 0, 1), Lv(RID, 0, 1),
			Lv(LIDI, 0, 1), Lv(RIDI, 0, 1), Lv(RID, 0, 1), Lv(RIDI, 0, 1), Lv(RD, 0, 1), Lv(RID, 0, 1),
			LIUI, RIDI, LIDI, LIUI, RUI, RD
		);
	}
	else if (szPattern == "3_3") {
		CollVertData(Lv(LU, 1, 1), Lv(LIUI, 0, 1), Lv(LD, 0, 1), Lv(LIUI, 0, 1), Lv(RD, 0, 1), Lv(LD, 0, 1),
			Lv(LU), Lv(RU), Lv(LIUI), Lv(LIUI), Lv(RU), Lv(RUI),
			Lv(LIUI), Lv(RUI), LIUI, LIUI, Lv(RUI), RUI,
			LIUI, RUI, RD, Lv(LU), Lv(LIUI), LIUI
		);
	}
	else if (szPattern == "3_4") {
		CollVertData(Lv(RIU, 1, 1), Lv(RU, 1, 1), Lv(RID, 0, 1), Lv(RID, 0, 1), Lv(RU, 1, 1), Lv(RD, 0, 1),
			Lv(LU), Lv(RIU), Lv(LUI), Lv(LUI), Lv(RIU), Lv(RIUI),
			Lv(LUI), Lv(RIUI), LUI, LUI, Lv(RIUI), RIUI,
			LUI, RIUI, LD, LD, RIUI, RID,
			Lv(RIUI), Lv(RIU), Mh3(RIUI), Mh3(RIUI), RID, RIUI
		);
	}
	else if (szPattern == "3_5" || szPattern == "3_7" || szPattern == "3_a" || szPattern == "3_b" || szPattern == "3_d" || szPattern == "3_e" || szPattern == "3_f") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 1, 1), Lv(LD, 0, 1), Lv(LD, 0, 1), Lv(RU, 1, 1), Lv(RD, 0, 1));
	}
	else if (szPattern == "3_6") {
		CollVertData(Lv(RU, 1, 1), Lv(RD, 0, 1), Lv(RIUI, 0, 1), Lv(RIUI, 0, 1), Lv(RD, 0, 1), Lv(LD, 0, 1),
			Lv(LU), Lv(RIU), Lv(LUI), Lv(LUI), Lv(RIU), Lv(RIUI),
			Lv(RIU), Lv(RU), Lv(RIUI), Lv(RIUI), Lv(RU), RIUI,
			Lv(LUI), Lv(RIUI), LUI, LUI, Lv(RIUI), RIUI,
			LUI, RIUI, LD
		);
	}
	else if (szPattern == "3_8") {
		CollVertData(Lv(LU), Lv(LIUI), Lv(LUI), Lv(LU, 1, 1), Lv(LIU, 1, 1), Lv(LIUI, 1, 1),
			Lv(LIU, 1, 1), Lv(RIU, 1, 1), Lv(LIUI, 1, 1), Lv(LIUI, 1, 1), Lv(RIU, 1, 1), Lv(RIUI, 1, 1),
			Lv(RIU, 1, 1), Lv(RU, 1, 1), Lv(RIUI, 1, 1), Lv(RIUI), Lv(RU), Lv(RUI),
			Lv(LUI), Lv(RUI), LUI, LUI, Lv(RUI), RUI,
			LUI, RUI, LD, LD, RUI, RD
		);
	}
	else if (szPattern == "3_9") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 1, 1), Lv(RIUI, 1, 1), Lv(LU, 1, 1), Lv(RIUI, 1, 1), Lv(LD, 0, 1),
			Lv(RU), Lv(RUI), Lv(RIUI), Lv(RIUI), RIUI, LD,
			RIUI, RD, LD, RIUI, RUI, RD,
			Lv(RIUI), Lv(RUI), RIUI, RIUI, Lv(RUI), RUI
		);
	}
	else if (szPattern == "3_c") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 1, 1), Lv(LIUI, 1, 1), Lv(LIUI, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1),
			Lv(LU), Lv(LIUI), Lv(LUI), Lv(LIUI), RD, LIUI,
			LUI, LIUI, LD, LD, LIUI, RD,
			Lv(LUI), Lv(LIUI), LUI, LUI, Lv(LIUI), LIUI
		);
	}
	else if (szPattern == "37_0") {
		CollVertData(
			Lv(LUI, 2), Lv(RUI, 2), Lv(LUI), Lv(LUI), Lv(RUI, 2), Lv(RUI),
			Lv(LUI, 2), Lv(LU, 2), Lv(RUI, 2), Lv(RUI, 2), Lv(LU, 2), Lv(RU, 2),
			Lv(LUI), Lv(LID), Lv(LD), Lv(LUI), Lv(RUI), Lv(LID),
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI, LID, RUI, RD
		);
	}
	else if (szPattern == "337_0") {
		CollVertData(
			Lv(LUI, 3), Lv(RUI, 3), Lv(LUI), Lv(LUI), Lv(RUI, 3), Lv(RUI),
			Lv(LUI, 3), Lv(LU, 3), Lv(RUI, 3), Lv(RUI, 3), Lv(LU, 3), Lv(RU, 3),
			Lv(LUI), Lv(LID), Lv(LD), Lv(LUI), Lv(RUI), Lv(LID),
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI, LID, RUI, RD
		);
	}
	else if (szPattern == "377_0") {
		CollVertData(
			Lv(LUI, 3), Lv(RUI, 3), Lv(LUI, 2), Lv(LUI, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LUI, 3), Lv(LU, 3), Lv(RUI, 3), Lv(RUI, 3), Lv(LU, 3), Lv(RU, 3),
			Lv(LUI, 2), Lv(LID, 2), Lv(LD, 2), Lv(LUI, 2), Lv(RUI, 2), Lv(LID, 2),
			Lv(LID, 2), Lv(RUI, 2), LID, LID, Lv(RUI, 2), RUI, LID, RUI, RD
		);
	}
	else if (szPattern == "3b_0") {
		CollVertData(Lv(LU, 2), Lv(RU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(RU, 2), Lv(RUI, 2),
			Lv(LUI, 2), Lv(RUI, 2), Lv(LUI), Lv(LUI), Lv(RUI, 2), Lv(RUI),
			Lv(LUI), Lv(RUI), Lv(RID), Lv(RID), Lv(RUI), Lv(RD),
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID,
			LUI, RID, LD
		);
	}
	else if (szPattern == "33b_0") {
		CollVertData(Lv(LU, 3), Lv(RU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(LUI, 3), Lv(RUI, 3), Lv(LUI), Lv(LUI), Lv(RUI, 3), Lv(RUI),
			Lv(LUI), Lv(RUI), Lv(RID), Lv(RID), Lv(RUI), Lv(RD),
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID,
			LUI, RID, LD
		);
	}
	else if (szPattern == "3bb_0") {
		CollVertData(Lv(LU, 3), Lv(RU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(LUI, 3), Lv(RUI, 3), Lv(LUI, 2), Lv(LUI, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LUI, 2), Lv(RUI, 2), Lv(RID, 2), Lv(RID, 2), Lv(RUI, 2), Lv(RD, 2),
			Lv(LUI, 2), Lv(RID, 2), LUI, LUI, Lv(RID, 2), RID,
			LUI, RID, LD
		);
	}
	else if (szPattern == "33_0") {
		CollVertData(Lv(LU, 2), Lv(RU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(RU, 2), Lv(RUI, 2),
			Lv(LUI, 2), Lv(RUI, 2), LUI, LUI, Lv(RUI, 2), RUI,
			LUI, RUI, LD, LD, RUI, RD);
	}
	else if (szPattern == "333_0") {
		CollVertData(Lv(LU, 3), Lv(RU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(LUI, 3), Lv(RUI, 3), LUI, LUI, Lv(RUI, 3), RUI,
			LUI, RUI, LD, LD, RUI, RD);
	}
	else if (szPattern == "5d_0") {
		CollVertData(Lv(RIU, 2), Lv(RU, 2), Lv(RUI, 2), Lv(RIU, 2), Lv(RUI, 2), Lv(LDI, 2),
			Lv(LDI, 2), Lv(RUI, 2), Lv(LID, 2), Lv(LDI, 2), Lv(LID, 2), Lv(LD, 2),
			Lv(RIU, 2), Lv(LDI, 2), RIU, RIU, Lv(LDI, 2), LDI,
			Lv(LID, 2), Lv(RUI, 2), Lv(LID), Lv(LID), Lv(RUI, 2), Lv(RUI),
			Lv(LID), Lv(RUI), Lv(RD), LU, RIU, LDI
		);
	}
	else if (szPattern == "55d_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RUI, 3), Lv(RIU, 3), Lv(RUI, 3), Lv(LDI, 3),
			Lv(LDI, 3), Lv(RUI, 3), Lv(LID, 3), Lv(LDI, 3), Lv(LID, 3), Lv(LD, 3),
			Lv(RIU, 3), Lv(LDI, 3), RIU, RIU, Lv(LDI, 3), LDI,
			Lv(LID, 3), Lv(RUI, 3), Lv(LID), Lv(LID), Lv(RUI, 3), Lv(RUI),
			Lv(LID), Lv(RUI), Lv(RD), LU, RIU, LDI
		);
	}
	else if (szPattern == "5dd_0") {
		CollVertData(Lv(RIU, 3), Lv(RU, 3), Lv(RUI, 3), Lv(RIU, 3), Lv(RUI, 3), Lv(LDI, 3),
			Lv(LDI, 3), Lv(RUI, 3), Lv(LID, 3), Lv(LDI, 3), Lv(LID, 3), Lv(LD, 3),
			Lv(RIU, 3), Lv(LDI, 3), RIU, RIU, Lv(LDI, 3), LDI,
			Lv(LID, 3), Lv(RUI, 3), Lv(LID, 2), Lv(LID, 2), Lv(RUI, 3), Lv(RUI, 2),
			Lv(LID, 2), Lv(RUI, 2), Lv(RD, 2), LU, RIU, LDI
		);
	}
	else if (szPattern == "7_0") {
		CollVertData(Lv(LU), Lv(RU), Lv(LD), Lv(LD), Lv(RU), Lv(LID), Lv(LID), Lv(RU), Lv(RUI),
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI,
			LID, RUI, RD
		);
	}
	else if (szPattern == "7_1") {
		CollVertData(Lv(LU, 1, 1), Lv(CTR, 1, 1), Lv(LD, 1, 1), Lv(LU), Lv(RU), Lv(CTR),
			Lv(RU), Lv(RUI), Lv(LD), Lv(LD), Lv(RUI), Lv(LID),
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI,
			LID, RUI, RD
		);
	}
	else if (szPattern == "7_2") {
		CollVertData(Lv(LDI, 1, 1), Lv(RDI, 0, 1), Lv(LD, 1, 1), Lv(LD, 1, 1), Lv(RDI, 0, 1), Lv(RD, 0, 1),
			Lv(LU), Lv(RU), Lv(RUI), Lv(LU), Lv(RUI), Lv(LI2DI), Lv(LU), Lv(LI2DI), Lv(LDI),
			Lv(LI2DI), Lv(RUI), RUI, Lv(LI2DI), RUI, LI2DI,
			LI2DI, RUI, RDI, RDI, Mh7(LI2DI), LI2DI,
			Lv(LDI), Lv(LI2DI), Mh7(LI2DI)
		);
	}
	else if (szPattern == "7_3") {
		CollVertData(Lv(LU, 1, 1), Lv(CTR, 1, 1), Lv(LD, 1, 1), Lv(LD, 1, 1), Lv(CTR, 1, 1), Lv(RD, 0, 1),
			Lv(LU), Lv(RU), Lv(CTR), Lv(CTR), Lv(RU), Lv(RUI), Lv(CTR), Lv(RUI), Lv(RI2DI2), //
			RI2DI2, RUI, RD,
			Lv(CTR), Lv(RI2DI2), Mh3(RI2DI2), RD, Mh3(RI2DI2), RI2DI2,
			Lv(RI2DI2), Lv(RUI), RI2DI2, RI2DI2, Lv(RUI), RUI
		);
	}

	else if (szPattern == "7_4") {
		CollVertData(Lv(RIU, 1, 1), Lv(RU, 1, 1), Lv(RID, 0, 1), Lv(RID, 0, 1), Lv(RU, 1, 1), Lv(RD, 0, 1),
			Lv(LU), Lv(RIU), Lv(RIUI), Lv(LU), Lv(RIUI), Lv(LD),
			Lv(LD), Lv(RIUI), Lv(LID), Lv(LID), Lv(RIUI), Lv(RIUI2), LID, RIUI2, RID,
			Lv(LID), Lv(RIUI2), LID, LID, Lv(RIUI2), RIUI2,
			Mh7(RIUI2), RID, RIUI2, Lv(RIUI2), Lv(RIU), Mh7(RIUI2)
		);
	}
	else if (szPattern == "7_5" || szPattern == "7_a" || szPattern == "7_b" || szPattern == "7_d" || szPattern == "7_e" || szPattern == "7_f")
	{
		CollVertData(Lv(LU, 1, 1), Lv(RU, 1, 1), Lv(LD, 1, 1), Lv(LD, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1));
	}
	else if (szPattern == "7_6" || szPattern == "7_7") {
		CollVertData(Lv(LU), Lv(RU), Lv(LD), Lv(LD, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1));
	}
	else if (szPattern == "7_8") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 1, 1), Lv(CTR), Lv(LU), Lv(CTR), Lv(LD),
			Lv(CTR), Lv(RU), Lv(RUI), Lv(CTR), Lv(RUI), Lv(LID), Lv(LD), Lv(CTR), Lv(LID), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "7_9") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 1, 1), Lv(LD, 1, 1),
			Lv(CTR), Lv(RU), Lv(RUI), Lv(CTR), Lv(RUI), Lv(LID), Lv(LD), Lv(CTR), Lv(LID), LID, RUI, RD,
			Lv(LID), Lv(RUI), LID, LID, Lv(RUI), RUI
		);
	}
	else if (szPattern == "7_c") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 1, 1), Lv(CTR, 1, 1), Lv(CTR, 1, 1), Lv(RU, 1, 1), Lv(RD, 0, 1),
			Lv(LU), Lv(CTR), Lv(LD), Lv(LD), Lv(CTR), Lv(LID), Lv(LID), Lv(CTR), Lv(RI2DI2), LID, RI2DI2, RD,
			Lv(LID), Lv(RI2DI2), LID, LID, Lv(RI2DI2), RI2DI2,
			Lv(RI2DI2), Lv(CTR), Mh3(RI2DI2), Mh3(RI2DI2), RD, RI2DI2
		);
	}
	else if (szPattern == "77_0") {
		CollVertData(Lv(LU, 2), Lv(RU, 2), Lv(LD, 2), Lv(LD, 2), Lv(RU, 2), Lv(LID, 2), Lv(LID, 2), Lv(RU, 2), Lv(RUI, 2),
			Lv(LU, 2), Lv(RU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(RU, 2), Lv(RUI, 2),
			Lv(LID, 2), Lv(RUI, 2), LID, LID, Lv(RUI, 2), RUI,
			LID, RUI, RD
		);
	}
	else if (szPattern == "777_0") {
		CollVertData(Lv(LU, 3), Lv(RU, 3), Lv(LD, 3), Lv(LD, 3), Lv(RU, 3), Lv(LID, 3), Lv(LID, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(LU, 3), Lv(RU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(RU, 3), Lv(RUI, 3),
			Lv(LID, 3), Lv(RUI, 3), LID, LID, Lv(RUI, 3), RUI,
			LID, RUI, RD
		);
	}
	else if (szPattern == "a_0") {
		CollVertData(Lv(LU), Lv(LIU), Lv(LUI), Lv(LUI), Lv(LIU), Lv(RID), Lv(RID), Lv(LIU), Lv(RDI), Lv(RID), Lv(RDI), Lv(RD),
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID,
			Lv(RDI), Lv(LIU), RDI, RDI, Lv(LIU), LIU,
			LUI, RID, LD,
			LIU, RU, RDI
		);
	}
	else if (szPattern == "a_1") {
		CollVertData(Lv(LU, 1, 1), Lv(CTR, 1, 1), Lv(LD, 0, 1),
			LIU, RU, RDI, Lv(RDI), Lv(LIU), RDI, RDI, Lv(LIU), LIU,
			Lv(LU), Lv(LIU), Lv(CTR), Lv(LIU), Lv(RDI), Lv(CTR), Lv(CTR), Lv(RDI), Lv(RD),
			Lv(CTR), Lv(RD), Lv(RID), Lv(CTR), Lv(RID), Lv(LI2DI2), LD, LI2DI2, RID,
			Lv(LI2DI2), Lv(RID), LI2DI2, LI2DI2, Lv(RID), RID,
			LD, Mh3(LI2DI2), LI2DI2, Lv(CTR), Lv(LI2DI2), Mh3(LI2DI2)
		);
	}
	else if (szPattern == "a_2") {
		CollVertData(Lv(CTR, 1, 1), Lv(RD, 1, 1), Lv(LD, 0, 1),
			LIU, RU, RDI, Lv(RDI), Lv(LIU), RDI, RDI, Lv(LIU), LIU,
			Lv(LU), Lv(LIU), Lv(CTR), Lv(LIU), Lv(RDI), Lv(CTR), Lv(CTR), Lv(RDI), Lv(RD),
			Lv(LU), Lv(CTR), Lv(LUI), Lv(LUI), Lv(CTR), Lv(LI2DI2), LUI, LI2DI2, LD,
			Lv(LUI), Lv(LI2DI2), LUI, LUI, Lv(LI2DI2), LI2DI2,
			Mh3(LI2DI2), LD, LI2DI2, Lv(LI2DI2), Lv(CTR), Mh3(LI2DI2)
		);
	}
	else if (szPattern == "a_3") {
		CollVertData(Lv(LU, 1, 1), Lv(RD, 1, 1), Lv(LD, 0, 1),
			LIU, RU, RDI, Lv(RDI), Lv(LIU), RDI, RDI, Lv(LIU), LIU,
			Lv(LU), Lv(LIU), Lv(CTR), Lv(LIU), Lv(RDI), Lv(CTR), Lv(CTR), Lv(RDI), Lv(RD)
		);
	}
	else if (szPattern == "a_4") {
		CollVertData(Lv(CTR, 1, 1), Lv(RU, 0, 1), Lv(RD, 1, 1),
			Lv(LU), Lv(CTR), Lv(LUI), Lv(LUI), Lv(CTR), Lv(RID), Lv(CTR), Lv(RD), Lv(RID),
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID, LUI, RID, LD,
			Lv(LU), Lv(LIU), Lv(CTR), Lv(LIU), Lv(RI2UI2), Lv(CTR), LIU, RU, RI2UI2,
			Lv(RI2UI2), Lv(LIU), RI2UI2, RI2UI2, Lv(LIU), LIU,
			RU, Mh3(RI2UI2), RI2UI2, Lv(CTR), Lv(RI2UI2), Mh3(RI2UI2)
		);
	}
	else if (szPattern == "a_5") {
		CollVertData(Lv(CTR, 1, 1), Lv(RU, 0, 1), Lv(RD, 1, 1), Lv(LU, 1, 1), Lv(CTR, 1, 1), Lv(LD, 0, 1),
			Lv(CTR), Lv(RD), Lv(RID), Lv(CTR), Lv(RID), Lv(LI2DI2), LI2DI2, RID, LD,
			Lv(LU), Lv(LIU), Lv(CTR), Lv(LIU), Lv(RI2UI2), Lv(CTR), LIU, RU, RI2UI2,
			Lv(LI2DI2), Lv(RID), LI2DI2, LI2DI2, Lv(RID), RID,
			Lv(RI2UI2), Lv(LIU), RI2UI2, RI2UI2, Lv(LIU), LIU,
			Mh3(LI2DI2), Lv(CTR), Lv(LI2DI2), LI2DI2, LD, Mh3(LI2DI2),
			Lv(CTR), Lv(RI2UI2), Mh3(RI2UI2), RU, Mh3(RI2UI2), RI2UI2
		);
	}
	else if (szPattern == "a_6") {
		CollVertData(Lv(CTR, 1, 1), Lv(RU, 0, 1), Lv(RD, 1, 1), Lv(CTR, 1, 1), Lv(RD, 1, 1), Lv(LD, 0, 1),
			Lv(LU), Lv(LIU), Lv(LUI), Lv(LUI), Lv(LIU), Lv(LI2DI2), Lv(LIU), Lv(RI2UI2), Lv(LI2DI2),
			LUI, LI2DI2, LD, LIU, RU, RI2UI2,
			Lv(LUI), Lv(LI2DI2), LUI, LUI, Lv(LI2DI2), LI2DI2,
			Lv(RI2UI2), Lv(LIU), RI2UI2, RI2UI2, Lv(LIU), LIU,
			Mh3(LI2DI2), LD, LI2DI2, Lv(LI2DI2), Lv(CTR), Mh3(LI2DI2),
			Lv(CTR), Lv(RI2UI2), Mh3(RI2UI2), RU, Mh3(RI2UI2), RI2UI2
		);
	}
	else if (szPattern == "a_7") {
		CollVertData(Lv(CTR, 1, 1), Lv(RU, 0, 1), Lv(RD, 1, 1), Lv(LU, 1, 1), Lv(RD, 1, 1), Lv(LD, 0, 1),
			Lv(LU), Lv(LIU), Lv(CTR), Lv(LIU), Lv(RI2UI2), Lv(CTR), LIU, RU, RI2UI2,
			Lv(RI2UI2), Lv(LIU), RI2UI2, RI2UI2, Lv(LIU), LIU,
			Lv(CTR), Lv(RI2UI2), Mh3(RI2UI2), RU, Mh3(RI2UI2), RI2UI2
		);
	}
	else if (szPattern == "a_8") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(CTR, 1, 1),
			Lv(LU), Lv(CTR), Lv(LUI), Lv(LUI), Lv(CTR), Lv(RID), Lv(CTR), Lv(RD), Lv(RID),
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID, LUI, RID, LD,
			Lv(CTR), Lv(RI2UI2), Lv(RDI), Lv(CTR), Lv(RDI), Lv(RD), RI2UI2, RU, RDI,
			Lv(RDI), Lv(RI2UI2), RDI, RDI, Lv(RI2UI2), RI2UI2,
			Mh3(RI2UI2), RU, RI2UI2, Lv(RI2UI2), Lv(CTR), Mh3(RI2UI2)
		);
	}
	else if (szPattern == "a_9") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(CTR, 1, 1), Lv(LU, 1, 1), Lv(CTR, 1, 1), Lv(LD, 0, 1),
			Lv(LI2DI2), Lv(RI2UI2), Lv(RID), Lv(RI2UI2), Lv(RDI), Lv(RID), Lv(RID), Lv(RDI), Lv(RD),
			RI2UI2, RU, RDI, LI2DI2, RID, LD,
			Lv(LI2DI2), Lv(RID), LI2DI2, LI2DI2, Lv(RID), RID,
			Lv(RDI), Lv(RI2UI2), RDI, RDI, Lv(RI2UI2), RI2UI2,
			Lv(CTR), Lv(LI2DI2), Mh3(LI2DI2), LD, Mh3(LI2DI2), LI2DI2,
			Lv(RI2UI2), Lv(CTR), Mh3(RI2UI2), Mh3(RI2UI2), RU, RI2UI2
		);
	}
	else if (szPattern == "a_a") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(CTR), Lv(LD, 0, 1), Lv(CTR), Lv(RD, 1, 1),
			Lv(LU), Lv(CTR), Lv(LUI), Lv(LUI), Lv(CTR), Lv(LI2DI2), LUI, LI2DI2, LD,
			Lv(CTR), Lv(RI2UI2), Lv(RDI), Lv(CTR), Lv(RDI), Lv(RD), RI2UI2, RU, RDI,
			Lv(LUI), Lv(LI2DI2), LUI, LUI, Lv(LI2DI2), LI2DI2,
			Lv(RDI), Lv(RI2UI2), RDI, RDI, Lv(RI2UI2), RI2UI2,
			Lv(LI2DI2), Lv(CTR), Mh3(LI2DI2), Mh3(LI2DI2), LD, LI2DI2,
			Lv(RI2UI2), Lv(CTR), Mh3(RI2UI2), Mh3(RI2UI2), RU, RI2UI2
		);
	}
	else if (szPattern == "a_b") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(CTR), Lv(LU, 1, 1), Lv(RD, 1, 1), Lv(LD, 0, 1),
			Lv(CTR), Lv(RI2UI2), Lv(RDI), Lv(CTR), Lv(RDI), Lv(RD), RI2UI2, RU, RDI,
			Lv(RDI), Lv(RI2UI2), RDI, RDI, Lv(RI2UI2), RI2UI2,
			Lv(RI2UI2), Lv(CTR), Mh3(RI2UI2), Mh3(RI2UI2), RU, RI2UI2
		);
	}
	else if (szPattern == "a_c") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(RD, 1, 1),
			Lv(LU), Lv(CTR), Lv(LUI), Lv(LUI), Lv(CTR), Lv(RID), Lv(CTR), Lv(RD), Lv(RID),
			Lv(LUI), Lv(RID), LUI, LUI, Lv(RID), RID, LUI, RID, LD
		);
	}
	else if (szPattern == "a_d") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(RD, 1, 1), Lv(LU, 1, 1), Lv(CTR, 1, 1), Lv(LD, 0, 1),
			Lv(CTR), Lv(RD), Lv(RID), Lv(CTR), Lv(RID), Lv(LI2DI2), LI2DI2, RID, LD,
			Lv(LI2DI2), Lv(RID), LI2DI2, LI2DI2, Lv(RID), RID,
			Lv(CTR), Lv(LI2DI2), Mh3(LI2DI2), LD, Mh3(LI2DI2), LI2DI2
		);
	}
	else if (szPattern == "a_e") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(RD, 1, 1), Lv(LD, 0, 1), Lv(CTR, 1, 1), Lv(RD, 1, 1),
			Lv(LU), Lv(CTR), Lv(LUI), Lv(LUI), Lv(CTR), Lv(LI2DI2), LUI, LI2DI2, LD,
			Lv(LUI), Lv(LI2DI2), LUI, LUI, Lv(LI2DI2), LI2DI2,
			Lv(LI2DI2), Lv(CTR), Mh3(LI2DI2), Mh3(LI2DI2), LD, LI2DI2
		);
	}
	else if (szPattern == "a_f") {
		CollVertData(Lv(LU, 1, 1), Lv(RU, 0, 1), Lv(RD, 1, 1), Lv(LU, 1, 1), Lv(RD, 1, 1), Lv(LD, 0, 1));
	}
	else if (szPattern == "aa_0") {
		CollVertData(Lv(LU, 2), Lv(LIU, 2), Lv(LUI, 2), Lv(LUI, 2), Lv(LIU, 2), Lv(RID, 2), Lv(RID, 2), Lv(LIU, 2), Lv(RDI, 2), Lv(RID, 2), Lv(RDI, 2), Lv(RD, 2),
			Lv(LUI, 2), Lv(RID, 2), LUI, LUI, Lv(RID, 2), RID,
			Lv(RDI, 2), Lv(LIU, 2), RDI, RDI, Lv(LIU, 2), LIU,
			LUI, RID, LD,
			LIU, RU, RDI
		);
	}
	else if (szPattern == "aaa_0") {
		CollVertData(Lv(LU, 3), Lv(LIU, 3), Lv(LUI, 3), Lv(LUI, 3), Lv(LIU, 3), Lv(RID, 3), Lv(RID, 3), Lv(LIU, 3), Lv(RDI, 3), Lv(RID, 3), Lv(RDI, 3), Lv(RD, 3),
			Lv(LUI, 3), Lv(RID, 3), LUI, LUI, Lv(RID, 3), RID,
			Lv(RDI, 3), Lv(LIU, 3), RDI, RDI, Lv(LIU, 3), LIU,
			LUI, RID, LD,
			LIU, RU, RDI
		);
	}
	else
	{
		CollVertData(LU, RU, LD, LD, RU, RD);
		//Utility.DebugText(szPattern + "不存在");
		//else if(szPattern == "1"
	}
}

template<typename Vector4,typename ... Args> 
void AMazeBuilderBrushTemplate::CollVertData(Vector4 vec,Args ... args)
{
	CollVertData(vec);
	CollVertData(args...); // 递归调用
}

template<typename Vector4>
void AMazeBuilderBrushTemplate::CollVertData(Vector4 vec)
{
	vertList.Insert(vec.ToVector(),0);
	//normalList.Add_normal);
	FColor color = ColorArr[(vec.w)];
	color = FColor::White; // 测试代码，先不管顶点色
	colorList.Add(color);
	triList.Add(gTriIndex++);
}

Vector4 AMazeBuilderBrushTemplate::Lv(Vector4 point, int level, int ColorIndex)
{
	return point + Vector4(0, 0, level * levelHeight, ColorIndex);
}

Vector4 AMazeBuilderBrushTemplate::Mh3(Vector4 point)
{
	return point + Vector4(0, 0, -(1 - cornerSize / gridSize) * levelHeight, 0);
}

Vector4 AMazeBuilderBrushTemplate::Mh7(Vector4 point)
{
	return point + Vector4(0, 0, -(1 - (2 * cornerSize / gridSize)) * levelHeight,0);
}

void AMazeBuilderBrushTemplate::InitPoints()
{
	/*Unity是右手坐标系，Max也是右手坐标系，Unreal是左手坐标系*/
	/*
	LU = Vector4(gridSize / 2, 0, -gridSize / 2);
	LD = Vector4(gridSize / 2, 0, gridSize / 2);
	RU = Vector4(-gridSize / 2, 0, -gridSize / 2);
	RD = Vector4(-gridSize / 2, 0, gridSize / 2);

	LIU = LU - Vector4(cornerSize, 0, 0);
	RIU = RU + Vector4(cornerSize, 0, 0);
	LID = LD - Vector4(cornerSize, 0, 0);
	RID = RD + Vector4(cornerSize, 0, 0);

	LUI = LU + Vector4(0, 0, cornerSize);
	LDI = LD - Vector4(0, 0, cornerSize);
	RUI = RU + Vector4(0, 0, cornerSize);
	RDI = RD - Vector4(0, 0, cornerSize);

	LIUI = LU + Vector4(-cornerSize, 0, cornerSize);
	RIUI = RU + Vector4(cornerSize, 0, cornerSize);
	LIDI = LD + Vector4(-cornerSize, 0, -cornerSize);
	RIDI = RD + Vector4(cornerSize, 0, -cornerSize);

	CTR = Vector4();

	RI2DI2 = CTR + Vector4(-0.5f * cornerSize, 0, 0.5f * cornerSize, 0);
	LI2DI2 = CTR + Vector4(0.5f * cornerSize, 0, 0.5f * cornerSize, 0);
	RI2UI2 = CTR - Vector4(0.5f * cornerSize, 0, 0.5f * cornerSize, 0);
	LI2DI = LIDI - Vector4(cornerSize, 0, 0, 0);
	RIUI2 = RIU + Vector4(0, 0, 2 * cornerSize, 0);
	*/
	// 切换 x = x,y = -z,z = y
	LU = Vector4(gridSize / 2, gridSize / 2, 0);
	LD = Vector4(gridSize / 2, -gridSize / 2, 0);
	RU = Vector4(-gridSize / 2, gridSize / 2, 0);
	RD = Vector4(-gridSize / 2, -gridSize / 2, 0);

	LIU = LU - Vector4(cornerSize, 0, 0);
	RIU = RU + Vector4(cornerSize, 0, 0);
	LID = LD - Vector4(cornerSize, 0, 0);
	RID = RD + Vector4(cornerSize, 0, 0);

	LUI = LU + Vector4(0, -cornerSize, 0);
	LDI = LD - Vector4(0, -cornerSize, 0);
	RUI = RU + Vector4(0, -cornerSize, 0);
	RDI = RD - Vector4(0, -cornerSize, 0);

	LIUI = LU + Vector4(-cornerSize, -cornerSize,0);
	RIUI = RU + Vector4(cornerSize, -cornerSize,0);
	LIDI = LD + Vector4(-cornerSize, cornerSize,0);
	RIDI = RD + Vector4(cornerSize, cornerSize,0);

	CTR = Vector4();

	RI2DI2 = CTR + Vector4(-0.5f * cornerSize, -0.5f * cornerSize, 0, 0);
	LI2DI2 = CTR + Vector4(0.5f * cornerSize, -0.5f * cornerSize,0, 0);
	RI2UI2 = CTR - Vector4(0.5f * cornerSize, -0.5f * cornerSize,0, 0);
	LI2DI = LIDI - Vector4(cornerSize, 0, 0, 0);
	RIUI2 = RIU + Vector4(0, -2 * cornerSize, 0,0);

	vertList.Empty();
	colorList.Empty();
	triList.Empty();
	gTriIndex = 0;
	pattern = FMazeBuilderUltility::GetStrokeCode(this->GetName());
	path = FMazeBuilderUltility::GetPathCode(this->GetName());
}

void AMazeBuilderBrushTemplate::CreateMesh(FString szpattern)
{
	vertList.Empty();
	triList.Empty();
	uvList.Empty();
	colorList.Empty();
	//meshColorsCheck.Empty();
	InitPoints();
	CollectMeshData(szpattern);
	FOccluderVertexArray meshVertices = FOccluderVertexArray(vertList, vertList.Num());
	FOccluderVertexArray meshNormals = FOccluderVertexArray();
	TArray<FProcMeshTangent> meshTangent;
	mesh->CreateMeshSection(0, meshVertices, triList, meshNormals, uvList, colorList, meshTangent, true);
	//Material = CreateEditorOnlyDefaultSubobject<UMaterialInterface>("VertexColor", true);
	//mesh->SetMaterial(0, Material);
	//mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_EngineTraceChannel2, ECollisionResponse::ECR_Block);
	mesh->SetCollisionObjectType(ECollisionChannel::ECC_EngineTraceChannel2);
}

// Called when the game starts or when spawned
void AMazeBuilderBrushTemplate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMazeBuilderBrushTemplate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

