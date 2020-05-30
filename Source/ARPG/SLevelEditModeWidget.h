// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"



/**
 * 
 */
class ARPG_API SLevelEditModeWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLevelEditModeWidget) : _OwnerHUD() {} // the OwnerHUD var is passed to the widget so the owner can be set.

	SLATE_ARGUMENT(TWeakObjectPtr<class ALevelEditHUD>, OwnerHUD)
	SLATE_ATTRIBUTE(class UTexture2D*, SelectTileTexture)
	SLATE_ATTRIBUTE(class UTexture2D*, ChangeTileTexture)
	SLATE_ATTRIBUTE(class UTexture2D*, DeleteTileTexture)
	SLATE_ATTRIBUTE(class UTexture2D*, MoveCameraTexture)
	SLATE_ATTRIBUTE(int, EditMode)
	SLATE_END_ARGS()
	
	TWeakObjectPtr<class ALevelEditHUD> OwnerHUD;
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TSharedPtr<SImage> Image;

	void SetImage(UTexture2D* Texture);

	FReply OnSelectClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	FReply OnChangeClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	FReply OnDeleteClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	FReply OnMoveClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

	int EditMode;
protected:
	FSlateBrush SelectBrush;
	FSlateBrush ChangeBrush;
	FSlateBrush DeleteBrush;
	FSlateBrush MoveBrush;
};
