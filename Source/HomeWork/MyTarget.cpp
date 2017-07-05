// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTarget.h"


// Sets default values
AMyTarget::AMyTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

	MyComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyLight1 = CreateDefaultSubobject<USpotLightComponent>(TEXT("MyLight1"));
	MyLight2 = CreateDefaultSubobject<USpotLightComponent>(TEXT("MyLight2"));
	MyLight3 = CreateDefaultSubobject<USpotLightComponent>(TEXT("MyLight3"));
	MyLight4 = CreateDefaultSubobject<USpotLightComponent>(TEXT("MyLight4"));
	MyLight5 = CreateDefaultSubobject<USpotLightComponent>(TEXT("MyLight5"));
	MyLight6 = CreateDefaultSubobject<USpotLightComponent>(TEXT("MyLight6"));
	//MyLightsScene = CreateDefaultSubobject<USceneComponent>(TEXT("MyLightsScene"));
	
	RootComponent = Box;

	MyLight1->SetupAttachment(Box);
	MyLight2->SetupAttachment(Box);
	MyLight3->SetupAttachment(Box);
	MyLight4->SetupAttachment(Box);
	MyLight5->SetupAttachment(Box);
	MyLight6->SetupAttachment(Box);
	MyComponent->SetupAttachment(Box);
}

// Called when the game starts or when spawned
void AMyTarget::BeginPlay()
{
	Super::BeginPlay();

	aimed = false;
}

// Called every frame
void AMyTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//MyLightsScene->SetVisibility(aimed);
	MyLight1->SetVisibility(aimed);
	MyLight2->SetVisibility(aimed);
	MyLight3->SetVisibility(aimed);
	MyLight4->SetVisibility(aimed);
	MyLight5->SetVisibility(aimed);
	MyLight6->SetVisibility(aimed);
}

