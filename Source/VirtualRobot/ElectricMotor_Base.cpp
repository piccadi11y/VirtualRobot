// Fill out your copyright notice in the Description page of Project Settings.

#include "ElectricMotor_Base.h"


// Sets default values
AElectricMotor_Base::AElectricMotor_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* Create and setup object's components. */
	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = ObjectMesh;
	Tyre = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tyre"));
	Tyre->SetupAttachment(ObjectMesh, TEXT("Wheel"));
}

// Called when the game starts or when spawned
void AElectricMotor_Base::BeginPlay()
{
	Super::BeginPlay();
	
	/* Create meshes and enable physics. */
	ObjectMesh->SetStaticMesh(MeshToUse_Self);
	ObjectMesh->SetSimulatePhysics(true);
	Tyre->SetStaticMesh(MeshToUse_Tyre);
	Tyre->SetSimulatePhysics(true);
}

// Called every frame
void AElectricMotor_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/* Rotate the tyre. */
	Tyre->AddLocalRotation(FRotator(0.f, 1.f, 0.f));
}

void AElectricMotor_Base::Set_MeshToUse_Self(UStaticMesh* Mesh) {
	/* Set pointer to the mesh to be used for self, to the pointer passed in. */
	MeshToUse_Self = Mesh;
}

void AElectricMotor_Base::AttachToChassis(AActor* Chassis, const char* Socket) {
	/* Attach to the chassis passed through. */
	this->AttachToComponent(Chassis->GetRootComponent(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), Socket);
}

void AElectricMotor_Base::Set_MeshToUse_Tyre(UStaticMesh* Mesh) {
	/* Set pointer to the mesh to be used for the tyre, to the pointer passed in. */
	MeshToUse_Tyre = Mesh;
}