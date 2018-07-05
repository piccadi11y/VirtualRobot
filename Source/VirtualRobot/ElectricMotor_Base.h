// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "ElectricMotor_Base.generated.h"

UCLASS()
class VIRTUALROBOT_API AElectricMotor_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElectricMotor_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** The static mesh that is used to represent the component's mesh. */
	UStaticMesh* MeshToUse_Self;
	/** The static mesh to use for the tyre. */
	UStaticMesh* MeshToUse_Tyre;
	/** The component being used to represent the object. */
	UStaticMeshComponent* ObjectMesh;
	/** The component being used to represent the tyre. */
	UStaticMeshComponent* Tyre;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Set the mesh to use for representing self. */
	void Set_MeshToUse_Self(UStaticMesh* Mesh);
	/** Set the mesh to use for representing tyre. */
	void Set_MeshToUse_Tyre(UStaticMesh* Mesh);
	/** Attach to the chassis passed through. */
	void AttachToChassis(AActor* Chassis, const char* Socket);

	
};
