// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPCPawn.h"
#include "DialogueObject.h"
#include "IObject.h"
#include "EventSystem.h"
#include "Components/SceneComponent.h"
#include "GameManagment.generated.h"



/*
USTRUCT()
struct Map
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TSubclassOf<AMapTile> Map;

};
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARPG_API UGameManagment : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameManagment();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//TODO: Make these private, use proper encapsulation
	UFUNCTION(BlueprintCallable, Category = "Set Up")
	void SetDialogueSystem(class UDialogueSystem* DiagPtr);
	class UDialogueSystem* GetDialogueSystem();
	
	//Pointer to player	
	void SetPlayerPawn(class APlayerPawn* PlayerPtr);
	class APlayerPawn* GetPlayerPawn();
	
	//Pointer to current map
	void SetMap(class AMapObject* MapPtr);
	class AMapObject* GetMap();
	
	//Function for events system
	void TriggerEvent(FString Command);

	//Function to load map
	void LoadMap(TSubclassOf<AMapObject> MapSpawn, int startx, int starty);
	void LoadMap(FString MapName, int startx, int starty);

	ANPCPawn* GetNPC(int Index);
	void AddNPC(ANPCPawn* NPC);
	void RemoveNPC(int Index);
	void ClearNPCs();

	IObject* GetIObject(int Index);
	void AddIObject(IObject Obj);
	void RemoveIObject(int Index);
	void ClearIObjects();
	

	//TArray<TSubclassOf<AMapObject>> MapsCopy;
private:
	TArray<class ANPCPawn*> NPCs;
	std::vector<IObject> IObjects;
	
	UPROPERTY()
	class UDialogueSystem* DialogueSystem;
    class APlayerPawn* Player;
	class AMapObject* Map;
	
	EventSystem EventSys;

	//Stores which map is the default map
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		TSubclassOf<AMapObject> DefaultMap;

	//Stores other maps that will b used
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		TMap<FString,TSubclassOf<AMapObject>> Maps;
};
