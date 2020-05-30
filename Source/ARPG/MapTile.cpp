// Fill out your copyright notice in the Description page of Project Settings.

#include "MapTile.h"
#include "ARPG.h"
#include "PaperSpriteComponent.h"
#include "GameManagment.h"
#include "DynamicSprite.h"



// Sets default values
AMapTile::AMapTile()
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

}

// Called when the game starts or when spawned
void AMapTile::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMapTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMapTile::OnTileEntered()
{
	UE_LOG(LogTemp, Warning, TEXT("TileEntered"));
	if (IsTrigger)
	{
		UE_LOG(LogTemp, Warning, TEXT("EventTriggered"));		
		gameManComp->TriggerEvent(TriggerCommand);//Trigger event via Game Managment component
		
	}
}

void AMapTile::UpdateTexture(UTexture2D* Texture)
{
	Sprite->SetMobility(EComponentMobility::Stationary);
	DynamicSprite->SetTexture(Texture);
	Sprite->SetSprite(DynamicSprite);
	Sprite->MarkRenderStateDirty();
	Sprite->MarkRenderTransformDirty();
}

void AMapTile::SetBlocked(bool Blocked)
{
	IsBlocked = Blocked;
}

void AMapTile::SetTrigger(bool Trigger)
{
	IsTrigger = Trigger;
}

bool AMapTile::GetBlocked()
{
	return IsBlocked;
}

bool AMapTile::GetTrigger()
{
	return IsTrigger;
}

void AMapTile::SetTriggerCommand(FString Command)
{
	TriggerCommand = Command;
}

FString AMapTile::GetTriggerCommand()
{
	return TriggerCommand;
}

void AMapTile::SetGameManComp(class UGameManagment* GameManCompPtr)
{
	gameManComp = GameManCompPtr;
}

