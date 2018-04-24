// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "ChooseNextWaypoint_C.h"
#include "PatrolRoute_C.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint_C::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	
	// Get PatrolRoute Component
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute_C>();
	if (!ensure(PatrolRoute)) { UE_LOG(LogTemp, Warning, TEXT("PatrolRoutes Not Found !!!")); return EBTNodeResult::Failed; }

	// Get PatrolPoints
	 PatrolPoints = ControlledPawn->FindComponentByClass<UPatrolRoute_C>()->GetPatrolPointsCPP();
	if (ensure(PatrolPoints.Num() == 0)) { UE_LOG(LogTemp, Warning, TEXT("PatrolPoints is Empty !!!")); return EBTNodeResult::Failed; }


	// Set Next WayPoints
	auto Blackboardkey = OwnerComp.GetBlackboardComponent();
	auto Index = Blackboardkey->GetValueAsInt(IndexKey.SelectedKeyName);  // we can made = GetValueAsInt("IndexKey"); = like this
	Blackboardkey->SetValueAsObject(WayPointkey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle Index
	auto Length = PatrolPoints.Num();
	Index++;
	Index%=Length;
	Blackboardkey->SetValueAsInt(IndexKey.SelectedKeyName, Index);

	//UE_LOG(LogTemp, Warning, TEXT("AI Controller Name: %s"), *AiController->GetName());
	//UE_LOG(LogTemp, Warning, TEXT("Index %i"), Index);
	return EBTNodeResult::Succeeded;
}
