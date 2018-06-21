// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Chassis_Base.h"
#include "Chassis_Small.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALROBOT_API AChassis_Small : public AChassis_Base
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AChassis_Small();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override final;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override final;
	
	
};
