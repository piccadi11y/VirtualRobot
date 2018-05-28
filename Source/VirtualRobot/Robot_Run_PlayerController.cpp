// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot_Run_PlayerController.h"

void ARobot_Run_PlayerController::BeginPlay() {
	Super::BeginPlay();

	/* Set the input mode to UI only. */
	SetInputMode(FInputModeUIOnly());
	/* Set the cursor to show. */
	bShowMouseCursor = true;
}


