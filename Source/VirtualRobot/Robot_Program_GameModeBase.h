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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = RobotProgramming)
		int blockId = 0;
	

	/** The widget class we will use as our menu widget when the program start. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = RobotProgramming)
		TSubclassOf<UUserWidget> StartingWidgetClass;

	/** The widget instance that we are currently using as our menu. */
	UPROPERTY()
		UUserWidget* CurrentWidget;

	FileInterface* FI;

	/** List of all program files that can be loaded. */
	TArray<FString> FilesAvailable_Program;

	TArray<Program_Block> Blocks;

	TArray<int> blockIds;


	int rowCounter = 0;
	int columnCounter = 0;

	


public:
	/** Remove the current menu widget and create a new one from the specified class, if provided. */
	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void ChangeRobotProgrammingWidget(TSubclassOf<UUserWidget> NewWidgetClass);


	/*UENUM(BlueprintType)
		enum class BlockType
	{
		FORWARD,
		BACKWARD,
		TURNING,
		LIGHT_SENSOR,
		PROXIMITY_SENSOR,
		TOUCH_SENSOR,
		FOR_LOOP,
		FOREVER_LOOP,
		WAIT
	};*/

	

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		int CreateBlock(TArray<int> Inputs, FString blockType);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void SaveProgram(FString fileName);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		int getRow(int ID);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		int getColumn(int ID);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		int getBlockPosition(int ID);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		 TArray<int> getBlockInfo(int blockPosition);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		FString callGetBlockType(int ID);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void updateBlock(int ID, TArray<int> Inputs);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void deleteBlock(int ID);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		TArray<FString> readProgramFile(FString fileName);

	/** Load Program files. */
	UFUNCTION(BlueprintCallable, Category = SelectionMenu)
		void LoadAvailableFiles_Program();

	/** Getter of the Program files list. */
	UFUNCTION(BlueprintCallable, Category = SelectionMenu)
		TArray<FString> GetAvailableFiles_Program();

	UFUNCTION(BlueprintCallable, Category = SelectionMenu)
		TArray<int> splitString(FString stringToSplit);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void resetBlocks();
};
