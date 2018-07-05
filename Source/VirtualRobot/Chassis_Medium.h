// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Chassis_Base.h"
#include "Chassis_Medium.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALROBOT_API AChassis_Medium : public AChassis_Base
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AChassis_Medium();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override final;

	/** The left drive motor. */
	AActor* Motor_Drive_Left;
	FString Motor_Drive_Left_Type;
	/** The right drive motor */
	AActor* Motor_Drive_Right;
	FString Motor_Drive_Right_Type;
	/** Attach the motors. */
	void AttachDriveMotors();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override final;

	/** Set class' pointers to motors. */
	void Set_Motor_Drive(AActor* Actor, const FString &Type, const int &Loc);
};
