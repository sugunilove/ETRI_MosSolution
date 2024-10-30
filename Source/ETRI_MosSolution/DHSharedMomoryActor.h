// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DHSharedMomoryActor.generated.h"

UCLASS()
class ETRI_MOSSOLUTION_API ADHSharedMomoryActor : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ADHSharedMomoryActor();

private :
	double timeStamp;
	
	void Read_SharedMemory(float DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintImplementableEvent)
	void CallSharedMemoryData(float ppg, float hr);
};
