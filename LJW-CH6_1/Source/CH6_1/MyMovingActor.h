// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorBase.h"
#include "MyMovingActor.generated.h"

UCLASS()
class CH6_1_API AMyMovingActor : public AMyActorBase
{
	GENERATED_BODY()
	
public:	
	AMyMovingActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
	float MoveSpeed;
	float RealMoveSpeed;
	float PlusMoveDist;
	bool OnOff;
	int8 PlusMinusDirect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
	float MaxRange;

	UFUNCTION()
	void SetGoActor();
	UPROPERTY()
	FTimerHandle Timer;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
