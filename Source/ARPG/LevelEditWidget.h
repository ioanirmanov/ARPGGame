// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Slate.h"
#include "SlateGameResources.h"
#include "MapEditor.h"



/**
 * 
 */
class ARPG_API SLevelEditWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SLevelEditWidget) : _OwnerHUD() {} // the OwnerHUD var is passed to the widget so the owner can be set.

	SLATE_ARGUMENT(TWeakObjectPtr<class ALevelEditHUD>, OwnerHUD)

	SLATE_ATTRIBUTE(UTexture2D*, ButtonTexture)

	SLATE_END_ARGS()
public:
	SLevelEditWidget();

	TWeakObjectPtr<class ALevelEditHUD> OwnerHUD;
	
	TSharedPtr<SScrollBox> ScrollBox;
	TSharedPtr<SScrollBox> ObjectScrollBox;

	void AddTile(class UMapEditor* mEdit);
	
	void AddTile(UTexture2D* Texture);

	void AddTile(UTexture2D* Texture, FString name);

	void AddObject(UTexture2D* Texture);

	void AddObject(UTexture2D* Texture, FString name);

	void RebuildTileList();
	void RebuildObjectList();

	void Construct(const FArguments& InArgs);

	class UMapEditor* MapEditor;

	FReply AddTileClicked();
	FReply RemoveClicked();

	FReply AddObjectClicked();
	FReply RemoveObjectClicked();

	FReply ChangeGridClicked();
	FReply ChangeTileClicked();

	TArray<TSharedPtr<SWidget>> TileSetWidgets;

	TArray<TSharedPtr<SWidget>> ObjectTileSetWidgets;

	TSharedPtr<SWidget> EditModeWidget;
	TSharedPtr<SOverlay> Overlay;
	UPROPERTY(EditAnywhere, Category = "Player Properties")
	TSharedPtr<UTexture2D> ChangeTileUnChecked;

	void LoadEditModeWidget(UTexture2D* SelectTexture, UTexture2D* ChangeTexture, UTexture2D* DeleteTexture, UTexture2D* MoveTexture, int EditorMode);
	void RemoveEditModeWidget();
	/*Pointer to resources in GameModule*/
	TSharedPtr<FSlateGameResources> MyUIResources;

	int tmp = 1032;

	TSharedPtr<STextBlock> GridSizeText;
	TSharedPtr<STextBlock> TileSizeText;
	TSharedPtr<SCheckBox> IsBlockedBox;
	TSharedPtr<SCheckBox> IsTriggerBox;
	TSharedPtr<SEditableText> TriggerCommandText;
	TSharedPtr<SEditableText> ObjectLayerText;
	TSharedPtr<SOverlay> PropertiesBox;

	void ReloadPropertiesWidget();


	FText GetGridSizeText();
	FText GetTileSizeText();
    ECheckBoxState GetIsTriggerChecked();
	ECheckBoxState GetIsBlockedChecked();

	bool IsTileTrigger = false;
	bool IsTileBlocked = false;
	int MapGridSizeY = 3;
	int MapGridSizeX = 3;
	int MapTileSizeX = 16;
	int MapTileSizeY = 16;
	int ObjectLayer = 0;
	FText TileTriggerCommand;

	TSharedPtr<SOverlay> GridSizeDialogue;
	TSharedPtr<SEditableText> NewGridSizeX;
	TSharedPtr<SEditableText> NewGridSizeY;
	TSharedPtr<SEditableText> NewGridAnchorX;
	TSharedPtr<SEditableText> NewGridAnchorY;
	TSharedPtr<SOverlay> TileSizeDialogue;
	TSharedPtr<SEditableText> NewTileSizeX;
	TSharedPtr<SEditableText> NewTileSizeY;

	FReply GridSizeDialogueCancel();
	FReply GridSizeDialogueChange();

	FReply TileSizeDialogueCancel();
	FReply TileSizeDialogueChange();

	FReply OnSaveMapClicked();
	FReply OnOpenMapClicked();

	void ShowGridSizeDialogue();
	void RemoveGridSizeDialogue();
	void ShowTileSizeDialogue();
	void RemoveTileSizeDialogue();

	//void RebuildTileSet(TArray<struct FTileSetTile*> tiles);
};
