// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogueBox.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"
#include "Runtime/Engine/Classes/Engine/Font.h"



// Sets default values
ADialogueBox::ADialogueBox()
{
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("BoxBase"));
	}

	
	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BoxSprite"));
	Sprite->AttachTo(RootComponent);
	
	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("BoxText"));
	Text->AttachTo(RootComponent);
	
}

// Called when the game starts or when spawned
void ADialogueBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADialogueBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADialogueBox::UpdateText()
{
	Text->SetText(FText::FromString(CurrentText));
}

void ADialogueBox::AddLine(FString Line)
{

	FString NewLine = Line;
	//Split Lines
	TArray<FString> Lines;
	int TextWidth, TextHeight;// = (NewLine.Len() + 1) * Text->WorldSize;
	Text->Font->GetStringHeightAndWidth(NewLine, TextHeight, TextWidth);

	UE_LOG(LogTemp, Warning, TEXT("TextWidth %i"), TextWidth);
	while (TextWidth > BoxWidth)
	{
		int StartSearchIndex = floor((BoxWidth / Text->WorldSize) - 1);
		int SearchWidth;
		Text->Font->GetStringHeightAndWidth(NewLine.Mid(0, StartSearchIndex), TextHeight, SearchWidth);
		while (SearchWidth >= BoxWidth)
		{
			StartSearchIndex--;
			Text->Font->GetStringHeightAndWidth(NewLine.Mid(0, StartSearchIndex), TextHeight, SearchWidth);
		}
		int LastSpaceIndex = NewLine.Find(FString(" "), ESearchCase::IgnoreCase, ESearchDir::FromEnd, StartSearchIndex);
		UE_LOG(LogTemp, Warning, TEXT("LastSpaceIndex %i"), LastSpaceIndex);
		UE_LOG(LogTemp, Warning, TEXT("StartSearchIndex %i"), StartSearchIndex);
		if (LastSpaceIndex != -1)
		{
			Lines.Add(NewLine.Mid(0, LastSpaceIndex + 1));
			NewLine = NewLine.RightChop(LastSpaceIndex + 1);
		}
		else
		{
			Lines.Add(NewLine.Mid(0, StartSearchIndex));
			NewLine = NewLine.RightChop(StartSearchIndex);
		}
		Text->Font->GetStringHeightAndWidth(NewLine, TextHeight, TextWidth);
	}
	Lines.Add(NewLine);
	UE_LOG(LogTemp, Warning, TEXT("NewHeight %i"), (UsedLines + Lines.Num()) * TextHeight);
	//If Lines will be more than can fit clear box
	if ((UsedLines + Lines.Num()) * TextHeight > BoxHeight)
	{
		CurrentText = "";
		UsedLines = 0;
	}
	for (int i = 0; i < Lines.Num(); i++)
	{
		if (!CurrentText.Equals(FString("")))
			CurrentText.Append(FString("\n"));
		CurrentText.Append(Lines[i]);
		UsedLines++;
	}
	
	
	UE_LOG(LogTemp, Warning, TEXT("OnButtonPress"));
	UpdateText();
}

void ADialogueBox::ClearText()
{
	CurrentText = "";
	UpdateText();
}

void ADialogueBox::MoveToCamPos(float CamX, float CamY, float OrthoWidth, float AspRatio)
{
	float CamHeight = OrthoWidth / AspRatio;
	float BoxY = CamY - ((CamHeight / 2) - DisplayHeight);
	this->SetActorLocation(FVector(CamX, 30, BoxY));
}
	
