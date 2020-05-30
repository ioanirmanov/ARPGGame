// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelEditWidget.h"
#include "LevelEditHUD.h"
#include "TileSetWidget.h"
#include "SLevelEditModeWidget.h"
#include "SLevelEditProperties.h"
#include "MapEditor.h"
#include "Engine.h"
#include "ARPG.h"


#define LOCTEXT_NAMESPACE "SLevelEditWidget"

SLevelEditWidget::SLevelEditWidget()
{
	
}

FReply SLevelEditWidget::OnSaveMapClicked()
{
	MapEditor->SaveMap();
	return FReply::Handled();
}

FReply SLevelEditWidget::OnOpenMapClicked()
{
	MapEditor->OpenMap();
	return FReply::Handled();
}

FReply SLevelEditWidget::TileSizeDialogueCancel()
{
	RemoveTileSizeDialogue();
	return FReply::Handled();
}

FReply SLevelEditWidget::TileSizeDialogueChange()
{
	int NewSizeX = FCString::Atoi(*NewTileSizeX->GetText().ToString());
	int NewSizeY = FCString::Atoi(*NewTileSizeY->GetText().ToString());
	MapEditor->ChangeTileSize(NewSizeX, NewSizeY);
	RemoveTileSizeDialogue();
	return FReply::Handled();
}

FReply SLevelEditWidget::GridSizeDialogueCancel()
{
	RemoveGridSizeDialogue();
	return FReply::Handled();
}

FReply SLevelEditWidget::GridSizeDialogueChange()
{
	int NewSizeX = FCString::Atoi(*NewGridSizeX->GetText().ToString());
	int NewSizeY = FCString::Atoi(*NewGridSizeY->GetText().ToString());
	int AnchorX = FCString::Atoi(*NewGridAnchorX->GetText().ToString());
	int AnchorY = FCString::Atoi(*NewGridAnchorY->GetText().ToString());
	MapEditor->ChangeGridSize(NewSizeX, NewSizeY, AnchorX, AnchorY);
	RemoveGridSizeDialogue();
	return FReply::Handled();
}

void SLevelEditWidget::RemoveGridSizeDialogue()
{
	Overlay.Get()->RemoveSlot(GridSizeDialogue.ToSharedRef());

}

void SLevelEditWidget::RemoveTileSizeDialogue()
{
	Overlay.Get()->RemoveSlot(TileSizeDialogue.ToSharedRef());

}

