// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"

/**
 * 
 */
class ARPG_API STileSetWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(STileSetWidget) : _OwnerHUD() {} // the OwnerHUD var is passed to the widget so the owner can be set.

	SLATE_ARGUMENT(TWeakObjectPtr<class ALevelEditHUD>, OwnerHUD)
   
    
	SLATE_ATTRIBUTE(class SLevelEditWidget*, LevelEditWidget)
	SLATE_ATTRIBUTE(class UMapEditor*, mEdit)
	SLATE_ATTRIBUTE(class UTexture2D*, TileImage)
    SLATE_ATTRIBUTE(int, TileIndex)
    SLATE_ATTRIBUTE(FText, TileName)
	
    SLATE_END_ARGS()
public:


	TWeakObjectPtr<class ALevelEditHUD> OwnerHUD;

	void Construct(const FArguments& InArgs);
	void OnNameChanged(const FText& InText, ETextCommit::Type InCommitInfo);
	STileSetWidget();
	~STileSetWidget();

	bool Selected = false;
	FText Name = FText::FromString("New Tile");


	class SLevelEditWidget* lvlEdtWdgt;
	UPROPERTY()
	TSharedPtr<class UMapEditor> mapEditor;

	TAttribute<FLinearColor> colour;
	FLinearColor GetColour() const;
	FReply OnTileClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
protected:
	FSlateBrush ItemBrush;
};
