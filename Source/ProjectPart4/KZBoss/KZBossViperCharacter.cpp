// Fill out your copyright notice in the Description page of Project Settings.


#include "KZBoss/KZBossViperCharacter.h"

// Sets default values
AKZBossViperCharacter::AKZBossViperCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentSpeed = 0.0f;
	CurrentPhase = EBossPhase::Phase1_Normal_A;
}

// Called when the game starts or when spawned
void AKZBossViperCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKZBossViperCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 현재 속도를 계산하여 저장 (애니메이션 블루프린트에서 참조됨)
	CurrentSpeed = GetVelocity().Size();
	// 공중에 뜰 때 걷는 애니메이션이 나오는 것이 싫다면 -> GetVelocity().Size2D()로 변경하자.
}

// Called to bind functionality to input
void AKZBossViperCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