void SLevelEditWidget::ShowGridSizeDialogue()
{

	Overlay.Get()->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SAssignNew(GridSizeDialogue,SOverlay)
			+SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SBox)
			
		.WidthOverride(600)
		.HeightOverride(400)
			[
			SNew(SColorBlock)
			.Color(FLinearColor::Black)
			]
			
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		    [
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("     Change Grid Size     ")))
				.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 30))
		    ]
	        + SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
		    [
			     SNew(SHorizontalBox)
				 +SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("New Size X: ")))
				    .Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
				]
			    +SHorizontalBox::Slot()
				[
					SNew(SBorder)
					[
						SAssignNew(NewGridSizeX,SEditableText)
						.Text(FText::FromString(FString::FromInt(MapGridSizeX)))
					    .Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
					]
				]
		    ]
			+ SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("New Size Y: ")))
				.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
				]
			+ SHorizontalBox::Slot()
				[
					SNew(SBorder)
					[
						SAssignNew(NewGridSizeY, SEditableText)
						.Text(FText::FromString(FString::FromInt(MapGridSizeY)))
				.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
					]
				]
				]
		
	+ SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("Old Anchor X: ")))
				.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
				]
			+ SHorizontalBox::Slot()
				[
					SNew(SBorder)
					[
						SAssignNew(NewGridAnchorX, SEditableText)
						.Text(FText::FromString(TEXT("0")))
				.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
					]
				]
				]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Old Anchor Y: ")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SBorder)
			[
				SAssignNew(NewGridAnchorY, SEditableText)
				.Text(FText::FromString(TEXT("0")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
			]
		]
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Change Size")))
		.OnClicked(this, &SLevelEditWidget::GridSizeDialogueChange)
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Cancel")))
		.OnClicked(this, &SLevelEditWidget::GridSizeDialogueCancel)
		]
		]
	]

		];
		
}
void SLevelEditWidget::ShowTileSizeDialogue()
{
	Overlay.Get()->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SAssignNew(TileSizeDialogue, SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SBox)

			.WidthOverride(600)
		.HeightOverride(400)
		[
			SNew(SColorBlock)
			.Color(FLinearColor::Black)
		]

		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("     Change Tile Size     ")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 30))
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("New Size X: ")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SBorder)
			[
				SAssignNew(NewTileSizeX, SEditableText)
				.Text(FText::FromString(FString::FromInt(MapTileSizeX)))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
			]
		]
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("New Size Y: ")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SBorder)
			[
				SAssignNew(NewTileSizeY, SEditableText)
				.Text(FText::FromString(FString::FromInt(MapTileSizeY)))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
			]
		]
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Change Size")))
		.OnClicked(this, &SLevelEditWidget::TileSizeDialogueChange)
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Cancel")))
		.OnClicked(this, &SLevelEditWidget::TileSizeDialogueCancel)
		]
		]
		]

		];
}
void SLevelEditWidget::ReloadPropertiesWidget()
{
	Overlay.Get()->RemoveSlot(PropertiesBox.ToSharedRef());
	Overlay.Get()->AddSlot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Top)
		.Padding(15)
		[

			SAssignNew(PropertiesBox,SOverlay)
			+ SOverlay::Slot()
		[
			SNew(SBox)
			.WidthOverride(500)
		.HeightOverride(600)
		[
			SNew(SColorBlock)
			.Color(FLinearColor::Black)
		]
		]
	+ SOverlay::Slot()
		[
			// Populate the widget
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		[
			
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Properties")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SAssignNew(GridSizeText, STextBlock)
			.Text(GetGridSizeText())
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(100.0f)
		.HeightOverride(20.0f)
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Change")))
		.OnClicked(this, &SLevelEditWidget::ChangeGridClicked)
		]

		]
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SAssignNew(TileSizeText, STextBlock)
			.Text(GetTileSizeText())
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(100.0f)
		.HeightOverride(20.0f)
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Change")))
		.OnClicked(this, &SLevelEditWidget::ChangeTileClicked)
		]

		]
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Tile Properties")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SNew(STextBlock)
			.Text(FText::FromString(TEXT("IsBlocked")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SAssignNew(IsBlockedBox, SCheckBox)
			.IsChecked(GetIsBlockedChecked())
		]
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SNew(STextBlock)
			.Text(FText::FromString(TEXT("IsTrigger")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SAssignNew(IsTriggerBox, SCheckBox)
			.IsChecked(GetIsTriggerChecked())
		]
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Object Layer")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SBorder)
			[
			SAssignNew(ObjectLayerText, SEditableText)
			.Text(FText::FromString(FString::FromInt(ObjectLayer)))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
			]
		]
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Trigger Command")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(100.0f)
		[
			SNew(SBorder)
			[
				SAssignNew(TriggerCommandText, SEditableText)
				.Text(TileTriggerCommand)
				.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
			]
		]
		]

	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SNew(SButton)
			.Text(FText::FromString(TEXT("Save Map")))
		.OnClicked(this, &SLevelEditWidget::OnSaveMapClicked)
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Open Map")))
		.OnClicked(this, &SLevelEditWidget::OnOpenMapClicked)
		]
		]
		]

		]
		];

}

