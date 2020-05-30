// Fill out your copyright notice in the Description page of Project Settings.


#include "MapObject.h"
#include "ARPG.h"
#include "GenMapFromText.h"
#include "MapTile.h"
#include "GameManagment.h"
#include "PlayerPawn.h"
#include "DialogueSystem.h"
#include "IObject.h"


// Sets default values
AMapObject::AMapObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TileBase"));
	}
}


// Called when the game starts or when spawned
void AMapObject::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMapObject::Generate()
{
	if (GenerateMapFromText)
	{
		TArray<UActorComponent*> children;
		GetComponents(children);

		//Get the GenMapFromText component which should be attached to MapObject actor
		for (int i = 0; i < children.Num(); i++)
		{
			if (children[i])
			{
				UActorComponent* child = children[i];
				FString name = child->GetName();
				if (child->GetName() == "GenMapFromText")
				{
					Generator = (UGenMapFromText*)child;
				}
			}
		}
		//Get values from compoennt
		TileSet = Generator->GetTileSet();
		ObjectTileSet = Generator->GetObjectSet();
		TilesMap = Generator->GetTiles();
		ObjectsMap = Generator->GetObjects();
		TileSizeX = Generator->GetTileSizeX();
		TileSizeY = Generator->GetTileSizeY();
		MapHeight = Generator->GetMapHeight();
		MapWidth = Generator->GetMapWidth();
		gameManComp->GetPlayerPawn()->SetTileSizeX(TileSizeX);
		gameManComp->GetPlayerPawn()->SetTileSizeY(TileSizeY);
		gameManComp->GetPlayerPawn()->SetMapWidth(MapWidth);
		gameManComp->GetPlayerPawn()->SetMapHeight(MapHeight);

	}


	//Generate tiles
	for (int y = 0; y < TilesMap.Num(); y++)
	{
		Tiles.Add(FRow());//Add row of tiles
		for (int x = 0; x < TilesMap[y].Row.Num(); x++)
		{
			Tiles[y].Row.Add(nullptr);//add null pointer to row for new tile
			SpawnTile(x, y, TilesMap[y].Row[x].Type, TilesMap[y].Row[x].Layer);//spawn tile
			Tiles[y].Row[x]->SetBlocked(TilesMap[y].Row[x].isBlocked);//Set tiles properties
			Tiles[y].Row[x]->SetTrigger(TilesMap[y].Row[x].isTrigger);
			Tiles[y].Row[x]->SetTriggerCommand(TilesMap[y].Row[x].TriggerCommand);
			//Tiles[y].Row[x]->gameManComp = gameManComp;
		}
	}


	for (int y = 0; y < ObjectsMap.Num(); y++)
	{
		Objects.Add(FRow());
		for (int x = 0; x < ObjectsMap[y].Row.Num(); x++)
		{
			Objects[y].Row.Add(nullptr);
			if (ObjectsMap[y].Row[x].Type != 0)
			{
				SpawnObject(x, y, ObjectsMap[y].Row[x].Type, ObjectsMap[y].Row[x].Layer);
				Objects[y].Row[x]->SetBlocked(ObjectsMap[y].Row[x].isBlocked);
				Objects[y].Row[x]->SetTrigger(ObjectsMap[y].Row[x].isTrigger);
				Objects[y].Row[x]->SetTriggerCommand(ObjectsMap[y].Row[x].TriggerCommand);
				//Objects[y].Row[x]->gameManComp = gameManComp;
			}
		}
	}

	for (int x = 0; x < MapWidth; x++)
	{
		NPCs.Add(TArray<int>());
		InteractableObjects.Add(TArray<int>());
		for (int y = 0; y < MapHeight; y++)
		{
			NPCs[x].Add(-1);
			InteractableObjects[x].Add(-1);
		}
	}

	for (int i = 0; i < Generator->GetNPCNum(); i++)
	{
		ANPCPawn* SpawnNPC = GetWorld()->SpawnActor<ANPCPawn>(Generator->GetNPCType(i), FVector::ZeroVector, FRotator::ZeroRotator);
		SpawnNPC->SetMapX(Generator->GetNPCPos(i).X);
	    SpawnNPC->SetMapY(Generator->GetNPCPos(i).Y);
		SpawnNPC->SetTileSizeX(TileSizeX);
		SpawnNPC->SetTileSizeY(TileSizeY);
		SpawnNPC->SetMapHeight(MapHeight);
		SpawnNPC->SetMapWidth(MapWidth);
		NPCs[Generator->GetNPCPos(i).X][Generator->GetNPCPos(i).Y] = i;
		if (Generator->GetNPCDialogueNum(i) > 0) SpawnNPC->SetDialogueOnPress(1);
		for (int a = 0; a < Generator->GetNPCDialogueNum(i); a++)
		{
			SpawnNPC->AddDialogueObject(Generator->GetNPCDialogue(i,a));
		}
		gameManComp->AddNPC(SpawnNPC);
	}

	for (int i = 0; i < Generator->GetIObjectNum(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("IObj Added"));
		IObject IObj;
		InteractableObjects[Generator->GetIObjectPos(i).X][Generator->GetIObjectPos(i).Y] = i;
		if (Generator->GetIObjectDialogueNum(i) > 0) IObj.SetDialogueOnPress(1);
		for (int a = 0; a < Generator->GetIObjectDialogueNum(i); a++)
		{
			IObj.AddDialogueObject(Generator->GetIObjectDialogue(i,a));
		}
		gameManComp->AddIObject(IObj);
	}

}


