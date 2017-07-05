// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SpotLightComponent.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "MyTarget.generated.h"

UCLASS()
class HOMEWORK_API AMyTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "MyComponents")
	UStaticMeshComponent* MyComponent;

	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "MyComponents")
	//USceneComponent* MyLightsScene;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "MyComponents")
	USpotLightComponent* MyLight1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "MyComponents")
	USpotLightComponent* MyLight2;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "MyComponents")
	USpotLightComponent* MyLight3;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "MyComponents")
	USpotLightComponent* MyLight4;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "MyComponents")
	USpotLightComponent* MyLight5;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "MyComponents")
	USpotLightComponent* MyLight6;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "MyComponents")
	UBoxComponent* Box;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	bool aimed;
	
};
