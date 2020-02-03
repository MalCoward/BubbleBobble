// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	movement_delay = AActor::GetWorld()->GetTimeSeconds();
}

void AEnemy::Movement()
{
	if (AActor::GetWorld()->GetTimeSeconds()  >= movement_delay + 1.0)
	{
		movement_delay = AActor::GetWorld()->GetTimeSeconds();
		move_dir = (!move_dir);
	}
	if (move_dir)
	{
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), 1);
	}
	else
	{
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), -1);
	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
