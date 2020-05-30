// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManagment.h"
#include "PlayerPawn.h"
#include "MapObject.h"
#include "DialogueSystem.h"
#include "Classes/GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UGameManagment::UGameManagment()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGameManagment::BeginPlay()
{
	Super::BeginPlay();

	EventSys = EventSystem();
	EventSys.SetUp();
	EventSys.SetGameManComp(this);

	//if player pointer is empty
	if (!Player)
	{
		//Get player pawn (spawned as default pawn of gamemode), and point player pointer to it
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		APawn* pawn = PlayerController->GetPawn();
		Player = (APlayerPawn*)pawn;
		Player->SetGameManComp(this);
	}
	//If map pointer empty
	//If map pointer empty
	if (!Map)
	{
		//Spawn defaultmap and set Map pointer to it
		Map = GetWorld()->SpawnActor<AMapObject>(DefaultMap, FVector::ZeroVector, FRotator::ZeroRotator);
		Map->SetGameManComp(this);//passes a pointer to the Game Managment component (this) to the map
		Map->Generate();
		Player->SetMap(Map);//Lets player pawn known about the map
		Player->SetTileSizeX(Map->GetTileSizeX());
		Player->SetTileSizeY(Map->GetTileSizeY());
		Player->SetMapHeight(Map->GetMapHeight());
		Player->SetMapWidth(Map->GetMapWidth());
	}

	if (DialogueSystem)
	{
		DialogueSystem->SetGameManComp(this);
	}

	UE_LOG(LogTemp, Warning, TEXT("Num Of Maps %i"), Maps.Num());
	
	/*
	if (TestNPC)
	{
		ANPCPawn* SpawnNPC = GetWorld()->SpawnActor<ANPCPawn>(TestNPC, FVector::ZeroVector, FRotator::ZeroRotator);
		SpawnNPC->MapX = 1;
		SpawnNPC->MapY = 1;
		SpawnNPC->TileSizeX = Map->TileSizeX;
		SpawnNPC->TileSizeY = Map->TileSizeY;
		SpawnNPC->MapHeight = Map->MapHeight;
		SpawnNPC->MapWidth = Map->MapWidth;
		AddNPC(SpawnNPC);
		Map->NPCs[1][1] = 0;
		
	}
	*/
	// ...
	
}


// Called every frame
void UGameManagment::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGameManagment::TriggerEvent(FString Command)
{
	EventSys.TriggerEvent(Command);
}

void UGameManagment::LoadMap(TSubclassOf<AMapObject> MapSpawn, int startx, int starty)
{
	AMapObject* OldMap = Map;//Pointer to current map
	Map = GetWorld()->SpawnActor<AMapObject>(MapSpawn, FVector::ZeroVector, FRotator::ZeroRotator);//Spawn new map
	//Set up player variables
	Player->SetMap(Map);
	Player->SetMapX(startx);
	Player->SetMapY(starty);
	Player->SetOffsetX(0);
	Player->SetOffsetY(0);
	OldMap->UnLoad();//Unload the old map
	ClearNPCs();
	ClearIObjects();
	Map->SetGameManComp(this);
	Map->Generate();
}
void UGameManagment::LoadMap(FString MapName, int startx, int starty)
{
	TSubclassOf<AMapObject> MapSpawn;
	if (Maps.Contains(MapName)) MapSpawn = *Maps.Find(MapName);
	else return;
	LoadMap(MapSpawn, startx, starty);
}

ANPCPawn* UGameManagment::GetNPC(int Index)
{
	if (Index < NPCs.Num())
		return NPCs[Index];
	else
	{
		return NPCs[NPCs.Num() - 1];
	}
}

void UGameManagment::AddNPC(ANPCPawn* NPC)
{
	NPCs.Add(NPC);
}

void UGameManagment::RemoveNPC(int Index)
{
	NPCs.RemoveAt(Index);
}

void UGameManagment::ClearNPCs()
{
	for (int i = 0; i < NPCs.Num(); i++)
	{
		NPCs[i]->Destroy();
	}
	NPCs.Empty();
}

IObject* UGameManagment::GetIObject(int Index)
{
	if (Index < IObjects.size())
		return &IObjects[Index];
	else
	{
		return &IObjects[IObjects.size() - 1];
	}
}

void UGameManagment::AddIObject(IObject Obj)
{
	IObjects.push_back(Obj);
}

void UGameManagment::RemoveIObject(int Index)
{
	IObjects.erase(IObjects.begin()+Index);
}

void UGameManagment::ClearIObjects()
{
	IObjects.clear();
}

void UGameManagment::SetDialogueSystem(class UDialogueSystem* DiagPtr)
{
	DialogueSystem = DiagPtr;
}

class UDialogueSystem* UGameManagment::GetDialogueSystem()
{
	return DialogueSystem;
}

void UGameManagment::SetPlayerPawn(class APlayerPawn* PlayerPtr)
{
	Player = PlayerPtr;
}

class APlayerPawn* UGameManagment::GetPlayerPawn()
{
	return Player;
}

void UGameManagment::SetMap(class AMapObject* MapPtr)
{
	Map = MapPtr;
}

class AMapObject* UGameManagment::GetMap()
{
	return Map;
}



