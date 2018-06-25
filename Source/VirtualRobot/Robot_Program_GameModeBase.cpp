// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot_Program_GameModeBase.h"
#include "FileInterface.h"
#include "Program_Block.h"

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

void ARobot_Program_GameModeBase::CreateBlock(TArray<int> Inputs) {
	
	Blocks.Add(Program_Block(blockId++,Inputs[1],Inputs[2]));
	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(Inputs[1]));
	
}

void ARobot_Program_GameModeBase::TestShow() {
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(Blocks[0].AddContents()));
}

void ARobot_Program_GameModeBase::SaveProgram() {
	FString test1 = "WorkPlz";
	TArray<FString> stringBlocks;
	FString blockString;
	int counter = 0;
	
	for (auto blockToGet: Blocks) {
		blockString = blockToGet.GetStringBlock();
		stringBlocks.Add(blockString);
		
	}

	
	FI->File_Write_Program(test1, stringBlocks);
}