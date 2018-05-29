// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Engine.h"
#include "FileInterface.h"
#include "Robot_Run_GameModeBase.generated.h"

/**
 * 
 */	
UCLASS()
class VIRTUALROBOT_API ARobot_Run_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	/** Remove the current menu widget and create a new one from the specified class, if provided. */
	UFUNCTION(BlueprintCallable, Category = Menus)
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
	

	/** Load Robot files. */
	UFUNCTION(BlueprintCallable, Category = SelectionMenu)
		void LoadAvailableFiles_Robot();
	/** Load Program files. */
	UFUNCTION(BlueprintCallable, Category = SelectionMenu)
		void LoadAvailableFiles_Program();
	/** Getter of the Robot files list. */
	UFUNCTION(BlueprintCallable, Category = SelectionMenu)
		TArray<FString> GetAvailableFiles_Robot();
	/** Getter of the Program files list. */
	UFUNCTION(BlueprintCallable, Category = SelectionMenu)
		TArray<FString> GetAvailableFiles_Program();

protected:
	/** Called when the game starts. */
	virtual void BeginPlay() override;


	// please notice the fact an object of type 'FileInterface' is never created, the code just works :)
	/** The file interface we will use for loading and saving robots/code. */
	FileInterface* FI;
	
	/** List of all robot files that can be loaded. */
	TArray<FString> FilesAvailable_Robot;

	/** List of all program files that can be loaded. */
	TArray<FString> FilesAvailable_Program;


	/** The widget class we will use as our menu widget when the program start. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Menus)
		TSubclassOf<UUserWidget> StartingWidgetClass;

	/** The widget instance that we are currently using as our menu. */
	UPROPERTY()
		UUserWidget* CurrentWidget;
};
