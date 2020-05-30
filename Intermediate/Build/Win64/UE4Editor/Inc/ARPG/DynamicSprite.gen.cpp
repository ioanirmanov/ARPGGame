// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "DynamicSprite.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDynamicSprite() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_UDynamicSprite_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_UDynamicSprite();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSprite();
	UPackage* Z_Construct_UPackage__Script_ARPG();
// End Cross Module References
	void UDynamicSprite::StaticRegisterNativesUDynamicSprite()
	{
	}
	UClass* Z_Construct_UClass_UDynamicSprite_NoRegister()
	{
		return UDynamicSprite::StaticClass();
	}
	UClass* Z_Construct_UClass_UDynamicSprite()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UPaperSprite,
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IncludePath", "DynamicSprite.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "DynamicSprite.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UDynamicSprite>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UDynamicSprite::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
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
	IMPLEMENT_CLASS(UDynamicSprite, 1026515438);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDynamicSprite(Z_Construct_UClass_UDynamicSprite, &UDynamicSprite::StaticClass, TEXT("/Script/ARPG"), TEXT("UDynamicSprite"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDynamicSprite);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
