// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBullet.h"


// Sets default values
AMyBullet::AMyBullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Initialize var--------------------------------------------------------------------------------------------
	started = false;
	anim_duration = 5;
	height = 25;
	forward_dist = 150;
	FlyTraectory = CreateDefaultSubobject<USplineComponent>(TEXT("Traectory"));
	FlyTraectory->ClearSplinePoints();
	
	rotation_speed = 20;
	Roll.Add(0.0f, (0.0f + rotation_speed), 0.0f);
	//Initialize var--------------------------------------------------------------------------------------------

	
	//timeline setting------------------------------------------------------------------------------------------
	static ConstructorHelpers::FObjectFinder<UCurveFloat> Curvy(TEXT("CurveFloat'/Game/MyBP/TimeCur.TimeCur'"));
	if (Curvy.Object) {
		fCurve = Curvy.Object;
	}

	ScoreTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineScore"));
	
	//Bind the Callbackfuntion for the float return value
	InterpFunction.BindUFunction(this, FName{ TEXT("TimelineFloatReturn") });
	//timeline setting------------------------------------------------------------------------------------------


	// adding components----------------------------------------------------------------------------------------
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	ConeScene = CreateDefaultSubobject<USceneComponent>(TEXT("ConeScene"));
	ConeScene->SetupAttachment(RootComponent);
	
	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	Collision->OnComponentHit.AddDynamic(this, &AMyBullet::OnHit);
	Collision->SetupAttachment(ConeScene);

	Collision->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	Collision->CanCharacterStepUpOn = ECB_No;
		
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	if (Mesh.Object)
		BulletMesh->SetStaticMesh(Mesh.Object);
	BulletMesh->SetupAttachment(Collision);
	// adding components----------------------------------------------------------------------------------------
}

void AMyBullet::SetAim(FVector AimLoc, FVector ForwardVec)
{
	//Set Traectory to Aim--------------------------------------------------------------------------------------
	SpawnLocation = this->GetActorLocation();
	AimLocation = AimLoc;
	FVector ForwardPoint;

	//add points to spline
	FlyTraectory->ClearSplinePoints();

	FlyTraectory->AddSplinePointAtIndex(SpawnLocation, 0, ESplineCoordinateSpace::World);
	FlyTraectory->SetSplinePointType(0, ESplinePointType::Linear);

	ForwardPoint = SpawnLocation + ForwardVec * forward_dist;
	ForwardPoint.Z += height / 4;
	FlyTraectory->AddSplinePointAtIndex(ForwardPoint, 1, ESplineCoordinateSpace::World);
	FlyTraectory->SetSplinePointType(1, ESplinePointType::Curve);

	MidLocation.Set((AimLocation.X + SpawnLocation.X) / 2, (AimLocation.Y + SpawnLocation.Y) / 2, (AimLocation.Z + SpawnLocation.Z) / 2 + height);
	FlyTraectory->AddSplinePointAtIndex(MidLocation, 2, ESplineCoordinateSpace::World);//add height
	FlyTraectory->SetSplinePointType(2, ESplinePointType::Curve);

	FlyTraectory->AddSplinePointAtIndex(AimLocation, 3, ESplineCoordinateSpace::World);
	FlyTraectory->SetSplinePointType(3, ESplinePointType::Curve);
	//Set Traectory to Aim--------------------------------------------------------------------------------------

	started = true;

	ScoreTimeline->SetTimelineLength(1);
	ScoreTimeline->SetPlayRate(anim_duration);
	ScoreTimeline->Play();

	Collision->UpdateBodySetup();

	//Roll.Add(0.0f, 0.0f, (0.0f + rotation_speed));

	// rotate scene to aim

	ConeScene->SetWorldTransform(this->GetActorTransform());
}

// Called when the game starts or when spawned
void AMyBullet::BeginPlay()
{
	Super::BeginPlay();

	//Add the float curve to the timeline and connect it to your timelines's interpolation function
	ScoreTimeline->AddInterpFloat(fCurve, InterpFunction, FName{ TEXT("Floaty") });
}

// Called every frame
void AMyBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//ConeScene->AddLocalRotation(Roll);
}

//Your Callback Function for the timeline float value
void AMyBullet::TimelineFloatReturn(float time)
{
	//Your float val from curve returns here
	if (started)
	{
		ConeScene->SetWorldTransform(FlyTraectory->GetTransformAtTime(time, ESplineCoordinateSpace::World));
		BulletMesh->AddLocalRotation(Roll);
	}
	if (time == 1)
		BangEffect();
}

void AMyBullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	//if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	//{
	//	OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

	//	this->BangEffect();
	//}	
}

void AMyBullet::BangEffect()
{
	if (WeaponHitEffect != NULL)
	{
		FRotator Norm(180, 180, 180);

		//Spawn particle at impact
		UGameplayStatics::SpawnEmitterAtLocation(
			GetWorld(),
			WeaponHitEffect,
			ConeScene->GetComponentLocation(),
			ConeScene->GetComponentRotation() - Norm);
	}
	if (BangSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(ConeScene, BangSound, ConeScene->GetComponentLocation());
	}

	Destroy();
}