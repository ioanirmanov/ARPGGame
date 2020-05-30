// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LevelEditPawn.generated.h"

UCLASS()
class ARPG_API ALevelEditPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALevelEditPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//Camera
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		class UCameraComponent* Cam;
	
		
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	class UMapEditor* mapEditor;


	void HandleClick();
	void HandleClickReleased();
	void HandleScrollWheelClick();
	void HandleScrollWheelReleased();
	void HandleScrollWheelUp();
	void HandleScrollWheelDown();
};