void SLevelEditWidget::LoadEditModeWidget(UTexture2D* SelectTexture, UTexture2D* ChangeTexture, UTexture2D* DeleteTexture, UTexture2D* MoveTexture, int EditMode)
{
	Overlay.Get()->AddSlot()
		.HAlign(HAlign_Center)
		[
			SAssignNew(EditModeWidget, SLevelEditModeWidget)
			.OwnerHUD(OwnerHUD)
		.SelectTileTexture(SelectTexture)
		.ChangeTileTexture(ChangeTexture)
		.DeleteTileTexture(DeleteTexture)
		.MoveCameraTexture(MoveTexture)
		.EditMode(EditMode)
		];
}

void SLevelEditWidget::RemoveEditModeWidget()
{
	Overlay.Get()->RemoveSlot(EditModeWidget.ToSharedRef());
}


void SLevelEditWidget::AddTile(class UMapEditor* mEdit)
{
	TSharedPtr<STileSetWidget> tileWidget;
	TSharedPtr<SLevelEditWidget> lvlEW;
	/*
	ScrollBox.Get()->AddSlot()
		[
			SAssignNew(tileWidget, STileSetWidget)
			.OwnerHUD(OwnerHUD)
		.LevelEditWidget((TSharedPtr<SLevelEditWidget>)this)
		];
	tileWidget->mapEditor = (TSharedPtr<UMapEditor>)mEdit;
	*/
}


void SLevelEditWidget::AddTile(UTexture2D* Texture)
{
	
	TSharedPtr<STileSetWidget> tileWidget;

	UE_LOG(LogTemp, Warning, TEXT("tmp %i \n"), tmp);
	ScrollBox.Get()->AddSlot()
		[
			SAssignNew(tileWidget,STileSetWidget)
			.OwnerHUD(OwnerHUD)
		.LevelEditWidget(this)
		.TileImage(Texture)
		];
	
	//tileWidget->mapEditor = MakeShareable(mEdit);
	TileSetWidgets.Add(tileWidget);
	
}
void SLevelEditWidget::AddTile(UTexture2D* Texture, FString name)
{
	TSharedPtr<STileSetWidget> tileWidget;
	UE_LOG(LogTemp, Warning, TEXT("tmp %i \n"), tmp);
	ScrollBox.Get()->AddSlot()
		[
			SAssignNew(tileWidget, STileSetWidget)
			.OwnerHUD(OwnerHUD)
		.LevelEditWidget(this)
		.TileImage(Texture)
		.TileName(FText::FromString(name))
		];

	TileSetWidgets.Add(tileWidget);
}

void SLevelEditWidget::AddObject(UTexture2D* Texture)
{

	TSharedPtr<STileSetWidget> tileWidget;

	UE_LOG(LogTemp, Warning, TEXT("tmp %i \n"), tmp);
	ObjectScrollBox.Get()->AddSlot()
		[
			SAssignNew(tileWidget, STileSetWidget)
			.OwnerHUD(OwnerHUD)
		.LevelEditWidget(this)
		.TileImage(Texture)
		];

	//tileWidget->mapEditor = MakeShareable(mEdit);
	ObjectTileSetWidgets.Add(tileWidget);

}
void SLevelEditWidget::AddObject(UTexture2D* Texture, FString name)
{
	TSharedPtr<STileSetWidget> tileWidget;
	UE_LOG(LogTemp, Warning, TEXT("tmp %i \n"), tmp);
	ObjectScrollBox.Get()->AddSlot()
		[
			SAssignNew(tileWidget, STileSetWidget)
			.OwnerHUD(OwnerHUD)
		.LevelEditWidget(this)
		.TileImage(Texture)
		.TileName(FText::FromString(name))
		];

	ObjectTileSetWidgets.Add(tileWidget);
}

