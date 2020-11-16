// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "MazeBuilderBrushTemplate.generated.h"

class Vector4
{
public:
	float x;
	float y;
	float z;
	float w;

	Vector4()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}

	Vector4(float x, float y, float z, float w = 0)
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
	float gridSize = 1;
	UPROPERTY(EditInstanceOnly)
	float cornerSize = 0.3f;
	UPROPERTY(EditInstanceOnly)
	float levelHeight = 0.5f;
	UPROPERTY(EditInstanceOnly)
	FString pattern = "0";
	UPROPERTY(EditInstanceOnly)
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
	* s_1_1_0表示stage的1笔刷的1路径的0样式
	* w_1_0_1表示wall 的1笔刷的0路径的1样式
	* f_1_0_1表示fence的1笔刷的0路径的1样式
	* 诸如此类
	* x正方向为←，Z正方向为↓，三角形顺时针方向
	*/
	void CollectMeshData(FString szPattern);

	//为了解决嵌套层太多的问题将创建函数拆分成两个函数
	void CollectBaseMeshData(FString szPattern);
	void CollectCompleteMeshData(FString szPattern);

	void CollVertData(Vector4 pointArgs,...);
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
