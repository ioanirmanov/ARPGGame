// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LevelEditHUD.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API ALevelEditHUD : public AHUD
{
	GENERATED_BODY()
	
	
public:

	ALevelEditHUD();

	TSharedPtr<class SLevelEditWidget> MyUIWidget; // Reference to the main chat widget
	

	int thing = 1032;

protected:

	virtual void PostInitializeComponents() override; // All game elements are created, add our chat box
	
	virtual void DrawHUD() override;

	
	
};
