// Fill out your copyright notice in the Description page of Project Settings.
/// This is Only Test Class and It's work fine
#pragma once

#include "AIController.h"
#include "Perception/AiPerceptionComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC_AI_C.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API ANPC_AI_C : public AAIController
{
	GENERATED_BODY()
	


public:

	ANPC_AI_C();

	virtual void BeginPlay() override;

	// We can set Blackboard in BP
	UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
	UBlackboardData* BlackboardToUse;

	// We can set BehaviorTree in BP
	UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
	UBehaviorTree* BehaviorTreeToUse;


	// This is the Blackboardcomponent that will be as Return value later. 
	UPROPERTY()
	UBlackboardComponent* BB;

	// Perception component. 
	UPROPERTY(VisibleAnywhere, Category = "AI")
	UAIPerceptionComponent* AIPerception;

	// Main function, when sensing stuff.
	UFUNCTION()
	void SenseStuff(AActor* UpdatedActor, FAIStimulus Stimulus);

	// this is seperate part of the class, we need them only to see which secnse is set in Percieption
	UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
	TSubclassOf<UAISense> HearingSense;

	UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
	TSubclassOf<UAISense> SightSense;
	
	
	
};
