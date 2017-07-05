//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "MyBullet.h"
//#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
//#include "Runtime/Engine/Classes/Components/SplineComponent.h"
//#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
//#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
//#include "MyTraectory.generated.h"
//
//UCLASS()
//class HOMEWORK_API AMyTraectory : public AActor
//{
//	GENERATED_BODY()
//	
//public:	
//	// Sets default values for this actor's properties
//	AMyTraectory();
//	void Start(AMyBullet* pActr, FVector AimLoc);
//
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//	//variables---------------------------------------------
//	AMyBullet* Actr;
//	FVector SpawnLocation;
//	FVector AimLocation;
//	FVector MidLocation;
//	FTransform NewPosition;
//	const FVector SpawnRotatorVec;
//	const FRotator SpawnRotator;
//	float time;
//	bool started;
//	//-------------------------------------------------------
//
//
//	//timeline-----------------------------------------------
//	UPROPERTY()
//	UTimelineComponent* ScoreTimeline;
//
//	UPROPERTY()
//	UCurveFloat* fCurve;
//
//	FOnTimelineFloat InterpFunction{};
//
//	UFUNCTION()
//	void TimelineFloatReturn(float time);
//	//--------------------------------------------------------
//
//
//	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
//	USplineComponent* FlyTraectory;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//	UPROPERTY(EditAnywhere, Category = "MyVar")
//		float height;
//
//	UPROPERTY(EditAnywhere, Category = "MyVar")
//		float anim_duration;
//
//	
//};
