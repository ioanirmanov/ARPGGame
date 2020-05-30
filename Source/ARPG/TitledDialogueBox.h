// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueBox.h"
#include "TitledDialogueBox.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API ATitledDialogueBox : public ADialogueBox
{
	GENERATED_BODY()
public:
	ATitledDialogueBox();

	void ChangeTitle(FString NewTitle);

private:
	UPROPERTY(EditAnywhere, Category = "Dialogue Box Properties")
		class UTextRenderComponent* Title;
	
};
