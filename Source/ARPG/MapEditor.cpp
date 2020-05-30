// Fill out your copyright notice in the Description page of Project Settings.
// Fill out your copyright notice in the Description page of Project Settings.

#include "MapEditor.h"
#include "Engine.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "Runtime/ImageWrapper/Public/IImageWrapper.h"
#include "Runtime/ImageWrapper/Public/IImageWrapperModule.h"
#include "TileSetWidget.h"
#include "LevelEditHUD.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "GridLine.h"
#include "LevelEditPawn.h"
#include "MapEditorTile.h"
#include "DynamicSprite.h"
#include "SLevelEditModeWidget.h"


// Sets default values for this component's properties
UMapEditor::UMapEditor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMapEditor::ChangeGridSize(int NewSizeX, int NewSizeY, int AnchorX, int AnchorY)
{
	SelectedTileX = 0;
	SelectedTileY = 0;
	TArray<TArray<class AMapEditorTile*>> tmpTileMap = TileMap;
	TArray<TArray<class AMapEditorTile*>> tmpObjectTileMap = ObjectTileMap;
	TileMap.Empty();
	ObjectTileMap.Empty();
	GridSizeX = NewSizeX;
	GridSizeY = NewSizeY;
	LvlEditWidget->MapGridSizeX = GridSizeX;
	LvlEditWidget->MapGridSizeY = GridSizeY;
	LvlEditWidget->ReloadPropertiesWidget();
	GenerateEmptyMap();
	//Copy existing map
	int startx = AnchorX;
	if (startx < 0) startx = 0;
	int starty = AnchorY;
	if (starty < 0) starty = 0;
	int endx = tmpTileMap.Num() + AnchorX;
	if (endx > GridSizeX) endx = GridSizeX;
	int endy = tmpTileMap.Num() + AnchorY;
	if (endy > GridSizeY) endy = GridSizeY;
	for (int x = startx; x < endx; x++)
	{
		for (int y = starty; y < endy; y++)
		{

			UE_LOG(LogTemp, Warning, TEXT("%i %i %i %i\n"), x, y, x - AnchorX, y - AnchorY);
			UE_LOG(LogTemp, Warning, TEXT("%i \n"), tmpTileMap[x - AnchorX][y - AnchorY]->TileType);
			TileMap[x][y]->TileType = tmpTileMap[x - AnchorX][y - AnchorY]->TileType;
			TileMap[x][y]->IsBlocked = tmpTileMap[x - AnchorX][y - AnchorY]->IsBlocked;
			TileMap[x][y]->IsTrigger = tmpTileMap[x - AnchorX][y - AnchorY]->IsTrigger;
			TileMap[x][y]->TriggerCommand = tmpTileMap[x - AnchorX][y - AnchorY]->TriggerCommand;
			TileMap[x][y]->UpdateTexture(TileSet[TileMap[x][y]->TileType].texture);
			ObjectTileMap[x][y]->TileType = tmpObjectTileMap[x - AnchorX][y - AnchorY]->TileType;
			ObjectTileMap[x][y]->UpdateTexture(ObjectTileSet[ObjectTileMap[x][y]->TileType].texture);
		}
	}
	//Delete Old Tiles
	for (int x = 0; x < tmpTileMap.Num(); x++)
	{
		for (int y = 0; y < tmpTileMap[0].Num(); y++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%i %i\n"), x, y);
			tmpTileMap[x][y]->Destroy();
			tmpObjectTileMap[x][y]->Destroy();
		}
	}
	tmpTileMap.Empty();
	tmpObjectTileMap.Empty();
	for (int i = 0; i < GridLines.Num(); i++)
	{
		GridLines[i]->Destroy();
	}
	GridLines.Empty();
	MakeGrid();
	
}

void UMapEditor::ChangeTileSize(int NewSizeX, int NewSizeY)
{
	TileSizeX = NewSizeX;
	TileSizeY = NewSizeY;
	for (int x = 0; x < GridSizeX; x++)
	{
		for (int y = 0; y < GridSizeY; y++)
		{	
			FVector NewLocation = FVector(x*TileSizeX + (TileSizeX / 2), 1, -TileSizeY * y - (TileSizeY / 2));
			FVector NewObjectLocation = FVector(x*TileSizeX + (TileSizeX / 2), 5, -TileSizeY * y - (TileSizeY / 2));
			TileMap[x][y]->SetActorLocation(NewLocation);
			ObjectTileMap[x][y]->SetActorLocation(NewObjectLocation);
		}
	}
	LvlEditWidget->MapTileSizeX = TileSizeX;
	LvlEditWidget->MapTileSizeY = TileSizeY;
	LvlEditWidget->ReloadPropertiesWidget();
	for (int i = 0; i < GridLines.Num(); i++)
	{
		GridLines[i]->Destroy();
	}
	GridLines.Empty();
	MakeGrid();
}

void UMapEditor::LoadToolBarTextures()
{
	SelectUnpressed = LoadObject<UTexture2D>(NULL, TEXT("/Game/MapEditor/UI/Buttons/SelectUnpressed.SelectUnpressed"), NULL, LOAD_None, NULL);
	SelectPressed = LoadObject<UTexture2D>(NULL, TEXT("/Game/MapEditor/UI/Buttons/SelectPressed.SelectPressed"), NULL, LOAD_None, NULL);
	ChangeUnpressed = LoadObject<UTexture2D>(NULL, TEXT("/Game/MapEditor/UI/Buttons/ChangeUnpressed.ChangeUnpressed"), NULL, LOAD_None, NULL);
	ChangePressed = LoadObject<UTexture2D>(NULL, TEXT("/Game/MapEditor/UI/Buttons/ChangePressed.ChangePressed"), NULL, LOAD_None, NULL);
	DeleteUnpressed = LoadObject<UTexture2D>(NULL, TEXT("/Game/MapEditor/UI/Buttons/DeleteUnpressed.DeleteUnpressed"), NULL, LOAD_None, NULL);
	DeletePressed = LoadObject<UTexture2D>(NULL, TEXT("/Game/MapEditor/UI/Buttons/DeletePressed.DeletePressed"), NULL, LOAD_None, NULL);
	MoveUnpressed = LoadObject<UTexture2D>(NULL, TEXT("/Game/MapEditor/UI/Buttons/MoveUnpressed.MoveUnpressed"), NULL, LOAD_None, NULL);
	MovePressed = LoadObject<UTexture2D>(NULL, TEXT("/Game/MapEditor/UI/Buttons/MovePressed.MovePressed"), NULL, LOAD_None, NULL);
}

