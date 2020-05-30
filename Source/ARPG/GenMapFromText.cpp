// Fill out your copyright notice in the Description page of Project Settings.

#include "GenMapFromText.h"
#include "Engine.h"
#include "DynamicSprite.h"
#include "DialogueObject.h"
#include "Runtime/ImageWrapper/Public/IImageWrapper.h"
#include "Runtime/ImageWrapper/Public/IImageWrapperModule.h"


// Sets default values for this component's properties
UGenMapFromText::UGenMapFromText()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGenMapFromText::BeginPlay()
{
	Super::BeginPlay();

	FString FullPath = FString(FPaths::GameDir() + "/Maps/" + MapName);
	FString MapText;
	FFileHelper::LoadFileToString(MapText, *FString(FullPath + "/" + MapName + ".txt"));
	FString str = MapText;
	int GridSizeStartIndex, GridSizeEndIndex, TileSizeStartIndex, TileSizeEndIndex, TileSetStartIndex, TileSetEndIndex, ObjectSetStartIndex, ObjectSetEndIndex, TileStartIndex, TileEndIndex, ObjectStartIndex, ObjectEndIndex, LayerStartIndex, LayerEndIndex, BlockStartIndex, BlockEndIndex, TriggerStartIndex, TriggerEndIndex, NPCStartIndex, NPCEndIndex, IObjectStartIndex, IObjectEndIndex = -1;

	ScanForTag(MapText, GridSizeStartIndex, GridSizeEndIndex, TileSizeStartIndex, TileSizeEndIndex, TileSetStartIndex, TileSetEndIndex, ObjectSetStartIndex, ObjectSetEndIndex, TileStartIndex, TileEndIndex, ObjectStartIndex, ObjectEndIndex, LayerStartIndex, LayerEndIndex, BlockStartIndex, BlockEndIndex, TriggerStartIndex, TriggerEndIndex, NPCStartIndex, NPCEndIndex, IObjectStartIndex, IObjectEndIndex);

	UE_LOG(LogTemp, Warning, TEXT("Tile Start And End %i, %i"), TileStartIndex, TileEndIndex);

	

	if (GridSizeStartIndex > 0 && GridSizeEndIndex > 0 && GridSizeEndIndex > GridSizeStartIndex)
	{
		FString GridSizeText = MapText.Left(GridSizeEndIndex).Right(GridSizeEndIndex - GridSizeStartIndex - 2);

		int x, y;
		TArray<FString> tmpArr;
		//Get position of tile for command
		GridSizeText.ParseIntoArray(tmpArr, TEXT(" "), false);
		x = FCString::Atoi(*tmpArr[0]);
		y = FCString::Atoi(*tmpArr[1]);
		MapWidth = x;
		MapHeight = y;

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
	/*
	if (TileSetStartIndex > 0 && TileSetEndIndex > 0 && TileSetEndIndex > TileSetStartIndex)//If tag positions found and valid
	{
		TArray<FString> TileSetLines;
		//Split the section of text between the Indexes into lines
		str.Left(TileSetEndIndex + 1).Right(TileSetEndIndex - TileSetStartIndex + 1).ParseIntoArrayLines(TileSetLines, false);
		for (int i = 0; i < TileSetLines.Num() - 2; i++)//process each line, skip first and last as empty
		{
			if (UniversalTileSet.Contains(TileSetLines[i + 1].ToUpper()))
			{
				TileSet.Add(UniversalTileSet[TileSetLines[i + 1].ToUpper()]);
			}
		}
	}
	*/
	if (TileSetStartIndex > 0 && TileSetEndIndex > 0 && TileSetEndIndex > TileSetStartIndex)//If tag positions found and valid
	{
		TArray<FString> TileSetLines;
		//Split the section of text between the Indexes into lines
		MapText.Left(TileSetEndIndex).Right(TileSetEndIndex - TileSetStartIndex - 2).ParseIntoArrayLines(TileSetLines, false);
		for (int i = 0; i < TileSetLines.Num() - 1; i++)//process each line, skip first and last as empty
		{
			FTileSetTile NewTile;
			bool IsValid;
			NewTile.TileName = FText::FromString(TileSetLines[i]);
			NewTile.texture = Load2DTextureFromFile(FString(FullPath + "/" + TileSetLines[i] + ".png"), IsValid);
			TileSet.Add(NewTile);
			
		}
	}
	/*
	if (ObjectSetStartIndex > 0 && ObjectSetEndIndex > 0 && ObjectSetEndIndex > ObjectSetStartIndex)
	{
		TArray<FString> ObjectSetLines;
		str.Left(ObjectSetEndIndex + 1).Right(ObjectSetEndIndex - ObjectSetStartIndex + 1).ParseIntoArrayLines(ObjectSetLines, false);
		for (int i = 0; i < ObjectSetLines.Num() - 2; i++)
		{
			if (UniversalTileSet.Contains(ObjectSetLines[i + 1].ToUpper()))
			{
				ObjectSet.Add(UniversalTileSet[ObjectSetLines[i + 1].ToUpper()]);
			}
		}
	}
	*/

	if (ObjectSetStartIndex > 0 && ObjectSetEndIndex > 0 && ObjectSetEndIndex > ObjectSetStartIndex)//If tag positions found and valid
	{
		TArray<FString> TileSetLines;
		//Split the section of text between the Indexes into lines
		MapText.Left(ObjectSetEndIndex).Right(ObjectSetEndIndex - ObjectSetStartIndex - 2).ParseIntoArrayLines(TileSetLines, false);
		for (int i = 0; i < TileSetLines.Num() - 1; i++)//process each line, skip first and last as empty
		{
			FTileSetTile NewTile;
			bool IsValid;
			NewTile.TileName = FText::FromString(TileSetLines[i]);
			NewTile.texture = Load2DTextureFromFile(FString(FullPath + "/" + TileSetLines[i] + ".png"), IsValid);
			ObjectSet.Add(NewTile);
		}
	}

	if (TileStartIndex > 0 && TileEndIndex > 0 && TileEndIndex > TileStartIndex)
	{
		TArray<FString> TilesLines;
		str.Left(TileEndIndex + 1).Right(TileEndIndex - TileStartIndex + 1).ParseIntoArrayLines(TilesLines, false);

		for (int y = 0; y < TilesLines.Num()-2; y++)
		{
			TArray<FString> tmpArr;
			//Split line into separate numbers
			TilesLines[y+1].ParseIntoArray(tmpArr, TEXT(" "), false);
			Tiles.Add(FnumRow());
			for (int x = 0; x < tmpArr.Num() - 1; x++)
			{
				Tiles[y].Row.Add(FTileProp());//add tile
				Tiles[y].Row[x].Type = FCString::Atoi(*tmpArr[x]);//set tile type based on number in file

			}

		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Object Start And End %i, %i"), ObjectStartIndex, ObjectEndIndex);

	if (ObjectStartIndex > 0 && ObjectEndIndex > 0 && ObjectEndIndex > ObjectStartIndex)
	{
		TArray<FString> ObjectLines;
		str.Left(ObjectEndIndex + 1).Right(ObjectEndIndex - ObjectStartIndex + 1).ParseIntoArrayLines(ObjectLines, false);

		for (int y = 0; y < ObjectLines.Num() - 2; y++)
		{
			TArray<FString> tmpArr;
			ObjectLines[y+1].ParseIntoArray(tmpArr, TEXT(" "), false);
			Objects.Add(FnumRow());
			for (int x = 0; x < tmpArr.Num() - 1; x++)
			{
				Objects[y].Row.Add(FTileProp());
				Objects[y].Row[x].Type = FCString::Atoi(*tmpArr[x]);

			}

		}
	}
	if (LayerStartIndex > 0 && LayerEndIndex > 0 && LayerEndIndex > LayerStartIndex)
	{
		TArray<FString> LayerLines;
		str.Left(LayerEndIndex + 1).Right(LayerEndIndex - LayerStartIndex + 1).ParseIntoArrayLines(LayerLines, false);

		for (int y = 0; y < LayerLines.Num() - 2; y++)
		{
			TArray<FString> tmpArr;
			LayerLines[y + 1].ParseIntoArray(tmpArr, TEXT(" "), false);
			if (y < Objects.Num())
			{
				for (int x = 0; x < tmpArr.Num() - 1; x++)
				{
					if (x < Objects[y].Row.Num())
					{
						Objects[y].Row[x].Layer = FCString::Atoi(*tmpArr[x]);
					}
				}
			}

		}
	}
	if (BlockStartIndex > 0 && BlockEndIndex > 0 && BlockEndIndex > BlockStartIndex)
	{
		TArray<FString> BlockLines;
		str.Left(BlockEndIndex + 1).Right(BlockEndIndex - BlockStartIndex + 1).ParseIntoArrayLines(BlockLines, false);

		for (int y = 0; y < BlockLines.Num() - 2; y++)
		{
			TArray<FString> tmpArr;
			BlockLines[y + 1].ParseIntoArray(tmpArr, TEXT(" "), false);
			if (y < Tiles.Num())
			{
				for (int x = 0; x < tmpArr.Num() - 1; x++)
				{
					if (x < Tiles[y].Row.Num())
					{
						if (FCString::Atoi(*tmpArr[x]) == 1)
						{
							Tiles[y].Row[x].isBlocked = true;
						}
					}
				}
			}
			
		}
	}
	if (TriggerStartIndex > 0 && TriggerEndIndex > 0 && TriggerEndIndex > TriggerStartIndex)
	{
		TArray<FString> TriggerLines;
		str.Left(TriggerEndIndex + 1).Right(TriggerEndIndex - TriggerStartIndex + 1).ParseIntoArrayLines(TriggerLines, false);

		for (int i = 0; i < (TriggerLines.Num() - 2)/2; i++)// Lines/2 as position + command takes 2 lines
		{
			int x, y;
			TArray<FString> tmpArr;
			//Get position of tile for command
			TriggerLines[(i*2) + 1].ParseIntoArray(tmpArr, TEXT(" "), false);
			x = FCString::Atoi(*tmpArr[0]);
			y = FCString::Atoi(*tmpArr[1]);
			Tiles[y].Row[x].isTrigger = true;//Set tile to be a trigger
			Tiles[y].Row[x].TriggerCommand = TriggerLines[(i*2) + 2];//Set the command of tile from second line

		}
	}

	//UE_LOG(LogTemp, Warning, TEXT("NPC Start And End %i, %i"), NPCStartIndex, NPCEndIndex);

	if (NPCStartIndex > 0 && NPCEndIndex > 0 && NPCEndIndex > NPCStartIndex)//If tag positions found and valid
	{
		TArray<FString> NPCLines;
		//Split the section of text between the Indexes into lines
		str.Left(NPCEndIndex + 1).Right(NPCEndIndex - NPCStartIndex + 1).ParseIntoArrayLines(NPCLines, false);
		//UE_LOG(LogTemp, Warning, TEXT("NPC Lines Num %i"), NPCLines.Num());
		for (int i = 0; i < (NPCLines.Num() - 2)/3; i++)//process each 3 lines, skip first and last as empty
		{
			int x, y;
			FString NPCType;
			FString DialoguePath;
			TArray<FString> tmpArr;
			NPCType = NPCLines[(i * 3) + 1].ToUpper();
			NPCLines[(i * 3) + 2].ParseIntoArray(tmpArr, TEXT(" "), false);
			x = FCString::Atoi(*tmpArr[0]);
			y = FCString::Atoi(*tmpArr[1]);
			DialoguePath = NPCLines[(i * 3) + 3];

			//UE_LOG(LogTemp, Warning, TEXT("NPC Type: %s"), *NPCType);
			if (NPCMap.Contains(NPCType))
			{
				//(LogTemp, Warning, TEXT("NPC found"));
				NPCTypes.Add(*NPCMap.Find(NPCType));
				NPCPos.Add(FVector2D(x, y));
			}

			NPCDialogue.Add(LoadDialogue(DialoguePath));
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("IObj Start And End %i, %i"), IObjectStartIndex, IObjectEndIndex);
	if (IObjectStartIndex > 0 && IObjectEndIndex > 0 && IObjectEndIndex > IObjectStartIndex)//If tag positions found and valid
	{
		TArray<FString> IObjectLines;
		//Split the section of text between the Indexes into lines
		str.Left(IObjectEndIndex + 1).Right(IObjectEndIndex - IObjectStartIndex + 1).ParseIntoArrayLines(IObjectLines, false);
		//UE_LOG(LogTemp, Warning, TEXT("NPC Lines Num %i"), NPCLines.Num());
		for (int i = 0; i < (IObjectLines.Num() - 2) / 2; i++)//process each 3 lines, skip first and last as empty
		{
			UE_LOG(LogTemp, Warning, TEXT("IObj Added Gen Map"));
			int x, y;
			FString DialoguePath;
			TArray<FString> tmpArr;
			IObjectLines[(i * 3) + 1].ParseIntoArray(tmpArr, TEXT(" "), false);
			x = FCString::Atoi(*tmpArr[0]);
			y = FCString::Atoi(*tmpArr[1]);
			DialoguePath = IObjectLines[(i * 3) + 2];

			IObjectPos.Add(FVector2D(x, y));
			IObjectDialogue.Add(LoadObjectDialogue(DialoguePath));
		}
	}
	// ...
	
}

void UGenMapFromText::ScanForTag(FString &text, int &GridSizeStartIndex, int &GridSizeEndIndex, int &TileSizeStartIndex, int &TileSizeEndIndex, int &TileSetStart, int &TileSetEnd, int &ObjectSetStart, int &ObjectSetEnd, int &TilesStart, int &TilesEnd, int &ObjectsStart, int &ObjectsEnd, int &ObjectLayersStart, int &ObjectLayersEnd, int &BlockedStart, int &BlockedEnd, int &TriggersStart, int &TriggersEnd, int &NPCStart, int &NPCEnd, int &IObjectStart, int &IObjectEnd)
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
	NPCStart = text.Find(FString(TEXT("<NPCS>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<NPC>")).Len();
	NPCEnd = text.Find(FString(TEXT("</NPCS>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	IObjectStart = text.Find(FString(TEXT("<INTERACTABLEOBJECTS>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<INTERACTABLEOBJECTS>")).Len();
	IObjectEnd = text.Find(FString(TEXT("</INTERACTABLEOBJECTS>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
}

TArray<DialogueObject> UGenMapFromText::LoadDialogue(FString DialogueFileName)
{
	TArray<DialogueObject> Objects;
	FString FullPath = FString(FPaths::GameDir() + "/Maps/" + MapName + "/NPCs");
	FString DialogueText;
	FFileHelper::LoadFileToString(DialogueText, *FString(FullPath + "/" + DialogueFileName + ".txt"));
	FString str = DialogueText;
	//UE_LOG(LogTemp, Warning, TEXT("DialogueText %s"), *FString(FullPath + "/" + DialogueFileName + ".txt"));
	int DialogueObjStart;
	int DialogueObjEnd;
	DialogueObjStart = str.Find(FString(TEXT("<DIALOGUEOBJECT>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<DIALOGUEOBJECT>")).Len();
	DialogueObjEnd = str.Find(FString(TEXT("</DIALOGUEOBJECT>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	//UE_LOG(LogTemp, Warning, TEXT("Dialogue Start And End %i, %i"), DialogueObjStart, DialogueObjEnd)
	while (DialogueObjStart != -1 && DialogueObjEnd != -2 && DialogueObjEnd > DialogueObjStart)
	{
		DialogueObject DObj;
		UE_LOG(LogTemp, Warning, TEXT("Dialogue Object found"));
		TArray<FString> DialogueLines;
		//Split the section of text between the Indexes into lines
		str.Left(DialogueObjEnd).Right(DialogueObjEnd - DialogueObjStart - 2).ParseIntoArrayLines(DialogueLines, false);
		for (int i = 1; i < DialogueLines.Num() - 1; i++)//process each line, skip first and last as empty
		{
			FString Command = DialogueLines[i].ToUpper();
			UE_LOG(LogTemp, Warning, TEXT("Command %s"), *Command);
			if (Command.Equals("NEWLINE"))
			{
				FDialogueItem DItem;
				DItem.Type = NewLine;
				DItem.String = DialogueLines[i + 1];
				DObj.AddDialogueItem(DItem);
				i++;
			}
			else if (Command.Equals("SETTITLE"))
			{
				FDialogueItem DItem;
				DItem.Type = SetTitle;
				DItem.String = DialogueLines[i + 1];
				DObj.AddDialogueItem(DItem);
				i++;
			}
			else if (Command.Equals("NEWPAGE"))
			{
				FDialogueItem DItem;
				DItem.Type = NewPage;
				DItem.String = DialogueLines[i + 1];
				DObj.AddDialogueItem(DItem);
				i++;
			}
			else if (Command.Equals("FREEZE"))
			{
				FDialogueItem DItem;
				DItem.Type = FreezePlayer;
				DObj.AddDialogueItem(DItem);
			}
			else if (Command.Equals("UNFREEZE"))
			{
				FDialogueItem DItem;
				DItem.Type = UnFreezePlayer;
				DObj.AddDialogueItem(DItem);
			}
			
		}
		Objects.Add(DObj);
		UE_LOG(LogTemp, Warning, TEXT("DObj Items Num %i"), DObj.GetDialogueItemsLength());
		str = str.RightChop(DialogueObjEnd + FString(TEXT("<DIALOGUEOBJECT>")).Len());
		DialogueObjStart = str.Find(FString(TEXT("<DIALOGUEOBJECT>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<DIALOGUEOBJECT>")).Len();
		DialogueObjEnd = str.Find(FString(TEXT("</DIALOGUEOBJECT>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	}
	return Objects;
}

TArray<DialogueObject> UGenMapFromText::LoadObjectDialogue(FString DialogueFileName)
{
	TArray<DialogueObject> Objects;
	FString FullPath = FString(FPaths::GameDir() + "/Maps/" + MapName + "/Objects");
	FString DialogueText;
	FFileHelper::LoadFileToString(DialogueText, *FString(FullPath + "/" + DialogueFileName + ".txt"));
	FString str = DialogueText;
	//UE_LOG(LogTemp, Warning, TEXT("DialogueText %s"), *FString(FullPath + "/" + DialogueFileName + ".txt"));
	int DialogueObjStart;
	int DialogueObjEnd;
	DialogueObjStart = str.Find(FString(TEXT("<DIALOGUEOBJECT>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<DIALOGUEOBJECT>")).Len();
	DialogueObjEnd = str.Find(FString(TEXT("</DIALOGUEOBJECT>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	//UE_LOG(LogTemp, Warning, TEXT("Dialogue Start And End %i, %i"), DialogueObjStart, DialogueObjEnd)
	while (DialogueObjStart != -1 && DialogueObjEnd != -2 && DialogueObjEnd > DialogueObjStart)
	{
		DialogueObject DObj;
		UE_LOG(LogTemp, Warning, TEXT("Dialogue Object found"));
		TArray<FString> DialogueLines;
		//Split the section of text between the Indexes into lines
		str.Left(DialogueObjEnd).Right(DialogueObjEnd - DialogueObjStart - 2).ParseIntoArrayLines(DialogueLines, false);
		for (int i = 1; i < DialogueLines.Num() - 1; i++)//process each line, skip first and last as empty
		{
			FString Command = DialogueLines[i].ToUpper();
			UE_LOG(LogTemp, Warning, TEXT("Command %s"), *Command);
			if (Command.Equals("NEWLINE"))
			{
				FDialogueItem DItem;
				DItem.Type = NewLine;
				DItem.String = DialogueLines[i + 1];
				DObj.AddDialogueItem(DItem);
				i++;
			}
			else if (Command.Equals("SETTITLE"))
			{
				FDialogueItem DItem;
				DItem.Type = SetTitle;
				DItem.String = DialogueLines[i + 1];
				DObj.AddDialogueItem(DItem);
				i++;
			}
			else if (Command.Equals("NEWPAGE"))
			{
				FDialogueItem DItem;
				DItem.Type = NewPage;
				DItem.String = DialogueLines[i + 1];
				DObj.AddDialogueItem(DItem);
				i++;
			}
			else if (Command.Equals("FREEZE"))
			{
				FDialogueItem DItem;
				DItem.Type = FreezePlayer;
				DObj.AddDialogueItem(DItem);
			}
			else if (Command.Equals("UNFREEZE"))
			{
				FDialogueItem DItem;
				DItem.Type = UnFreezePlayer;
				DObj.AddDialogueItem(DItem);
			}

		}
		Objects.Add(DObj);
		UE_LOG(LogTemp, Warning, TEXT("DObj Items Num %i"), DObj.GetDialogueItemsLength());
		str = str.RightChop(DialogueObjEnd + FString(TEXT("<DIALOGUEOBJECT>")).Len());
		DialogueObjStart = str.Find(FString(TEXT("<DIALOGUEOBJECT>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) + FString(TEXT("<DIALOGUEOBJECT>")).Len();
		DialogueObjEnd = str.Find(FString(TEXT("</DIALOGUEOBJECT>")), ESearchCase::IgnoreCase, ESearchDir::FromStart, -1) - 1;
	}
	return Objects;
}


// Called every frame
void UGenMapFromText::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UTexture2D* UGenMapFromText::Load2DTextureFromFile(const FString& FullFilePath, bool& IsValid)
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

TArray<FTileSetTile> UGenMapFromText::GetTileSet()
{
	return TileSet;
}

TArray<FTileSetTile> UGenMapFromText::GetObjectSet()
{
	return ObjectSet;
}

TArray<FnumRow> UGenMapFromText::GetTiles()
{
	return Tiles;
}

TArray<FnumRow> UGenMapFromText::GetObjects()
{
	return Objects;
}

TSubclassOf<ANPCPawn> UGenMapFromText::GetNPCType(int Index)
{
	return NPCTypes[Index];
}

FVector2D UGenMapFromText::GetNPCPos(int Index)
{
	return NPCPos[Index];
}

class DialogueObject UGenMapFromText::GetNPCDialogue(int IndexA, int IndexB)
{
	return NPCDialogue[IndexA][IndexB];
}

FVector2D UGenMapFromText::GetIObjectPos(int Index)
{
	return IObjectPos[Index];
}

class DialogueObject UGenMapFromText::GetIObjectDialogue(int IndexA, int IndexB)
{
	return IObjectDialogue[IndexA][IndexB];
}

int UGenMapFromText::GetTileSizeX()
{
	return TileSizeX;
}

int UGenMapFromText::GetTileSizeY()
{
	return TileSizeY;
}

int UGenMapFromText::GetMapHeight()
{
	return MapHeight;
}

int UGenMapFromText::GetMapWidth()
{
	return MapWidth;
}

int UGenMapFromText::GetNPCNum()
{
	return NPCTypes.Num();
}

int UGenMapFromText::GetIObjectNum()
{
	return IObjectPos.Num();
}

int UGenMapFromText::GetNPCDialogueNum(int Index)
{
	return NPCDialogue[Index].Num();
}

int UGenMapFromText::GetIObjectDialogueNum(int Index)
{
	return IObjectDialogue[Index].Num();
}