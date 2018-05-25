// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu_PlayerController.h"

void AMainMenu_PlayerController::BeginPlay() {
	Super::BeginPlay();

	/* Set the input mode to UI only. */
	SetInputMode(FInputModeUIOnly());
	/* Set the cursor to show. */
	bShowMouseCursor = true;
}


