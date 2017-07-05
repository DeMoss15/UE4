//// Fill out your copyright notice in the Description page of Project Settings.
//
//#include "MyTraectory.h"
//
//
//// Sets default values
//AMyTraectory::AMyTraectory()
//{
// 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//	//Initialize var--------------------------------------------------------------------------------------------
//	started = false;
//	anim_duration = 0.1;
//	height = 25;
//	FlyTraectory = CreateDefaultSubobject<USplineComponent>(TEXT("Traectory"));
//	//Initialize var--------------------------------------------------------------------------------------------
//
//
//	//timeline setting------------------------------------------------------------------------------------------
//	static ConstructorHelpers::FObjectFinder<UCurveFloat> Curvy(TEXT("CurveFloat'/Game/MyBP/TimeCur.TimeCur'"));
//	if (Curvy.Object) {
//		fCurve = Curvy.Object;
//	}
//
//	ScoreTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineScore"));
//	ScoreTimeline->SetPlayRate(anim_duration);
//
//	//Bind the Callbackfuntion for the float return value
//	InterpFunction.BindUFunction(this, FName{ TEXT("TimelineFloatReturn") });
//	//timeline setting------------------------------------------------------------------------------------------
//}
//
//void AMyTraectory::Start(AMyBullet* pActr, FVector AimLoc)
//{
//	//Initialize var--------------------------------------------------------------------------------------------
//	//time = 0;
//	Actr = pActr;
//		
//	//Set Traectory to Aim--------------------------------------------------------------------------------------
//	SpawnLocation = Actr->GetActorLocation();
//	AimLocation = AimLoc;
//
//	//add points to spline
//	FlyTraectory->AddSplineWorldPoint(SpawnLocation);
//	FlyTraectory->SetSplinePointType(0, ESplinePointType::Linear);
//
//	MidLocation.Set((AimLocation.X + SpawnLocation.X) / 2, (AimLocation.Y + SpawnLocation.Y) / 2, (AimLocation.Z + SpawnLocation.Z) / 2 + height);
//	FlyTraectory->AddSplineWorldPoint(MidLocation);//add height
//	FlyTraectory->SetSplinePointType(1, ESplinePointType::Curve);
//
//	FlyTraectory->AddSplineWorldPoint(AimLocation);
//	FlyTraectory->SetSplinePointType(2, ESplinePointType::Linear);
//	//Set Traectory to Aim--------------------------------------------------------------------------------------
//
//	started = true;
//
//	ScoreTimeline->PlayFromStart();
//}
//
//// Called when the game starts or when spawned
//void AMyTraectory::BeginPlay()
//{
//	Super::BeginPlay();
//	
//	//Add the float curve to the timeline and connect it to your timelines's interpolation function
//	ScoreTimeline->AddInterpFloat(fCurve, InterpFunction, FName{ TEXT("Floaty") });
//
//	// Start your Timeline or PlayFromStart() etc, can be called anywhere in this class
//	ScoreTimeline->Play();
//}
//
//// Called every frame
//void AMyTraectory::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
////Your Callback Function for the timeline float value
//void AMyTraectory::TimelineFloatReturn(float time)
//{
//	//Your float val from curve returns here
//	if (started)
//	{
//		NewPosition.SetTranslation(FlyTraectory->GetLocationAtTime(time, ESplineCoordinateSpace::World));
//		NewPosition.SetRotation((FQuat)FlyTraectory->GetRotationAtTime(time, ESplineCoordinateSpace::World));
//		Actr->AddActorWorldTransform(NewPosition);
//	}
//}