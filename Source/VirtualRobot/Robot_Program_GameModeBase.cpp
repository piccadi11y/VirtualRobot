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

int ARobot_Program_GameModeBase::CreateBlock(TArray<int> Inputs, FString blockType) {



	//create a block, initialize it with its variables, then add the block to an array
	Blocks.Add(Program_Block(blockId,Inputs[0],Inputs[1],Inputs[2],rowCounter, columnCounter, blockType));
	blockIds.Add(blockId);
	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("OCOLUMN: ") + FString::FromInt(columnCounter));
	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("ORow: ") + FString::FromInt(rowCounter));
	
	if (columnCounter % 3 == 0 && columnCounter != 0) {
		//if (GEngine)
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("mdoulus: ") + FString::FromInt(columnCounter % 3));
		columnCounter = 0;
		++rowCounter;
		
	} else {
		++columnCounter;
		//if (GEngine)
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("++"));
	}
	return blockId++;
}

void ARobot_Program_GameModeBase::TestShow() {
	
}

void ARobot_Program_GameModeBase::SaveProgram() {
	FString test1 = "WorkPlz";
	TArray<FString> stringBlocks;
	FString blockString;
	
	//for each block in the array get all of its elements and turn them into one string, and add that string to the array
	for (auto blockToGet: Blocks) {
		blockString = blockToGet.GetStringBlock();
		stringBlocks.Add(blockString);
	}
	
	FI->File_Write_Program(test1, stringBlocks);
}

int ARobot_Program_GameModeBase::getRow() {
	//if(GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Row: ") + FString::FromInt(rowCounter));
	return rowCounter;
}
int ARobot_Program_GameModeBase::getColumn() {
	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue,TEXT("COLUMN: ") + FString::FromInt(columnCounter));
	return columnCounter;
}

TArray<int> ARobot_Program_GameModeBase::getBlockInfo(int ID) {
	int blockPosition = getBlockPosition(ID);
	TArray<int> blockStuff = Blocks[blockPosition].GetInfoForBoxes();
	return blockStuff;
}

int ARobot_Program_GameModeBase::getBlockPosition(int ID) {
	for (int i = 0; i < blockIds.Num(); i++) {
		if (blockIds[i] == ID) {
			return i;
		}
	}
	return -1;
}

FString ARobot_Program_GameModeBase::callGetBlockType(int ID) {
	int blockPosition = getBlockPosition(ID);
	return	Blocks[blockPosition].GetBlockType();
}

void ARobot_Program_GameModeBase::updateBlock(int ID, TArray<int> Inputs) {
	int blockPosition = getBlockPosition(ID);
	Blocks[blockPosition].UpdateBlock(Inputs[0], Inputs[1], Inputs[2]);
}

void ARobot_Program_GameModeBase::deleteBlock(int ID) {
	int blockPosition = getBlockPosition(ID);
	Blocks.RemoveAt(blockPosition);
	blockIds.RemoveAt(blockPosition);
	
}