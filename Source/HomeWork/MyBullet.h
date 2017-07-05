// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "MyTraectory.h"
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Core/Public/Math/TransformNonVectorized.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Components/SplineComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "Runtime/Core/Public/Math/Quat.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "GameFramework/Actor.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "MyBullet.generated.h"

UCLASS()
class HOMEWORK_API AMyBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBullet();
	void SetAim(FVector AimLoc);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//variables---------------------------------------------
	AMyBullet* Actr;
	FVector SpawnLocation;
	FVector AimLocation;
	FVector MidLocation;
	FTransform NewPosition;
	const FVector SpawnRotatorVec;
	const FRotator SpawnRotator;
	float time;
	bool started;
	//-------------------------------------------------------
		

	//timeline-----------------------------------------------
	UPROPERTY()
	UTimelineComponent* ScoreTimeline;

	UPROPERTY()
	UCurveFloat* fCurve;

	FOnTimelineFloat InterpFunction{};

	UFUNCTION()
	void TimelineFloatReturn(float time);
	//--------------------------------------------------------


	//components----------------------------------------------
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	USceneComponent* RootScene;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	USceneComponent* ConeScene;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* BulletMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	UCapsuleComponent* Collision;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	USplineComponent* FlyTraectory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* WeaponHitEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* BangSound;
	//--------------------------------------------------------


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "MyVar")
	float rotation_speed;

	UPROPERTY(EditAnywhere, Category = "MyVar")
	float height;

	UPROPERTY(EditAnywhere, Category = "MyVar")
	float anim_duration;

	UPROPERTY(EditAnywhere, Category = "MyVar")
	FRotator Roll;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void BangEffect();
};
