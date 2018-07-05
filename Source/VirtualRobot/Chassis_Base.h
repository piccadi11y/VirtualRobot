// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"
#include "MacroDefinitions.h"
#include "ElectricMotor_Drive_Basic.h"
#include "Chassis_Base.generated.h"

UCLASS()
class VIRTUALROBOT_API AChassis_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChassis_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** The static mesh that is used to represent the component's mesh. */
	UStaticMesh* MeshToUse_Self;
	/** The mesh being used to represent the object. */
	UStaticMeshComponent* ObjectMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Set the mesh that the object will use to represent self. */
	void Set_MeshToUse_Self(UStaticMesh* Mesh);
	/** Attach self to the supplied logic board. */
	void AttachToLogicBoard(AActor* LB);
	
};
