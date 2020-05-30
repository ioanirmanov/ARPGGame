// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MapTile.generated.h"

UCLASS()
class ARPG_API AMapTile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMapTile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void SetGameManComp(class UGameManagment* GameManCompPtr);

	//Function called when player enters tile
	void OnTileEntered();

	void UpdateTexture(UTexture2D* Texture);

	void SetBlocked(bool Blocked);
	void SetTrigger(bool Trigger);
	bool GetBlocked();
	bool GetTrigger();

	void SetTriggerCommand(FString Command);
	FString GetTriggerCommand();

private:
	UPROPERTY(EditAnywhere, Category = "Tile Properties")
		class UGameManagment* gameManComp;

	UPROPERTY(EditAnywhere, Category = "Tile Properties")
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere, Category = "Tile Properties")
		class UDynamicSprite* DynamicSprite;

	UPROPERTY(EditAnywhere, Category = "Tile Properties")
		bool IsBlocked;
	UPROPERTY(EditAnywhere, Category = "Tile Properties")
		bool IsTrigger;
	//Command that runs when tile triggered
	UPROPERTY(EditAnywhere, Category = "Tile Properties")
		FString TriggerCommand;

};
