// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovePlatform.generated.h"

UCLASS()
class CH6_API AMovePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void EndPlay(EEndPlayReason::Type EndPlayReason) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomInfo")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomInfo", meta=(DisplayName = "MeshComp", ToolTip = "Rot Actor Mesh"))
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomInfo", meta=(DisplayName = "HowManyRot", ClampMin = "0", ClampMax = "300", Tooltip = "Rot: 0~300"))
	int32 RotateValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomInfo", meta = (DisplayName = "HowManyRot", ClampMin = "0", ClampMax = "60", Tooltip = "Time: 0~60"))
	FTimerHandle Timeisticking;

	UFUNCTION()
	void DisappearPlatform();

	//bluprintcallable : 블루프린트에서 호출가능
	//blueprintpure : 블루프린트에서 값만 반환(실행핀x)
	//blueprintimplementableevent : 블루프린트에서 구현
	//blueprintnativeevent : C++기본구현 + 블루프린트에서 확장
	//category="" : 메뉴분류
	//callineditor : 에디터에서 버튼처럼 실행가능

public:	
	// Called every frame
	float totaltime;
	//float distance;
	//AActor* FoundStart;

	virtual void Tick(float DeltaTime) override;
};
