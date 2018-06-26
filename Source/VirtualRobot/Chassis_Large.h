// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Chassis_Base.h"
#include "Chassis_Large.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALROBOT_API AChassis_Large : public AChassis_Base
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AChassis_Large();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override final;

	/** The front left drive motor. */
	AActor* Motor_Drive_Left_Centre;
	FString Motor_Drive_Left_Centre_Type;
	/** The back left drive motor. */
	AActor* Motor_Drive_Left_Rear;
	FString Motor_Drive_Left_Rear_Type;
	/** The front right drive motor. */
	AActor* Motor_Drive_Right_Centre;
	FString Motor_Drive_Right_Centre_Type;
	/** The rear right drive motor. */
	AActor* Motor_Drive_Right_Rear;
	FString Motor_Drive_Right_Rear_Type;
	void AttachDriveMotors();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override final;
	
	void Set_Motor_Drive(AActor* Actor, const FString &Type, const int &Loc);
};
