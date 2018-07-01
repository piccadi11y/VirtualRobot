// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Robot_Program_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALROBOT_API ARobot_Program_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	
};
