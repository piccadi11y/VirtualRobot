// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot_Program_PlayerController.h"

void ARobot_Program_PlayerController::BeginPlay() {
	Super::BeginPlay();

	/* Set the input mode to UI only. */
	SetInputMode(FInputModeUIOnly());
	/* Set the cursor to show. */
	bShowMouseCursor = true;
}


