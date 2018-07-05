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
	//increment row and colum counters when need be so that correct blocks on each line
	if (columnCounter % 3 == 0 && columnCounter != 0) {
		columnCounter = 0;
		++rowCounter;
		
	} else {
		++columnCounter;
	}
	//return Id to be set in blueprint so blocks can be individually called when clicked
	return blockId++;
}


void ARobot_Program_GameModeBase::SaveProgram(FString fileName) {
	TArray<FString> stringBlocks;
	FString blockString;
	
	//for each block in the array get all of its elements and turn them into one string, and add that string to the array
	for (auto blockToGet: Blocks) {
		blockString = blockToGet.GetStringBlock();
		stringBlocks.Add(blockString);
	}
	//write array to file with name inputted
	FI->File_Write_Program(fileName, stringBlocks);
}

int ARobot_Program_GameModeBase::getRow(int ID) {
	int blockPosition = getBlockPosition(ID);
	int rowCounter = Blocks[blockPosition].GetRow();
	return rowCounter;
}
int ARobot_Program_GameModeBase::getColumn(int ID) {
	int blockPosition = getBlockPosition(ID);
	int columnCounter = Blocks[blockPosition].GetColumn();
	return columnCounter;
}

TArray<int> ARobot_Program_GameModeBase::getBlockInfo(int ID) {
	int blockPosition = getBlockPosition(ID);
	TArray<int> blockStuff = Blocks[blockPosition].GetInfoForBoxes();
	return blockStuff;
}

int ARobot_Program_GameModeBase::getBlockPosition(int ID) {
	//search the Id array to find location of certain block
	for (int i = 0; i < blockIds.Num(); i++) {
		if (blockIds[i] == ID) {
			return i;
		}
	}
	//error return
	return -1;
}

FString ARobot_Program_GameModeBase::callGetBlockType(int ID) {
	int blockPosition = getBlockPosition(ID);
	return	Blocks[blockPosition].GetBlockType();
}

void ARobot_Program_GameModeBase::updateBlock(int ID, TArray<int> Inputs) {
	int blockPosition = getBlockPosition(ID);
	//[0] = mtr1 [1]= mtr2 [2] = duration
	Blocks[blockPosition].UpdateBlock(Inputs[0], Inputs[1], Inputs[2]);
}

void ARobot_Program_GameModeBase::deleteBlock(int ID) {
	int blockPosition = getBlockPosition(ID);
	Blocks.RemoveAt(blockPosition);
	blockIds.RemoveAt(blockPosition);
	
}

TArray<FString> ARobot_Program_GameModeBase::GetAvailableFiles_Program() {
	/* Returns the list of available robot files to caller. */
	return FilesAvailable_Program;
}

void ARobot_Program_GameModeBase::LoadAvailableFiles_Program() {
	/* Sets the program files availble to the results of the file interface's search. */
	FilesAvailable_Program = FI->LoadFileList_Program();
}

TArray<FString> ARobot_Program_GameModeBase::readProgramFile(FString fileName) {
	//remove the file extension as it is added in the file interface
	if (fileName.Contains(FString(PROGRAM_EXTENSION))) {
		fileName.RemoveAt(fileName.Len() - PROGRAM_EXTENSION_LENGTH, PROGRAM_EXTENSION_LENGTH);
	}
	TArray<FString> filePrintOut = FI->File_Read_Program(fileName);
	return filePrintOut;
}

TArray<int> ARobot_Program_GameModeBase::splitString(FString stringToSplit) {
	TArray<FString> splitted;
	TArray<int> splittedInt;
	int length = stringToSplit.Len();
	FString blockType = "";
	//create length of array so that items can be appended
	for (int j = 0; j < length - 2 ; ++j) {
		splitted.Add("");
	}

	//go through every character in string and add character to element in array until comma then start new element
	int counter = 0;
	for (auto character : stringToSplit) {
		if (character == ',') {
			splittedInt.Add(FCString::Atoi(*splitted[counter]));
			++counter;
		} else {
			splitted[counter].AppendChar(character);
		}
	}
	//send the block type to holder
	//this must be done as cant return two different type of inputs
	//and is safe as it is the next function to be called and is never changed or called anywhere else
	blockTypeHolder = splitted[3];
	//return each part as int
	return splittedInt;
}

void ARobot_Program_GameModeBase::resetBlocks() {
	Blocks.Empty();
	blockIds.Empty();
	blockId = 0;
	rowCounter = 0;
	columnCounter = 0;
}

FString ARobot_Program_GameModeBase::getBlockTypeHolder() {
	return blockTypeHolder;
}