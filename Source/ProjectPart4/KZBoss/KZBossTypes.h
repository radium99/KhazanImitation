// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KZBossTypes.generated.h"

UENUM(BlueprintType)
enum class EBossPhase : uint8
{
    Phase1_Normal_A     UMETA(DisplayName = "1-1 (Normal Standard)"),
    Phase1_Normal_B     UMETA(DisplayName = "1-2 (Normal Enraged)"),
    Phase2_Trans_A      UMETA(DisplayName = "2-1 (Transform Standard)"),
    Phase2_Trans_B      UMETA(DisplayName = "2-2 (Transform Berserk)")
};
