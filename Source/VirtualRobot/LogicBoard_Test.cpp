// Fill out your copyright notice in the Description page of Project Settings.

#include "LogicBoard_Test.h"


// Sets default values
ALogicBoard_Test::ALogicBoard_Test()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALogicBoard_Test::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ALogicBoard_Test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector loc = GetActorLocation();
	loc.Z += 0.1f;
	SetActorLocation(loc);

}



