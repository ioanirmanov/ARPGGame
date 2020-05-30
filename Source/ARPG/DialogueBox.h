// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DialogueBox.generated.h"

UCLASS()
class ARPG_API ADialogueBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADialogueBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddLine(FString Line);
	void ClearText();

	void MoveToCamPos(float CamX, float CamY, float OrthoWidth, float AspRatio);
	
private:
	UPROPERTY(EditAnywhere, Category = "Dialogue Box Properties")
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere, Category = "Dialogue Box Properties")
		class UTextRenderComponent* Text;

	UPROPERTY(EditAnywhere, Category = "Dialogue Box Properties")
		float BoxWidth = 100;
	UPROPERTY(EditAnywhere, Category = "Dialogue Box Properties")
		float BoxHeight = 100;

	UPROPERTY(EditAnywhere, Category = "Dialogue Box Properties")
	float DisplayHeight = 100;

	FString CurrentText = "";

	int UsedLines = 0;

	void UpdateText();

};
