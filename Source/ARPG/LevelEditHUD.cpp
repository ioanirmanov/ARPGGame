// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelEditHUD.h"
#include "Engine.h"
#include "LevelEditWidget.h"
#include "MapEditor.h"


ALevelEditHUD::ALevelEditHUD()
{

}

void ALevelEditHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();



	if (GEngine && GEngine->GameViewport) // make sure our screen is ready for the widget
	{
		SAssignNew(MyUIWidget, SLevelEditWidget).OwnerHUD(this); // add the widget and assign it to the var
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MyUIWidget.ToSharedRef()));
	}

	thing = 532;
}

void ALevelEditHUD::DrawHUD()
{
	Super::DrawHUD();
}