void SLevelEditWidget::RebuildTileList()
{
	ScrollBox.Get()->ClearChildren();
	TileSetWidgets.Empty();
	for (int i = 0; i < MapEditor->TileSet.Num(); i++)
	{
		AddTile(MapEditor->TileSet[i].texture,MapEditor->TileSet[i].TileName.ToString());
	}
}
void SLevelEditWidget::RebuildObjectList()
{
	ObjectScrollBox.Get()->ClearChildren();
	ObjectTileSetWidgets.Empty();
	for (int i = 0; i < MapEditor->ObjectTileSet.Num(); i++)
	{
		AddObject(MapEditor->ObjectTileSet[i].texture, MapEditor->ObjectTileSet[i].TileName.ToString());
	}
}

void SLevelEditWidget::Construct(const FArguments& InArgs)
{

	OwnerHUD = InArgs._OwnerHUD;

	ChildSlot
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)

		.Padding(0)
		[
			
			SAssignNew(Overlay, SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Top)
		.Padding(15)
		[
			SAssignNew(PropertiesBox, SOverlay)
			+ SOverlay::Slot()
		[
			SNew(SBox)
			.WidthOverride(500)
		.HeightOverride(600)
		[
			SNew(SColorBlock)
			.Color(FLinearColor::Black)
		]
		]
	+ SOverlay::Slot()
		[
			// Populate the widget
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		[

			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Properties")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SAssignNew(GridSizeText, STextBlock)
			.Text(GetGridSizeText())
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(100.0f)
		.HeightOverride(20.0f)
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Change")))
		.OnClicked(this, &SLevelEditWidget::ChangeGridClicked)
		]

		]
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SAssignNew(TileSizeText, STextBlock)
			.Text(GetTileSizeText())
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(100.0f)
		.HeightOverride(20.0f)
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Change")))
		.OnClicked(this, &SLevelEditWidget::ChangeTileClicked)
		]

		]
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Tile Properties")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SNew(STextBlock)
			.Text(FText::FromString(TEXT("IsBlocked")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SAssignNew(IsBlockedBox, SCheckBox)
			.IsChecked(GetIsBlockedChecked())
		]
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SNew(STextBlock)
			.Text(FText::FromString(TEXT("IsTrigger")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SAssignNew(IsTriggerBox, SCheckBox)
			.IsChecked(GetIsTriggerChecked())
		]
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Object Layer")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SBorder)
			[
				SAssignNew(ObjectLayerText, SEditableText)
				.Text(FText::FromString(FString::FromInt(ObjectLayer)))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
			]
		]
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Trigger Command")))
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
		]
	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(100.0f)
		[
			SNew(SBorder)
			[
				SAssignNew(TriggerCommandText, SEditableText)
				.Text(TileTriggerCommand)
		.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
			]
		]
		]

	+ SVerticalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(500.0f)
		.HeightOverride(50.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		[

			SNew(SButton)
			.Text(FText::FromString(TEXT("Save Map")))
		.OnClicked(this, &SLevelEditWidget::OnSaveMapClicked)
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(FText::FromString(TEXT("Open Map")))
		.OnClicked(this, &SLevelEditWidget::OnOpenMapClicked)
		]
		]
		]
		]
		]
			
			+SOverlay::Slot()
	[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
		.MaxWidth(500.0f)
		.Padding(15)
		[
			//TileSetList
			SNew(SVerticalBox) // outter container
			+ SVerticalBox::Slot()
		.VAlign(VAlign_Top)
		    [
				SNew(STextBlock)
				.Text(FText::FromString("Tiles"))
		        .Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 30))
		    ]
			+ SVerticalBox::Slot()
		    .AutoHeight()
		    .MaxHeight(450.f)
		    .VAlign(VAlign_Fill)
		    .HAlign(HAlign_Left)
		     [
				 SNew(SBox)
				 .HeightOverride(450.f)
				 [
					 SAssignNew(ScrollBox, SScrollBox)
				 ]
				
			 ]
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SBox)
					.WidthOverride(100)
				    .HeightOverride(20)
				    [
						SNew(SButton)
						.Text(FText::FromString("Add New"))
				        .OnClicked(this, &SLevelEditWidget::AddTileClicked)
				    ]
				]
			    + SHorizontalBox::Slot()
				.AutoWidth()
				[
					SNew(SBox)
					.WidthOverride(100)
				    .HeightOverride(20)
				    [
					   SNew(SButton)
					   .Text(FText::FromString("Remove"))
					.OnClicked(this, &SLevelEditWidget::RemoveClicked)
				    ]
				]
			]
				//ObjectTileSetlIst
					+ SVerticalBox::Slot()
					[
						SNew(STextBlock)
						.Text(FText::FromString("Objects"))
					.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 30))
					]
				+ SVerticalBox::Slot()
					.AutoHeight()
					.MaxHeight(450.f)
					.VAlign(VAlign_Top)
					.HAlign(HAlign_Left)
					[
						SNew(SBox)
						.HeightOverride(450.f)
					[
						SAssignNew(ObjectScrollBox, SScrollBox)
					]
					]
				+ SVerticalBox::Slot()
					.AutoHeight()
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SBox)
						.WidthOverride(100)
					.HeightOverride(20)
					[
						SNew(SButton)
						.Text(FText::FromString("Add New"))
					.OnClicked(this, &SLevelEditWidget::AddObjectClicked)
					]
					]
				+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SBox)
						.WidthOverride(100)
					.HeightOverride(20)
					[
						SNew(SButton)
						.Text(FText::FromString("Remove"))
					.OnClicked(this, &SLevelEditWidget::RemoveObjectClicked)
					]
					]	
			]	
		]		
		]	
	];

	//AddTile();
}

