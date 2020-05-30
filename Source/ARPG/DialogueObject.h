// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

enum EBoxType
{
	Titled,
	TitledImage
};

enum EDialogueType
{
	NewPage,
	NewLine,
	SetTitle,
	FreezePlayer,
	UnFreezePlayer,
	EventCommand,
};



struct FDialogueItem
{
	//UPROPERTY(EditAnywhere, Category = "Systems", BlueprintReadWrite)
	EDialogueType Type;
	//UPROPERTY(EditAnywhere, Category = "Systems", BlueprintReadWrite)
	FString String;
	//UPROPERTY(EditAnywhere, Category = "Systems", BlueprintReadWrite)
	FString SourceType;
	//UPROPERTY(EditAnywhere, Category = "Systems", BlueprintReadWrite)
    int Source;
};

/**
 * 
 */
class ARPG_API DialogueObject
{
public:
	DialogueObject();
	~DialogueObject();
	void AddDialogueItem(FDialogueItem Item);
	int GetDialogueItemsLength();
	FDialogueItem* GetDialogueItem(int Index);
	void SetBoxType(EBoxType NewType);
	EBoxType GetBoxType();
private:
	//UPROPERTY(EditAnywhere, Category = "Systems", BlueprintReadWrite)
	TArray<FDialogueItem> DialogueItems;
	FString Tag;
	EBoxType BoxType;
};
