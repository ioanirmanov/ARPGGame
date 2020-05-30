// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterPawn.h"
#include "ARPG.h"
#include "PaperSpriteComponent.h"
#include "Classes/GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MapObject.h"
#include "MapTile.h"
#include "GameManagment.h"
#include "DialogueSystem.h"

// Sets default values
ACharacterPawn::ACharacterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CharRoot"));
	}

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("TileSprite"));
	Sprite->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void ACharacterPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetClipAdjust();
	this->SetActorLocation(FVector((int)(MapX*TileSizeX + OffsetX), 15 + ClipAdjust, (int)(-MapY * TileSizeY - OffsetY)));
}

// Called to bind functionality to input
void ACharacterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterPawn::MoveX(float axisValue)
{
	if (axisValue > 0 && !FMath::IsNearlyZero(axisValue))//if pressing right
	{
		Direction = Right;
		bool NotBlocked = true;


		if (MapX < Map->GetRowNum(MapY) - 1)//if not on right most tile of row
		{

		}
		else
		{
			//if on last tile then block way
			NotBlocked = false;
		}

		//Check if tile to the right if blocked
		if (CheckBlocked(MapX + 1, MapY)) NotBlocked = false;
		if (OffsetY >= 0)//if sprite overlaps onto the tile below
		{
			if (CheckBlocked(MapX + 1, MapY + 1)) NotBlocked = false;
		}
		if (OffsetY < -(6.0f*(TileSizeY / 16)))//if sprite overlaps onto the tile above, -6 so allow some overlap
		{
			if (CheckBlocked(MapX + 1, MapY - 1)) NotBlocked = false;
		}
		//UE_LOG(LogTemp, Warning, TEXT("MapX: %i"), MapX);
		//UE_LOG(LogTemp, Warning, TEXT("OffsetX: %f"), OffsetX);
		//UE_LOG(LogTemp, Warning, TEXT("Objects Row: %i"), Map->Objects[MapY].Row.Num());

		//if way is not blocked or is blocked but player is left of the current tile's centre
		if (NotBlocked || (NotBlocked == false && OffsetX < 0))
		{
			MovingX = true;
			OffsetX += MoveSpeed;

			if (OffsetX >= TileSizeX / 2)//if going on to next tile (8 as tiles are 16*16)			
			{
				MapX += 1;
				OffsetX = -(TileSizeX / 2);
				Map->OnTileEntered(MapY, MapX);//Run Tiles OnTileEntered Function				
			}
			if (OffsetX < 0)//if on left side of tile				
			{
				//Set which frame of the walk cycle to be on, if the number of frames in the walk cycle
				//is a factor * MoveSpeed is a factor of the tile width than should produce even timing of frames
				Sprite->SetSprite(WalkRightSprites[FMath::FloorToInt(((OffsetX + TileSizeX) / TileSizeX)*(WalkDownSprites.Num()))]);
				UE_LOG(LogTemp, Warning, TEXT("Sprite %i"), FMath::FloorToInt(((OffsetX + TileSizeX) / TileSizeX)*(WalkDownSprites.Num())));
			}
			else//if centre of right side of tile				
			{
				Sprite->SetSprite(WalkRightSprites[FMath::FloorToInt((FMath::Abs(OffsetX) / TileSizeX)*(WalkDownSprites.Num()))]);
			}

		}
		else
		{
			//if not moving set to first sprite in walk cycle
			Sprite->SetSprite(WalkRightSprites[0]);
		}
	}
	else if (axisValue < 0 && !FMath::IsNearlyZero(axisValue))
	{
		Direction = Left;

		bool NotBlocked = true;

		if (MapX > 0)
		{

		}
		else
		{
			NotBlocked = false;
		}
		if (CheckBlocked(MapX - 1, MapY)) NotBlocked = false;
		if (OffsetY >= 0)
		{
			if (CheckBlocked(MapX - 1, MapY + 1)) NotBlocked = false;
		}
		if (OffsetY < -(6.0f*(TileSizeY / 16)))
		{
			if (CheckBlocked(MapX - 1, MapY - 1)) NotBlocked = false;
		}

		if (NotBlocked || (NotBlocked == false && OffsetX > 0))
		{
			MovingX = true;
			OffsetX -= MoveSpeed;
			//Check If Blocked Underneath


			if (OffsetX <= -(TileSizeX / 2))
			{
				MapX -= 1;
				OffsetX = TileSizeX / 2;
				Map->OnTileEntered(MapY, MapX);
			}

			if (OffsetX < 0)
			{
				Sprite->SetSprite(WalkLeftSprites[FMath::FloorToInt(((OffsetX + TileSizeX) / TileSizeX)*(WalkDownSprites.Num()))]);
				UE_LOG(LogTemp, Warning, TEXT("Sprite %i"), FMath::FloorToInt(((OffsetX + TileSizeX) / TileSizeX)*(WalkDownSprites.Num())));
			}
			else
			{
				Sprite->SetSprite(WalkLeftSprites[FMath::FloorToInt((FMath::Abs(OffsetX) / TileSizeX)*(WalkDownSprites.Num()))]);
			}

		}
		else
		{
			Sprite->SetSprite(WalkLeftSprites[0]);
		}


	}
	else
	{
		MovingX = false;
	}
}

