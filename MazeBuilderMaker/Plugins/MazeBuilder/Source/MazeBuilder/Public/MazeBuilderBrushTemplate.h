// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "MazeBuilderUltility.h"
#include "MazeBuilderBrushTemplate.generated.h"

class Vector4
{
public:
	float x;
	float y;
	float z;
	int w;

	Vector4()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}

	Vector4(float x, float y, float z, int w = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vector4 operator+(const Vector4& other)
	{
		Vector4 v;
		v.x = this->x + other.x;
		v.y = this->y + other.y;
		v.z = this->z + other.z;
		v.w = this->w + other.w;
		return v;
	}

	int operator[](const int& index)
	{
		Vector4 v;
		if (index == 0) return (int)(v.x);
		else if (index == 1) return (int)(v.y);
		else if (index == 2) return (int)(v.z);
		else if (index == 3) return v.w;
		else return 0;
	}

	Vector4 operator-(const Vector4& other)
	{
		Vector4 v;
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
	UPROPERTY(EditInstanceOnly)
	float gridSize = 100.0f;
	UPROPERTY(EditInstanceOnly)
	float cornerSize = 30.0f;
	UPROPERTY(EditInstanceOnly)
	float levelHeight = 50.0f;
	FString pattern = "0";
	FString path = "0";
	Vector4 LU;
	Vector4 LIU;
	Vector4 RIU;
	Vector4 RU;
	Vector4 RUI;
	Vector4 RDI;
	Vector4 RD;
	Vector4 RID;
	Vector4 LID;
	Vector4 LD;
	Vector4 LDI;
	Vector4 LUI;
	Vector4 LIUI;
	Vector4 RIUI;
	Vector4 LIDI;
	Vector4 RIDI;
	Vector4 CTR;

	// 7系列的参数
	Vector4 LI2DI;
	Vector4 RI2DI2;
	Vector4 RIUI2;
	//a系列参数
	Vector4 RI2UI2;
	Vector4 LI2DI2;

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

	template<typename Vector4,typename ... Args> void CollVertData(Vector4 vec,Args ... args);
	template<typename Vector4> void CollVertData(Vector4 vec);
	//LevelUp 将点提升一个高度
	Vector4 Lv(Vector4 point, int level = 1, int ColorIndex = 0);

	//计算高度的中间点,用于斜坡的绘制
	Vector4 Mh3(Vector4 point);

	Vector4 Mh7(Vector4 point);

	void InitPoints();

	void CreateMesh(FString pattern);

	//void UpdateMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void OnConstruction(const FTransform& Transform) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
