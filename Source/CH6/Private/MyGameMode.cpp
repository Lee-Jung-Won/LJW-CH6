// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "MovePlatform3.h"

AMyGameMode::AMyGameMode()
{
	many = 5;
}

void AMyGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	float RandX;
	float RandY;
	float RandZ = 2500.0f;
	int32 RandSpeed;

	for (int i = 0; i < many; i++)
	{
		RandX = FMath::FRandRange(6000.0f, 7000.0f);
		RandY = FMath::FRandRange(8100.0f, 11000.0f);
		RandSpeed = FMath::RandRange(0,500);

		AMovePlatform3* NewActor = GetWorld()->SpawnActor<AMovePlatform3>(
			AMovePlatform3::StaticClass(),
			FVector(RandX, RandY, RandZ),
			FRotator::ZeroRotator
		);
		NewActor->SetMoveSpeed(RandSpeed);
		ListSpawnPlatform.Add(NewActor);
	}
}

void AMyGameMode::StartToLeaveMap()
{
	for (int j = 0; j < many; j++)
	{
		ListSpawnPlatform[j]->Destroy();
	}
	Super::StartToLeaveMap();
}
