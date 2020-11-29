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

	// 7ϵ�еĲ���
	Vector4 LI2DI;
	Vector4 RI2DI2;
	Vector4 RIUI2;
	//aϵ�в���
	Vector4 RI2UI2;
	Vector4 LI2DI2;

	TArray<FColor> ColorArr; //��ͬ�ײ����ɫ����

	TArray<FVector> vertList;
	TArray<FVector2D> uvList;
	TArray<FColor> colorList;
	TArray<int> triList;
	int gTriIndex = 0;
	UProceduralMeshComponent* mesh;
	/**
	* ����pattern���򴴽���ͬ�Ķ�������
	* T_1_1_0��ʾterrain��1��ˢ��1·����0��ʽ
	* W_1_0_1��ʾwall ��1��ˢ��0·����1��ʽ
	* F_1_0_1��ʾfence��1��ˢ��0·����1��ʽ,fence �ǰ�ǽ
	* H_1_0_1��ʾhole ��1��ˢ��0·����1��ʽ
	* �������
	* x������Ϊ����Z������Ϊ����������˳ʱ�뷽��
	*/
	void CollectMeshData(FString szPattern);

	//Ϊ�˽��Ƕ�ײ�̫������⽫����������ֳ���������
	void CollectBaseMeshData(FString szPattern);
	void CollectCompleteMeshData(FString szPattern);

	template<typename Vector4,typename ... Args> void CollVertData(Vector4 vec,Args ... args);
	template<typename Vector4> void CollVertData(Vector4 vec);
	//LevelUp ��������һ���߶�
	Vector4 Lv(Vector4 point, int level = 1, int ColorIndex = 0);

	//����߶ȵ��м��,����б�µĻ���
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
