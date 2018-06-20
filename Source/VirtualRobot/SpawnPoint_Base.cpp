// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnPoint_Base.h"


// Sets default values
ASpawnPoint_Base::ASpawnPoint_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshObject = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshObject;
}

// Called when the game starts or when spawned
void ASpawnPoint_Base::BeginPlay()
{
	Super::BeginPlay();

	MeshObject->SetStaticMesh(MeshToUse);

	PassSelfToGameMode();
	
}

// Called every frame
void ASpawnPoint_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnPoint_Base::PassSelfToGameMode() {
	ARobot_Run_GameModeBase* GM = Cast<ARobot_Run_GameModeBase>(GetWorld()->GetAuthGameMode());
	GM->SetSpawnPointPointer(this);
}

void ASpawnPoint_Base::InitSpawn(FString FileName_Robot, FString FileName_Program) {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FileName_Robot + FString(" ") + FileName_Program);

	ALogicBoard_Test* LB = Cast<ALogicBoard_Test>(Spawn_LogicBoard(LogicBoard_Test_Mesh));
}

ALogicBoard_Test* ASpawnPoint_Base::Spawn_LogicBoard(UStaticMesh* Mesh) {
	FTransform Transform(FRotator(0.f, 0.f, 0.f), FVector(0.f, 0.f, 20.f));
	ALogicBoard_Test* LB = Cast<ALogicBoard_Test>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, ALogicBoard_Test::StaticClass(), Transform));
	if (LB != nullptr) {
		LB->Set_MeshToUse_Self(Mesh);
		UGameplayStatics::FinishSpawningActor(LB, Transform);
		return LB;
	}
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Failed to create LogicBoard.");
	return nullptr;
}

void ASpawnPoint_Base::LoadRobotData(FString FileName) {

}

void ASpawnPoint_Base::LoadProgramData(FString FileName) {

}