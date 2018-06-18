// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chassis_Base.h"
#include "Components/StaticMeshComponent.h"
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

	/** The mesh being used to represent the object. */
	UStaticMeshComponent* ObjectMesh;

	/** The chassis the logic board is attached to. */
	AChassis_Base* Chassis;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
		UStaticMesh* MeshToUse;
	
};
