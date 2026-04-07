// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CH6_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AMyGameMode();

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void StartToLeaveMap() override;

	TArray<AActor*> ListSpawnPlatform;
	UPROPERTY()
	int32 many;
};
