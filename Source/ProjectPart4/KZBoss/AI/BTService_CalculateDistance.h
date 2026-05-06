// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_CalculateDistance.generated.h"

/**
 * 보스와 타겟(플레이어) 사이의 거리를 계산하여 블랙보드에 저장하는 서비스입니다.
 */
UCLASS()
class PROJECTPART4_API UBTService_CalculateDistance : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_CalculateDistance();

protected:
	/** 매 프레임(또는 설정된 간격마다) 실행되는 로직 */
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
