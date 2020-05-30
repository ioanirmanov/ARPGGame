// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelEditPawn.h"
#include "Classes/GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MapEditor.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Engine.h"



// Sets default values
ALevelEditPawn::ALevelEditPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TileBase"));
	}


	//Set up camera
	class USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->TargetArmLength = 50.0f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->bEnableCameraRotationLag = false;
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->CameraLagSpeed = 10.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SpringArm->SetWorldRotation(FRotator(0.0f, -90.0f, 0.0f));

	Cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Cam->bUsePawnControlRotation = false;
	Cam->ProjectionMode = ECameraProjectionMode::Orthographic;
	Cam->OrthoWidth = 230.0f;
	Cam->AttachToComponent(SpringArm, FAttachmentTransformRules::KeepRelativeTransform, USpringArmComponent::SocketName);
	Cam->SetWorldRotation(FRotator(0.0f, -90.0f, 0.0f));

}

// Called when the game starts or when spawned
void ALevelEditPawn::BeginPlay()
{
	//this->SetActorLocation(FVector(0, 15, 0));
}

// Called every frame
void ALevelEditPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//this->SetActorLocation(FVector(0, 15, 0));
}

// Called to bind functionality to input
void ALevelEditPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Click",IE_Pressed, this, &ALevelEditPawn::HandleClick);
	PlayerInputComponent->BindAction("Click", IE_Released, this, &ALevelEditPawn::HandleClickReleased);
	PlayerInputComponent->BindKey(EKeys::MiddleMouseButton, IE_Pressed, this, &ALevelEditPawn::HandleScrollWheelClick);
	PlayerInputComponent->BindKey(EKeys::MiddleMouseButton, IE_Released, this, &ALevelEditPawn::HandleScrollWheelReleased);
	PlayerInputComponent->BindKey(EKeys::MouseScrollUp, IE_Pressed, this, &ALevelEditPawn::HandleScrollWheelUp);
	PlayerInputComponent->BindKey(EKeys::MouseScrollDown, IE_Pressed, this, &ALevelEditPawn::HandleScrollWheelDown);
}

void ALevelEditPawn::HandleClick()
{
	mapEditor->OnClick();
}
void ALevelEditPawn::HandleClickReleased()
{
	mapEditor->OnClickReleased();
}
void ALevelEditPawn::HandleScrollWheelClick()
{
	mapEditor->OnScrollWheelClick();
}
void ALevelEditPawn::HandleScrollWheelReleased()
{
	mapEditor->OnScrollWheelReleased();
}
void ALevelEditPawn::HandleScrollWheelUp()
{
	Cam->SetOrthoWidth(Cam->OrthoWidth / 1.1f);
}
void ALevelEditPawn::HandleScrollWheelDown()
{
	Cam->SetOrthoWidth(Cam->OrthoWidth * 1.1f);
}