FReply SLevelEditWidget::AddTileClicked()
{
	//AddTile();
	if (MapEditor)
	{
		MapEditor->AddTile(this);
	}
	return FReply::Handled();
}

FReply SLevelEditWidget::RemoveClicked()
{
	//AddTile();
	if (MapEditor)
	{
		MapEditor->RemoveSelectedTile();
	}
	return FReply::Handled();
}

FReply SLevelEditWidget::AddObjectClicked()
{
	//AddTile();
	if (MapEditor)
	{
		MapEditor->AddObject(this);
	}
	return FReply::Handled();
}

FReply SLevelEditWidget::RemoveObjectClicked()
{
	//AddTile();
	if (MapEditor)
	{
		MapEditor->RemoveSelectedObject();
	}
	return FReply::Handled();
}

FReply SLevelEditWidget::ChangeGridClicked()
{
	ShowGridSizeDialogue();
    //SLevelEditModeWidget* EModeWidget = (SLevelEditModeWidget*)EditModeWidget.Get();
	//EModeWidget->EditMode = 3;
	return FReply::Handled();
}

FReply SLevelEditWidget::ChangeTileClicked()
{
	ShowTileSizeDialogue();
	//SLevelEditModeWidget* EModeWidget = (SLevelEditModeWidget*)EditModeWidget.Get();
	//EModeWidget->EditMode = 3;
	return FReply::Handled();
}


FText SLevelEditWidget::GetGridSizeText()
{
	FText Result = FText::FromString(TEXT("Grid Size: " + FString::FromInt(MapGridSizeX) + "x" + FString::FromInt(MapGridSizeY)));
	return Result;
}

FText SLevelEditWidget::GetTileSizeText()
{
	FText Result = FText::FromString(TEXT("Grid Size: " + FString::FromInt(MapTileSizeX) + "x" + FString::FromInt(MapTileSizeY)));
	return Result;
}

ECheckBoxState SLevelEditWidget::GetIsTriggerChecked()
{
	
	if (IsTileTrigger)
	{
		return ECheckBoxState::Checked;
	}
	else
	{
		return ECheckBoxState::Unchecked;
	}
}

ECheckBoxState SLevelEditWidget::GetIsBlockedChecked()
{

	if (IsTileBlocked)
	{
		return ECheckBoxState::Checked;
	}
	else
	{
		return ECheckBoxState::Unchecked;
	}
}

