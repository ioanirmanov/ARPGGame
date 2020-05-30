// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapEditorTile.generated.h"

UCLASS()
class ARPG_API AMapEditorTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapEditorTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Tile Properties")
	class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere, Category = "Tile Properties")
	class UDynamicSprite* DynamicSprite;

	UPROPERTY(EditAnywhere, Category = "Tile Properties")
	int TileType = 0;

	bool IsBlocked = false;

	bool IsTrigger = false;

	FString TriggerCommand;

	int Layer;

	void UpdateTexture(UTexture2D* Texture);
	
};
