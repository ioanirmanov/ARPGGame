// Fill out your copyright notice in the Description page of Project Settings.

#include "SLevelEditModeWidget.h"
#include "Engine.h"



void SLevelEditModeWidget::Construct(const FArguments& InArgs)
{
	OwnerHUD = InArgs._OwnerHUD;
	if (InArgs._EditMode.IsSet())
	{
		EditMode = InArgs._EditMode.Get();
	}
	if (InArgs._SelectTileTexture.IsSet() && InArgs._ChangeTileTexture.IsSet()
		&& InArgs._DeleteTileTexture.IsSet() && InArgs._MoveCameraTexture.IsSet())
	{
		SelectBrush.SetResourceObject(InArgs._SelectTileTexture.Get());
		SelectBrush.ImageSize.X = InArgs._SelectTileTexture.Get()->GetSurfaceWidth();
		SelectBrush.ImageSize.Y = InArgs._SelectTileTexture.Get()->GetSurfaceHeight();
		SelectBrush.DrawAs = ESlateBrushDrawType::Image;
		
		ChangeBrush.SetResourceObject(InArgs._ChangeTileTexture.Get());
		ChangeBrush.ImageSize.X = InArgs._ChangeTileTexture.Get()->GetSurfaceWidth();
		ChangeBrush.ImageSize.Y = InArgs._ChangeTileTexture.Get()->GetSurfaceHeight();
		ChangeBrush.DrawAs = ESlateBrushDrawType::Image;

		DeleteBrush.SetResourceObject(InArgs._DeleteTileTexture.Get());
		DeleteBrush.ImageSize.X = InArgs._DeleteTileTexture.Get()->GetSurfaceWidth();
		DeleteBrush.ImageSize.Y = InArgs._DeleteTileTexture.Get()->GetSurfaceHeight();
		DeleteBrush.DrawAs = ESlateBrushDrawType::Image;

		MoveBrush.SetResourceObject(InArgs._MoveCameraTexture.Get());
		MoveBrush.ImageSize.X = InArgs._MoveCameraTexture.Get()->GetSurfaceWidth();
		MoveBrush.ImageSize.Y = InArgs._MoveCameraTexture.Get()->GetSurfaceHeight();
		MoveBrush.DrawAs = ESlateBrushDrawType::Image;

		TSharedPtr<SBox> SelectBox;
		TSharedPtr<SBox> ChangeBox;
		TSharedPtr<SBox> DeleteBox;
		TSharedPtr<SBox> MoveBox;

		ChildSlot
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Bottom)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
			[
				SAssignNew(SelectBox,SBox)
				.WidthOverride(100.0f)
			.HeightOverride(100.0f)
			[
				// Populate the widget
				SAssignNew(Image, SImage)
				.Image(&SelectBrush)
			]
			]
		+ SHorizontalBox::Slot()
			[
				SAssignNew(ChangeBox,SBox)
				.WidthOverride(100.0f)
			.HeightOverride(100.0f)
			[
				// Populate the widget
				SNew(SImage)
				.Image(&ChangeBrush)
			]
			]
		+ SHorizontalBox::Slot()
			[
				SAssignNew(DeleteBox,SBox)
				.WidthOverride(100.0f)
			.HeightOverride(100.0f)
			[
				// Populate the widget
				SNew(SImage)
				.Image(&DeleteBrush)
			]
			]
		+ SHorizontalBox::Slot()
			[
				SAssignNew(MoveBox,SBox)
				.WidthOverride(100.0f)
			.HeightOverride(100.0f)
			[
				// Populate the widget
				SNew(SImage)
				.Image(&MoveBrush)
			]
			]

			];
		SelectBox->SetOnMouseButtonDown(FPointerEventHandler::CreateRaw(this, &SLevelEditModeWidget::OnSelectClicked));
		ChangeBox->SetOnMouseButtonDown(FPointerEventHandler::CreateRaw(this, &SLevelEditModeWidget::OnChangeClicked));
		DeleteBox->SetOnMouseButtonDown(FPointerEventHandler::CreateRaw(this, &SLevelEditModeWidget::OnDeleteClicked));
		MoveBox->SetOnMouseButtonDown(FPointerEventHandler::CreateRaw(this, &SLevelEditModeWidget::OnMoveClicked));
	}
	
}

void SLevelEditModeWidget::SetImage(UTexture2D* Texture)
{
	
	FSlateBrush ItemBrush;
	ItemBrush.SetResourceObject(Texture);
	ItemBrush.ImageSize.X = Texture->GetSurfaceWidth();
	ItemBrush.ImageSize.Y = Texture->GetSurfaceHeight();
	ItemBrush.DrawAs = ESlateBrushDrawType::Image;
	Image->SetImage(&ItemBrush);
	
}

FReply SLevelEditModeWidget::OnSelectClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	UE_LOG(LogTemp, Warning, TEXT("Select Clicked\n"));
	EditMode = 0;
	return FReply::Handled();
}
FReply SLevelEditModeWidget::OnChangeClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	UE_LOG(LogTemp, Warning, TEXT("Change Clicked\n"));
	EditMode = 1;
	return FReply::Handled();
}
FReply SLevelEditModeWidget::OnDeleteClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	UE_LOG(LogTemp, Warning, TEXT("Delete Clicked\n"));
	EditMode = 2;
	return FReply::Handled();
}
FReply SLevelEditModeWidget::OnMoveClicked(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	UE_LOG(LogTemp, Warning, TEXT("Move Clicked\n"));
	EditMode = 3;
	return FReply::Handled();
}


