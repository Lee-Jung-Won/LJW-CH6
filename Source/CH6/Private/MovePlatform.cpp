// Fill out your copyright notice in the Description page of Project Settings.
#include "MovePlatform.h"
//#include "GameFramework/PlayerStart.h"
//#include "Kismet/GameplayStatics.h"


// Sets default values
AMovePlatform::AMovePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneRoot);
	///Script/Engine.StaticMesh'/Game/UtopianCity/Meshes/SM_FloorSquareThick.SM_FloorSquareThick'
	///Script/Engine.Material'/Game/Pack_Bonus/Materials/M_Pack_Bonus_Stone_1.M_Pack_Bonus_Stone_1'

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/UtopianCity/Meshes/SM_FloorSquareThick.SM_FloorSquareThick"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterailAsset1(TEXT("/Game/Pack_Bonus/Materials/M_Pack_Bonus_Stone_1.M_Pack_Bonus_Stone_1"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterailAsset2(TEXT("/Game/Pack_Bonus/Materials/M_Pack_Bonus_Wall_3.M_Pack_Bonus_Wall_3"));

	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}

	if (MaterailAsset1.Succeeded() && MaterailAsset2.Succeeded())
	{
		StaticMesh->SetMaterial(0, MaterailAsset1.Object);
		StaticMesh->SetMaterial(1, MaterailAsset2.Object);
	}
	
	//totaltime = 0.0f;
	//distance = 0.0f;
	RotateValue = 100;
}

// Called when the game starts or when spawned
void AMovePlatform::BeginPlay()
{
	Super::BeginPlay();

	//FoundStart = UGameplayStatics::GetActorOfClass(GetWorld(), APlayerStart::StaticClass());
	//if (!FoundStart)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("PlayerStart를 찾지 못했습니다."));
	//	return;
	//}

	GetWorldTimerManager().SetTimer(
		Timeisticking, // 정보를 담을 변수 > 나중에 콜
		this, // 클래스객체의 포인터 ex) AMyActor* Act 면 Act대입
		&AMovePlatform::DisappearPlatform, // 입력한객체의 함수이름 - AMyActor::Eat
		2.0f, // 주기(초)
		true, // 반복여부
		0.0f	// 첫실행 몇초후
	);
	// SetTimer() : regist
	// ClearTimer(timer변수) : stop
	// IsTimerActive(timer변수) : check running / T/F반환
	// pauseTimer(timer변수) / unpauseTimer() : pause/resume

}

void AMovePlatform::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	totaltime = 0.0f;
	Super::EndPlay(EndPlayReason);
}

void AMovePlatform::DisappearPlatform()
{
	static bool switchv = true;
	SetActorHiddenInGame(switchv);
	SetActorEnableCollision(!switchv);
	SetActorTickEnabled(!switchv);
	switchv = !switchv;
}

// Called every frame
void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	totaltime += DeltaTime;
	//distance = FVector::Dist(GetActorLocation(), FoundStart->GetActorLocation());
	AddActorLocalRotation(FRotator(0.0f, RotateValue * FMath::Sin(totaltime) * DeltaTime, 0.0f));


}

