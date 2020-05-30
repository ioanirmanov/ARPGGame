// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "MapObject.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapObject() {}
// Cross Module References
	ARPG_API UScriptStruct* Z_Construct_UScriptStruct_FnumRow();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	ARPG_API UScriptStruct* Z_Construct_UScriptStruct_FTileProp();
	ARPG_API UScriptStruct* Z_Construct_UScriptStruct_FRow();
	ARPG_API UClass* Z_Construct_UClass_AMapTile_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_AMapObject_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_AMapObject();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ARPG_API UClass* Z_Construct_UClass_UGameManagment_NoRegister();
	ARPG_API UScriptStruct* Z_Construct_UScriptStruct_FTileSetTile();
	ARPG_API UClass* Z_Construct_UClass_UGenMapFromText_NoRegister();
// End Cross Module References
class UScriptStruct* FnumRow::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ARPG_API uint32 Get_Z_Construct_UScriptStruct_FnumRow_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FnumRow, Z_Construct_UPackage__Script_ARPG(), TEXT("numRow"), sizeof(FnumRow), Get_Z_Construct_UScriptStruct_FnumRow_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FnumRow(FnumRow::StaticStruct, TEXT("/Script/ARPG"), TEXT("numRow"), false, nullptr, nullptr);
static struct FScriptStruct_ARPG_StaticRegisterNativesFnumRow
{
	FScriptStruct_ARPG_StaticRegisterNativesFnumRow()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("numRow")),new UScriptStruct::TCppStructOps<FnumRow>);
	}
} ScriptStruct_ARPG_StaticRegisterNativesFnumRow;
	UScriptStruct* Z_Construct_UScriptStruct_FnumRow()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FnumRow_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_ARPG();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("numRow"), sizeof(FnumRow), Get_Z_Construct_UScriptStruct_FnumRow_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FnumRow>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Row_MetaData[] = {
				{ "Category", "numRow" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Row = { UE4CodeGen_Private::EPropertyClass::Array, "Row", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FnumRow, Row), METADATA_PARAMS(NewProp_Row_MetaData, ARRAY_COUNT(NewProp_Row_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Row_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Row", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FTileProp, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Row,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Row_Inner,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"numRow",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FnumRow),
				alignof(FnumRow),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FnumRow_CRC() { return 3422885469U; }
class UScriptStruct* FTileProp::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ARPG_API uint32 Get_Z_Construct_UScriptStruct_FTileProp_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FTileProp, Z_Construct_UPackage__Script_ARPG(), TEXT("TileProp"), sizeof(FTileProp), Get_Z_Construct_UScriptStruct_FTileProp_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FTileProp(FTileProp::StaticStruct, TEXT("/Script/ARPG"), TEXT("TileProp"), false, nullptr, nullptr);
static struct FScriptStruct_ARPG_StaticRegisterNativesFTileProp
{
	FScriptStruct_ARPG_StaticRegisterNativesFTileProp()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("TileProp")),new UScriptStruct::TCppStructOps<FTileProp>);
	}
} ScriptStruct_ARPG_StaticRegisterNativesFTileProp;
	UScriptStruct* Z_Construct_UScriptStruct_FTileProp()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FTileProp_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_ARPG();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("TileProp"), sizeof(FTileProp), Get_Z_Construct_UScriptStruct_FTileProp_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "ModuleRelativePath", "MapObject.h" },
				{ "ToolTip", "Struct to store properties of a tile that will be generated" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTileProp>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Layer_MetaData[] = {
				{ "Category", "TileProp" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Layer = { UE4CodeGen_Private::EPropertyClass::Int, "Layer", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FTileProp, Layer), METADATA_PARAMS(NewProp_Layer_MetaData, ARRAY_COUNT(NewProp_Layer_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TriggerCommand_MetaData[] = {
				{ "Category", "TileProp" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_TriggerCommand = { UE4CodeGen_Private::EPropertyClass::Str, "TriggerCommand", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FTileProp, TriggerCommand), METADATA_PARAMS(NewProp_TriggerCommand_MetaData, ARRAY_COUNT(NewProp_TriggerCommand_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isTrigger_MetaData[] = {
				{ "Category", "TileProp" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			auto NewProp_isTrigger_SetBit = [](void* Obj){ ((FTileProp*)Obj)->isTrigger = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isTrigger = { UE4CodeGen_Private::EPropertyClass::Bool, "isTrigger", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FTileProp), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isTrigger_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isTrigger_MetaData, ARRAY_COUNT(NewProp_isTrigger_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isBlocked_MetaData[] = {
				{ "Category", "TileProp" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			auto NewProp_isBlocked_SetBit = [](void* Obj){ ((FTileProp*)Obj)->isBlocked = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isBlocked = { UE4CodeGen_Private::EPropertyClass::Bool, "isBlocked", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FTileProp), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isBlocked_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isBlocked_MetaData, ARRAY_COUNT(NewProp_isBlocked_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
				{ "Category", "TileProp" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Type = { UE4CodeGen_Private::EPropertyClass::Int, "Type", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FTileProp, Type), METADATA_PARAMS(NewProp_Type_MetaData, ARRAY_COUNT(NewProp_Type_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Layer,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TriggerCommand,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isTrigger,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isBlocked,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Type,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"TileProp",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FTileProp),
				alignof(FTileProp),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FTileProp_CRC() { return 699122528U; }
class UScriptStruct* FRow::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ARPG_API uint32 Get_Z_Construct_UScriptStruct_FRow_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRow, Z_Construct_UPackage__Script_ARPG(), TEXT("Row"), sizeof(FRow), Get_Z_Construct_UScriptStruct_FRow_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRow(FRow::StaticStruct, TEXT("/Script/ARPG"), TEXT("Row"), false, nullptr, nullptr);
static struct FScriptStruct_ARPG_StaticRegisterNativesFRow
{
	FScriptStruct_ARPG_StaticRegisterNativesFRow()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("Row")),new UScriptStruct::TCppStructOps<FRow>);
	}
} ScriptStruct_ARPG_StaticRegisterNativesFRow;
	UScriptStruct* Z_Construct_UScriptStruct_FRow()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FRow_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_ARPG();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("Row"), sizeof(FRow), Get_Z_Construct_UScriptStruct_FRow_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "ModuleRelativePath", "MapObject.h" },
				{ "ToolTip", "Row of tiles" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRow>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Row_MetaData[] = {
				{ "Category", "Row" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Row = { UE4CodeGen_Private::EPropertyClass::Array, "Row", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FRow, Row), METADATA_PARAMS(NewProp_Row_MetaData, ARRAY_COUNT(NewProp_Row_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Row_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Row", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_AMapTile_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Row,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Row_Inner,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"Row",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FRow),
				alignof(FRow),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRow_CRC() { return 1561942855U; }
	void AMapObject::StaticRegisterNativesAMapObject()
	{
	}
	UClass* Z_Construct_UClass_AMapObject_NoRegister()
	{
		return AMapObject::StaticClass();
	}
	UClass* Z_Construct_UClass_AMapObject()
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
				{ "IncludePath", "MapObject.h" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectsMap_MetaData[] = {
				{ "Category", "Object Generation" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ObjectsMap = { UE4CodeGen_Private::EPropertyClass::Array, "ObjectsMap", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AMapObject, ObjectsMap), METADATA_PARAMS(NewProp_ObjectsMap_MetaData, ARRAY_COUNT(NewProp_ObjectsMap_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ObjectsMap_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ObjectsMap", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FnumRow, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Objects_MetaData[] = {
				{ "Category", "Object Tiles" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Objects = { UE4CodeGen_Private::EPropertyClass::Array, "Objects", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AMapObject, Objects), METADATA_PARAMS(NewProp_Objects_MetaData, ARRAY_COUNT(NewProp_Objects_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Objects_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Objects", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FRow, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TilesMap_MetaData[] = {
				{ "Category", "Map Generation" },
				{ "ModuleRelativePath", "MapObject.h" },
				{ "ToolTip", "Holds properties for the map that will be generated" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TilesMap = { UE4CodeGen_Private::EPropertyClass::Array, "TilesMap", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AMapObject, TilesMap), METADATA_PARAMS(NewProp_TilesMap_MetaData, ARRAY_COUNT(NewProp_TilesMap_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_TilesMap_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "TilesMap", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FnumRow, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tiles_MetaData[] = {
				{ "Category", "Map Tiles" },
				{ "ModuleRelativePath", "MapObject.h" },
				{ "ToolTip", "The initialised mao" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Tiles = { UE4CodeGen_Private::EPropertyClass::Array, "Tiles", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AMapObject, Tiles), METADATA_PARAMS(NewProp_Tiles_MetaData, ARRAY_COUNT(NewProp_Tiles_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Tiles_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Tiles", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FRow, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_gameManComp_MetaData[] = {
				{ "Category", "Object Generation" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "MapObject.h" },
				{ "ToolTip", "Pointer to Game Managment component" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_gameManComp = { UE4CodeGen_Private::EPropertyClass::Object, "gameManComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000080009, 1, nullptr, STRUCT_OFFSET(AMapObject, gameManComp), Z_Construct_UClass_UGameManagment_NoRegister, METADATA_PARAMS(NewProp_gameManComp_MetaData, ARRAY_COUNT(NewProp_gameManComp_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectTileSet_MetaData[] = {
				{ "Category", "Object Generation" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ObjectTileSet = { UE4CodeGen_Private::EPropertyClass::Array, "ObjectTileSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AMapObject, ObjectTileSet), METADATA_PARAMS(NewProp_ObjectTileSet_MetaData, ARRAY_COUNT(NewProp_ObjectTileSet_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ObjectTileSet_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ObjectTileSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FTileSetTile, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Generator_MetaData[] = {
				{ "Category", "Map Generation" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "MapObject.h" },
				{ "ToolTip", "Component that will be used to generate a map from textasset" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Generator = { UE4CodeGen_Private::EPropertyClass::Object, "Generator", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000080009, 1, nullptr, STRUCT_OFFSET(AMapObject, Generator), Z_Construct_UClass_UGenMapFromText_NoRegister, METADATA_PARAMS(NewProp_Generator_MetaData, ARRAY_COUNT(NewProp_Generator_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GenerateMapFromText_MetaData[] = {
				{ "Category", "Map Generation" },
				{ "ModuleRelativePath", "MapObject.h" },
			};
#endif
			auto NewProp_GenerateMapFromText_SetBit = [](void* Obj){ ((AMapObject*)Obj)->GenerateMapFromText = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_GenerateMapFromText = { UE4CodeGen_Private::EPropertyClass::Bool, "GenerateMapFromText", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AMapObject), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_GenerateMapFromText_SetBit)>::SetBit, METADATA_PARAMS(NewProp_GenerateMapFromText_MetaData, ARRAY_COUNT(NewProp_GenerateMapFromText_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TileSet_MetaData[] = {
				{ "Category", "Map Generation" },
				{ "ModuleRelativePath", "MapObject.h" },
				{ "ToolTip", "Tile set for map" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TileSet = { UE4CodeGen_Private::EPropertyClass::Array, "TileSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AMapObject, TileSet), METADATA_PARAMS(NewProp_TileSet_MetaData, ARRAY_COUNT(NewProp_TileSet_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_TileSet_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "TileSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FTileSetTile, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ObjectsMap,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ObjectsMap_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Objects,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Objects_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TilesMap,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TilesMap_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Tiles,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Tiles_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_gameManComp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ObjectTileSet,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ObjectTileSet_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Generator,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GenerateMapFromText,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TileSet,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TileSet_Inner,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AMapObject>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AMapObject::StaticClass,
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
	IMPLEMENT_CLASS(AMapObject, 1130844596);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMapObject(Z_Construct_UClass_AMapObject, &AMapObject::StaticClass, TEXT("/Script/ARPG"), TEXT("AMapObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMapObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
