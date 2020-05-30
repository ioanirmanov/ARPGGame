// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterPawn.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"


UCLASS()
class ARPG_API APlayerPawn : public ACharacterPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void HandlePress();

	void FreezePlayer();
	void UnFreezePlayer();

	void PlayerMoveX(float axisValue);
	void PlayerMoveY(float axisValue);

private:

	float CamPosX;
	float CamPosY;

	bool Freeze = false;
};
