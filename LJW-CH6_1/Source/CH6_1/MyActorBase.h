#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorBase.generated.h"

class USceneComponent;
class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class CH6_1_API AMyActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActorBase();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> SceneRootComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBoxComponent> BoxComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
};
