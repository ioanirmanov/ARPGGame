// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



/**
 * 
 */
class ARPG_API EventSystem
{
public:
	EventSystem();
	~EventSystem();
	void SetUp();
	void TriggerEvent(FString Command);
	void SetGameManComp(class UGameManagment* GameManCompPtr);
private:
	static const int CommandNo = 1;
	FString Commands[CommandNo] = { TEXT("LOADLEVEL") };
	TMap < FString, int> FunctionMap;
	void(EventSystem::*FuncArray[CommandNo])(TArray<FString>) = { &EventSystem::LoadLevel };
	void LoadLevel(TArray<FString> Args);

	class UGameManagment* GameManComp;
};
