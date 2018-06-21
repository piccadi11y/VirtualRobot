// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Robot_Run_GameModeBase.h"
#include "Engine.h"
#include "FileInterface.h"
#include "LogicBoard_Test.h"
#include "LogicBoard_Basic.h"
#include "Chassis_Base.h"
#include "SpawnPoint_Base.generated.h"

#define LOGIC_BOARD_TAG "[Logic Board]"
#define LOGIC_BOARD_TYPE__TEST "Test"
#define LOGIC_BOARD_TYPE__BASIC "Basic"
#define CHASSIS_TAG "[Chassis]"
#define CHASSIS_TYPE__SMALL "Small"
#define CHASSIS_TYPE__MEDIUM "Medium"
#define CHASSIS_TYPE__LARGE "Large"

UCLASS()
class VIRTUALROBOT_API ASpawnPoint_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPoint_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Pass self to Game Mode. */
	void PassSelfToGameMode();
	/** Load Robot Data. */
	void LoadRobotData(FString FileName);
	/** Load Program Data. */
	void LoadProgramData(FString FileName);
	/** Find chosen component in robot file. */
	FString FindChosenComponent(const FString &ComponentTag);

	/** The mesh being used to represent the object. */
	UStaticMeshComponent* MeshObject;
	/** The file interface. */
	FileInterface* FI;

	/** Array to store Robot Data. */
	TArray<FString> Data_Robot;
	/** Array to store Program Data. */
	TArray<FString> Data_Program;


	/** Set the mesh for the logicboard to use. */
	AActor* Spawn_LogicBoard(UStaticMesh* Mesh, const FString &Type);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** The static mesh set in the editor to be used to represent the object. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
		UStaticMesh* MeshToUse;

	/** The static meshes to use for the different logic boards. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = LogicBoard)
		UStaticMesh* LogicBoard_Test_Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = LogicBoard)
		UStaticMesh* LogicBoard_Basic_Mesh;

	/** Initialises the spawn sequence. */
	void InitSpawn(FString FileName_Robot, FString FileName_Program);
	



	/** Test function to be called form the GameMode to confirm connection. */
	//void TestPrint() { GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("From SP")); }
};
