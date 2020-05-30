// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCPawn.h"


ANPCPawn::ANPCPawn()
{
	DialogueObject DObj;
	FDialogueItem DItemTitle;
	DItemTitle.Type = SetTitle;
	DItemTitle.String = "NPC";
	FDialogueItem Freeze;
	Freeze.Type = FreezePlayer;
	Freeze.String = "";
	DObj.AddDialogueItem(DItemTitle);
	DObj.AddDialogueItem(Freeze);
	FDialogueItem DItem;
	DItem.Type = NewLine;
	DItem.String ="I am an NPC";
	FDialogueItem DItem2;
	DItem2.Type = NewLine;
	DItem2.String = "Pleased to meet you";
	DObj.AddDialogueItem(DItem);
	DObj.AddDialogueItem(DItem2);
	FDialogueItem UnFreeze;
	UnFreeze.Type = UnFreezePlayer;
	UnFreeze.String = "";
	DObj.AddDialogueItem(UnFreeze);
	AddDialogueObject(DObj);
}

DialogueObject ANPCPawn::GetDialogueObject(int ObjectNo)
{
	if(ObjectNo < DialogueObjects.size())
		return DialogueObjects[ObjectNo];
	else
	{
		return DialogueObjects[DialogueObjects.size() - 1];
	}
}

int ANPCPawn::GetDialogueOnPress()
{
	return DialogueONPress;
}

void ANPCPawn::SetDialogueOnPress(int Index)
{
	DialogueONPress = Index;
}

void ANPCPawn::AddDialogueObject(DialogueObject Obj)
{
	DialogueObjects.push_back(Obj);
}


