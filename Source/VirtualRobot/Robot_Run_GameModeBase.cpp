// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot_Run_GameModeBase.h"

void ARobot_Run_GameModeBase::BeginPlay() {
	Super::BeginPlay();
	
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