void UMapEditor::UpdateToolBar()
{
	switch (EditorMode)
	{	
	case EEditorMode::SelectTile:
		LvlEditWidget->LoadEditModeWidget(SelectPressed, ChangeUnpressed, DeleteUnpressed, MoveUnpressed, 0);
		break;
	case EEditorMode::ChangeTile:
		LvlEditWidget->LoadEditModeWidget(SelectUnpressed, ChangePressed, DeleteUnpressed, MoveUnpressed, 1);
		break;
	case EEditorMode::DeleteTile:
		LvlEditWidget->LoadEditModeWidget(SelectUnpressed, ChangeUnpressed, DeletePressed, MoveUnpressed, 2);
		break;
	case EEditorMode::MoveCamera:
		LvlEditWidget->LoadEditModeWidget(SelectUnpressed, ChangeUnpressed, DeleteUnpressed, MovePressed, 3);
		break;
	}

}


// Called when the game starts
void UMapEditor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	AHUD* hud = PlayerController->GetHUD();
	ALevelEditHUD* lvlEdtHUD = (ALevelEditHUD*)hud;
	
	

	//if player pointer is empty
	if (!LevelEditPawn)
	{
		//Get player pawn (spawned as default pawn of gamemode), and point player pointer to it
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		APawn* pawn = PlayerController->GetPawn();
		LevelEditPawn = (ALevelEditPawn*)pawn;
		LevelEditPawn->mapEditor = this;
	}
	
	LvlEditWidget = lvlEdtHUD->MyUIWidget;

	
	UE_LOG(LogTemp, Warning, TEXT("%i \n"), lvlEdtHUD->thing);
	
	UE_LOG(LogTemp, Warning, TEXT("Pointer Valid :"));
	if (LvlEditWidget.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("True \n"));
		UE_LOG(LogTemp, Warning, TEXT("%i \n"), LvlEditWidget->tmp);
		LvlEditWidget->MapEditor = this;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("False \n"));
	}
	
	LoadToolBarTextures();
	UpdateToolBar();
	
	//Make background grid
	MakeGrid();
	LevelEditPawn->SetActorLocation(FVector((GridSizeX*TileSizeX)/2, 15, -(GridSizeY*TileSizeY)/2));
	
	//Make Empty Texture At Default Size;
	UTexture2D* EmptyTexture = BlankTile;
	

	FTileSetTile newTile = {};
	newTile.TileName = FText::FromString("EmptyTile");
	newTile.texture = EmptyTexture;
	TileSet.Add(newTile);
	ObjectTileSet.Add(newTile);

	if (LvlEditWidget.IsValid())
	{
		
		LvlEditWidget->AddTile(EmptyTexture, newTile.TileName.ToString());
		LvlEditWidget->AddObject(EmptyTexture, newTile.TileName.ToString());
		SelectedTileSetTile = TileSet.Num() - 1;
	}
	GenerateEmptyMap();
}

void UMapEditor::GenerateEmptyMap()
{
	for (int x = 0; x < GridSizeX; x++)
	{
		TArray<AMapEditorTile*> newArr;
		TArray<AMapEditorTile*> newArrObject;
		TileMap.Add(newArr);
		ObjectTileMap.Add(newArrObject);
		for (int y = 0; y < GridSizeY; y++)
		{
			FVector NewLocation = FVector(x*TileSizeX + (TileSizeX/2) , 1, -TileSizeY * y  - (TileSizeY/2));
			FVector NewObjectLocation = FVector(x*TileSizeX + (TileSizeX / 2), 5, -TileSizeY * y - (TileSizeY / 2));
			AMapEditorTile* NewTile = GetWorld()->SpawnActor<AMapEditorTile>(EmptyTile, NewLocation, FRotator::ZeroRotator);
			AMapEditorTile* NewObjectTile = GetWorld()->SpawnActor<AMapEditorTile>(EmptyTile, NewObjectLocation, FRotator::ZeroRotator);
			NewTile->UpdateTexture(BlankTile);
			NewObjectTile->UpdateTexture(BlankTile);
			TileMap[x].Add(NewTile);
			ObjectTileMap[x].Add(NewObjectTile);
		}
	}
}

void UMapEditor::MakeGrid()
{

	//Create background grid
	for (int x = 0; x < GridSizeX + 1; x++)
	{
		FVector NewLocation = FVector(x*TileSizeX + (GridThickness / 2), 0, -(TileSizeY * GridSizeY) - (GridThickness / 2));
		AGridLine* gLine = GetWorld()->SpawnActor<AGridLine>(GridLine, NewLocation, FRotator::ZeroRotator);
		gLine->Sprite->SetRelativeScale3D(FVector(GridThickness, GridThickness, (TileSizeY * GridSizeY) + GridThickness));
		GridLines.Add(gLine);
	}
	for (int y = 0; y < GridSizeY + 1; y++)
	{
		FVector NewLocation = FVector(TileSizeX * GridSizeX + (GridThickness / 2), 0, -y * TileSizeY - (GridThickness / 2));
		AGridLine* gLine = GetWorld()->SpawnActor<AGridLine>(GridLine, NewLocation, FRotator::ZeroRotator);
		gLine->Sprite->SetRelativeScale3D(FVector((TileSizeX * GridSizeX) + GridThickness, GridThickness, GridThickness));
		GridLines.Add(gLine);
	}
}

