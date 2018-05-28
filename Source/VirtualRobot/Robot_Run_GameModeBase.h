// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Engine.h"

#include "FileHelper.h"
#include "PlatformFile.h"

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
	
	/** Write array to file. */
	UFUNCTION(BlueprintCallable, Category = File_Manipulation)
		void File_Write(FString dir, FString fileName, FString txt);
	UFUNCTION(BlueprintCallable, Category = File_Manipulation)
		void File_Write_arr(FString dir, FString fileName, TArray<FString> txt);
	/** Read array to file. */
	UFUNCTION(BlueprintCallable, Category = File_Manipulation)
		void File_Read();

	UFUNCTION(BlueprintCallable)
		bool VerifyOrCreateDirectory(const FString& TestDir) const;

protected:
	/** Called when the game starts. */
	virtual void BeginPlay() override;

	/** The widget class we will use as our menu widget when the program start. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Menus)
		TSubclassOf<UUserWidget> StartingWidgetClass;

	/** The widget instance that we are currently using as our menu. */
	UPROPERTY()
		UUserWidget* CurrentWidget;
	
	
};
