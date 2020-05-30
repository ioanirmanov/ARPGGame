// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelEditWidget.h"
#include "Components/SceneComponent.h"
#include "MapEditor.generated.h"


USTRUCT()
struct FTileSetTile
{
	GENERATED_BODY()

	UPROPERTY()
	class UTexture2D* texture;

	UPROPERTY()
	FText TileName;

};

UENUM()
enum EEditorMode
{
	SelectTile,
	ChangeTile,
	DeleteTile,
	MoveCamera
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARPG_API UMapEditor : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMapEditor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddTile(class SLevelEditWidget* SourceWidget);
	void AddObject(class SLevelEditWidget* SourceWidget);

	TSharedPtr<class SLevelEditWidget> LvlEditWidget;

	UTexture2D* Load2DTextureFromFile(const FString& FullFilePath, bool& IsValid);

	void Save2DTextureToFile(UTexture2D* texture, FString FileName);

	TArray<FTileSetTile> TileSet;
	TArray<FTileSetTile> ObjectTileSet;

	TArray<TArray<class AMapEditorTile*>> TileMap;
	TArray<TArray<class AMapEditorTile*>> ObjectTileMap;
	void GenerateEmptyMap();

	int SelectedTileSetTile = -1;
	int SelectedTileSetObject = -1;

	//For selecting tile from tile set
	void SelectTile(int index);
	void SelectObjectTile(int index);

	void RemoveSelectedTile();
	void RemoveSelectedObject();

	UPROPERTY(EditAnywhere, Category = "Grid")
	TSubclassOf<class AGridLine> GridLine;
	UPROPERTY(EditAnywhere, Category = "Grid")
	TSubclassOf<class AGridLine> MBoxLine;
	UPROPERTY(EditAnywhere, Category = "Grid")
	TSubclassOf<class AGridLine> SBoxLine;
	UPROPERTY(EditAnywhere, Category = "EmptyTile")
		TSubclassOf<class AMapEditorTile> EmptyTile;
	void MakeGrid();
	void DrawSelectionBox();
	void DrawMouseOverBox();
	int GridSizeX = 3;
	int GridSizeY = 3;
	int TileSizeX = 16;
	int TileSizeY = 16;
	float GridThickness = 1;
	TArray<AGridLine*> GridLines;
	TArray<AGridLine*> MouseOverBox;
	TArray<AGridLine*> SelectionBox;

	int SelectedTileX = 0;
	int SelectedTileY = 0;

	int MouseTileX = 0;
	int MouseTileY = 0;

	float MousePosX;
	float MousePosY;

	bool MouseRightDown;
	bool MouseScrollDown;

	void OnClick();
	void OnClickReleased();
	void OnScrollWheelClick();
	void OnScrollWheelReleased();
	void SelectMapTile();
	void ChangeTile();
	void DeleteTile();

	EEditorMode EditorMode = EEditorMode::ChangeTile;

	UPROPERTY(EditAnywhere, Category = "Player Properties")
		class UTexture2D* BlankTile;

	//Textures For Toolbar
	UTexture2D* SelectUnpressed;
	UTexture2D* SelectPressed;
	UTexture2D* ChangeUnpressed;
	UTexture2D* ChangePressed;
	UTexture2D* DeleteUnpressed;
	UTexture2D* DeletePressed;
	UTexture2D* MoveUnpressed;
	UTexture2D* MovePressed;

	void LoadToolBarTextures();

	void UpdateToolBar();

	void UpdateCurrentTileData();

	void ChangeGridSize(int NewSizeX, int NewSizeY, int AnchorX, int AnchorY);

	void ChangeTileSize(int NewSizeX, int NewSizeY);

	void SaveMap();
	void OpenMap();

	FString MapToText();

	void ScanForTag(FString &text, int &GridSizeStartIndex, int &GridSizeEndIndex, int &TileSizeStartIndex, int &TileSizeEndIndex, int &TileSetStart, int &TileSetEnd, int &ObjectSetStart, int &ObjectSetEnd, int &TilesStart, int &TilesEnd, int &ObjectsStart, int &ObjectsEnd, int &ObjectLayersStart, int &ObjectLayersEnd, int &BlockedStart, int &BlockedEnd, int &TriggersStart, int &TriggersEnd);

private:
	APlayerController* PlayerController;
	class ALevelEditPawn* LevelEditPawn;

	
};