void ACharacterPawn::MoveY(float axisValue)
{

	if (MovingX == false)//if not moving sideways
	{
		if (axisValue > 0 && !FMath::IsNearlyZero(axisValue))
		{
			Direction = Up;
			
			bool NotBlocked = true;
			if (MapY > 0)
			{

			}
			else
			{
				NotBlocked = false;
			}

			if (CheckBlocked(MapX, MapY - 1)) NotBlocked = false;
			if (OffsetX > (2.0f*(TileSizeY / 16)))//2 and -2 to allows some leeway for player
			{
				if (CheckBlocked(MapX + 1, MapY - 1)) NotBlocked = false;
			}
			if (OffsetX < -(2.0f*(TileSizeY / 16)))
			{
				if (CheckBlocked(MapX - 1, MapY - 1)) NotBlocked = false;
			}
			UE_LOG(LogTemp, Warning, TEXT("OffsetY %f"), OffsetY);
			UE_LOG(LogTemp, Warning, TEXT("MapY %i"), MapY);
			UE_LOG(LogTemp, Warning, TEXT("MapX %i"), MapX);
			if (NotBlocked == false)
			{
				UE_LOG(LogTemp, Warning, TEXT("Blocked"));
			}
			if (NotBlocked || (NotBlocked == false && OffsetY > -(6.0f*(TileSizeY / 16))))
			{
				OffsetY -= MoveSpeed;
				if (OffsetY <= -(TileSizeY / 2))
				{
					MapY -= 1;
					OffsetY = TileSizeY / 2;
					Map->OnTileEntered(MapY, MapX);
				}
				//UE_LOG(LogTemp, Warning, TEXT("Sprite Index: %i"), FMath::FloorToInt((FMath::Abs(OffsetY) / 16)*(WalkUpSprites.Num())));
				if (OffsetY < 0)
				{
					Sprite->SetSprite(WalkUpSprites[FMath::FloorToInt(((OffsetY + TileSizeY) / TileSizeY)*(WalkDownSprites.Num()))]);
					UE_LOG(LogTemp, Warning, TEXT("Sprite %i"), FMath::FloorToInt(((OffsetY + TileSizeY) / TileSizeY)*(WalkDownSprites.Num())));
				}
				else
				{
					Sprite->SetSprite(WalkUpSprites[FMath::FloorToInt((FMath::Abs(OffsetY) / TileSizeY)*(WalkDownSprites.Num()))]);
				}

			}
			else
			{
				Sprite->SetSprite(WalkUpSprites[0]);
			}

		}
		else if (axisValue < 0 && !FMath::IsNearlyZero(axisValue))
		{
			Direction = Down;

			bool NotBlocked = true;

			if (MapY < Map->GetTilesNum() - 1)
			{

			}
			else
			{
				NotBlocked = false;
			}

			if (CheckBlocked(MapX, MapY + 1)) NotBlocked = false;
			if (OffsetX >(2.0f*(TileSizeY / 16)))
			{
				if (CheckBlocked(MapX + 1, MapY + 1)) NotBlocked = false;
			}
			if (OffsetX < -(2.0f*(TileSizeY / 16)))
			{
				if (CheckBlocked(MapX - 1, MapY + 1)) NotBlocked = false;
			}
			if (NotBlocked || (NotBlocked == false && OffsetY < -2))
			{

				OffsetY += MoveSpeed;
				if (OffsetY > TileSizeY / 2)
				{
					MapY += 1;
					OffsetY = -(TileSizeY / 2);
					Map->OnTileEntered(MapY, MapX);
				}
			}
			if (OffsetY < 0)
			{
				Sprite->SetSprite(WalkDownSprites[FMath::FloorToInt(((OffsetY + TileSizeY) / TileSizeY)*(WalkDownSprites.Num()))]);
				UE_LOG(LogTemp, Warning, TEXT("Sprite %i"), FMath::FloorToInt(((OffsetY + TileSizeY) / TileSizeY)*(WalkDownSprites.Num())));
			}
			else
			{
				Sprite->SetSprite(WalkDownSprites[FMath::FloorToInt((FMath::Abs(OffsetY) / TileSizeY)*(WalkDownSprites.Num()))]);
			}
		}
	}
}

