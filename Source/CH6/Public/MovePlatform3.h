// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovePlatform3.generated.h"

UCLASS()
class CH6_API AMovePlatform3 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovePlatform3();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CustomInfo")
	USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CustomInfo")
	UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomInfo", meta = (ClampMin = "0", ClampMax = "1000"))
	int32 MoveRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomInfo", meta = (ClampMin = "0", ClampMax = "500"))
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomInfo")
	FVector StartLoc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomInfo")
	FTimerHandle Timeistickingg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomInfo", meta = (ClampMin = "0"))
	int32 MoveDisAmount;
	UFUNCTION()
	void MoveDisPlatform();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetMoveSpeed(int32 newspeed);
};
