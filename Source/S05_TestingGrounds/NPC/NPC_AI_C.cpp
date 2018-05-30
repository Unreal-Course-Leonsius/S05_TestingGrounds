// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "NPC_AI_C.h"


ANPC_AI_C::ANPC_AI_C()
{

	// It's emty

}

void ANPC_AI_C::BeginPlay()
{

	Super::BeginPlay(); // We run Blueprint-beginplay, if we need it for some reason.

	if (!ensure(BlackboardToUse)) { return; } // We ensure that pointer isn't null
	UseBlackboard(BlackboardToUse, BB);
	if (!ensure(BehaviorTreeToUse)) { return; }// We ensure that BehaviorTree isn't null

	/// BehaviourTree and Blackboard connect each other in Unreal Editor									  
	RunBehaviorTree(BehaviorTreeToUse);   // Run the behavior tree


	// We get the perception component from the components list
	AIPerception = FindComponentByClass<UAIPerceptionComponent>();
	if (!ensure(AIPerception)) { return; }

	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ANPC_AI_C::SenseStuff);

	// It's only test to get all Percieved actors in particlur sense

	//TArray<AActor*> ActorsSensed;  // GetPerceivedActors() function in second argument require array
	//AIPerception->GetPerceivedActors(HearingSense, ActorsSensed);


}

void ANPC_AI_C::SenseStuff(AActor * UpdatedActor, FAIStimulus Stimulus)
{

	// We set Focalpoint if the sense was successfull
	if (Stimulus.WasSuccessfullySensed())
	{
		BB->SetValueAsObject("Enemy", UpdatedActor);
		UE_LOG(LogTemp, Warning, TEXT("Sensing Actor"));
	}
	else
	{
		BB->ClearValue("Enemy");
		UE_LOG(LogTemp, Warning, TEXT("Ain't sensing anything"));
	}

}
