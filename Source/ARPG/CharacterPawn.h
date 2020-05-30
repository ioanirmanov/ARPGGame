// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CharacterPawn.generated.h"

enum EDirection
{
	Right,
	Down,
	Left,
	Up
};

UCLASS()
class ARPG_API ACharacterPawn : public APawn
{
	GENERATED_BODY()

public:	

	// Sets default values for this pawn's properties
	ACharacterPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetGameManComp(class UGameManagment* GameManCompPtr);
	
	//Pointer to map
	void SetMap(class AMapObject* MapPtr);

	void SetMapX(int NewX);
	void SetMapY(int NewY);
	int GetMapX();
	int GetMapY();

	void SetTileSizeX(int NewX);
	void SetTileSizeY(int NewY);
	int GetTileSizeX();
	int GetTileSizeY();

	void SetMapHeight(int NewHeight);
	void SetMapWidth(int NewWidth);
	int GetMapHeight();
	int GetMapWidth();

	void SetOffsetX(int NewX);
	void SetOffsetY(int NewY);
	int GetOffsetX();
	int GetOffsetY();

	void SetMoveSpeed(float NewSpeed);
	float GetMoveSpeed();

	//Function that handle input
	void MoveX(float axisValue);
	void MoveY(float axisValue);

	//Function to check is a certain tile is blocked
	bool CheckBlocked(int X, int Y);

	FString GetCharacterName();

	EDirection GetDirection();
	void SetDirection(EDirection Dir);
	void SetClipAdjust();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UGameManagment* GameManComp;

	UPROPERTY(EditAnywhere, Category = "Player Properties")
		class AMapObject* Map;

	//Position on map, in terms of tiles
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		int MapX = 0;
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		int MapY = 0;

	//Offset from map position
	float OffsetX;
	float OffsetY;

	int TileSizeX = 16;
	int TileSizeY = 16;

	int MapHeight = 10;
	int MapWidth = 10;

	UPROPERTY(EditAnywhere, Category = "Player Properties")
		float MoveSpeed = 1.0f;

	//Current displayed sprite
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		class UPaperSpriteComponent* Sprite;
	//Camera
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		class UCameraComponent* Cam;

	//Arrays of sprites for walk cycle
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		TArray<class UPaperSprite*> WalkRightSprites;
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		TArray<class UPaperSprite*> WalkLeftSprites;
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		TArray<class UPaperSprite*> WalkUpSprites;
	UPROPERTY(EditAnywhere, Category = "Player Properties")
		TArray<class UPaperSprite*> WalkDownSprites;

	EDirection Direction = Right; 
	bool MovingX;
	
	FString CharName;

	float ClipAdjust;
};
