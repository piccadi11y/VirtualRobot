// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu_GameModeBase.h"

void AMainMenu_GameModeBase::BeginPlay() {
	Super::BeginPlay();

	/* On load, verify/create default directories. */
	VerifyCreateDefaultDirectories();
	/* On load, verify/create default files. */
	VerifyCreateDefaultFiles();

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

void AMainMenu_GameModeBase::VerifyCreateDefaultFiles() {
	FString fnR, fnP, pR, pP, absR, absP;
	/* Set filename to be used for defaults. */
	fnR = "Default" + FString(ROBOT_EXTENSION);
	fnP = "Default" + FString(PROGRAM_EXTENSION);
	/* Set the paths to each directory. */
	pR = FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_ROBOTS) + "/";
	pP = FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_PROGRAMS) + "/";
	/* Create abs path for .rbt or .prgm files. */
	absR = pR + fnR;
	absP = pP + fnP;
	/* If the files don't already exist, create/populate them. */
	if (!FI->CheckFileExists(absR)) FI->File_Write(pR, fnR, {	FString("[Logic Board]"),
																FString("Test"),
																FString("[Chassis]"),
																FString("Small"),
																FString("[Drive Motors]"),
																FString("Basic"),
																FString("[Tyres]"),
																FString("Basic")});
	if (!FI->CheckFileExists(absP)) FI->File_Write(pP, fnP, { FString("100,100,20,Forward"), FString("11,12,9,Backward"), FString("50,25,15,Turning") , FString("1,1,3,Forward") });
}