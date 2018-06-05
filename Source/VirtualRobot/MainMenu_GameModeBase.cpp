// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu_GameModeBase.h"

void AMainMenu_GameModeBase::BeginPlay() {
	Super::BeginPlay();

	/* On load, verify/create default directories. */
	VerifyCreateDefaultDirectories();

	/* On load, call function to change widget, passing through our starting widget. */
	ChangeMenuWidget(StartingWidgetClass);
}

void AMainMenu_GameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass) {
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

void AMainMenu_GameModeBase::VerifyCreateDefaultDirectories() {
	if (!FI->VerifyOrCreateDefaultDirectories()) {
		GEngine->AddOnScreenDebugMessage(0, 2.f, FColor::Red, FString("Failed to create default directories."));
	}
}
