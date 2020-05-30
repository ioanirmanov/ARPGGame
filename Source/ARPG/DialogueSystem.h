// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DialogueObject.h"
#include "DialogueSystem.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARPG_API UDialogueSystem : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDialogueSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AddDialogueObject(class DialogueObject NewObject);
	void OnButtonPress();
	UPROPERTY(EditAnywhere, Category = "Dialogue Boxes")
	TSubclassOf<class ATitledDialogueBox> TitleBox;
	void MoveBoxToCam(float CamX, float CamY, float OrthoWidth, float AspRatio);

	bool BoxDisplayed();

	void SetGameManComp(class UGameManagment* GameManCompPtr);
private:
	TArray<DialogueObject> DialogueQueue;

	class ADialogueBox* DialogueBoxPtr;

	void DisplayTitledBox();
	void AddLine(FString Line);
	void ChangeTitle(FString NewTitle);
	void UpdateDialogue();
	void ChangeText(FString NewText);
	void NewPage();
	
	bool MoveToNextObj = true;

	int CurrentDialogueIndex = -1;

	class UGameManagment* GameManComp;
};
