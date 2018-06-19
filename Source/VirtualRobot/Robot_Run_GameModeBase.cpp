// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot_Run_GameModeBase.h"

void ARobot_Run_GameModeBase::BeginPlay() {
	Super::BeginPlay();
	
	/* Load a list of the available robot files. */
	LoadAvailableFiles_Robot();
	/* Load a list of the available program files.*/
	LoadAvailableFiles_Program();
	/* On load, call function to change widget, passing through our starting widget. */
	ChangeMenuWidget(StartingWidgetClass);

}

void ARobot_Run_GameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass) {
	/* If a widget exists, remove it from the screen and clear the pointer. */
	if (CurrentWidget != nullptr) {
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	/* If we are passing a valid widget in, create that widget. */
	if (NewWidgetClass != nullptr) {
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		/* If widget creation was successful, add it to the screen. */
		if (CurrentWidget != nullptr) {
			CurrentWidget->AddToViewport();
		}
	}
}

void ARobot_Run_GameModeBase::LoadAvailableFiles_Robot() {
	/* Sets the robot files availble to the results of the file interface's search. */
	FilesAvailable_Robot = FI->LoadFileList_Robot();
}

void ARobot_Run_GameModeBase::LoadAvailableFiles_Program() {
	/* Sets the program files availble to the results of the file interface's search. */
	FilesAvailable_Program = FI->LoadFileList_Program();
}

TArray<FString> ARobot_Run_GameModeBase::GetAvailableFiles_Robot() {
	/* Returns the list of available robot files to caller. */
	return FilesAvailable_Robot;
}

TArray<FString> ARobot_Run_GameModeBase::GetAvailableFiles_Program() {
	/* Returns the list of available robot files to caller. */
	return FilesAvailable_Program;
}

void ARobot_Run_GameModeBase::SetSpawnPointPointer(AActor* SP) {
	/* Checks there isn't already a spawn point in the level, sets reference to the Spawn Point. */
	if (SpawnPoint == nullptr) SpawnPoint = Cast<ASpawnPoint_Base>(SP);
	//SpawnPoint->TestPrint();
}

void ARobot_Run_GameModeBase::SpawnRobot(FString FileName_Robot, FString FileName_Program) {
	if (FileName_Robot.Contains(FString(ROBOT_EXTENSION))) {
		FileName_Robot.RemoveAt(FileName_Robot.Len() - ROBOT_EXTENSION_LENGTH, ROBOT_EXTENSION_LENGTH);
	}
	if (FileName_Program.Contains(FString(PROGRAM_EXTENSION))) {
		FileName_Program.RemoveAt(FileName_Program.Len() - PROGRAM_EXTENSION_LENGTH, PROGRAM_EXTENSION_LENGTH);
	}

	SpawnPoint->InitSpawn(FileName_Robot, FileName_Program);
}