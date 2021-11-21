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
	//�ڳ��������ɵĶ���ʱ���ø�name��¼stroke������ģ������,����ʱ��ʱ��
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

	// 7ϵ�еĲ���
	FCollectCode LI2DI;
	FCollectCode RI2DI2;
	FCollectCode RIUI2;
	//aϵ�в���
	FCollectCode RI2UI2;
	FCollectCode LI2DI2;

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

	template<typename FCollectCode,typename ... Args> void CollVertData(FCollectCode vec,Args ... args);
	template<typename FCollectCode> void CollVertData(FCollectCode vec);
	//LevelUp ��������һ���߶�
	FCollectCode Lv(FCollectCode point, int level = 1, int ColorIndex = 0);

	//����߶ȵ��м��,����б�µĻ���
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