// Called every frame
void UMapEditor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	int newSelectedTile = SelectedTileSetTile;
	//Check if tile that not current selected tile has Selected = true
	for (int i = 0; i < LvlEditWidget->TileSetWidgets.Num(); i++)
	{
		if (i != SelectedTileSetTile)
		{
			class STileSetWidget* tWidge = (STileSetWidget*)LvlEditWidget->TileSetWidgets[i].Get();
			if (tWidge->Selected)
			{
				newSelectedTile = i;
				
			}
		}
	}
	if (newSelectedTile != SelectedTileSetTile)
		SelectTile(newSelectedTile);

	
	for (int i = 0; i < LvlEditWidget->TileSetWidgets.Num(); i++)
	{
		//If tile is not selected set selected to false, and vice versa
		class STileSetWidget* tWidge = (STileSetWidget*)LvlEditWidget->TileSetWidgets[i].Get();
		if (i != SelectedTileSetTile)
		{	
			tWidge->Selected = false;
		}
		else
		{
			tWidge->Selected = true;
		}

		//Update Names
		TileSet[i].TileName = tWidge->Name;

	}

	
	int newSelectedObject = SelectedTileSetObject;
	//Check if object that not current selected tile has Selected = true
	for (int i = 0; i < LvlEditWidget->ObjectTileSetWidgets.Num(); i++)
	{
		if (i != SelectedTileSetObject)
		{
			class STileSetWidget* tWidge = (STileSetWidget*)LvlEditWidget->ObjectTileSetWidgets[i].Get();
			if (tWidge->Selected)
			{
				newSelectedObject = i;

			}
		}
	}
	if (newSelectedObject != SelectedTileSetObject)
		SelectObjectTile(newSelectedObject);


	for (int i = 0; i < LvlEditWidget->ObjectTileSetWidgets.Num(); i++)
	{
		//If tile is not selected set selected to false, and vice versa
		class STileSetWidget* tWidge = (STileSetWidget*)LvlEditWidget->ObjectTileSetWidgets[i].Get();
		if (i != SelectedTileSetObject)
		{
			tWidge->Selected = false;
		}
		else
		{
			tWidge->Selected = true;
		}

		//Update Names
		ObjectTileSet[i].TileName = tWidge->Name;

	}

	//CheckToolBox
	int CurrentEditMode;
	switch (EditorMode)
	{
	case EEditorMode::SelectTile:
		CurrentEditMode = 0;
		break;
	case EEditorMode::ChangeTile:
		CurrentEditMode = 1;
		break;
	case EEditorMode::DeleteTile:
		CurrentEditMode = 2;
		break;
	case EEditorMode::MoveCamera:
		CurrentEditMode = 3;
		break;
	}
	
	SLevelEditModeWidget* EditModeWidget = (SLevelEditModeWidget*)LvlEditWidget->EditModeWidget.Get();
	if (CurrentEditMode != EditModeWidget->EditMode)
	{
		LvlEditWidget->RemoveEditModeWidget();
		switch (EditModeWidget->EditMode)
		{
		case 0:
			EditorMode = EEditorMode::SelectTile;
			break;
		case 1:
			EditorMode = EEditorMode::ChangeTile;
			break;
		case 2:
			EditorMode = EEditorMode::DeleteTile;
			break;
		case 3:
			EditorMode = EEditorMode::MoveCamera;
			for (int i = 0; i < MouseOverBox.Num(); i++)
			{
				MouseOverBox[i]->Destroy();
			}
			MouseOverBox.Empty();
			break;
		}
		UpdateToolBar();

	}
	//Get Mouse Position
	float MouseX = 0;
	float MouseY = 0;
	PlayerController->GetMousePosition(MouseX, MouseY);
	//UE_LOG(LogTemp, Warning, TEXT("MouseX: %f , MouseY: %f\n"), MouseX, MouseY);

	float CamPosX = LevelEditPawn->Cam->GetComponentTransform().GetLocation().X;
	float CamPosY = -LevelEditPawn->Cam->GetComponentTransform().GetLocation().Z;
	//UE_LOG(LogTemp, Warning, TEXT("CamPosX: %f , CamPosY: %f\n"), CamPosX, CamPosY);
	float OrthoWidth = LevelEditPawn->Cam->OrthoWidth;
	int ViewPortSizeX = 0;
	int ViewPortSizeY = 0;
	PlayerController->GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	//UE_LOG(LogTemp, Warning, TEXT("ViewPortSizeX: %i , ViewPortSizeY: %i\n"), ViewPortSizeX, ViewPortSizeY);
	//Get position relative to map
	float MouseMapX = (OrthoWidth /  ViewPortSizeX) //Ratio Of screen pixel to camera pixel
		* (MouseX - (ViewPortSizeX / 2))//Mouse Position Relative To Middle
		+ CamPosX;//CameraPosition

	float MouseMapY = (OrthoWidth / ViewPortSizeX) //Ratio Of screen pixel to camera pixel
		* (MouseY - (ViewPortSizeY / 2))//Mouse Position Relative To Middle
		+ CamPosY;//CameraPosition

	MouseTileX = floor(MouseMapX / TileSizeX);
	MouseTileY = floor(MouseMapY / TileSizeY);
	if (MouseTileX >= GridSizeX || MouseTileX < 0 || MouseTileY >= GridSizeY || MouseTileY < 0)
	{
		MouseTileX = -1;
		MouseTileY = -1;
	}

	if (EditorMode == EEditorMode::MoveCamera)
	{
		if (MouseRightDown)
		{
			float MouseDifferenceX = MouseX - MousePosX;
			float MouseDifferenceY = MouseY - MousePosY;
			LevelEditPawn->SetActorLocation(FVector(CamPosX - (MouseDifferenceX*((OrthoWidth / ViewPortSizeX))), LevelEditPawn->Cam->GetComponentTransform().GetLocation().Y, -CamPosY +(MouseDifferenceY*(OrthoWidth / ViewPortSizeX))));
		}
	}
	else
	{
		if (MouseScrollDown)
		{
			float MouseDifferenceX = MouseX - MousePosX;
			float MouseDifferenceY = MouseY - MousePosY;
			LevelEditPawn->SetActorLocation(FVector(CamPosX - (MouseDifferenceX*((OrthoWidth / ViewPortSizeX))), LevelEditPawn->Cam->GetComponentTransform().GetLocation().Y, -CamPosY + (MouseDifferenceY*(OrthoWidth / ViewPortSizeX))));
		}
	}

	MousePosX = MouseX;
	MousePosY = MouseY;
	//UE_LOG(LogTemp, Warning, TEXT("MouseTileX: %i , MouseTileY: %i\n"), MouseTileX, MouseTileY);
	if(EditorMode != EEditorMode::MoveCamera)
		DrawMouseOverBox();
	DrawSelectionBox();

	UpdateCurrentTileData();

	//Clamp Zoom Level
	LevelEditPawn->Cam->SetOrthoWidth(FMath::Clamp(LevelEditPawn->Cam->OrthoWidth, TileSizeX/1.0f, TileSizeX*GridSizeX * 10.0f));
	
}

void UMapEditor::OnClick()
{
	MouseRightDown = true;
	switch (EditorMode)
	{
	case EEditorMode::SelectTile:
		SelectMapTile();
		break;
	case EEditorMode::ChangeTile:
		ChangeTile();
		break;
	case EEditorMode::DeleteTile:
		DeleteTile();
		break;
	case EEditorMode::MoveCamera:
		
			break;

	}
	
}

void UMapEditor::OnClickReleased()
{
	MouseRightDown = false;
}

void UMapEditor::OnScrollWheelReleased()
{
	MouseScrollDown = false;
}
void UMapEditor::OnScrollWheelClick()
{
	MouseScrollDown = true;
}

