// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IInteractableTarget.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIInteractableTarget : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTPART4_API IIInteractableTarget
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	// 타겟의 종류를 반환하는 가상 함수 (예: 플레이어, 환경 요소 등)
	// = 0은 순수 가상 함수로, 상속받는 쪽에서 반드시 구현해야 함을 뜻함(Effective C++ 지침)
	virtual FName GetTargetType() const = 0;

	// AI가 이 대상을 공격 타겟으로 삼을 수 있는지 여부
	virtual bool IsAttackable() const = 0;
public:
};
