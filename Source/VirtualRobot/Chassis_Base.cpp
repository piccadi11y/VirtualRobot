// Fill out your copyright notice in the Description page of Project Settings.

#include "Chassis_Base.h"


// Sets default values
AChassis_Base::AChassis_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* Setup components for the object. */
	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = ObjectMesh;

}

// Called when the game starts or when spawned
void AChassis_Base::BeginPlay()
{
	Super::BeginPlay();
	
	/* Set mesh and enable physics. */
	ObjectMesh->SetStaticMesh(MeshToUse_Self);
	ObjectMesh->SetSimulatePhysics(true);
}

// Called every frame
void AChassis_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChassis_Base::Set_MeshToUse_Self(UStaticMesh* Mesh) {
	/* Set pointer to mesh to use for self, to the pointer being passed through. */
	MeshToUse_Self = Mesh;
}

void AChassis_Base::AttachToLogicBoard(AActor* LB) {
	/* Attach self to the logic board passed through. */
	this->AttachToComponent(LB->GetRootComponent(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("Chassis_Socket"));
}
