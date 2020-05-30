// Fill out your copyright notice in the Description page of Project Settings.

#include "GridLIne.h"
#include "PaperSpriteComponent.h"


// Sets default values
AGridLine::AGridLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TileBase"));
	}

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("TileSprite"));
	Sprite->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AGridLine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