void AMapObject::UnLoad()
{
	//Destroy tile
	for (int y = 0; y < TilesMap.Num(); y++)
	{
		for (int x = 0; x < TilesMap[y].Row.Num(); x++)
		{
			Tiles[y].Row[x]->Destroy();
		}
	}

	//Destroy objects
	for (int y = 0; y < ObjectsMap.Num(); y++)
	{
		for (int x = 0; x < ObjectsMap[y].Row.Num(); x++)
		{
			if (ObjectsMap[y].Row[x].Type != 0)
			{
				Objects[y].Row[x]->Destroy();
			}
		}
	}
	//Destroy MapObject
	Destroy();
}


// Called every frame
void AMapObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMapObject::SpawnTile(int x, int y, int tiletype, int layer)
{
	//Spawn Tiles with position based on x, y and layer
	FVector NewLocation = FVector(x*TileSizeX, 0 + (layer *10.0f), -y * TileSizeY);
	AMapTile* Newtile = GetWorld()->SpawnActor<AMapTile>(NewLocation, FRotator::ZeroRotator);
	Newtile->UpdateTexture(TileSet[tiletype].texture);
	Newtile->SetActorScale3D(FVector(-1.0f, 1.0f, 1.0f));
	Tiles[y].Row[x] = Newtile;
	Newtile->SetGameManComp(gameManComp);//Pass pointer to Game Managment component to tile
	//Attach tile to MapObject
	Newtile->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}


void AMapObject::SpawnObject(int x, int y, int tiletype, int layer)
{
	FVector NewLocation = FVector(x*TileSizeX, 10.0f + (layer *10.0f), -y * TileSizeY);
	AMapTile* Newtile = GetWorld()->SpawnActor<AMapTile>(NewLocation, FRotator::ZeroRotator);
	Newtile->UpdateTexture(ObjectTileSet[tiletype].texture);
	Newtile->SetActorScale3D(FVector(-1.0f, 1.0f, 1.0f));
	Newtile->SetGameManComp(gameManComp);
	Objects[y].Row[x] = Newtile;
	Newtile->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void AMapObject::Interact(int X, int Y, EDirection Dir)
{
	if (!gameManComp->GetDialogueSystem()->BoxDisplayed())
	{
		if (NPCs[X][Y] != -1)
		{
			ANPCPawn* NPC = gameManComp->GetNPC(NPCs[X][Y]);
			DialogueObject DObj = NPC->GetDialogueObject(NPC->GetDialogueOnPress());
			gameManComp->GetDialogueSystem()->AddDialogueObject(DObj);
			switch (Dir)
			{
			case Right:
				NPC->SetDirection(Left);
				break;
			case Down:
				NPC->SetDirection(Up);
				break;
			case Left:
				NPC->SetDirection(Right);
				break;
			case Up:
				NPC->SetDirection(Down);
				break;
			}
		}
		else if (InteractableObjects[X][Y] != -1)
		{
			IObject* IObj = gameManComp->GetIObject(InteractableObjects[X][Y]);
			DialogueObject DObj = IObj->GetDialogueObject(IObj->GetDialogueOnPress());
			gameManComp->GetDialogueSystem()->AddDialogueObject(DObj);
		}
	}	
}

void AMapObject::SetGameManComp(class UGameManagment* GameManCompPtr)
{
	gameManComp = GameManCompPtr;
}

int AMapObject::GetRowNum(int Y)
{
	return Tiles[Y].Row.Num();
}

int AMapObject::GetObjRowNum(int Y)
{
	return Objects[Y].Row.Num();
}

int AMapObject::GetTilesNum()
{
	return Tiles.Num();
}

int AMapObject::GetObjsNum()
{
	return Objects.Num();
}

bool AMapObject::GetTileBlocked(int Y, int X)
{
	return Tiles[Y].Row[X]->GetBlocked();
}

bool AMapObject::GetObjectBlocked(int Y, int X)
{
	return Objects[Y].Row[X]->GetBlocked();
}

bool AMapObject::TileExists(int Y, int X)
{
	return Tiles[Y].Row[X];
}

bool AMapObject::ObjExists(int Y, int X)
{
	return Objects[Y].Row[X];
}

int AMapObject::GetNPCs(int X, int Y)
{
	return NPCs[X][Y];
}

void AMapObject::OnTileEntered(int Y, int X)
{
	Tiles[Y].Row[X]->OnTileEntered();
}

void AMapObject::SetMapHeight(int NewHeight)
{
	MapHeight = NewHeight;
}

void AMapObject::SetMapWidth(int NewWidth)
{
	MapWidth = NewWidth;
}

int AMapObject::GetMapHeight()
{
	return MapHeight;
}

int AMapObject::GetMapWidth()
{
	return MapWidth;
}

void AMapObject::SetTileSizeX(int NewX)
{
	TileSizeX = NewX;
}

void AMapObject::SetTileSizeY(int NewY)
{
	TileSizeY = NewY;
}

int AMapObject::GetTileSizeX()
{
	return TileSizeX;
}

int AMapObject::GetTileSizeY()
{
	return TileSizeY;
}



