// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chassis_Small.h"
#include "Chassis_Medium.h"
#include "Chassis_Large.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "MacroDefinitions.h"
#include "LogicBoard_Base.generated.h"

UCLASS()
class VIRTUALROBOT_API ALogicBoard_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALogicBoard_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** The static mesh that is to be used to represent the component's mesh. */
	UStaticMesh* MeshToUse_Self;
	/** The mesh being used to represent the object. */
	UStaticMeshComponent* ObjectMesh;

	/** The chassis the logic board is attached to. */
	AActor* Chassis;
	FString Chassis_Type;
	/** Attach the chassis to self */
	void AttachChassis();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** set the mesh to use for self */
	void Set_MeshToUse_Self(UStaticMesh* Mesh);
	/** set the chassis to use */
	void Set_Chassis(AActor* Actor, FString &Type);
};
