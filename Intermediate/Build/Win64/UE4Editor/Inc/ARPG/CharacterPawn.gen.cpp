// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "CharacterPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharacterPawn() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_ACharacterPawn_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_ACharacterPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSprite_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_AMapObject_NoRegister();
// End Cross Module References
	void ACharacterPawn::StaticRegisterNativesACharacterPawn()
	{
	}
	UClass* Z_Construct_UClass_ACharacterPawn_NoRegister()
	{
		return ACharacterPawn::StaticClass();
	}
	UClass* Z_Construct_UClass_ACharacterPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_APawn,
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "CharacterPawn.h" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WalkDownSprites_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_WalkDownSprites = { UE4CodeGen_Private::EPropertyClass::Array, "WalkDownSprites", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(ACharacterPawn, WalkDownSprites), METADATA_PARAMS(NewProp_WalkDownSprites_MetaData, ARRAY_COUNT(NewProp_WalkDownSprites_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WalkDownSprites_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "WalkDownSprites", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WalkUpSprites_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_WalkUpSprites = { UE4CodeGen_Private::EPropertyClass::Array, "WalkUpSprites", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(ACharacterPawn, WalkUpSprites), METADATA_PARAMS(NewProp_WalkUpSprites_MetaData, ARRAY_COUNT(NewProp_WalkUpSprites_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WalkUpSprites_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "WalkUpSprites", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WalkLeftSprites_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_WalkLeftSprites = { UE4CodeGen_Private::EPropertyClass::Array, "WalkLeftSprites", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(ACharacterPawn, WalkLeftSprites), METADATA_PARAMS(NewProp_WalkLeftSprites_MetaData, ARRAY_COUNT(NewProp_WalkLeftSprites_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WalkLeftSprites_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "WalkLeftSprites", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WalkRightSprites_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
				{ "ToolTip", "Arrays of sprites for walk cycle" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_WalkRightSprites = { UE4CodeGen_Private::EPropertyClass::Array, "WalkRightSprites", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(ACharacterPawn, WalkRightSprites), METADATA_PARAMS(NewProp_WalkRightSprites_MetaData, ARRAY_COUNT(NewProp_WalkRightSprites_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WalkRightSprites_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "WalkRightSprites", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UPaperSprite_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Cam_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
				{ "ToolTip", "Camera" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Cam = { UE4CodeGen_Private::EPropertyClass::Object, "Cam", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000080009, 1, nullptr, STRUCT_OFFSET(ACharacterPawn, Cam), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(NewProp_Cam_MetaData, ARRAY_COUNT(NewProp_Cam_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sprite_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
				{ "ToolTip", "Current displayed sprite" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sprite = { UE4CodeGen_Private::EPropertyClass::Object, "Sprite", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000080009, 1, nullptr, STRUCT_OFFSET(ACharacterPawn, Sprite), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_Sprite_MetaData, ARRAY_COUNT(NewProp_Sprite_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MoveSpeed_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MoveSpeed = { UE4CodeGen_Private::EPropertyClass::Float, "MoveSpeed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(ACharacterPawn, MoveSpeed), METADATA_PARAMS(NewProp_MoveSpeed_MetaData, ARRAY_COUNT(NewProp_MoveSpeed_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapY_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MapY = { UE4CodeGen_Private::EPropertyClass::Int, "MapY", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(ACharacterPawn, MapY), METADATA_PARAMS(NewProp_MapY_MetaData, ARRAY_COUNT(NewProp_MapY_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapX_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
				{ "ToolTip", "Position on map, in terms of tiles" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MapX = { UE4CodeGen_Private::EPropertyClass::Int, "MapX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(ACharacterPawn, MapX), METADATA_PARAMS(NewProp_MapX_MetaData, ARRAY_COUNT(NewProp_MapX_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Map_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "CharacterPawn.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Map = { UE4CodeGen_Private::EPropertyClass::Object, "Map", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000001, 1, nullptr, STRUCT_OFFSET(ACharacterPawn, Map), Z_Construct_UClass_AMapObject_NoRegister, METADATA_PARAMS(NewProp_Map_MetaData, ARRAY_COUNT(NewProp_Map_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WalkDownSprites,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WalkDownSprites_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WalkUpSprites,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WalkUpSprites_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WalkLeftSprites,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WalkLeftSprites_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WalkRightSprites,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WalkRightSprites_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Cam,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Sprite,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MoveSpeed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MapY,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MapX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Map,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ACharacterPawn>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ACharacterPawn::StaticClass,
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
	IMPLEMENT_CLASS(ACharacterPawn, 3380695475);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACharacterPawn(Z_Construct_UClass_ACharacterPawn, &ACharacterPawn::StaticClass, TEXT("/Script/ARPG"), TEXT("ACharacterPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACharacterPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
