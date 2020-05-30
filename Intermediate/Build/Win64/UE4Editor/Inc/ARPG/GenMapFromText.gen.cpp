// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "GenMapFromText.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGenMapFromText() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_UGenMapFromText_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_UGenMapFromText();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ARPG_API UClass* Z_Construct_UClass_ANPCPawn_NoRegister();
	ARPG_API UScriptStruct* Z_Construct_UScriptStruct_FnumRow();
	ARPG_API UScriptStruct* Z_Construct_UScriptStruct_FTileSetTile();
	ARPG_API UClass* Z_Construct_UClass_AMapTile_NoRegister();
// End Cross Module References
	void UGenMapFromText::StaticRegisterNativesUGenMapFromText()
	{
	}
	UClass* Z_Construct_UClass_UGenMapFromText_NoRegister()
	{
		return UGenMapFromText::StaticClass();
	}
	UClass* Z_Construct_UClass_UGenMapFromText()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "ClassGroupNames", "Custom" },
				{ "IncludePath", "GenMapFromText.h" },
				{ "ModuleRelativePath", "GenMapFromText.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapName_MetaData[] = {
				{ "Category", "MapNanme" },
				{ "ModuleRelativePath", "GenMapFromText.h" },
				{ "ToolTip", "TextAsset from which map will be generated" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapName = { UE4CodeGen_Private::EPropertyClass::Str, "MapName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(UGenMapFromText, MapName), METADATA_PARAMS(NewProp_MapName_MetaData, ARRAY_COUNT(NewProp_MapName_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NPCMap_MetaData[] = {
				{ "Category", "NPCs" },
				{ "ModuleRelativePath", "GenMapFromText.h" },
			};
#endif
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_NPCMap = { UE4CodeGen_Private::EPropertyClass::Map, "NPCMap", RF_Public|RF_Transient|RF_MarkAsNative, 0x0024080000000001, 1, nullptr, STRUCT_OFFSET(UGenMapFromText, NPCMap), METADATA_PARAMS(NewProp_NPCMap_MetaData, ARRAY_COUNT(NewProp_NPCMap_MetaData)) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_NPCMap_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "NPCMap_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000001, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_NPCMap_ValueProp = { UE4CodeGen_Private::EPropertyClass::Class, "NPCMap", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000001, 1, nullptr, 1, Z_Construct_UClass_ANPCPawn_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Objects_MetaData[] = {
				{ "Category", "Map Tiles" },
				{ "ModuleRelativePath", "GenMapFromText.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Objects = { UE4CodeGen_Private::EPropertyClass::Array, "Objects", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(UGenMapFromText, Objects), METADATA_PARAMS(NewProp_Objects_MetaData, ARRAY_COUNT(NewProp_Objects_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Objects_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Objects", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FnumRow, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tiles_MetaData[] = {
				{ "Category", "Map Tiles" },
				{ "ModuleRelativePath", "GenMapFromText.h" },
				{ "ToolTip", "Object tile set" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Tiles = { UE4CodeGen_Private::EPropertyClass::Array, "Tiles", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(UGenMapFromText, Tiles), METADATA_PARAMS(NewProp_Tiles_MetaData, ARRAY_COUNT(NewProp_Tiles_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Tiles_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Tiles", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FnumRow, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectSet_MetaData[] = {
				{ "Category", "Map Tiles" },
				{ "ModuleRelativePath", "GenMapFromText.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ObjectSet = { UE4CodeGen_Private::EPropertyClass::Array, "ObjectSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(UGenMapFromText, ObjectSet), METADATA_PARAMS(NewProp_ObjectSet_MetaData, ARRAY_COUNT(NewProp_ObjectSet_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ObjectSet_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ObjectSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FTileSetTile, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TileSet_MetaData[] = {
				{ "Category", "Map Tiles" },
				{ "ModuleRelativePath", "GenMapFromText.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TileSet = { UE4CodeGen_Private::EPropertyClass::Array, "TileSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(UGenMapFromText, TileSet), METADATA_PARAMS(NewProp_TileSet_MetaData, ARRAY_COUNT(NewProp_TileSet_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_TileSet_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "TileSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FTileSetTile, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UniversalTileSet_MetaData[] = {
				{ "Category", "Map Tiles" },
				{ "ModuleRelativePath", "GenMapFromText.h" },
				{ "ToolTip", "Tile set for both tiles and objects, must be filled or exception will occur" },
			};
#endif
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_UniversalTileSet = { UE4CodeGen_Private::EPropertyClass::Map, "UniversalTileSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0024080000000001, 1, nullptr, STRUCT_OFFSET(UGenMapFromText, UniversalTileSet), METADATA_PARAMS(NewProp_UniversalTileSet_MetaData, ARRAY_COUNT(NewProp_UniversalTileSet_MetaData)) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_UniversalTileSet_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "UniversalTileSet_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000001, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_UniversalTileSet_ValueProp = { UE4CodeGen_Private::EPropertyClass::Class, "UniversalTileSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000001, 1, nullptr, 1, Z_Construct_UClass_AMapTile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MapName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NPCMap,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NPCMap_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NPCMap_ValueProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Objects,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Objects_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Tiles,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Tiles_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ObjectSet,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ObjectSet_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TileSet,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TileSet_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_UniversalTileSet,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_UniversalTileSet_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_UniversalTileSet_ValueProp,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UGenMapFromText>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UGenMapFromText::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
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
	IMPLEMENT_CLASS(UGenMapFromText, 3510172659);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGenMapFromText(Z_Construct_UClass_UGenMapFromText, &UGenMapFromText::StaticClass, TEXT("/Script/ARPG"), TEXT("UGenMapFromText"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGenMapFromText);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
