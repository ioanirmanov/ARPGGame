// Fill out your copyright notice in the Description page of Project Settings.

#include "MapEditorTile.h"
#include "DynamicSprite.h"
#include "PaperSpriteComponent.h"


// Sets default values
AMapEditorTile::AMapEditorTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TileBase"));
	}

	DynamicSprite = CreateDefaultSubobject<UDynamicSprite>(TEXT("DynamicSprite"));

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("TileSprite"));
	Sprite->SetSprite(DynamicSprite);
	Sprite->AttachTo(RootComponent);

	FTransform transform = Sprite->GetRelativeTransform();
	transform.SetScale3D(FVector(-1, 1, 1));
	
	Sprite->SetRelativeTransform(transform);
	

}

// Called when the game starts or when spawned
void AMapEditorTile::BeginPlay()
{
	Super::BeginPlay();
	
	
	
}

// Called every frame
void AMapEditorTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

void AMapEditorTile::UpdateTexture(UTexture2D* Texture)
{
	Sprite->SetMobility(EComponentMobility::Stationary);
	DynamicSprite->SetTexture(Texture);
	Sprite->SetSprite(DynamicSprite);
	Sprite->MarkRenderStateDirty();
	Sprite->MarkRenderTransformDirty();
}