bool ACharacterPawn::CheckBlocked(int X, int Y)
{
	bool TileBlocked = false;
	if (Y >= 0 && Y < Map->GetTilesNum())//check is Y is in map
	{
		if (X >= 0 && X < Map->GetRowNum(Y))//check is X is in Row Y
		{
			if (Map->TileExists(Y,X))//if pointer to tile is not empty
			{
				UE_LOG(LogTemp, Warning, TEXT("TilesAccessed"));
				TileBlocked = Map->GetTileBlocked(Y,X);
				if (GameManComp->GetMap()->GetNPCs(X,Y) != -1)
					TileBlocked = true;

			}
		}
	}
	//Check objects as well
	bool ObjectBlocked = false;
	if (Y >= 0 && Y < Map->GetObjsNum())
	{
		if (X >= 0 && X < Map->GetObjRowNum(Y))
		{
			if (Map->ObjExists(Y, X))
			{
				UE_LOG(LogTemp, Warning, TEXT("ObjectAccessed"));
				ObjectBlocked = Map->GetObjectBlocked(Y,X);
			}
		}
	}

	return TileBlocked || ObjectBlocked;
}

FString ACharacterPawn::GetCharacterName()
{
	return CharName;
}

EDirection ACharacterPawn::GetDirection()
{
	return Direction;
}

void ACharacterPawn::SetDirection(EDirection Dir)
{
	Direction = Dir;
	switch (Direction)
	{
	case Right:
		Sprite->SetSprite(WalkRightSprites[0]);
		break;
	case Down:
		Sprite->SetSprite(WalkDownSprites[0]);
		break;
	case Left:
		Sprite->SetSprite(WalkLeftSprites[0]);
		break;
	case Up:
		Sprite->SetSprite(WalkUpSprites[0]);
		break;
	}
	
}

void ACharacterPawn::SetClipAdjust()
{
	ClipAdjust = (((MapHeight * TileSizeY / 2) - ((MapY * TileSizeY) + OffsetY)) / (MapHeight * TileSizeY)) * -9.0f;
}

void ACharacterPawn::SetGameManComp(class UGameManagment* GameManCompPtr)
{
	GameManComp = GameManCompPtr;
}

void ACharacterPawn::SetMap(class AMapObject* MapPtr)
{
	Map = MapPtr;
}

void ACharacterPawn::SetMapX(int NewX)
{
	MapX = NewX;
}

void ACharacterPawn::SetMapY(int NewY)
{
	MapY = NewY;
}

int ACharacterPawn::GetMapX()
{
	return MapX;
}

int ACharacterPawn::GetMapY()
{
	return MapY;
}

void ACharacterPawn::SetOffsetX(int NewX)
{
	OffsetX = NewX;
}

void ACharacterPawn::SetOffsetY(int NewY)
{
	OffsetY = NewY;
}

int ACharacterPawn::GetOffsetX()
{
	return OffsetX;
}

int ACharacterPawn::GetOffsetY()
{
	return OffsetY;
}

void ACharacterPawn::SetMapHeight(int NewHeight)
{
	MapHeight = NewHeight;
}

void ACharacterPawn::SetMapWidth(int NewWidth)
{
	MapWidth = NewWidth;
}

int ACharacterPawn::GetMapHeight()
{
	return MapHeight;
}

int ACharacterPawn::GetMapWidth()
{
	return MapWidth;
}

void ACharacterPawn::SetTileSizeX(int NewX)
{
	TileSizeX = NewX;
}

void ACharacterPawn::SetTileSizeY(int NewY)
{
	TileSizeY = NewY;
}

int ACharacterPawn::GetTileSizeX()
{
	return TileSizeX;
}

int ACharacterPawn::GetTileSizeY()
{
	return TileSizeY;
}

void ACharacterPawn::SetMoveSpeed(float NewSpeed)
{
	MoveSpeed = NewSpeed;
}

float ACharacterPawn::GetMoveSpeed()
{
	return MoveSpeed;
}
