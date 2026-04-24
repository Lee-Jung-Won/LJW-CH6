#include "MyMovingActor.h"

AMyMovingActor::AMyMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMyMovingActor::SetGoActor()
{
	float DeltaTime = GetWorld()->DeltaTimeSeconds;

	if (GetActorLocation().Y >= (StartLocation.Y + MaxRange) ||
		GetActorLocation().Y <= (StartLocation.Y - MaxRange))
	{
		MoveSpeed = -MoveSpeed;
	}

	AddActorLocalOffset(FVector(0.0f, MoveSpeed * DeltaTime, 0.0f));
}

void AMyMovingActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(StartLocation);
	GetWorldTimerManager().SetTimer(
		Timer,
		this,
		&AMyMovingActor::SetGoActor,
		0.01f,
		true,
		2.0f
	);
}

void AMyMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

