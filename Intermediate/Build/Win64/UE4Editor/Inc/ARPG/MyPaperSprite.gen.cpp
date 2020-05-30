// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "MyPaperSprite.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyPaperSprite() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_UMyPaperSprite_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_UMyPaperSprite();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSprite();
	UPackage* Z_Construct_UPackage__Script_ARPG();
// End Cross Module References
	void UMyPaperSprite::StaticRegisterNativesUMyPaperSprite()
	{
	}
	UClass* Z_Construct_UClass_UMyPaperSprite_NoRegister()
	{
		return UMyPaperSprite::StaticClass();
	}
	UClass* Z_Construct_UClass_UMyPaperSprite()
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
				{ "IncludePath", "MyPaperSprite.h" },
				{ "ModuleRelativePath", "MyPaperSprite.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UMyPaperSprite>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UMyPaperSprite::StaticClass,
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
	IMPLEMENT_CLASS(UMyPaperSprite, 1603136070);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMyPaperSprite(Z_Construct_UClass_UMyPaperSprite, &UMyPaperSprite::StaticClass, TEXT("/Script/ARPG"), TEXT("UMyPaperSprite"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyPaperSprite);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
