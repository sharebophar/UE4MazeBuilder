// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "MazeBuilderUltility.h"
#include "MazeBuilderBrushTemplate.generated.h"

USTRUCT()
struct MAZEBUILDER_API FCollectCode
{
	GENERATED_BODY()
public:
	float x;
	float y;
	float z;
	int w;

	FCollectCode()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}

	FCollectCode(float x, float y, float z, int w = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	FCollectCode operator+(const FCollectCode& other)
	{
		FCollectCode v;
		v.x = this->x + other.x;
		v.y = this->y + other.y;
		v.z = this->z + other.z;
		v.w = this->w + other.w;
		return v;
	}

	int operator[](const int& index)
	{
		if (index == 0) return (int)(this->x);
		else if (index == 1) return (int)(this->y);
		else if (index == 2) return (int)(this->z);
		else if (index == 3) return this->w;
		else return 0;
	}

	FCollectCode operator-(const FCollectCode& other)
	{
		FCollectCode v;
		v.x = this->x - other.x;
		v.y = this->y - other.y;
		v.z = this->z - other.z;
		v.w = this->w - other.w;
		return v;
	}

	FVector ToVector()
	{
		return FVector(x, y, z);
	}
};

UCLASS()
class MAZEBUILDER_API AMazeBuilderBrushTemplate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeBuilderBrushTemplate();
	//UPROPERTY(VisibleAnyWhere)
	//UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditInstanceOnly,Category="MazeBuilder")
	float gridSize = 100.0f;
	UPROPERTY(EditInstanceOnly, Category = "MazeBuilder")
	float cornerSize = 30.0f;
	UPROPERTY(EditInstanceOnly, Category = "MazeBuilder")
	float levelHeight = 50.0f;
	UPROPERTY(EditAnywhere, Category = "MazeBuilder")
	bool bShowProceduralMesh = true;
	//在场景中生成的对象时，用该name记录stroke的衍生模板名字,调试时临时打开
	UPROPERTY(VisibleInstanceOnly, Category = "MazeBuilder")
	FString name = "";
	FString pattern = "0";
	UPROPERTY(VisibleInstanceOnly, Category = "MazeBuilder")
	FString path = "0";
	UPROPERTY()
	FCollectCode LU;
	FCollectCode LIU;
	FCollectCode RIU;
	FCollectCode RU;
	FCollectCode RUI;
	FCollectCode RDI;
	FCollectCode RD;
	FCollectCode RID;
	FCollectCode LID;
	FCollectCode LD;
	FCollectCode LDI;
	FCollectCode LUI;
	FCollectCode LIUI;
	FCollectCode RIUI;
	FCollectCode LIDI;
	FCollectCode RIDI;
	FCollectCode CTR;

	// 7系列的参数
	FCollectCode LI2DI;
	FCollectCode RI2DI2;
	FCollectCode RIUI2;
	//a系列参数
	FCollectCode RI2UI2;
	FCollectCode LI2DI2;

	TArray<FColor> ColorArr; //不同阶层的颜色常量

	TArray<FVector> vertList;
	TArray<FVector2D> uvList;
	TArray<FColor> colorList;
	TArray<int> triList;
	int gTriIndex = 0;
	UProceduralMeshComponent* mesh;
	/**
	* 根据pattern规则创建不同的顶点序列
	* T_1_1_0表示terrain的1笔刷的1路径的0样式
	* W_1_0_1表示wall 的1笔刷的0路径的1样式
	* F_1_0_1表示fence的1笔刷的0路径的1样式,fence 是矮墙
	* H_1_0_1表示hole 的1笔刷的0路径的1样式
	* 诸如此类
	* x正方向为←，Z正方向为↓，三角形顺时针方向
	*/
	void CollectMeshData(FString szPattern);

	//为了解决嵌套层太多的问题将创建函数拆分成两个函数
	void CollectBaseMeshData(FString szPattern);
	void CollectCompleteMeshData(FString szPattern);

	template<typename FCollectCode,typename ... Args> void CollVertData(FCollectCode vec,Args ... args);
	template<typename FCollectCode> void CollVertData(FCollectCode vec);
	//LevelUp 将点提升一个高度
	FCollectCode Lv(FCollectCode point, int level = 1, int ColorIndex = 0);

	//计算高度的中间点,用于斜坡的绘制
	FCollectCode Mh3(FCollectCode point);

	FCollectCode Mh7(FCollectCode point);

	void InitPoints();

	void CreateMesh();

	void UpdateMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void OnConstruction(const FTransform& Transform) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
