// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LogicBoard_Base.h"
#include "LogicBoard_Test.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALROBOT_API ALogicBoard_Test : public ALogicBoard_Base
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ALogicBoard_Test();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override final;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override final;
	
	
};
