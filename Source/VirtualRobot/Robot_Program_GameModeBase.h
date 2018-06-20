// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Program_Block.h"
#include "Engine.h"
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

	TArray<Program_Block> Blocks;

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void CreateBlock(int Type, TArray<int> Inputs);

	UFUNCTION(BlueprintCallable, Category = RobotProgramming)
		void TestShow();
	
};
