// Fill out your copyright notice in the Description page of Project Settings.

#include "ElectricMotor_Base.h"


// Sets default values
AElectricMotor_Base::AElectricMotor_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = ObjectMesh;
	Tyre = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tyre"));
	Tyre->AttachToComponent(ObjectMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("Wheel"));
}

// Called when the game starts or when spawned
void AElectricMotor_Base::BeginPlay()
{
	Super::BeginPlay();
	
	ObjectMesh->SetStaticMesh(MeshToUse_Self);
	ObjectMesh->SetSimulatePhysics(true);
	Tyre->SetStaticMesh(MeshToUse_Tyre);
	Tyre->SetSimulatePhysics(true);
}

// Called every frame
void AElectricMotor_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Tyre->AddLocalRotation(FRotator(0.f, 1.f, 0.f));
}

void AElectricMotor_Base::Set_MeshToUse_Self(UStaticMesh* Mesh) {
	MeshToUse_Self = Mesh;
}

void AElectricMotor_Base::AttachToChassis(AActor* Chassis, const char* Socket) {
	this->AttachToComponent(Chassis->GetRootComponent(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), Socket);
}

void AElectricMotor_Base::Set_MeshToUse_Tyre(UStaticMesh* Mesh) {
	MeshToUse_Tyre = Mesh;
}