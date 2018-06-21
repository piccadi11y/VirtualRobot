// Fill out your copyright notice in the Description page of Project Settings.

#include "Chassis_Base.h"


// Sets default values
AChassis_Base::AChassis_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = ObjectMesh;

}

// Called when the game starts or when spawned
void AChassis_Base::BeginPlay()
{
	Super::BeginPlay();
	
	ObjectMesh->SetStaticMesh(MeshToUse_Self);
}

// Called every frame
void AChassis_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChassis_Base::Set_MeshToUSe_Self(UStaticMesh* Mesh) {
	MeshToUse_Self = Mesh;
}