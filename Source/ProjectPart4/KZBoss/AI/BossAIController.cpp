// Fill out your copyright notice in the Description page of Project Settings.


#include "KZBoss/AI/BossAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "KZBoss/KZBossViperCharacter.h" // 보스 캐릭터 참조를 위해 추가

ABossAIController::ABossAIController()
{
    // 1. 블랙보드 컴포넌트 생성
    BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void ABossAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (BTBoss && BTBoss->BlackboardAsset)
    {
        // 1. 블랙보드 사용 시작
        if (UseBlackboard(BTBoss->BlackboardAsset, BlackboardComp))
        {
            BlackboardComp->SetValueAsFloat(FName("Distance"), 99999.0f);
            
            // 2. 행동트리 실행
            RunBehaviorTree(BTBoss);

            // 3. 보스 캐릭터로부터 초기 페이즈를 가져와 블랙보드에 동기화
            AKZBossViperCharacter* Viper = Cast<AKZBossViperCharacter>(InPawn);
            if (Viper)
            {
                BlackboardComp->SetValueAsEnum(FName("CurrentPhase"), (uint8)Viper->CurrentPhase);
            }

            // 4. 플레이어 타겟 설정 (지연 실행 포함)
            RetrySetTarget();
            
        }
    }
}

void ABossAIController::RetrySetTarget()
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if (PlayerPawn)
    {
        BlackboardComp->SetValueAsObject(FName("PlayerPos"), PlayerPawn);
        UE_LOG(LogTemp, Warning, TEXT("Boss AI: Successfully set PlayerPos."));
    }
    else
    {
        // 플레이어를 못 찾았다면 0.2초 뒤에 다시 시도
        FTimerHandle TimerHandle;
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ABossAIController::RetrySetTarget, 0.2f, false);
        UE_LOG(LogTemp, Log, TEXT("Boss AI: Player not ready, retrying in 0.2s..."));
    }
}

void ABossAIController::UpdatePhase(EBossPhase NewPhase)
{
    if (BlackboardComp)
    {
        // 블랙보드 키 이름을 "CurrentPhase"로 통일
        BlackboardComp->SetValueAsEnum(FName("CurrentPhase"), static_cast<uint8>(NewPhase));
    }
}
