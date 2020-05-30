// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"
#include "ARPG.h"
#include "PaperSpriteComponent.h"
#include "Classes/GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MapObject.h"
#include "MapTile.h"
#include "GameManagment.h"
#include "DialogueSystem.h"



// Sets default values
APlayerPawn::APlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Set up things
	
	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CharRoot"));
	}

	//Set up camera

	Cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Cam->bUsePawnControlRotation = false;
	Cam->ProjectionMode = ECameraProjectionMode::Orthographic;
	Cam->OrthoWidth = 230.0f;
	Cam->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Cam->SetWorldRotation(FRotator(0.0f, 0.0f, -90.0f));

	
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());

	CamPosX = (int)(MapX*TileSizeX + OffsetX);
	CamPosY = (int)(-MapY * TileSizeY - OffsetY);
	float CamHeight = Cam->OrthoWidth / (ViewportSize.X / ViewportSize.Y);
	//If cam outsidemap stop
	if (Cam->OrthoWidth > MapWidth * TileSizeX)
	{
		CamPosX = (MapWidth * TileSizeX) / 2 - (TileSizeX / 2);
		//UE_LOG(LogTemp, Warning, TEXT("OutSide X Both Sides"));
		
	}
	else if (CamPosX - (Cam->OrthoWidth / 2) < -(TileSizeX/2))
	{
		CamPosX = Cam->OrthoWidth / 2 - (TileSizeX / 2);
	}
	else if (CamPosX + (Cam->OrthoWidth / 2) > (MapWidth * TileSizeX) - (TileSizeX / 2))
	{
		CamPosX = (MapWidth * TileSizeX) - (TileSizeX / 2) - (Cam->OrthoWidth / 2);
	}

	if (CamHeight > MapHeight * TileSizeY)
	{
		CamPosY = -(MapHeight * TileSizeY) / 2 + (TileSizeY/2);
	}
	else if (CamPosY + (CamHeight / 2) > TileSizeY)
	{
		CamPosY = -CamHeight / 2 + TileSizeY;
	}
	else if (CamPosY - (CamHeight / 2) < -(MapHeight * TileSizeY) + (TileSizeY / 2))
	{
		CamPosY = -(MapHeight * TileSizeY) + (TileSizeY / 2) + ((CamHeight / 2));
	}

	Cam->SetWorldLocation(FVector(CamPosX, 50, CamPosY));
	if (GameManComp)
	{
		if (GameManComp->GetDialogueSystem())
		{
			GameManComp->GetDialogueSystem()->MoveBoxToCam(CamPosX, CamPosY, Cam->OrthoWidth, Cam->AspectRatio);
		}
	}
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveX", this, &APlayerPawn::PlayerMoveX);
	InputComponent->BindAxis("MoveY", this, &APlayerPawn::PlayerMoveY);
	InputComponent->BindAction("Click", IE_Pressed ,this, &APlayerPawn::HandlePress);
}


void APlayerPawn::HandlePress()
{
	if (GameManComp)
	{
		if (GameManComp->GetDialogueSystem())
		{
			GameManComp->GetDialogueSystem()->OnButtonPress();
		}
		
		switch (GetDirection())
		{
		case Right:
			if (MapX < GameManComp->GetMap()->GetMapWidth() - 1)
			{
				GameManComp->GetMap()->Interact(MapX + 1, MapY, Right);
			}
			break;
		case Down:
			if (MapY < GameManComp->GetMap()->GetMapHeight() - 1)
			{
				GameManComp->GetMap()->Interact(MapX, MapY + 1, Down);
			}
			break;
		case Left:
			if (MapX > 0)
			{
				GameManComp->GetMap()->Interact(MapX - 1, MapY, Left);
			}
			break;
		case Up:
			if (MapY > 0)
			{
				GameManComp->GetMap()->Interact(MapX, MapY - 1, Up);
			}
			break;	
		}
	}
}

void APlayerPawn::FreezePlayer()
{
	Freeze = true;
}

void APlayerPawn::UnFreezePlayer()
{
	Freeze = false;
}

void APlayerPawn::PlayerMoveX(float axisValue)
{
	if (!Freeze)
	{
		this->MoveX(axisValue);
	}
}

void APlayerPawn::PlayerMoveY(float axisValue)
{
	if (!Freeze)
	{
		this->MoveY(axisValue);
	}
}