void UMapEditor::SaveMap()
{
	FString DialogTitle = "Save Map";
	FString DefaultPath = FPaths::GameDir();
	FString DefaultFile = "";
	uint32 Flags = EFileDialogFlags::None;
	FString FileTypes = "Folder (*)|*";
	TArray<FString> OutFilename;
	void* WindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (DesktopPlatform->SaveFileDialog(WindowHandle, DialogTitle, DefaultPath, DefaultFile, FileTypes, Flags, OutFilename))
	{
		UE_LOG(LogTemp, Warning, TEXT("FileName %s"), *OutFilename[0]);
		UE_LOG(LogTemp, Warning, TEXT("FileName %s"), *FPaths::GetCleanFilename(OutFilename[0]));
		PlatformFile.CreateDirectory(*OutFilename[0]);
		FString TextFilePath = OutFilename[0] + "/" + FPaths::GetCleanFilename(OutFilename[0]) + ".txt";
		FString MapText = MapToText();
		FFileHelper::SaveStringToFile(MapText, *TextFilePath);
		for (int i = 0; i < TileSet.Num(); i++)
		{
			Save2DTextureToFile(TileSet[i].texture, FString(OutFilename[0] + "/" + TileSet[i].TileName.ToString() + ".png"));
		}
		for (int i = 0; i < ObjectTileSet.Num(); i++)
		{
			Save2DTextureToFile(ObjectTileSet[i].texture, FString(OutFilename[0] + "/" + ObjectTileSet[i].TileName.ToString() + ".png"));
		}
	}
}

