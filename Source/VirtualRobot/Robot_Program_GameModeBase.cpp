// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot_Program_GameModeBase.h"

void ARobot_Program_GameModeBase::BeginPlay() {
	Super::BeginPlay();

	/* On load, call function to change widget, passing through our starting widget. */
	ChangeRobotProgrammingWidget(StartingWidgetClass);
}

void ARobot_Program_GameModeBase::ChangeRobotProgrammingWidget(TSubclassOf<UUserWidget> NewWidgetClass) {
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

void ARobot_Program_GameModeBase::CreateBlock(int Type, TArray<int> Inputs) {
	
	Blocks.Add(Program_Block(blockId++, Type, Inputs[1],Inputs[2]));
	
}

void ARobot_Program_GameModeBase::TestShow() {
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(Blocks[0].AddContents()));
}