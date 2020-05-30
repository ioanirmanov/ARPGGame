// Fill out your copyright notice in the Description page of Project Settings.

#include "IObject.h"



IObject::IObject()
{
}

IObject::~IObject()
{
}

DialogueObject IObject::GetDialogueObject(int ObjectNo)
{
	if (ObjectNo < DialogueObjects.size())
		return DialogueObjects[ObjectNo];
	else
	{
		return DialogueObjects[DialogueObjects.size() - 1];
	}
}

int IObject::GetDialogueOnPress()
{
	return DialogueONPress;
}

void IObject::SetDialogueOnPress(int Index)
{
	DialogueONPress = Index;
}

void IObject::AddDialogueObject(DialogueObject Obj)
{
	DialogueObjects.push_back(Obj);
}
