// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MapTile.h"
#include "MapObject.h"
#include "NPCPawn.h"
#include "Components/ActorComponent.h"
#include "GenMapFromText.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARPG_API UGenMapFromText : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGenMapFromText();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TArray<FTileSetTile> GetTileSet();
	TArray<FTileSetTile> GetObjectSet();

	TArray<FnumRow> GetTiles();
	TArray<FnumRow> GetObjects();

	int GetNPCNum();
	TSubclassOf<ANPCPawn> GetNPCType(int Index);
	FVector2D GetNPCPos(int Index);
	int GetNPCDialogueNum(int Index);
	class DialogueObject GetNPCDialogue(int IndexA, int IndexB);
	int GetIObjectNum();
	FVector2D GetIObjectPos(int Index);
	int GetIObjectDialogueNum(int Index);
	class DialogueObject GetIObjectDialogue(int IndexA, int IndexB);

	int GetTileSizeX();
	int GetTileSizeY();

	int GetMapHeight();
	int GetMapWidth();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	//Function that scans for tags is text asset
	void ScanForTag(FString &text, int &GridSizeStartIndex, int &GridSizeEndIndex, int &TileSizeStartIndex, int &TileSizeEndIndex, int &TileSetStart, int &TileSetEnd, int &ObjectSetStart, int &ObjectSetEnd, int &TilesStart, int &TilesEnd, int &ObjectsStart, int &ObjectsEnd, int &ObjectLayersStart, int &ObjectLayersEnd, int &BlockedStart, int &BlockedEnd, int &TriggersStart, int &TriggersEnd, int &NPCStart, int &NPCEnd, int &IObjectStart, int &IObjectEnd);

	TArray<class DialogueObject> LoadObjectDialogue(FString DialogueFileName);
	TArray<class DialogueObject> LoadDialogue(FString DialogueFileName);

	class UTexture2D* Load2DTextureFromFile(const FString& FullFilePath, bool& IsValid);

	//Tile set for both tiles and objects, must be filled or exception will occur
	UPROPERTY(EditAnywhere, Category = "Map Tiles")
		TMap<FString, TSubclassOf<AMapTile>> UniversalTileSet;

	UPROPERTY(EditAnywhere, Category = "Map Tiles")
		TArray<FTileSetTile> TileSet;

	UPROPERTY(EditAnywhere, Category = "Map Tiles")
		TArray<FTileSetTile> ObjectSet;//Object tile set

	UPROPERTY(EditAnywhere, Category = "Map Tiles")
		TArray<FnumRow> Tiles;

	UPROPERTY(EditAnywhere, Category = "Map Tiles")
		TArray<FnumRow> Objects;

	UPROPERTY(EditAnywhere, Category = "NPCs")
		TMap<FString, TSubclassOf<ANPCPawn>> NPCMap;

	TArray<TSubclassOf<ANPCPawn>> NPCTypes;
	TArray<FVector2D> NPCPos;
	TArray<TArray<class DialogueObject>> NPCDialogue;
	TArray<FVector2D> IObjectPos;
	TArray<TArray<class DialogueObject>> IObjectDialogue;

	//TextAsset from which map will be generated
	UPROPERTY(EditAnywhere, Category = "MapNanme")
		FString MapName;

	int TileSizeX = 16;
	int TileSizeY = 16;

	int MapWidth = 10;
	int MapHeight = 10;

};
