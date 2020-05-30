// Fill out your copyright notice in the Description page of Project Settings.

#include "TileSetWidget.h"
#include "LevelEditHUD.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "SWidget.h"
#include "LevelEditWidget.h"
#include "MapEditor.h"

STileSetWidget::STileSetWidget()
{
}

STileSetWidget::~STileSetWidget()
{
	//mapEditor.Reset();
	//mapEditor = nullptr;
	//lvlEdtWdgt = nullptr;
}



void STileSetWidget::Construct(const FArguments& InArgs)
{

	OwnerHUD = InArgs._OwnerHUD;
	if (InArgs._LevelEditWidget.IsSet())
	{
		lvlEdtWdgt = InArgs._LevelEditWidget.Get();

	}
	if (InArgs._mEdit.IsSet())
	{
		mapEditor = MakeShareable(InArgs._mEdit.Get());
	}
	if (InArgs._TileName.IsSet())
	{
		Name = InArgs._TileName.Get();
	}

	TSharedPtr<SBox> Box;
	TSharedPtr<SOverlay> Overlay;
	colour.Bind(this, &STileSetWidget::GetColour);
	if (InArgs._TileImage.IsSet())
	{
		ItemBrush.SetResourceObject(InArgs._TileImage.Get());
		ItemBrush.ImageSize.X = InArgs._TileImage.Get()->GetSurfaceWidth();
		ItemBrush.ImageSize.Y = InArgs._TileImage.Get()->GetSurfaceHeight();
		ItemBrush.DrawAs = ESlateBrushDrawType::Image;
		ChildSlot
			.VAlign(VAlign_Top)
			.HAlign(HAlign_Center)
			.Padding(0)
			[
				SAssignNew(Overlay, SOverlay)
				+ SOverlay::Slot()
			[
				SAssignNew(Box, SBox)
				.HeightOverride(100.0f)
			.WidthOverride(400.0f)
			[
				SNew(SColorBlock)
				.Color(colour)
			]
			]
		+ SOverlay::Slot()
			[
				SNew(SHorizontalBox)// outter container
				+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SBox)
				.WidthOverride(100.0f)
			.HeightOverride(100.0f)
			[
				SNew(SImage)
				.Image(&ItemBrush)


			]

			]
		+ SHorizontalBox::Slot()
			.Padding(15)
			.AutoWidth()
			[
				SNew(SBox)
				.WidthOverride(300.0f)
			[
				SNew(SEditableText)
				.Text(Name)
			.OnTextCommitted(this, &STileSetWidget::OnNameChanged)


			.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
			]

			]
			]


			];
	}
	else
	{
		ChildSlot
			.VAlign(VAlign_Top)
			.HAlign(HAlign_Left)
			.Padding(15)
			// move the chat box out from the corner 
			[
				SNew(SHorizontalBox)// outter container
				+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SAssignNew(Box, SBox)
				.WidthOverride(100.0f)
			.HeightOverride(100.0f)
			[
				SNew(SImage)


			]
			]
		+ SHorizontalBox::Slot()
			.Padding(15)
			.AutoWidth()
			[
				SNew(SBox)
				.WidthOverride(300.0f)
			[
				SNew(SEditableText)
				.Text(FText::FromString("New Tile Name"))
			.Font(FSlateFontInfo(FPaths::GameDir() / TEXT("UI/Fonts/Gothic.ttf"), 24))
			]

			]

			];
	}

	Overlay->SetOnMouseDoubleClick(FPointerEventHandler::CreateRaw(this, &STileSetWidget::OnTileClicked));

}

FReply STileSetWidget::OnTileClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
    Selected = true;
	return FReply::Handled();
}

FLinearColor STileSetWidget::GetColour() const
{		
	if (Selected) return FColor::Blue;		
	else return FColor::Black;
}

void STileSetWidget::OnNameChanged(const FText& InText, ETextCommit::Type InCommitInfo)
{
	Name = InText;
}
