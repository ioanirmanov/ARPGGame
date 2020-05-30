// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MapTile.h"
#include "MapEditor.h"
#include "CharacterPawn.h"
#include "GameFramework/Actor.h"
#include "MapObject.generated.h"


USTRUCT()
struct FRow //Row of tiles
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TArray<AMapTile*> Row;
};

USTRUCT()
struct FTileProp //Struct to store properties of a tile that will be generated
{
	GENERATED_BODY()
		
		UPROPERTY(EditAnywhere)
		int Type;
	UPROPERTY(EditAnywhere)
		bool isBlocked;
	UPROPERTY(EditAnywhere)
		bool isTrigger;
	UPROPERTY(EditAnywhere)
		FString TriggerCommand;
	UPROPERTY(EditAnywhere)
		int Layer;
		

};

USTRUCT()
struct FnumRow
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TArray<FTileProp> Row;
};


UCLASS()
class ARPG_API AMapObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMapObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void SetGameManComp(class UGameManagment* GameManCompPtr);

	void SpawnTile(int x, int y, int tiletype, int layer);

	void SpawnObject(int x, int y, int tiletype, int layer);

	void Generate();

	void UnLoad();

	int GetRowNum(int Y);
	int GetObjRowNum(int Y);
	int GetTilesNum();
	int GetObjsNum();
	bool GetTileBlocked(int Y, int X);
	bool GetObjectBlocked(int Y, int X);
	void OnTileEntered(int Y, int X);
	bool TileExists(int Y, int X);
	bool ObjExists(int Y, int X);

	int GetNPCs(int X, int Y);

	void SetTileSizeX(int NewX);
	void SetTileSizeY(int NewY);
	int GetTileSizeX();
	int GetTileSizeY();

	void SetMapHeight(int NewHeight);
	void SetMapWidth(int NewWidth);
	int GetMapHeight();
	int GetMapWidth();

	void Interact(int X, int Y, EDirection Dir);
	

private:

	//Tile set for map
	UPROPERTY(EditAnywhere, Category = "Map Generation")
		TArray<FTileSetTile> TileSet;

	UPROPERTY(EditAnywhere, Category = "Map Generation")
		bool GenerateMapFromText = true;

	//Component that will be used to generate a map from textasset
	UPROPERTY(EditAnywhere, Category = "Map Generation")
		class UGenMapFromText* Generator;

	UPROPERTY(EditAnywhere, Category = "Object Generation")
		TArray<FTileSetTile> ObjectTileSet;
	
	//Pointer to Game Managment component
	UPROPERTY(EditAnywhere, Category = "Object Generation")
		class UGameManagment* gameManComp;

	//The initialised mao
	UPROPERTY(EditAnywhere, Category = "Map Tiles")
		TArray<FRow> Tiles;

	//Holds properties for the map that will be generated
	UPROPERTY(EditAnywhere, Category = "Map Generation")
		TArray<FnumRow> TilesMap;

	UPROPERTY(EditAnywhere, Category = "Object Tiles")
		TArray<FRow> Objects;

	UPROPERTY(EditAnywhere, Category = "Object Generation")
		TArray<FnumRow> ObjectsMap;

	int TileSizeX = 16;
	int TileSizeY = 16;

	int MapWidth = 10;
	int MapHeight = 10;

	TArray<TArray<int>> NPCs;
	TArray<TArray<int>> InteractableObjects;
};
