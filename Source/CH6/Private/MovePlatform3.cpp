// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePlatform3.h"

// Sets default values
AMovePlatform3::AMovePlatform3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	///Script/Engine.StaticMesh'/Game/UtopianCity/Meshes/SM_Square10m.SM_Square10m'
	///Script/Engine.MaterialInstanceConstant'/Game/UtopianCity/Materials/MI_ColoredGlass05.MI_ColoredGlass05'
	/// 
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMeshComponent->SetupAttachment(SceneComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SetSM(TEXT("/Game/UtopianCity/Meshes/SM_Square10m.SM_Square10m"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> SetMat(TEXT("/Game/UtopianCity/Materials/MI_ColoredGlass05.MI_ColoredGlass05"));

	if (SetSM.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(SetSM.Object);
	}

	if (SetMat.Succeeded())
	{
		StaticMeshComponent->SetMaterial(0, SetMat.Object);
	}

	SetActorScale3D(FVector(0.45f, 0.45f, 0.65f));
	MoveRange = 250;
	MoveSpeed = 100.0f;
	MoveDisAmount = 300.0f;
}

// Called when the game starts or when spawned
void AMovePlatform3::BeginPlay()
{
	Super::BeginPlay();
	StartLoc = FVector(GetActorLocation());

	GetWorld()->GetTimerManager().SetTimer(
		Timeistickingg,
		this,
		&AMovePlatform3::MoveDisPlatform,
		3.0f,
		true
	);
}

void AMovePlatform3::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

	Super::EndPlay(EndPlayReason);
}

void AMovePlatform3::MoveDisPlatform()
{
	FVector ChangedLoc = GetActorLocation();
	ChangedLoc.Y += MoveDisAmount;
	SetActorLocation(ChangedLoc);
	MoveDisAmount = -MoveDisAmount;
}

// Called every frame
void AMovePlatform3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorWorldOffset(FVector(0.0f, 0.0f, MoveSpeed) * DeltaTime);
	if (FMath::Abs(GetActorLocation().Z - StartLoc.Z) >= MoveRange)
	{
		StartLoc = GetActorLocation();
		MoveSpeed = -MoveSpeed;
	}
	
}

void AMovePlatform3::SetMoveSpeed(int32 newspeed)
{
	MoveSpeed = newspeed;
}

