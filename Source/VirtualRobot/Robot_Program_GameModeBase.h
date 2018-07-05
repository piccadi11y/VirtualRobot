// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Program_Block.h"
#include "Engine.h"
#include "FileInterface.h"
#include "MacroDefinitions.h"
#include "Robot_Program_GameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class VIRTUALROBOT_API ARobot_Program_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	

protected:
	/** Called when the game starts. */
	virtual void BeginPlay() override;

	//variable that provides the id for every new block
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = RobotProgramming)
		int blockId = 0;
	
	/** The widget class we will use as our menu widget when the program start. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = RobotProgramming)
		TSubclassOf<UUserWidget> StartingWidgetClass;

	/** The widget instance that we are currently using as our menu. */
	UPROPERTY()
		UUserWidget* CurrentWidget;

	//So we can access the File Interface files
	FileInterface* FI;

	/** List of all program files that can be loaded. */
	TArray<FString> FilesAvailable_Program;
	//Array to store all the blocks created
	TArray<Program_Block> Blocks;
	//Array to store the Id of blacks in the order in which the blocks should be executed
	TArray<int> blockIds;
	//to store the blocktype when swapping between functions
	FString blockTypeHolder;
	//counters to provide row and colums for every new block
	int rowCounter = 0;
	int columnCounter = 0;

public:
	/** Remove the current menu widget and create a new one from the specified class, if provided. */
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void ChangeRobotProgrammingWidget(TSubclassOf<UUserWidget> NewWidgetClass);
	//create and intilaze a new block and add to array and return its ID
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		int CreateBlock(TArray<int> Inputs, FString blockType);
	//write each blocks information to a file with the inputted name
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void SaveProgram(FString fileName);
	//return the row for the block on screen
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		int getRow(int ID);
	//return column for block on screen
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		int getColumn(int ID);
	//finds the order in the block array that the passed in Id is located
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		int getBlockPosition(int ID);
	//get the stored values for a block to put back into the text boxes on screen
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		 TArray<int> getBlockInfo(int blockPosition);
	//call the blocks type
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		FString callGetBlockType(int ID);
	//call to update the members of a block with new values
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void updateBlock(int ID, TArray<int> Inputs);
	//remove block from array and its Id from the id array
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void deleteBlock(int ID);
	//read the loaded file
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		TArray<FString> readProgramFile(FString fileName);

	/** Load Program files. */
	UFUNCTION(BlueprintCallable, Category = SelectionMenu)
		void LoadAvailableFiles_Program();

	/** Getter of the Program files list. */
	UFUNCTION(BlueprintCallable, Category = SelectionMenu)
		TArray<FString> GetAvailableFiles_Program();
	//split each line from the file into elements of an array to be put into the text boxes
	UFUNCTION(BlueprintCallable, Category = SelectionMenu)
		TArray<int> splitString(FString stringToSplit);
	//get the tempoary holder of bocktype
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		FString getBlockTypeHolder();
	//empty both arrays
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void resetBlocks();
};
