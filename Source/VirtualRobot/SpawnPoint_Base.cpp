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
	/* Load robot data. */
	LoadRobotData(FileName_Robot);
	/* Load program data. */
	LoadProgramData(FileName_Program);

	/* Declare variable to be used to store LogicBoard pointer. */
	AActor* LogicBoard = nullptr;

	/* Get type of logic board to be created. */
	FString LogicBoard_Type = FindChosenComponent(FString(LOGIC_BOARD_TAG));
	/* If input isn't empty, try and create correlating logic board. */
	if (LogicBoard_Type != FString("")) {
		if (LogicBoard_Type == FString(LOGIC_BOARD_TYPE__TEST)) {
			/* Call logic board spawn function, store pointer. */
			LogicBoard = Spawn_LogicBoard(LogicBoard_Test_Mesh, LogicBoard_Type);
		}
		else if (LogicBoard_Type == FString(LOGIC_BOARD_TYPE__BASIC)) {
			LogicBoard = Spawn_LogicBoard(LogicBoard_Basic_Mesh, LogicBoard_Type);
		}
	}
	else GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString("Failed to spawn logic board."));


	AActor* Chassis_ptr = nullptr;
	/* Get the type of chassis to be created. */
	FString Chassis_Type = FindChosenComponent(FString(CHASSIS_TAG));
	/* If input isn't empty, try and create the correlating chassis. */
	if (Chassis_Type != FString("")) {
		if (Chassis_Type == FString(CHASSIS_TYPE__SMALL)) {
			Chassis_ptr = Spawn_Chassis(Chassis_Small_Mesh, Chassis_Type);
		}
		else if (Chassis_Type == FString(CHASSIS_TYPE__MEDIUM)) {
			Chassis_ptr = Spawn_Chassis(Chassis_Medium_Mesh, Chassis_Type);
		}
		else if (Chassis_Type == FString(CHASSIS_TYPE__LARGE)) {
			Chassis_ptr = Spawn_Chassis(Chassis_Large_Mesh, Chassis_Type);
		}
	}
	else GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Red, FString("Failed to spawn chassis."));

	if (Chassis_ptr) {
		/* if valid chassis, find motor/tyre type and spawn them */
		FString MotorType = FindChosenComponent(FString(MOTOR_DRIVE_TAG));
		FString TyreType = FindChosenComponent(FString(TYRE_TAG));
		if (MotorType != FString("")) {
			if (TyreType == FString(TYRE_TYPE__BASIC)) {
				if (MotorType == FString(MOTOR_DRIVE_TYPE__BASIC)) Spawn_Motors_Drive(Motor_Drive_Basic_Mesh, Tyre_Basic_Mesh, Chassis_ptr, Chassis_Type, MotorType);
			}
		}
	}
	if (LogicBoard && Chassis_ptr) Cast<ALogicBoard_Base>(LogicBoard)->Set_Chassis(Chassis_ptr, Chassis_Type); // if logic board and chassis are valid, attach the chassis to the logic board

}

AActor* ASpawnPoint_Base::Spawn_LogicBoard(UStaticMesh* Mesh, const FString &Type) {
	FTransform Transform(FRotator(0.f, 0.f, 0.f), FVector(0.f, 0.f, 20.f));
	if (Type == FString(LOGIC_BOARD_TYPE__TEST)) {
		/* Begin deferred spawn of logic board type: test. */
		ALogicBoard_Test* LB = Cast<ALogicBoard_Test>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, ALogicBoard_Test::StaticClass(), Transform));
		if (LB != nullptr) {
			/* Set the UStaticMesh for the object to use. */
			LB->Set_MeshToUse_Self(Mesh);
			/* Finish spawn. */
			UGameplayStatics::FinishSpawningActor(LB, Transform);
			return LB;
		}
	}
	else if (Type == FString(LOGIC_BOARD_TYPE__BASIC)) {
		ALogicBoard_Basic* LB = Cast<ALogicBoard_Basic>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, ALogicBoard_Basic::StaticClass(), Transform));
		if (LB != nullptr) {
			LB->Set_MeshToUse_Self(Mesh);
			UGameplayStatics::FinishSpawningActor(LB, Transform);
			return LB;
		}
	}
	/* TESTING - Let dev know if the spawn failed. */
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Failed to create Logic Board.");
	return nullptr;
}

