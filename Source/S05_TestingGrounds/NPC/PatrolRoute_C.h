// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute_C.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TESTINGGROUNDS_API UPatrolRoute_C : public UActorComponent
{
	GENERATED_BODY()

public:

	TArray<AActor*> GetPatrolPointsCPP() const;

private:

	UPROPERTY(EditInstanceOnly, Category = "Patrol Rout")
	TArray<AActor*> PatrolPointsCPP;

		/// ======== we need not this functions ========
/*
public:	
	// Sets default values for this component's properties
	UPatrolRoute_C();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
*/
};
