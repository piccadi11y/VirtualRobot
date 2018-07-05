// Fill out your copyright notice in the Description page of Project Settings.

#include "LogicBoard_Base.h"


// Sets default values
ALogicBoard_Base::ALogicBoard_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* setup object's components */
	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = ObjectMesh;
}

// Called when the game starts or when spawned
void ALogicBoard_Base::BeginPlay()
{
	Super::BeginPlay();
	
	/* set mesh and enable physics */
	ObjectMesh->SetStaticMesh(MeshToUse_Self);
	ObjectMesh->SetSimulatePhysics(true);
	
}

// Called every frame
void ALogicBoard_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALogicBoard_Base::Set_MeshToUse_Self(UStaticMesh* Mesh) {
	/* set pointer for mesh to use, to supplied pointer */
	MeshToUse_Self = Mesh;
}

void ALogicBoard_Base::Set_Chassis(AActor* Actor, FString &Type) {
	Chassis = Actor;
	Chassis_Type = Type;
	/* if valid chassis, attach */
	if (Chassis) AttachChassis();
}

void ALogicBoard_Base::AttachChassis() {
	/* check to see what type of chassis is being used, call appropriate code to attach the chassis to self */
	if (Chassis_Type == FString(CHASSIS_TYPE__SMALL)) Cast<AChassis_Small>(Chassis)->AttachToLogicBoard(Cast<AActor>(this));
	else if (Chassis_Type == FString(CHASSIS_TYPE__MEDIUM)) Cast<AChassis_Medium>(Chassis)->AttachToLogicBoard(Cast<AActor>(this));
	else if (Chassis_Type == FString(CHASSIS_TYPE__LARGE)) Cast<AChassis_Large>(Chassis)->AttachToLogicBoard(Cast<AActor>(this));
}