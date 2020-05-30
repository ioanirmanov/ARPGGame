// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "NPCPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNPCPawn() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_ANPCPawn_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_ANPCPawn();
	ARPG_API UClass* Z_Construct_UClass_ACharacterPawn();
	UPackage* Z_Construct_UPackage__Script_ARPG();
// End Cross Module References
	void ANPCPawn::StaticRegisterNativesANPCPawn()
	{
	}
	UClass* Z_Construct_UClass_ANPCPawn_NoRegister()
	{
		return ANPCPawn::StaticClass();
	}
	UClass* Z_Construct_UClass_ANPCPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacterPawn,
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "NPCPawn.h" },
				{ "ModuleRelativePath", "NPCPawn.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ANPCPawn>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ANPCPawn::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANPCPawn, 3725749460);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANPCPawn(Z_Construct_UClass_ANPCPawn, &ANPCPawn::StaticClass, TEXT("/Script/ARPG"), TEXT("ANPCPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANPCPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
