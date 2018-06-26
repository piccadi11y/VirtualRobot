// Fill out your copyright notice in the Description page of Project Settings.

#include "Chassis_Large.h"

// Sets default values
AChassis_Large::AChassis_Large()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChassis_Large::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AChassis_Large::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AChassis_Large::Set_Motor_Drive(AActor* Actor, const FString &Type, const int &Loc) {
	switch (Loc) {
	case int(EMotor_Drive_Locations::REAR_LEFT_e) : Motor_Drive_Left_Rear = Actor; Motor_Drive_Left_Rear_Type = Type; break;
	case int(EMotor_Drive_Locations::REAR_RIGHT_e) : Motor_Drive_Right_Rear = Actor; Motor_Drive_Right_Rear_Type = Type; break;
	case int(EMotor_Drive_Locations::CENTRE_LEFT_e) : Motor_Drive_Left_Centre = Actor; Motor_Drive_Left_Centre_Type = Type; break;
	case int(EMotor_Drive_Locations::CENTRE_RIGHT_e) : Motor_Drive_Right_Centre = Actor; Motor_Drive_Right_Centre_Type = Type; break;
	default: break;
	}
	if (Motor_Drive_Left_Rear && Motor_Drive_Left_Centre && Motor_Drive_Right_Rear && Motor_Drive_Right_Centre) AttachDriveMotors();
}

void AChassis_Large::AttachDriveMotors() {
	if (Motor_Drive_Left_Rear_Type == FString(MOTOR_DRIVE_TYPE__BASIC)) Cast<AElectricMotor_Drive_Basic>(Motor_Drive_Left_Rear)->AttachToChassis(Cast<AActor>(this), "Motor_Drive_Left_Rear");

	if (Motor_Drive_Right_Rear_Type == FString(MOTOR_DRIVE_TYPE__BASIC)) Cast<AElectricMotor_Drive_Basic>(Motor_Drive_Right_Rear)->AttachToChassis(Cast<AActor>(this), "Motor_Drive_Right_Rear");

	if (Motor_Drive_Left_Centre_Type == FString(MOTOR_DRIVE_TYPE__BASIC)) Cast<AElectricMotor_Drive_Basic>(Motor_Drive_Left_Centre)->AttachToChassis(Cast<AActor>(this), "Motor_Drive_Left_Centre");

	if (Motor_Drive_Right_Centre_Type == FString(MOTOR_DRIVE_TYPE__BASIC)) Cast<AElectricMotor_Drive_Basic>(Motor_Drive_Right_Centre)->AttachToChassis(Cast<AActor>(this), "Motor_Drive_Right_Centre");
}