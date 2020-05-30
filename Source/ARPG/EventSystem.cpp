// Fill out your copyright notice in the Description page of Project Settings.

#include "EventSystem.h"
#include "GameManagment.h"

EventSystem::EventSystem()
{
}

void EventSystem::SetUp()
{
	for (int i = 0; i < CommandNo; i++)
	{
		FunctionMap.Add(Commands[0], i);
	}
	
}

EventSystem::~EventSystem()
{
}

void EventSystem::TriggerEvent(FString Command)
{
	Command = Command.ToUpper();
	TArray<FString> cmdArr;
	Command.ParseIntoArray(cmdArr, TEXT(" "), true);
	if (FunctionMap.Contains(cmdArr[0]))
	{
		int FuncIndex = *FunctionMap.Find(cmdArr[0]);
		if (FuncIndex < CommandNo && FuncIndex >= 0)
		{
			cmdArr.RemoveAt(0);
			if (FuncArray[FuncIndex] != NULL)
			{
				(this->*(FuncArray[FuncIndex]))(cmdArr);
			}
		}
	}
	cmdArr.Empty();
}

void EventSystem::LoadLevel(TArray<FString> Args)
{
	FString MapName = Args[0];
	int startx = FCString::Atoi(*Args[1]);
	int starty = FCString::Atoi(*Args[2]);
	//Add error checking
	GameManComp->LoadMap(MapName, startx, starty);
}

void EventSystem::SetGameManComp(class UGameManagment* GameManCompPtr)
{
	GameManComp = GameManCompPtr;
}
