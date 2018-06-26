// Fill out your copyright notice in the Description page of Project Settings.

#include "Chassis_Small.h"

// Sets default values
AChassis_Small::AChassis_Small()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChassis_Small::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AChassis_Small::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChassis_Small::Set_Motor_Drive(AActor* Actor, const FString &Type, const int &Loc) {
	switch (Loc) {
	case int(EMotor_Drive_Locations::REAR_LEFT_e) : Motor_Drive_Left = Actor; Motor_Drive_Left_Type = Type; break;
	case int(EMotor_Drive_Locations::REAR_RIGHT_e) : Motor_Drive_Right = Actor; Motor_Drive_Right_Type = Type; break;
	default: break;
	}
	if (Motor_Drive_Left && Motor_Drive_Right) AttachDriveMotors();
}

void AChassis_Small::AttachDriveMotors() {
	if (Motor_Drive_Left_Type == FString(MOTOR_DRIVE_TYPE__BASIC)) Cast<AElectricMotor_Drive_Basic>(Motor_Drive_Left)->AttachToChassis(Cast<AActor>(this), "Motor_Drive_Left");

	if (Motor_Drive_Right_Type == FString(MOTOR_DRIVE_TYPE__BASIC)) Cast<AElectricMotor_Drive_Basic>(Motor_Drive_Right)->AttachToChassis(Cast<AActor>(this), "Motor_Drive_Right");
}