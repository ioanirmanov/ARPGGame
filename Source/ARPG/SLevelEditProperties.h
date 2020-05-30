// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"

/**
 * 
 */
class ARPG_API SLevelEditProperties : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLevelEditProperties) : _OwnerHUD() {} // the OwnerHUD var is passed to the widget so the owner can be set.

	SLATE_ARGUMENT(TWeakObjectPtr<class ALevelEditHUD>, OwnerHUD)
	SLATE_END_ARGS()

   TWeakObjectPtr<class ALevelEditHUD> OwnerHUD;

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
};