void UMapEditor::OpenMap()
{
	FString DialogTitle = "Open Map";
	FString DefaultPath = FPaths::GameDir();
	FString DefaultFile = "";
	uint32 Flags = EFileDialogFlags::None;
	FString FileTypes = "Text (*txt)|*txt";
	TArray<FString> OutFilename;
	void* WindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (DesktopPlatform->OpenFileDialog(WindowHandle, DialogTitle, DefaultPath, DefaultFile, FileTypes, Flags, OutFilename))
	{
		FString MapText;
		FFileHelper::LoadFileToString(MapText, *FString(OutFilename[0]));
		UE_LOG(LogTemp, Warning, TEXT("Path %s"), *FPaths::GetPath(OutFilename[0]));
		int GridSizeStartIndex,GridSizeEndIndex, TileSizeStartIndex, TileSizeEndIndex, TileSetStartIndex, TileSetEndIndex, ObjectSetStartIndex, ObjectSetEndIndex, TileStartIndex, TileEndIndex, ObjectStartIndex, ObjectEndIndex, LayerStartIndex, LayerEndIndex, BlockStartIndex, BlockEndIndex, TriggerStartIndex, TriggerEndIndex = -1;

		ScanForTag(MapText, GridSizeStartIndex, GridSizeEndIndex, TileSizeStartIndex, TileSizeEndIndex, TileSetStartIndex, TileSetEndIndex, ObjectSetStartIndex, ObjectSetEndIndex, TileStartIndex, TileEndIndex, ObjectStartIndex, ObjectEndIndex, LayerStartIndex, LayerEndIndex, BlockStartIndex, BlockEndIndex, TriggerStartIndex, TriggerEndIndex);

		UE_LOG(LogTemp, Warning, TEXT("Grid Start And End %i, %i"), GridSizeStartIndex, GridSizeEndIndex);

		if (GridSizeStartIndex > 0 && GridSizeEndIndex > 0 && GridSizeEndIndex > GridSizeStartIndex)
		{
			FString GridSizeText = MapText.Left(GridSizeEndIndex).Right(GridSizeEndIndex - GridSizeStartIndex - 2);

			int x, y;
			TArray<FString> tmpArr;
			//Get position of tile for command
			GridSizeText.ParseIntoArray(tmpArr, TEXT(" "), false);
			x = FCString::Atoi(*tmpArr[0]);
			y = FCString::Atoi(*tmpArr[1]);
			GridSizeX = x;
			GridSizeY = y;
		}
		if (TileSizeStartIndex > 0 && TileSizeEndIndex > 0 && TileSizeEndIndex > TileSizeStartIndex)
		{
			FString TileSizeText = MapText.Left(TileSizeEndIndex).Right(TileSizeEndIndex - TileSizeStartIndex - 2);

			int x, y;
			TArray<FString> tmpArr;
			//Get position of tile for command
			TileSizeText.ParseIntoArray(tmpArr, TEXT(" "), false);
			x = FCString::Atoi(*tmpArr[0]);
		    y = FCString::Atoi(*tmpArr[1]);
			TileSizeX = x;
			TileSizeY = y;

		}
		for (int x = 0; x < TileMap.Num(); x++)
		{
			for (int y = 0; y < TileMap[0].Num(); y++)
			{
				TileMap[x][y]->Destroy();
				ObjectTileMap[x][y]->Destroy();
			}
		}
		TileMap.Empty();
		ObjectTileMap.Empty();
		GenerateEmptyMap();
		UE_LOG(LogTemp, Warning, TEXT("Sizes %i, %i, %i, %i"), GridSizeX, GridSizeY, TileSizeX, TileSizeY);
		
		if (TileSetStartIndex > 0 && TileSetEndIndex > 0 && TileSetEndIndex > TileSetStartIndex)//If tag positions found and valid
		{
			TArray<FString> TileSetLines;
			//Split the section of text between the Indexes into lines
			MapText.Left(TileSetEndIndex).Right(TileSetEndIndex - TileSetStartIndex - 2).ParseIntoArrayLines(TileSetLines, false);
			for (int i = 1; i < TileSetLines.Num()-1; i++)//process each line, skip first and last as empty
			{
				FTileSetTile NewTile;
				bool IsValid;
				NewTile.TileName = FText::FromString(TileSetLines[i]);
				NewTile.texture = Load2DTextureFromFile(FString(FPaths::GetPath(OutFilename[0]) + "/" + TileSetLines[i] + ".png"), IsValid);
				TileSet.Add(NewTile);
				LvlEditWidget->AddTile(NewTile.texture, NewTile.TileName.ToString());
			}
		}

		if (ObjectSetStartIndex > 0 && ObjectSetEndIndex > 0 && ObjectSetEndIndex > ObjectSetStartIndex)//If tag positions found and valid
		{
			TArray<FString> TileSetLines;
			//Split the section of text between the Indexes into lines
			MapText.Left(ObjectSetEndIndex).Right(ObjectSetEndIndex - ObjectSetStartIndex - 2).ParseIntoArrayLines(TileSetLines, false);
			for (int i = 1; i < TileSetLines.Num()-1; i++)//process each line, skip first and last as empty
			{
				FTileSetTile NewTile;
				bool IsValid;
				NewTile.TileName = FText::FromString(TileSetLines[i]);
				NewTile.texture = Load2DTextureFromFile(FString(FPaths::GetPath(OutFilename[0]) + "/" + TileSetLines[i] + ".png"), IsValid);
				ObjectTileSet.Add(NewTile);
				LvlEditWidget->AddObject(NewTile.texture, NewTile.TileName.ToString());
			}
		}
		
		
		if (TileStartIndex > 0 && TileEndIndex > 0 && TileEndIndex > TileStartIndex)
		{
			TArray<FString> TilesLines;
			MapText.Left(TileEndIndex).Right(TileEndIndex - TileStartIndex - 2).ParseIntoArrayLines(TilesLines, false);

			for (int y = 0; y < GridSizeY; y++)
			{
				TArray<FString> tmpArr;
				//Split line into separate numbers
				TilesLines[y].ParseIntoArray(tmpArr, TEXT(" "), false);
				for (int x = 0; x < GridSizeX; x++)
				{
					TileMap[x][y]->TileType = FCString::Atoi(*tmpArr[x]);
					TileMap[x][y]->UpdateTexture(TileSet[FCString::Atoi(*tmpArr[x])].texture);

				}

			}
		}
		if (ObjectStartIndex > 0 && ObjectEndIndex > 0 && ObjectEndIndex > ObjectStartIndex)
		{
			TArray<FString> TilesLines;
			MapText.Left(ObjectEndIndex).Right(ObjectEndIndex - ObjectStartIndex - 2).ParseIntoArrayLines(TilesLines, false);

			for (int y = 0; y < GridSizeY; y++)
			{
				TArray<FString> tmpArr;
				//Split line into separate numbers
				TilesLines[y].ParseIntoArray(tmpArr, TEXT(" "), false);
				for (int x = 0; x < GridSizeX; x++)
				{
					ObjectTileMap[x][y]->TileType = FCString::Atoi(*tmpArr[x]);
					ObjectTileMap[x][y]->UpdateTexture(ObjectTileSet[FCString::Atoi(*tmpArr[x])].texture);

				}

			}
		}

		if (LayerStartIndex > 0 && LayerEndIndex > 0 && LayerEndIndex > LayerStartIndex)
		{
			TArray<FString> TilesLines;
			MapText.Left(LayerEndIndex).Right(LayerEndIndex - LayerStartIndex - 2).ParseIntoArrayLines(TilesLines, false);

			for (int y = 0; y < GridSizeY; y++)
			{
				TArray<FString> tmpArr;
				//Split line into separate numbers
				TilesLines[y].ParseIntoArray(tmpArr, TEXT(" "), false);
				for (int x = 0; x < GridSizeX; x++)
				{
					ObjectTileMap[x][y]->Layer = FCString::Atoi(*tmpArr[x]);

				}

			}
		}

		if (BlockStartIndex > 0 && BlockEndIndex > 0 && BlockEndIndex > BlockStartIndex)
		{
			TArray<FString> TilesLines;
			MapText.Left(BlockEndIndex).Right(BlockEndIndex - BlockStartIndex - 2).ParseIntoArrayLines(TilesLines, false);

			for (int y = 0; y < GridSizeY; y++)
			{
				TArray<FString> tmpArr;
				//Split line into separate numbers
				TilesLines[y].ParseIntoArray(tmpArr, TEXT(" "), false);
				for (int x = 0; x < GridSizeX; x++)
				{
					if (FCString::Atoi(*tmpArr[x]))
					{
						TileMap[x][y]->IsBlocked = 1;
					}
					else
					{
						TileMap[x][y]->IsBlocked = 0;
					}
				}

			}
		}
		if (TriggerStartIndex > 0 && TriggerEndIndex > 0 && TriggerEndIndex > TriggerStartIndex)
		{
			TArray<FString> TriggerLines;
			MapText.Left(TriggerEndIndex).Right(TriggerEndIndex - TriggerStartIndex - 2).ParseIntoArrayLines(TriggerLines, false);

			for (int i = 0; i < (TriggerLines.Num() - 1)/2; i++)// Lines/2 as position + command takes 2 lines
			{
				int x, y;
				TArray<FString> tmpArr;
				//Get position of tile for command
				TriggerLines[(i * 2)].ParseIntoArray(tmpArr, TEXT(" "), false);
				x = FCString::Atoi(*tmpArr[0]);
				y = FCString::Atoi(*tmpArr[1]);
				TileMap[x][y]->IsTrigger = true;//Set tile to be a trigger
				TileMap[x][y]->TriggerCommand = TriggerLines[(i * 2) + 1];//Set the command of tile from second line

			}

		}

		for (int i = 0; i < GridLines.Num(); i++)
		{
			GridLines[i]->Destroy();
		}
		GridLines.Empty();
		MakeGrid();

		SelectedTileSetObject = 0;
		SelectedTileSetTile = 0;
		SelectedTileX = 0;
		SelectedTileY = 0;
	
	}
}

