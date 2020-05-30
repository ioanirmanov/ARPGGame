// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicSprite.h"


UDynamicSprite::UDynamicSprite(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SpriteCollisionDomain = ESpriteCollisionMode::None;
	PixelsPerUnrealUnit = 1.0f;
	RenderGeometry.GeometryType = ESpritePolygonMode::SourceBoundingBox;
}


void UDynamicSprite::SetTexture(UTexture2D* Texture)
{
	if (Texture)
	{
		float Width = Texture->GetSizeX();
		float Height = Texture->GetSizeY();

		SourceTexture = Texture;
		SourceUV.Set(0, 0);
		SourceDimension.Set(Width, Height);

		const FVector2D Pivot = GetPivotPosition();
		BakedRenderData.Empty(6);

		// Uses 2 triangles to describe the mesh.
		// Each vertex is in the format: [ImageX relative to Pivot, ImageY relative to Pivot, U, V]
		BakedRenderData.Add(FVector4(0.0f - Pivot.X, Pivot.Y - 0.0f, 1.0f, 0.0f));
		BakedRenderData.Add(FVector4(Width - Pivot.X, Pivot.Y - 0.0f, 0.0f, 0.0f));
		BakedRenderData.Add(FVector4(Width - Pivot.X, Pivot.Y - Height, 0.0f, 1.0f));

		BakedRenderData.Add(FVector4(0.0f - Pivot.X, Pivot.Y - 0.0f, 1.0f, 0.0f));
		BakedRenderData.Add(FVector4(Width - Pivot.X, Pivot.Y - Height, 0.0f, 1.0f));
		BakedRenderData.Add(FVector4(0.0f - Pivot.X, Pivot.Y - Height, 1.0f, 1.0f));
	}
}