AActor* ASpawnPoint_Base::Spawn_Chassis(UStaticMesh* Mesh, const FString &Type) {
	FTransform Transform(FRotator(0.f, 0.f, 0.f), FVector(0.f, 0.f, 15.f));
	if (Type == FString(CHASSIS_TYPE__SMALL)) {
		/* Begin deferred spawn of chassis, type: small. */
		AChassis_Small* C = Cast<AChassis_Small>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AChassis_Small::StaticClass(), Transform));
		if (C != nullptr) {
			/* set the mesh for the chassis to use. */
			C->Set_MeshToUse_Self(Mesh);
			UGameplayStatics::FinishSpawningActor(C, Transform);
			return C;
		}
	}
	else if (Type == FString(CHASSIS_TYPE__MEDIUM)) {
		AChassis_Medium* C = Cast<AChassis_Medium>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AChassis_Medium::StaticClass(), Transform));
		if (C != nullptr) {
			C->Set_MeshToUse_Self(Mesh);
			UGameplayStatics::FinishSpawningActor(C, Transform);
			return C;
		}
	}
	else if (Type == FString(CHASSIS_TYPE__LARGE)) {
		AChassis_Large* C = Cast<AChassis_Large>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AChassis_Large::StaticClass(), Transform));
		if (C != nullptr) {
			C->Set_MeshToUse_Self(Mesh);
			UGameplayStatics::FinishSpawningActor(C, Transform);
			return C;
		}
	}
	return nullptr;
}

