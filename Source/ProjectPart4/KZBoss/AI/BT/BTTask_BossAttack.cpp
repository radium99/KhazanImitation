// Fill out your copyright notice in the Description page of Project Settings.


#include "KZBoss/AI/BT/BTTask_BossAttack.h"
#include "KZBoss/KZBossViperCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_BossAttack::UBTTask_BossAttack()
{
}

EBTNodeResult::Type UBTTask_BossAttack::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory)
{
	CachedOwerComp = &OwnerComp;
	AAIController* AIController = OwnerComp.GetAIOwner();
	AKZBossViperCharacter* Boss = Cast<AKZBossViperCharacter>(AIController->GetPawn());
	UE_LOG(LogTemp, Warning, TEXT("Attack Task: ExecuteTask Started!"));


	if (Boss)
	{
		// 공격 애니메이션이 재생될 때, 이동을 멈추도록 설정
		AIController->StopMovement();

		// 공격 애니메이션 재생 (KZBossViperCharacter 클래스에 PlayAttackMontage 함수 호출)
		Boss->PlayAttackMontage();

		// 공격 시작 상태임을 블랙보드에 알림
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(FName("isAttacking"), true);
	
		// 애니메이션 종료 대기 모드로 진입.
		return EBTNodeResult::InProgress;
	}

	return EBTNodeResult::Failed;
}

void UBTTask_BossAttack::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
}
