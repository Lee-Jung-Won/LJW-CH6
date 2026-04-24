#include "MyActorRotate.h"

AMyActorRotate::AMyActorRotate()
{
	PrimaryActorTick.bCanEverTick = true;
	Rotate = FRotator::ZeroRotator;
	Speed = 0.f;
}

void AMyActorRotate::BeginPlay()
{
	Super::BeginPlay();
}

void AMyActorRotate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(Rotate * DeltaTime * Speed);

}

