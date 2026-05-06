// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KZBossTypes.h"
#include "KZBossViperCharacter.generated.h"

UCLASS()
class PROJECTPART4_API AKZBossViperCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKZBossViperCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 공격 실행 함수 (몽타주 재생)
	UFUNCTION(BluePrintCallable, Category="Combat")
	void PlayAttackMontage();

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Combat")
	class UAnimMontage* BasicAttackMontage;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 매 프레임 속도 계산을 위해 Tick을 활용합니다.
	virtual void Tick(float DeltaTime) override;

public:	

	// 애니메이션 블루프린트에서 읽을 수 있도록 속도 변수 추가
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float CurrentSpeed;

	// 보스 페이즈
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boss State")
	EBossPhase CurrentPhase;
};
