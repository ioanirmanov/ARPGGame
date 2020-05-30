// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogueSystem.h"
#include "DialogueBox.h"
#include "TitledDialogueBox.h"
#include "DialogueObject.h"
#include "TitledDialogueBox.h"
#include "GameManagment.h"
#include "PlayerPawn.h"


// Sets default values for this component's properties
UDialogueSystem::UDialogueSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UDialogueSystem::AddDialogueObject(DialogueObject NewObject)
{
	DialogueQueue.Add(NewObject);
	if (!DialogueBoxPtr)
	{
		DisplayTitledBox();
		MoveToNextObj = true;
	}
}


// Called when the game starts
void UDialogueSystem::BeginPlay()
{
	Super::BeginPlay();
	/* Test
	DialogueObject DObj;
	FDialogueItem DItemTitle;
	DItemTitle.Type = SetTitle;
	DItemTitle.String = "Title";
	FDialogueItem Freeze;
	Freeze.Type = FreezePlayer;
	Freeze.String = "";
	DObj.AddDialogueItem(DItemTitle);
	DObj.AddDialogueItem(Freeze);
	FDialogueItem DItem;
	DItem.Type = NewLine;
	DItem.String = 
		"AAAAAAAAAA";
		//"Test Test Test Test Test Test Test Test Test Test Test Test Test";
	DObj.AddDialogueItem(DItem);
	DObj.AddDialogueItem(DItem);
	DObj.AddDialogueItem(DItem);
	DObj.AddDialogueItem(DItem);
	DObj.AddDialogueItem(DItem);
	DObj.AddDialogueItem(DItem);
	DObj.AddDialogueItem(DItem);
	DObj.AddDialogueItem(DItem);
	DObj.AddDialogueItem(DItem);
	FDialogueItem UnFreeze;
	UnFreeze.Type = UnFreezePlayer;
	UnFreeze.String = "";
	AddDialogueObject(DObj);
	DObj.AddDialogueItem(UnFreeze);
	UE_LOG(LogTemp, Warning, TEXT("DialogueQueue Num: %i"), DialogueQueue.Num());
	UE_LOG(LogTemp, Warning, TEXT("Items Num: %i"), DObj.GetDialogueItemsLength());
	*/
	// ...
	
}


// Called every frame
void UDialogueSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (DialogueBoxPtr)
	{
		UpdateDialogue();
		//UE_LOG(LogTemp, Warning, TEXT("Updating Dialogue"));
	}
	
}

void UDialogueSystem::UpdateDialogue()
{

	while (MoveToNextObj)
	{
		CurrentDialogueIndex++;
		UE_LOG(LogTemp, Warning, TEXT("DialogueQueue Num: %i"), DialogueQueue.Num());
		UE_LOG(LogTemp, Warning, TEXT("Items Num: %i"), DialogueQueue[0].GetDialogueItemsLength());
		
		if(CurrentDialogueIndex > DialogueQueue[0].GetDialogueItemsLength() - 1)
		{
			CurrentDialogueIndex = -1;
			DialogueQueue.RemoveAt(0);
			if (DialogueQueue.Num() == 0)
			{
				DialogueBoxPtr->Destroy();
				DialogueBoxPtr = 0;
				MoveToNextObj = false;
			}
		}
		else if (DialogueQueue[0].GetDialogueItem(CurrentDialogueIndex)->Type == EDialogueType::NewLine)
		{
			AddLine(DialogueQueue[0].GetDialogueItem(CurrentDialogueIndex)->String);
			MoveToNextObj = false;
		}
		else if (DialogueQueue[0].GetDialogueItem(CurrentDialogueIndex)->Type == EDialogueType::SetTitle)
		{
			ChangeTitle(DialogueQueue[0].GetDialogueItem(CurrentDialogueIndex)->String);
		}
		else if (DialogueQueue[0].GetDialogueItem(CurrentDialogueIndex)->Type == EDialogueType::NewPage)
		{
			NewPage();
		}
		else if (DialogueQueue[0].GetDialogueItem(CurrentDialogueIndex)->Type == EDialogueType::FreezePlayer)
		{
			GameManComp->GetPlayerPawn()->FreezePlayer();
			//UE_LOG(LogTemp, Warning, TEXT("Player Frozen"));
		}
		else if (DialogueQueue[0].GetDialogueItem(CurrentDialogueIndex)->Type == EDialogueType::UnFreezePlayer)
		{
			GameManComp->GetPlayerPawn()->UnFreezePlayer();
			//UE_LOG(LogTemp, Warning, TEXT("Player Unfrozen"));
		}
		
	}
}

void UDialogueSystem::AddLine(FString Line)
{
	DialogueBoxPtr->AddLine(Line);
}

void UDialogueSystem::NewPage()
{
	DialogueBoxPtr->ClearText();
}

void UDialogueSystem::DisplayTitledBox()
{
	DialogueBoxPtr = GetWorld()->SpawnActor<ADialogueBox>(TitleBox, FVector::ZeroVector, FRotator::ZeroRotator);
}

void UDialogueSystem::ChangeTitle(FString NewTitle)
{
	((ATitledDialogueBox*)DialogueBoxPtr)->ChangeTitle(NewTitle);
}

void UDialogueSystem::ChangeText(FString NewText)
{

}

void UDialogueSystem::OnButtonPress()
{
	UE_LOG(LogTemp, Warning, TEXT("OnButtonPress"));
	if (DialogueBoxPtr)
	{
		MoveToNextObj = true;
	}
}


void UDialogueSystem::MoveBoxToCam(float CamX, float CamY, float OrthoWidth, float AspRatio)
{
	if(DialogueBoxPtr) DialogueBoxPtr->MoveToCamPos(CamX, CamY, OrthoWidth, AspRatio);

}

bool UDialogueSystem::BoxDisplayed()
{
	return DialogueBoxPtr;
}

void UDialogueSystem::SetGameManComp(class UGameManagment* GameManCompPtr)
{
	GameManComp = GameManCompPtr;
}
