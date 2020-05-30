// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "MapEditor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapEditor() {}
// Cross Module References
	ARPG_API UEnum* Z_Construct_UEnum_ARPG_EEditorMode();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	ARPG_API UScriptStruct* Z_Construct_UScriptStruct_FTileSetTile();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_UMapEditor_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_UMapEditor();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ARPG_API UClass* Z_Construct_UClass_AMapEditorTile_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_AGridLine_NoRegister();
// End Cross Module References
	static UEnum* EEditorMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ARPG_EEditorMode, Z_Construct_UPackage__Script_ARPG(), TEXT("EEditorMode"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EEditorMode(EEditorMode_StaticEnum, TEXT("/Script/ARPG"), TEXT("EEditorMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ARPG_EEditorMode_CRC() { return 2656543458U; }
	UEnum* Z_Construct_UEnum_ARPG_EEditorMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ARPG();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EEditorMode"), 0, Get_Z_Construct_UEnum_ARPG_EEditorMode_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "SelectTile", (int64)SelectTile },
				{ "ChangeTile", (int64)ChangeTile },
				{ "DeleteTile", (int64)DeleteTile },
				{ "MoveCamera", (int64)MoveCamera },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "MapEditor.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ARPG,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EEditorMode",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::Regular,
				"EEditorMode",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FTileSetTile::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ARPG_API uint32 Get_Z_Construct_UScriptStruct_FTileSetTile_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FTileSetTile, Z_Construct_UPackage__Script_ARPG(), TEXT("TileSetTile"), sizeof(FTileSetTile), Get_Z_Construct_UScriptStruct_FTileSetTile_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FTileSetTile(FTileSetTile::StaticStruct, TEXT("/Script/ARPG"), TEXT("TileSetTile"), false, nullptr, nullptr);
static struct FScriptStruct_ARPG_StaticRegisterNativesFTileSetTile
{
	FScriptStruct_ARPG_StaticRegisterNativesFTileSetTile()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("TileSetTile")),new UScriptStruct::TCppStructOps<FTileSetTile>);
	}
} ScriptStruct_ARPG_StaticRegisterNativesFTileSetTile;
	UScriptStruct* Z_Construct_UScriptStruct_FTileSetTile()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FTileSetTile_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_ARPG();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("TileSetTile"), sizeof(FTileSetTile), Get_Z_Construct_UScriptStruct_FTileSetTile_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "ModuleRelativePath", "MapEditor.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTileSetTile>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TileName_MetaData[] = {
				{ "ModuleRelativePath", "MapEditor.h" },
			};
#endif
			static const UE4CodeGen_Private::FTextPropertyParams NewProp_TileName = { UE4CodeGen_Private::EPropertyClass::Text, "TileName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FTileSetTile, TileName), METADATA_PARAMS(NewProp_TileName_MetaData, ARRAY_COUNT(NewProp_TileName_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_texture_MetaData[] = {
				{ "ModuleRelativePath", "MapEditor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_texture = { UE4CodeGen_Private::EPropertyClass::Object, "texture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FTileSetTile, texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_texture_MetaData, ARRAY_COUNT(NewProp_texture_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TileName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_texture,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"TileSetTile",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FTileSetTile),
				alignof(FTileSetTile),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FTileSetTile_CRC() { return 3971373449U; }
	void UMapEditor::StaticRegisterNativesUMapEditor()
	{
	}
	UClass* Z_Construct_UClass_UMapEditor_NoRegister()
	{
		return UMapEditor::StaticClass();
	}
	UClass* Z_Construct_UClass_UMapEditor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_USceneComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "ClassGroupNames", "Custom" },
				{ "HideCategories", "Trigger PhysicsVolume" },
				{ "IncludePath", "MapEditor.h" },
				{ "ModuleRelativePath", "MapEditor.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BlankTile_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "MapEditor.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BlankTile = { UE4CodeGen_Private::EPropertyClass::Object, "BlankTile", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(UMapEditor, BlankTile), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_BlankTile_MetaData, ARRAY_COUNT(NewProp_BlankTile_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EmptyTile_MetaData[] = {
				{ "Category", "EmptyTile" },
				{ "ModuleRelativePath", "MapEditor.h" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_EmptyTile = { UE4CodeGen_Private::EPropertyClass::Class, "EmptyTile", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000001, 1, nullptr, STRUCT_OFFSET(UMapEditor, EmptyTile), Z_Construct_UClass_AMapEditorTile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_EmptyTile_MetaData, ARRAY_COUNT(NewProp_EmptyTile_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SBoxLine_MetaData[] = {
				{ "Category", "Grid" },
				{ "ModuleRelativePath", "MapEditor.h" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_SBoxLine = { UE4CodeGen_Private::EPropertyClass::Class, "SBoxLine", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000001, 1, nullptr, STRUCT_OFFSET(UMapEditor, SBoxLine), Z_Construct_UClass_AGridLine_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_SBoxLine_MetaData, ARRAY_COUNT(NewProp_SBoxLine_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MBoxLine_MetaData[] = {
				{ "Category", "Grid" },
				{ "ModuleRelativePath", "MapEditor.h" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_MBoxLine = { UE4CodeGen_Private::EPropertyClass::Class, "MBoxLine", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000001, 1, nullptr, STRUCT_OFFSET(UMapEditor, MBoxLine), Z_Construct_UClass_AGridLine_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_MBoxLine_MetaData, ARRAY_COUNT(NewProp_MBoxLine_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GridLine_MetaData[] = {
				{ "Category", "Grid" },
				{ "ModuleRelativePath", "MapEditor.h" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_GridLine = { UE4CodeGen_Private::EPropertyClass::Class, "GridLine", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000001, 1, nullptr, STRUCT_OFFSET(UMapEditor, GridLine), Z_Construct_UClass_AGridLine_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_GridLine_MetaData, ARRAY_COUNT(NewProp_GridLine_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BlankTile,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_EmptyTile,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SBoxLine,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MBoxLine,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GridLine,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UMapEditor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UMapEditor::StaticClass,
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
	IMPLEMENT_CLASS(UMapEditor, 2024634034);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMapEditor(Z_Construct_UClass_UMapEditor, &UMapEditor::StaticClass, TEXT("/Script/ARPG"), TEXT("UMapEditor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMapEditor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
