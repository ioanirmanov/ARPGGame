// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterPawn.h"
#include "DialogueObject.h"
#include <vector>
#include "NPCPawn.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API ANPCPawn : public ACharacterPawn
{
	GENERATED_BODY()
	
public:
	ANPCPawn();
	DialogueObject GetDialogueObject(int ObjectNo);
	void AddDialogueObject(DialogueObject Obj);
	int GetDialogueOnPress();
	void SetDialogueOnPress(int Index);
private:
	//UPROPERTY(EditAnywhere, Category = "Systems", BlueprintReadWrite)
	std::vector<DialogueObject> DialogueObjects;

	int DialogueONPress = 0; //Which dialogue option to use when next interacted with
};
