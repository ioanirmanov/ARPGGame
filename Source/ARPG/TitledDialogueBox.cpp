// Fill out your copyright notice in the Description page of Project Settings.

#include "TitledDialogueBox.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"

ATitledDialogueBox::ATitledDialogueBox()
{
	Title = CreateDefaultSubobject<UTextRenderComponent>(TEXT("BoxTitle"));
	Title->AttachTo(RootComponent);
}

void ATitledDialogueBox::ChangeTitle(FString NewTitle)
{
	Title->SetText(FText::FromString(NewTitle));
}


