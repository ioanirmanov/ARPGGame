// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogueObject.h"

DialogueObject::DialogueObject()
{
}

DialogueObject::~DialogueObject()
{
}

void DialogueObject::AddDialogueItem(FDialogueItem Item)
{
	DialogueItems.Add(Item);
}

FDialogueItem* DialogueObject::GetDialogueItem(int Index)
{
	if (Index > DialogueItems.Num() - 1) Index = DialogueItems.Num() - 1;
	return &DialogueItems[Index];
}

int DialogueObject::GetDialogueItemsLength()
{
	return DialogueItems.Num();
}

void DialogueObject::SetBoxType(EBoxType NewType)
{
	BoxType = NewType;
}

EBoxType DialogueObject::GetBoxType()
{
	return BoxType;
}
