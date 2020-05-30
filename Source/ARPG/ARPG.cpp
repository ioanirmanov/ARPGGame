// Fill out your copyright notice in the Description page of Project Settings.

#include "ARPG.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, ARPG, "ARPG" );
DEFINE_LOG_CATEGORY(MyGameEditor)

void FARPG::StartupModule()
{
	FDefaultGameModuleImpl::StartupModule();


}

void FARPG::ShutdownModule()
{
	FDefaultGameModuleImpl::ShutdownModule();

}

