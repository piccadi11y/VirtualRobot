// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnPoint_Base.h"


// Sets default values
ASpawnPoint_Base::ASpawnPoint_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/* Creates mesh component and sets it as root. */
	MeshObject = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshObject;
}

// Called when the game starts or when spawned
void ASpawnPoint_Base::BeginPlay()
{
	Super::BeginPlay();

	/* Set the mesh component to use the static mesh selected in the editor. */
	MeshObject->SetStaticMesh(MeshToUse);

	/* Pass self reference to GameMode, so that it can pass information through later. */
	PassSelfToGameMode();
	
}

// Called every frame
void ASpawnPoint_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnPoint_Base::PassSelfToGameMode() {
	/* Get pointer to GameMode. */
	ARobot_Run_GameModeBase* GM = Cast<ARobot_Run_GameModeBase>(GetWorld()->GetAuthGameMode());
	/* If pointer is valid, pass reference to self to appropriate function. */
	if (GM != nullptr) GM->SetSpawnPointPointer(this);
}

void ASpawnPoint_Base::InitSpawn(FString FileName_Robot, FString FileName_Program) {
	/* Test output to display file names being recieved. */
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FileName_Robot + FString(" ") + FileName_Program);

	/* Load robot data. */
	LoadRobotData(FileName_Robot);
	/* Load program data. */
	LoadProgramData(FileName_Program);


	FString InputString = FindChosenComponent(FString(LOGIC_BOARD_TAG));
	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, InputString);
	if (InputString != FString("")) {
		if (InputString == FString(LOGIC_BOARD_TYPE__TEST)) {
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString(LOGIC_BOARD_TYPE__TEST));
		}
	}

	/* Call logic board spawn function, store pointer. */
	ALogicBoard_Test* LB = Cast<ALogicBoard_Test>(Spawn_LogicBoard(LogicBoard_Test_Mesh));
}

ALogicBoard_Test* ASpawnPoint_Base::Spawn_LogicBoard(UStaticMesh* Mesh) {
	FTransform Transform(FRotator(0.f, 0.f, 0.f), FVector(0.f, 0.f, 20.f));
	/* Begin deferred spawn of logic baord. */
	ALogicBoard_Test* LB = Cast<ALogicBoard_Test>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, ALogicBoard_Test::StaticClass(), Transform));
	if (LB != nullptr) {
		/* Set the UStaticMesh for the object to use. */
		LB->Set_MeshToUse_Self(Mesh);
		/* Finish spawn. */
		UGameplayStatics::FinishSpawningActor(LB, Transform);
		return LB;
	}
	/* TESTING - Let dev know if the spawn failed. */
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Failed to create LogicBoard.");
	return nullptr;
}

void ASpawnPoint_Base::LoadRobotData(FString FileName) {
	/* Store returned data in appropriate array. */
	Data_Robot = FI->File_Read_Robot(FileName);
	/*for (int i = 0; i < Data_Robot.Num(); i++) {
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, Data_Robot[i]);
	}*/
}

void ASpawnPoint_Base::LoadProgramData(FString FileName) {
	/* Store returned data in appropriate array. */
	Data_Program = FI->File_Read_Program(FileName);
}

FString ASpawnPoint_Base::FindChosenComponent(const FString &ComponentTag) {
	for (int i{ 0 }; i < Data_Robot.Num(); i++) {
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::FromInt(i) + Data_Robot[i]);
		if (Data_Robot[i] == ComponentTag) return Data_Robot[++i];
	}
	return FString("empty");
}