// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "MapTile.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapTile() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_AMapTile_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_AMapTile();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	ARPG_API UClass* Z_Construct_UClass_UDynamicSprite_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_UGameManagment_NoRegister();
// End Cross Module References
	void AMapTile::StaticRegisterNativesAMapTile()
	{
	}
	UClass* Z_Construct_UClass_AMapTile_NoRegister()
	{
		return AMapTile::StaticClass();
	}
	UClass* Z_Construct_UClass_AMapTile()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "MapTile.h" },
				{ "ModuleRelativePath", "MapTile.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TriggerCommand_MetaData[] = {
				{ "Category", "Tile Properties" },
				{ "ModuleRelativePath", "MapTile.h" },
				{ "ToolTip", "Command that runs when tile triggered" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_TriggerCommand = { UE4CodeGen_Private::EPropertyClass::Str, "TriggerCommand", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AMapTile, TriggerCommand), METADATA_PARAMS(NewProp_TriggerCommand_MetaData, ARRAY_COUNT(NewProp_TriggerCommand_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsTrigger_MetaData[] = {
				{ "Category", "Tile Properties" },
				{ "ModuleRelativePath", "MapTile.h" },
			};
#endif
			auto NewProp_IsTrigger_SetBit = [](void* Obj){ ((AMapTile*)Obj)->IsTrigger = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsTrigger = { UE4CodeGen_Private::EPropertyClass::Bool, "IsTrigger", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AMapTile), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_IsTrigger_SetBit)>::SetBit, METADATA_PARAMS(NewProp_IsTrigger_MetaData, ARRAY_COUNT(NewProp_IsTrigger_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsBlocked_MetaData[] = {
				{ "Category", "Tile Properties" },
				{ "ModuleRelativePath", "MapTile.h" },
			};
#endif
			auto NewProp_IsBlocked_SetBit = [](void* Obj){ ((AMapTile*)Obj)->IsBlocked = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsBlocked = { UE4CodeGen_Private::EPropertyClass::Bool, "IsBlocked", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AMapTile), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_IsBlocked_SetBit)>::SetBit, METADATA_PARAMS(NewProp_IsBlocked_MetaData, ARRAY_COUNT(NewProp_IsBlocked_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DynamicSprite_MetaData[] = {
				{ "Category", "Tile Properties" },
				{ "ModuleRelativePath", "MapTile.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DynamicSprite = { UE4CodeGen_Private::EPropertyClass::Object, "DynamicSprite", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AMapTile, DynamicSprite), Z_Construct_UClass_UDynamicSprite_NoRegister, METADATA_PARAMS(NewProp_DynamicSprite_MetaData, ARRAY_COUNT(NewProp_DynamicSprite_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sprite_MetaData[] = {
				{ "Category", "Tile Properties" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "MapTile.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sprite = { UE4CodeGen_Private::EPropertyClass::Object, "Sprite", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000080009, 1, nullptr, STRUCT_OFFSET(AMapTile, Sprite), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_Sprite_MetaData, ARRAY_COUNT(NewProp_Sprite_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_gameManComp_MetaData[] = {
				{ "Category", "Tile Properties" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "MapTile.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_gameManComp = { UE4CodeGen_Private::EPropertyClass::Object, "gameManComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000080009, 1, nullptr, STRUCT_OFFSET(AMapTile, gameManComp), Z_Construct_UClass_UGameManagment_NoRegister, METADATA_PARAMS(NewProp_gameManComp_MetaData, ARRAY_COUNT(NewProp_gameManComp_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TriggerCommand,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_IsTrigger,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_IsBlocked,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DynamicSprite,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Sprite,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_gameManComp,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AMapTile>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AMapTile::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMapTile, 2212109846);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMapTile(Z_Construct_UClass_AMapTile, &AMapTile::StaticClass, TEXT("/Script/ARPG"), TEXT("AMapTile"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMapTile);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
