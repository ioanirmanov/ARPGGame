// Fill out your copyright notice in the Description page of Project Settings.

#include "SLevelEditProperties.h"
#include "SWidget.h"
#include "Engine.h"

void SLevelEditProperties::Construct(const FArguments& InArgs)
{
	
	ChildSlot
	.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
	[
		// Populate the widget
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Grid Size: 3x3")))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Change")))
		]
		]
		
	];
	
}

