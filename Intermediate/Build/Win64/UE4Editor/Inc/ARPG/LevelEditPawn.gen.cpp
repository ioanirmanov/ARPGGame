// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "LevelEditPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLevelEditPawn() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_ALevelEditPawn_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_ALevelEditPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void ALevelEditPawn::StaticRegisterNativesALevelEditPawn()
	{
	}
	UClass* Z_Construct_UClass_ALevelEditPawn_NoRegister()
	{
		return ALevelEditPawn::StaticClass();
	}
	UClass* Z_Construct_UClass_ALevelEditPawn()
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
				{ "IncludePath", "LevelEditPawn.h" },
				{ "ModuleRelativePath", "LevelEditPawn.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Cam_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "LevelEditPawn.h" },
				{ "ToolTip", "Camera" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Cam = { UE4CodeGen_Private::EPropertyClass::Object, "Cam", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080009, 1, nullptr, STRUCT_OFFSET(ALevelEditPawn, Cam), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(NewProp_Cam_MetaData, ARRAY_COUNT(NewProp_Cam_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Cam,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ALevelEditPawn>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ALevelEditPawn::StaticClass,
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
	IMPLEMENT_CLASS(ALevelEditPawn, 1745213072);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALevelEditPawn(Z_Construct_UClass_ALevelEditPawn, &ALevelEditPawn::StaticClass, TEXT("/Script/ARPG"), TEXT("ALevelEditPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALevelEditPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