void ASpawnPoint_Base::Spawn_Motors_Drive(UStaticMesh* Mesh_Motor, UStaticMesh* Mesh_Tyre, AActor* Chassis, const FString &ChassisType, const FString &Type) {
	FTransform Transform(FRotator(0.f, 0.f, 0.f), FVector(0.f, 0.f, 0.f));
	if (ChassisType == FString(CHASSIS_TYPE__SMALL)) {
		AChassis_Small* C = Cast<AChassis_Small>(Chassis);
		if (Type == FString(MOTOR_DRIVE_TYPE__BASIC)) {
			/* begin spawn of two motors (small chassis takes 2) */
			AElectricMotor_Drive_Basic* Motor_Left = Cast<AElectricMotor_Drive_Basic>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AElectricMotor_Drive_Basic::StaticClass(), Transform));
			AElectricMotor_Drive_Basic* Motor_Right = Cast<AElectricMotor_Drive_Basic>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AElectricMotor_Drive_Basic::StaticClass(), Transform));
			if (Motor_Left != nullptr) {
				/* set mesh for self, mesh for tyre */
				Motor_Left->Set_MeshToUse_Self(Mesh_Motor);
				Motor_Left->Set_MeshToUse_Tyre(Mesh_Tyre);
				/* finish object spawn */
				UGameplayStatics::FinishSpawningActor(Motor_Left, Transform);
			}
			if (Motor_Right != nullptr) {
				Motor_Right->Set_MeshToUse_Self(Mesh_Motor);
				Motor_Right->Set_MeshToUse_Tyre(Mesh_Tyre);
				UGameplayStatics::FinishSpawningActor(Motor_Right, Transform);
			}
			if (Motor_Left) C->Set_Motor_Drive(Motor_Left, Type, EMotor_Drive_Locations::REAR_LEFT_e);
			if (Motor_Right) C->Set_Motor_Drive(Motor_Right, Type, EMotor_Drive_Locations::REAR_RIGHT_e);
		}
	}
	else if (ChassisType == FString(CHASSIS_TYPE__MEDIUM)) {
		AChassis_Medium* C = Cast<AChassis_Medium>(Chassis);
		if (Type == FString(MOTOR_DRIVE_TYPE__BASIC)) {
			/* begin spawn of two motors (medium chassis takes 2) */
			AElectricMotor_Drive_Basic* Motor_Left = Cast<AElectricMotor_Drive_Basic>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AElectricMotor_Drive_Basic::StaticClass(), Transform));
			AElectricMotor_Drive_Basic* Motor_Right = Cast<AElectricMotor_Drive_Basic>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AElectricMotor_Drive_Basic::StaticClass(), Transform));
			if (Motor_Left != nullptr) {
				/* set mesh for self, mesh for tyre */
				Motor_Left->Set_MeshToUse_Self(Mesh_Motor);
				Motor_Left->Set_MeshToUse_Tyre(Mesh_Tyre);
				/* finish object spawn */
				UGameplayStatics::FinishSpawningActor(Motor_Left, Transform);
			}
			if (Motor_Right != nullptr) {
				Motor_Right->Set_MeshToUse_Self(Mesh_Motor);
				Motor_Right->Set_MeshToUse_Tyre(Mesh_Tyre);
				UGameplayStatics::FinishSpawningActor(Motor_Right, Transform);
			}
			if (Motor_Left) C->Set_Motor_Drive(Motor_Left, Type, EMotor_Drive_Locations::REAR_LEFT_e);
			if (Motor_Right) C->Set_Motor_Drive(Motor_Right, Type, EMotor_Drive_Locations::REAR_RIGHT_e);
		}
	}
	else if (ChassisType == FString(CHASSIS_TYPE__LARGE)) { // if chassis type__large
		AChassis_Large* C = Cast<AChassis_Large>(Chassis);
		if (Type == FString(MOTOR_DRIVE_TYPE__BASIC)) {
			/* begin spawn of four motors (large chassis takes 4) */
			AElectricMotor_Drive_Basic* Motor_Left_Rear = Cast<AElectricMotor_Drive_Basic>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AElectricMotor_Drive_Basic::StaticClass(), Transform));
			AElectricMotor_Drive_Basic* Motor_Right_Rear = Cast<AElectricMotor_Drive_Basic>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AElectricMotor_Drive_Basic::StaticClass(), Transform));
			AElectricMotor_Drive_Basic* Motor_Left_Centre = Cast<AElectricMotor_Drive_Basic>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AElectricMotor_Drive_Basic::StaticClass(), Transform));
			AElectricMotor_Drive_Basic* Motor_Right_Centre = Cast<AElectricMotor_Drive_Basic>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AElectricMotor_Drive_Basic::StaticClass(), Transform));
			if (Motor_Left_Rear != nullptr) {
				/* set mesh for self, mesh for tyre */
				Motor_Left_Rear->Set_MeshToUse_Self(Mesh_Motor);
				Motor_Left_Rear->Set_MeshToUse_Tyre(Mesh_Tyre);
				/* finish object spawn */
				UGameplayStatics::FinishSpawningActor(Motor_Left_Rear, Transform);
			}
			if (Motor_Right_Rear != nullptr) {
				Motor_Right_Rear->Set_MeshToUse_Self(Mesh_Motor);
				Motor_Right_Rear->Set_MeshToUse_Tyre(Mesh_Tyre);
				UGameplayStatics::FinishSpawningActor(Motor_Right_Rear, Transform);
			}
			if (Motor_Left_Centre != nullptr) {
				Motor_Left_Centre->Set_MeshToUse_Self(Mesh_Motor);
				Motor_Left_Centre->Set_MeshToUse_Tyre(Mesh_Tyre);
				UGameplayStatics::FinishSpawningActor(Motor_Left_Centre, Transform);
			}
			if (Motor_Right_Centre != nullptr) {
				Motor_Right_Centre->Set_MeshToUse_Self(Mesh_Motor);
				Motor_Right_Centre->Set_MeshToUse_Tyre(Mesh_Tyre);
				UGameplayStatics::FinishSpawningActor(Motor_Right_Centre, Transform);
			}
			/* if valid motors have been created, set them within the chassis */
			if (Motor_Left_Rear) C->Set_Motor_Drive(Motor_Left_Rear, Type, EMotor_Drive_Locations::REAR_LEFT_e);
			if (Motor_Right_Rear) C->Set_Motor_Drive(Motor_Right_Rear, Type, EMotor_Drive_Locations::REAR_RIGHT_e);
			if (Motor_Left_Centre) C->Set_Motor_Drive(Motor_Left_Centre, Type, EMotor_Drive_Locations::CENTRE_LEFT_e);
			if (Motor_Right_Centre) C->Set_Motor_Drive(Motor_Right_Centre, Type, EMotor_Drive_Locations::CENTRE_RIGHT_e);
		}
	}
}

void ASpawnPoint_Base::LoadRobotData(FString FileName) {
	/* Store returned data in appropriate array. */
	Data_Robot = FI->File_Read_Robot(FileName);
}

void ASpawnPoint_Base::LoadProgramData(FString FileName) {
	/* Store returned data in appropriate array. */
	Data_Program = FI->File_Read_Program(FileName);
}

FString ASpawnPoint_Base::FindChosenComponent(const FString &ComponentTag) {
	/* if data is found directly after a component's tag, return it .*/
	for (int i{ 0 }; i < Data_Robot.Num(); i++) if (Data_Robot[i] == ComponentTag && i + 1 != Data_Robot.Num()) return Data_Robot[++i];
	/* return empty if nothing is found */
	return FString("");
}