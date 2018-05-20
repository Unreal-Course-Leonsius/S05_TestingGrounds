// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard_C.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API APatrollingGuard_C : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()


	UPROPERTY(EditInstanceOnly, Category = "Patrol Rout")
	TArray<AActor*> PatrolPointsCPP;

public:

	TArray<AActor*> GetPatrolPointsCPP();
	
};
