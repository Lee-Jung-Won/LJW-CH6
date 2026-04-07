// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovePlatform2.generated.h"

UCLASS()
class CH6_API AMovePlatform2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovePlatform2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CustomInfo")
	USceneComponent* SceneComp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CustomInfo")
	UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomInfo")
	FVector StartWorldLoc;
	UPROPERTY(EditAnywhere, Category = "CustomInfo", meta = (ClampMin = "0", ClampMax = "20"))
	uint32 MoveSpeed;
	UPROPERTY(EditAnywhere, Category = "CustomInfo", meta = (ClampMin = "0", ClampMax = "1000"))
	uint32 MaxRange;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CustomInfo")
	float totaltime;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
