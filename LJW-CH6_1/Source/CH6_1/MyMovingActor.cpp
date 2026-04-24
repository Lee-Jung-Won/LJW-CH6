#include "MyMovingActor.h"

AMyMovingActor::AMyMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	PlusMinusDirect = 1.f;
	MoveSpeed = 1.f;
	PlusMoveDist = 0.f;
	OnOff = true;
}

void AMyMovingActor::SetGoActor()
{
	(OnOff) ? OnOff = false : OnOff = true;
}

void AMyMovingActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(StartLocation);
	GetWorldTimerManager().SetTimer(
		Timer,
		this,
		&AMyMovingActor::SetGoActor,
		3.0f,
		true,
		2.0f
	);
}

void AMyMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (OnOff)
	{
		float DeltaMove = MoveSpeed * DeltaTime;
		PlusMoveDist += DeltaMove;

		if (PlusMoveDist >= MaxRange)
		{
			PlusMinusDirect *= -1;
			PlusMoveDist = 0.0f;
		}

		AddActorLocalOffset(FVector(0.0f, OnOff * PlusMinusDirect * DeltaMove, 0.0f));
	}
}