void UMapEditor::ScanForTag(FString &text, int &GridSizeStartIndex, int &GridSizeEndIndex, int &TileSizeStartIndex, int &TileSizeEndIndex, int &TileSetStart, int &TileSetEnd, int &ObjectSetStart, int &ObjectSetEnd, int &TilesStart, int &TilesEnd, int &ObjectsStart, int &ObjectsEnd, int &ObjectLayersStart, int &ObjectLayersEnd, int &BlockedStart, int &BlockedEnd, int &TriggersStart, int &TriggersEnd)
{
	//Find where to start looking for things based on position of tags
	GridSizeStartIndex = text.Find(FString(TEXT("<GRIDSIZE>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<GRIDSIZE>")).Len();
	GridSizeEndIndex = text.Find(FString(TEXT("</GRIDSIZE>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	TileSizeStartIndex = text.Find(FString(TEXT("<TILESIZE>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<TILESIZE>")).Len();
	TileSizeEndIndex = text.Find(FString(TEXT("</TILESIZE>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	TileSetStart = text.Find(FString(TEXT("<TILESET>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<TILESET>")).Len();
	TileSetEnd = text.Find(FString(TEXT("</TILESET>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	ObjectSetStart = text.Find(FString(TEXT("<OBJECTTILESET>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<OBJECTTILESET>")).Len();
	ObjectSetEnd = text.Find(FString(TEXT("</OBJECTTILESET>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	TilesStart = text.Find(FString(TEXT("<TILES>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<TILES>")).Len();
	TilesEnd = text.Find(FString(TEXT("</TILES>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	ObjectsStart = text.Find(FString(TEXT("<OBJECTS>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<OBJECTS>")).Len();
	ObjectsEnd = text.Find(FString(TEXT("</OBJECTS>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	ObjectLayersStart = text.Find(FString(TEXT("<OBJECTLAYERS>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<OBJECTLAYERS>")).Len();
	ObjectLayersEnd = text.Find(FString(TEXT("</OBJECTLAYERS>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	BlockedStart = text.Find(FString(TEXT("<BLOCKED>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<BLOCKED>")).Len();
	BlockedEnd = text.Find(FString(TEXT("</BLOCKED>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	TriggersStart = text.Find(FString(TEXT("<TRIGGERS>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<TRIGGERS>")).Len();
	TriggersEnd = text.Find(FString(TEXT("</TRIGGERS>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
}

FString UMapEditor::MapToText()
{
	FString result;
	result += FString("<GridSize>\r\n" + FString::FromInt(GridSizeX) + " " + FString::FromInt(GridSizeY) + "\r\n</GridSize>\r\n");
	result += FString("<TileSize>\r\n" + FString::FromInt(TileSizeX) + " " + FString::FromInt(TileSizeY) + "\r\n</TileSize>\r\n");
	
	result += FString("<TileSet>\r\n");
	for (int i = 0; i < TileSet.Num(); i++)
	{
		result += FString(TileSet[i].TileName.ToString() + "\r\n");
	}
	result += FString("</TileSet>\r\n");

	result += FString("<ObjectTileSet>\r\n");
	for (int i = 0; i < ObjectTileSet.Num(); i++)
	{
		result += FString(ObjectTileSet[i].TileName.ToString() + "\r\n");
	}
		
	result += FString("</ObjectTileSet>\r\n");

	result += FString("<Tiles>\r\n");
	for (int y = 0; y < GridSizeY; y++)
	{
		for (int x = 0; x < GridSizeX; x++)
		{
			result += FString(FString::FromInt(TileMap[x][y]->TileType) + " ");
		}
		result += FString("\r\n");
	}
	result += FString("</Tiles>\r\n");

	result += FString("<Objects>\r\n");
	for (int y = 0; y < GridSizeY; y++)
	{
		for (int x = 0; x < GridSizeX; x++)
		{
			result += FString(FString::FromInt(ObjectTileMap[x][y]->TileType) + " ");
		}
		result += FString("\r\n");
	}
	result += FString("</Objects>\r\n");

	result += FString("<ObjectLayers>\r\n");
	for (int y = 0; y < GridSizeY; y++)
	{
		for (int x = 0; x < GridSizeX; x++)
		{
			result += FString(FString::FromInt(ObjectTileMap[x][y]->Layer) + " ");
		}
		result += FString("\r\n");
	}
	result += FString("</ObjectLayers>\r\n");

	result += FString("<Blocked>\r\n");
	for (int y = 0; y < GridSizeY; y++)
	{
		for (int x = 0; x < GridSizeX; x++)
		{
			if (TileMap[x][y]->IsBlocked)
			{
				result += FString("1 ");
			}
			else
			{
				result += FString("0 ");
			}
		}
		result += FString("\r\n");
	}
	result += FString("</Blocked>\r\n");

	result += FString("<Triggers>\r\n");
	for (int y = 0; y < GridSizeY; y++)
	{
		for (int x = 0; x < GridSizeX; x++)
		{
			if (TileMap[x][y]->IsTrigger)
			{
				result += FString(FString::FromInt(x) + " " + FString::FromInt(y) + "\r\n");
				result += FString(TileMap[x][y]->TriggerCommand + "\r\n");
			}
		}
	}
	result += FString("</Triggers>\r\n");
	
	return result;
}

void UMapEditor::SelectMapTile()
{
	if (MouseTileX != -1)
	{
		SelectedTileX = MouseTileX;
		SelectedTileY = MouseTileY;
		LvlEditWidget->IsTileBlocked = TileMap[SelectedTileX][SelectedTileY]->IsBlocked;
		LvlEditWidget->IsTileTrigger = TileMap[SelectedTileX][SelectedTileY]->IsTrigger;
		LvlEditWidget->TileTriggerCommand = FText::FromString(TileMap[SelectedTileX][SelectedTileY]->TriggerCommand);
		LvlEditWidget->ObjectLayer = ObjectTileMap[SelectedTileX][SelectedTileY]->Layer;
		LvlEditWidget->ReloadPropertiesWidget();
		UE_LOG(LogTemp, Warning, TEXT("Tile Selected"), MouseTileX, MouseTileY);
	}
	
}

void UMapEditor::ChangeTile()
{
	if (MouseTileX != -1)
	{
		SelectMapTile();
		if (SelectedTileSetTile != -1)
		{
			TileMap[SelectedTileX][SelectedTileY]->TileType = SelectedTileSetTile;
			TileMap[SelectedTileX][SelectedTileY]->UpdateTexture(TileSet[SelectedTileSetTile].texture);
		}
		else if (SelectedTileSetObject != -1)
		{
			ObjectTileMap[SelectedTileX][SelectedTileY]->TileType = SelectedTileSetObject;
			ObjectTileMap[SelectedTileX][SelectedTileY]->UpdateTexture(ObjectTileSet[SelectedTileSetObject].texture);
		}
		UE_LOG(LogTemp, Warning, TEXT("Tile Changed"), MouseTileX, MouseTileY);
	}
	
}

void UMapEditor::DeleteTile()
{
	if (MouseTileX != -1)
	{
		SelectMapTile();
		if (ObjectTileMap[SelectedTileX][SelectedTileY]->TileType > 0)
		{
			int tmpSelectTileSetTile = SelectedTileSetTile;
			int tmpSelectTileSetObject = SelectedTileSetObject;
			SelectedTileSetTile = -1;
			SelectedTileSetObject = 0;
			ChangeTile();
			tmpSelectTileSetTile = SelectedTileSetTile;
			tmpSelectTileSetObject = SelectedTileSetObject;
		}
		else
		{

			int tmpSelectTileSetTile = SelectedTileSetTile;
			int tmpSelectTileSetObject = SelectedTileSetObject;
			SelectedTileSetTile = 0;
			SelectedTileSetObject = -1;
			ChangeTile();
			tmpSelectTileSetTile = SelectedTileSetTile;
			tmpSelectTileSetObject = SelectedTileSetObject;
		}
	}
}

void UMapEditor::DrawSelectionBox()
{
	for (int i = 0; i < SelectionBox.Num(); i++)
	{
		SelectionBox[i]->Destroy();
	}
	SelectionBox.Empty();
	//Left Line
	FVector left = FVector(SelectedTileX*TileSizeX + (GridThickness / 2), 14, -TileSizeY - (GridThickness / 2) - (SelectedTileY*TileSizeY));
	AGridLine* leftLine = GetWorld()->SpawnActor<AGridLine>(SBoxLine, left, FRotator::ZeroRotator);
	leftLine->Sprite->SetRelativeScale3D(FVector(GridThickness, GridThickness, TileSizeY + GridThickness));
	SelectionBox.Add(leftLine);

	//Right Line
	FVector right = FVector((SelectedTileX + 1)*TileSizeX + (GridThickness / 2), 14, -TileSizeY - (GridThickness / 2) - (SelectedTileY*TileSizeY));
	AGridLine* rightLine = GetWorld()->SpawnActor<AGridLine>(SBoxLine, right, FRotator::ZeroRotator);
	rightLine->Sprite->SetRelativeScale3D(FVector(GridThickness, GridThickness, TileSizeY + GridThickness));
	SelectionBox.Add(rightLine);

	//Top Line
	FVector top = FVector(SelectedTileX*TileSizeX + TileSizeX + (GridThickness / 2), 14, -(GridThickness / 2) - (SelectedTileY*TileSizeY));
	AGridLine* topLine = GetWorld()->SpawnActor<AGridLine>(SBoxLine, top, FRotator::ZeroRotator);
	topLine->Sprite->SetRelativeScale3D(FVector(TileSizeX + GridThickness, GridThickness, GridThickness));
	SelectionBox.Add(topLine);

	//Bottom Line
	FVector bottom = FVector(SelectedTileX*TileSizeX + TileSizeX + (GridThickness / 2), 14, -(GridThickness / 2) - ((SelectedTileY + 1)*TileSizeY));
	AGridLine* bottomLine = GetWorld()->SpawnActor<AGridLine>(SBoxLine, bottom, FRotator::ZeroRotator);
	bottomLine->Sprite->SetRelativeScale3D(FVector(TileSizeX + GridThickness, GridThickness, GridThickness));
	SelectionBox.Add(bottomLine);
}

void UMapEditor::DrawMouseOverBox()
{
	for (int i = 0; i < MouseOverBox.Num(); i++)
	{
		MouseOverBox[i]->Destroy();
	}
	MouseOverBox.Empty();
	if (MouseTileX != -1 && (MouseTileX != SelectedTileX || MouseTileY != SelectedTileY))
	{
		//Left Line
		FVector left = FVector(MouseTileX*TileSizeX + (GridThickness / 2) , 15, -TileSizeY - (GridThickness / 2) - (MouseTileY*TileSizeY));
		AGridLine* leftLine = GetWorld()->SpawnActor<AGridLine>(MBoxLine, left, FRotator::ZeroRotator);
		leftLine->Sprite->SetRelativeScale3D(FVector(GridThickness, GridThickness, TileSizeY + GridThickness));
		MouseOverBox.Add(leftLine);

		//Right Line
		FVector right = FVector((MouseTileX+1)*TileSizeX + (GridThickness / 2), 15, -TileSizeY - (GridThickness / 2) - (MouseTileY*TileSizeY));
		AGridLine* rightLine = GetWorld()->SpawnActor<AGridLine>(MBoxLine, right, FRotator::ZeroRotator);
		rightLine->Sprite->SetRelativeScale3D(FVector(GridThickness, GridThickness, TileSizeY + GridThickness));
		MouseOverBox.Add(rightLine);

		//Top Line
		FVector top = FVector(MouseTileX*TileSizeX + TileSizeX + (GridThickness / 2), 15,  -(GridThickness / 2) - (MouseTileY*TileSizeY));
		AGridLine* topLine = GetWorld()->SpawnActor<AGridLine>(MBoxLine, top, FRotator::ZeroRotator);
		topLine->Sprite->SetRelativeScale3D(FVector(TileSizeX + GridThickness, GridThickness, GridThickness));
		MouseOverBox.Add(topLine);

		//Bottom Line
		FVector bottom = FVector(MouseTileX*TileSizeX + TileSizeX + (GridThickness / 2), 15, -(GridThickness / 2) - ((MouseTileY + 1)*TileSizeY));
		AGridLine* bottomLine = GetWorld()->SpawnActor<AGridLine>(MBoxLine, bottom, FRotator::ZeroRotator);
		bottomLine->Sprite->SetRelativeScale3D(FVector(TileSizeX + GridThickness, GridThickness, GridThickness));
		MouseOverBox.Add(bottomLine);
	}
}

void UMapEditor::AddTile(SLevelEditWidget* SourceWidget)
{
	
	FString DialogTitle = "Tile Image";
	FString DefaultPath = FPaths::GameDir();
	FString DefaultFile = "";
	uint32 Flags = EFileDialogFlags::None;
	FString FileTypes = "PNG files (*.png)|*.png";
	TArray<FString> OutFilename;
	void* WindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();

	if (DesktopPlatform->OpenFileDialog(WindowHandle, DialogTitle, DefaultPath, DefaultFile, FileTypes, Flags, OutFilename))
	{
		// do your stuff
		bool FileLoad;
		UTexture2D* Texture = Load2DTextureFromFile(OutFilename[0], FileLoad);
		
		if (FileLoad)
		{
			UE_LOG(LogTemp, Warning, TEXT("LoadTileTextureWirth: %f\n"), Texture->GetSurfaceWidth());
			UE_LOG(LogTemp, Warning, TEXT("TileSet Num %i \n"), TileSet.Num());
			FTileSetTile newTile = {};
			newTile.TileName = FText::FromString(FPaths::GetBaseFilename(OutFilename[0]));
			newTile.texture = Texture;
			TileSet.Add(newTile);

			if (SourceWidget)
			{
				//LvlEditWidget = SourceWidget;
				SourceWidget->AddTile(Texture, newTile.TileName.ToString());
				
				SelectTile(TileSet.Num() - 1);
				UE_LOG(LogTemp, Warning, TEXT("Selected Map Editor %i \n"), SelectedTileSetTile);
			}
			
		}
	}
}

void UMapEditor::AddObject(SLevelEditWidget* SourceWidget)
{

	FString DialogTitle = "Tile Image";
	FString DefaultPath = FPaths::GameDir();
	FString DefaultFile = "";
	uint32 Flags = EFileDialogFlags::None;
	FString FileTypes = "PNG files (*.png)|*.png";
	TArray<FString> OutFilename;
	void* WindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();

	if (DesktopPlatform->OpenFileDialog(WindowHandle, DialogTitle, DefaultPath, DefaultFile, FileTypes, Flags, OutFilename))
	{
		// do your stuff
		bool FileLoad;
		UTexture2D* Texture = Load2DTextureFromFile(OutFilename[0], FileLoad);
		if (FileLoad)
		{
			UE_LOG(LogTemp, Warning, TEXT("TileSet Num %i \n"), TileSet.Num());
			FTileSetTile newTile = {};
			newTile.TileName = FText::FromString(FPaths::GetBaseFilename(OutFilename[0]));
			newTile.texture = Texture;
			ObjectTileSet.Add(newTile);

			if (SourceWidget)
			{
				//LvlEditWidget = SourceWidget;
				SourceWidget->AddObject(Texture, newTile.TileName.ToString());
				SelectObjectTile(ObjectTileSet.Num() - 1);
				UE_LOG(LogTemp, Warning, TEXT("Selected Map Editor %i \n"), SelectedTileSetTile);
			}

		}
	}
}

void UMapEditor::Save2DTextureToFile(UTexture2D* texture, FString FileName)
{
	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

	IImageWrapperPtr ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);

	TArray<uint8>* UncompressedBGRA = NULL;

	const void* TextureData = texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	
	if (ImageWrapper.IsValid() && ImageWrapper->SetRaw(TextureData, texture->PlatformData->Mips[0].BulkData.GetBulkDataSize(), texture->GetSurfaceWidth(), texture->GetSurfaceHeight(), ERGBFormat::BGRA, 8))
	{
		texture->PlatformData->Mips[0].BulkData.Unlock();

	    const TArray<uint8> CompressedData = ImageWrapper->GetCompressed(10);

		FFileHelper::SaveArrayToFile(CompressedData, *FileName);
		
	}
}

UTexture2D* UMapEditor::Load2DTextureFromFile(const FString& FullFilePath, bool& IsValid)
{
	IsValid = false;
	UTexture2D* LoadedT2D = NULL;

	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

	IImageWrapperPtr ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);

	//Load From File
	TArray<uint8> RawFileData;
	if (!FFileHelper::LoadFileToArray(RawFileData, *FullFilePath))
	{
		return NULL;
	}

	//Create T2D!
	if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
	{
		const TArray<uint8>* UncompressedBGRA = NULL;
		if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBGRA))
		{

			LoadedT2D = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);
			LoadedT2D->LODGroup = TEXTUREGROUP_Pixels2D;
			//Valid?
			if (!LoadedT2D)
			{
				return NULL;
			}

			//Out!
			//Width = ImageWrapper->GetWidth();
			//Height = ImageWrapper->GetHeight();

			//Copy!
			void* TextureData = LoadedT2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
			FMemory::Memcpy(TextureData, UncompressedBGRA->GetData(), UncompressedBGRA->Num());
			LoadedT2D->PlatformData->Mips[0].BulkData.Unlock();
			

			//Update!
			LoadedT2D->UpdateResource();
		}
	}

	// Success!
	IsValid = true;
	return LoadedT2D;

}

void UMapEditor::SelectTile(int index)
{
	SelectedTileSetTile = index;
	if (SelectedTileSetObject > -1)
	{
		class STileSetWidget* tWidge = (STileSetWidget*)LvlEditWidget->ObjectTileSetWidgets[SelectedTileSetObject].Get();
		tWidge->Selected = false;
	}	
	SelectedTileSetObject = -1;
	UE_LOG(LogTemp, Warning, TEXT("Selected %i \n"), index);
}

void UMapEditor::SelectObjectTile(int index)
{
	if (SelectedTileSetTile > -1)
	{
		class STileSetWidget* tWidge = (STileSetWidget*)LvlEditWidget->TileSetWidgets[SelectedTileSetTile].Get();
		tWidge->Selected = false;
	}
	SelectedTileSetTile = -1;
	SelectedTileSetObject = index;
	UE_LOG(LogTemp, Warning, TEXT("Selected %i \n"), index);
}

void UMapEditor::RemoveSelectedTile()
{
	if (SelectedTileSetTile >= 1 && SelectedTileSetTile < TileSet.Num() )
	{
		TileSet.RemoveAt(SelectedTileSetTile);
		for (int x = 0; x < GridSizeX; x++)
		{
			for (int y = 0; y < GridSizeY; y++)
			{
				if (TileMap[x][y]->TileType == SelectedTileSetTile)
				{
					TileMap[x][y]->TileType = 0;
					TileMap[x][y]->UpdateTexture(BlankTile);
				}
			}
		}
		SelectedTileSetTile = FMath::Clamp(SelectedTileSetTile, 0, TileSet.Num() - 1);
		UE_LOG(LogTemp, Warning, TEXT("TileSet Num %i \n"), TileSet.Num());
		LvlEditWidget->RebuildTileList();
	}
	
}

void UMapEditor::RemoveSelectedObject()
{
	if (SelectedTileSetObject >= 1 && SelectedTileSetObject < ObjectTileSet.Num())
	{
		for (int x = 0; x < GridSizeX; x++)
		{
			for (int y = 0; y < GridSizeY; y++)
			{
				if (ObjectTileMap[x][y]->TileType == SelectedTileSetObject)
				{
					ObjectTileMap[x][y]->TileType = 0;
					ObjectTileMap[x][y]->UpdateTexture(BlankTile);
				}
			}
		}
		ObjectTileSet.RemoveAt(SelectedTileSetObject);
		SelectedTileSetTile = FMath::Clamp(SelectedTileSetObject, 0, ObjectTileSet.Num() - 1);
		UE_LOG(LogTemp, Warning, TEXT("TileSet Num %i \n"), ObjectTileSet.Num());
		LvlEditWidget->RebuildObjectList();
	}

	
}
void UMapEditor::UpdateCurrentTileData()
{
	TileMap[SelectedTileX][SelectedTileY]->IsBlocked = LvlEditWidget->IsBlockedBox->IsChecked();
	TileMap[SelectedTileX][SelectedTileY]->IsTrigger = LvlEditWidget->IsTriggerBox->IsChecked();
	TileMap[SelectedTileX][SelectedTileY]->TriggerCommand = LvlEditWidget->TriggerCommandText->GetText().ToString();
	ObjectTileMap[SelectedTileX][SelectedTileY]->Layer = FCString::Atoi(*LvlEditWidget->ObjectLayerText->GetText().ToString());

}

