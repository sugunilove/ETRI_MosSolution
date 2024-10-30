// Fill out your copyright notice in the Description page of Project Settings.


#include "DHSharedMomoryActor.h"
#include "DHSharedMemory.h"

// Sets default values
ADHSharedMomoryActor::ADHSharedMomoryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADHSharedMomoryActor::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void ADHSharedMomoryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Read_SharedMemory(DeltaTime);

}

void ADHSharedMomoryActor::Read_SharedMemory(float DeltaTime)
{
	double newStamp;
	memcpy(&newStamp, pmapFile_Vital_Time, DH_DATA_SIZE);
	if (timeStamp == newStamp)
	{
		return;
	}

	timeStamp = newStamp;
	double ppg_value, hr_value;
	memcpy(&ppg_value, pmapFile_Vital_PPG, DH_DATA_SIZE);
	memcpy(&hr_value, pmapFile_Vital_HR, DH_DATA_SIZE);

	CallSharedMemoryData(ppg_value, hr_value*DeltaTime);
}
