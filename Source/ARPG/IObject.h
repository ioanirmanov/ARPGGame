// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "DialogueObject.h"

/**
 * 
 */
class ARPG_API IObject
{
public:
	IObject();
	~IObject();
	DialogueObject GetDialogueObject(int ObjectNo);
	void AddDialogueObject(DialogueObject Obj);
	int GetDialogueOnPress();
	void SetDialogueOnPress(int Index);
private:
	std::vector<DialogueObject> DialogueObjects;
	int DialogueONPress = 0; //Which dialogue option to use when next interacted with
};
