// Fill out your copyright notice in the Description page of Project Settings.

#include "LogicBoard_Base.h"


// Sets default values
ALogicBoard_Base::ALogicBoard_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = ObjectMesh;
}

// Called when the game starts or when spawned
void ALogicBoard_Base::BeginPlay()
{
	Super::BeginPlay();

	ObjectMesh->SetStaticMesh(MeshToUse_Self);
	
}

// Called every frame
void ALogicBoard_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALogicBoard_Base::Set_MeshToUse_Self(UStaticMesh* Mesh) {
	MeshToUse_Self = Mesh;
}