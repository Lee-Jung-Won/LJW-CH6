// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorBase.h"
#include "MyActorRotate.generated.h"

UCLASS()
class CH6_1_API AMyActorRotate
	: public AMyActorBase
{
	GENERATED_BODY()
	
public:	
	AMyActorRotate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotate")
	FRotator Rotate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotate")
	float Speed;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
