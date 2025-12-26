// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::Move() 
{
	int RandomQuarterNum = FMath::RandRange(1, 4);
	FVector NewActorLocation = GetActorLocation();
	switch (RandomQuarterNum) {
	case 1:
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Yellow, TEXT("Move Forward"));
		NewActorLocation.X += 20;
		SetActorLocation(NewActorLocation);
		break;
	case 2:
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Yellow, TEXT("Move Back"));
		NewActorLocation.X += -20;
		SetActorLocation(NewActorLocation);
		break;
	case 3:
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Yellow, TEXT("Move Left"));
		NewActorLocation.Y += -20;
		SetActorLocation(NewActorLocation);
		break;
	case 4:
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Yellow, TEXT("Move Right"));
		NewActorLocation.Y += 20;
		SetActorLocation(NewActorLocation);
		break;
	}
}

void AMyActor::Turn()
{
	int RandomHalfNum = FMath::RandRange(1, 2);
	FRotator NewActorRotation = GetActorRotation();
	switch (RandomHalfNum) {
	case 1:
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Blue, TEXT("Turn Left"));
		NewActorRotation.Yaw += 90;
		SetActorRotation(NewActorRotation);
		break;
	case 2:
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Blue, TEXT("Turn Right"));
		NewActorRotation.Yaw += -90;
		SetActorRotation(NewActorRotation);
		break;
	}

}

void AMyActor::Event() 
{
	int RandomHalfNum = FMath::RandRange(1, 2);
	FVector NewActorLocation = GetActorLocation();
	switch (RandomHalfNum) {
	case 1:
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, TEXT("Event Occurs! Z Location +20!!"));
		NewActorLocation.Z += 20;
		SetActorLocation(NewActorLocation);
		break;
	case 2:
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, TEXT("Event Occurs! Z Location -20!!"));
		NewActorLocation.Z += -20;
		SetActorLocation(NewActorLocation);
		break;
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, TEXT("Move Start!"));
		int MoveCount = 0;
		int EventCount = 0;
		for (int i = 0; i < 10; i++) {
			int RandomHalfNum1 = FMath::RandRange(1, 2);
			if (RandomHalfNum1 == 1) {
				Move();
				MoveCount++;
			}
			else {
				Turn();
				MoveCount++;
			}
			int RandomHalfNum2 = FMath::RandRange(1, 2);
			if (RandomHalfNum2 == 1) {
				Event();
				EventCount++;
			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red, TEXT("Event Not Occurs..."));
			}
			
			FVector NowLocation = GetActorLocation();
			FString CurrentLocation = FString::Printf(TEXT("Current Location X: %.1f  Y : %.1f  Z: %.1f  Move: %d"), NowLocation.X, NowLocation.Y, NowLocation.Z,MoveCount);
			GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, CurrentLocation);
		}
		FString CombineCount = FString::Printf(TEXT(" Event: %d"),EventCount);
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Green, CombineCount);
	}
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

