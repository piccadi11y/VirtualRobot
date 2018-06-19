// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Robot_Run_GameModeBase.h"
#include "Engine.h"
#include "SpawnPoint_Base.generated.h"

UCLASS()
class VIRTUALROBOT_API ASpawnPoint_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPoint_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** The mesh being used to represent the object. */
	UStaticMeshComponent* MeshObject;

	/** Pass self to Game Mode. */
	void PassSelfToGameMode();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** The static mesh set in the editor to be used to represent the object. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
		UStaticMesh* MeshToUse;
	
	/** Test function to be called form the GameMode to confirm connection. */
	//void TestPrint() { GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("From SP")); }
};
