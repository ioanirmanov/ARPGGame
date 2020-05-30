// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "MapEditorTile.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapEditorTile() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_AMapEditorTile_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_AMapEditorTile();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	ARPG_API UClass* Z_Construct_UClass_UDynamicSprite_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
// End Cross Module References
	void AMapEditorTile::StaticRegisterNativesAMapEditorTile()
	{
	}
	UClass* Z_Construct_UClass_AMapEditorTile_NoRegister()
	{
		return AMapEditorTile::StaticClass();
	}
	UClass* Z_Construct_UClass_AMapEditorTile()
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
				{ "IncludePath", "MapEditorTile.h" },
				{ "ModuleRelativePath", "MapEditorTile.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TileType_MetaData[] = {
				{ "Category", "Tile Properties" },
				{ "ModuleRelativePath", "MapEditorTile.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_TileType = { UE4CodeGen_Private::EPropertyClass::Int, "TileType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AMapEditorTile, TileType), METADATA_PARAMS(NewProp_TileType_MetaData, ARRAY_COUNT(NewProp_TileType_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DynamicSprite_MetaData[] = {
				{ "Category", "Tile Properties" },
				{ "ModuleRelativePath", "MapEditorTile.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DynamicSprite = { UE4CodeGen_Private::EPropertyClass::Object, "DynamicSprite", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AMapEditorTile, DynamicSprite), Z_Construct_UClass_UDynamicSprite_NoRegister, METADATA_PARAMS(NewProp_DynamicSprite_MetaData, ARRAY_COUNT(NewProp_DynamicSprite_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sprite_MetaData[] = {
				{ "Category", "Tile Properties" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "MapEditorTile.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sprite = { UE4CodeGen_Private::EPropertyClass::Object, "Sprite", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080009, 1, nullptr, STRUCT_OFFSET(AMapEditorTile, Sprite), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_Sprite_MetaData, ARRAY_COUNT(NewProp_Sprite_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TileType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DynamicSprite,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Sprite,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AMapEditorTile>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AMapEditorTile::StaticClass,
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
	IMPLEMENT_CLASS(AMapEditorTile, 3408462664);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMapEditorTile(Z_Construct_UClass_AMapEditorTile, &AMapEditorTile::StaticClass, TEXT("/Script/ARPG"), TEXT("AMapEditorTile"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMapEditorTile);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
