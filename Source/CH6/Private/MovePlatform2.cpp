// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePlatform2.h"

// Sets default values
AMovePlatform2::AMovePlatform2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	///Script/Engine.StaticMesh'/Game/UtopianCity/Meshes/SM_Plane9x9LowPoly.SM_Plane9x9LowPoly'
	/// Script / Engine.Material'/Game/Pack_Bonus/Materials/M_Pack_Bonus_Wall_1.M_Pack_Bonus_Wall_1'
	///Script/Engine.Material'/Game/Pack_Bonus/Materials/M_Pack_Bonus_Wall_3.M_Pack_Bonus_Wall_3'
	/// /Script/Engine.Material'/Game/Pack_Bonus/Materials/M_Pack_Bonus_Stone_1.M_Pack_Bonus_Stone_1'
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(SceneComp);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Game/UtopianCity/Meshes/SM_Plane9x9LowPoly.SM_Plane9x9LowPoly"));
	static ConstructorHelpers::FObjectFinder<UMaterial> FindMat1(TEXT("/Game/Pack_Bonus/Materials/M_Pack_Bonus_Wall_1.M_Pack_Bonus_Wall_1"));

	if (FindMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(FindMesh.Object);
	}

	if (FindMat1.Succeeded())
	{
		MeshComp->SetMaterial(0, FindMat1.Object);
	}

	SetActorScale3D(FVector(0.5f, 0.5f, 1.5f));
	StartWorldLoc = FVector(5750.0f, 7400.0f, 2550.0f);
	MoveSpeed = 10;
	MaxRange = 500;
}

// Called when the game starts or when spawned
void AMovePlatform2::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(StartWorldLoc);
}

void AMovePlatform2::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	totaltime = 0.0f;
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AMovePlatform2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	totaltime += DeltaTime;
	//AddActorWorldTransform(FTransform(FRotator::ZeroRotator, FVector(0.0f,MaxRange * FMath::Sin(totaltime * MoveSpeed),0.0f), FVector(1.0f)));
	SetActorLocation(StartWorldLoc + FVector(0.0f, MaxRange * FMath::Sin(totaltime * MoveSpeed), 0.0f));
}

