// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "DialogueSystem.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueSystem() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_UDialogueSystem_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_UDialogueSystem();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ARPG_API UClass* Z_Construct_UClass_ATitledDialogueBox_NoRegister();
// End Cross Module References
	void UDialogueSystem::StaticRegisterNativesUDialogueSystem()
	{
	}
	UClass* Z_Construct_UClass_UDialogueSystem_NoRegister()
	{
		return UDialogueSystem::StaticClass();
	}
	UClass* Z_Construct_UClass_UDialogueSystem()
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
				{ "IncludePath", "DialogueSystem.h" },
				{ "ModuleRelativePath", "DialogueSystem.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TitleBox_MetaData[] = {
				{ "Category", "Dialogue Boxes" },
				{ "ModuleRelativePath", "DialogueSystem.h" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_TitleBox = { UE4CodeGen_Private::EPropertyClass::Class, "TitleBox", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000001, 1, nullptr, STRUCT_OFFSET(UDialogueSystem, TitleBox), Z_Construct_UClass_ATitledDialogueBox_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_TitleBox_MetaData, ARRAY_COUNT(NewProp_TitleBox_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TitleBox,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UDialogueSystem>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UDialogueSystem::StaticClass,
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
	IMPLEMENT_CLASS(UDialogueSystem, 1021360483);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDialogueSystem(Z_Construct_UClass_UDialogueSystem, &UDialogueSystem::StaticClass, TEXT("/Script/ARPG"), TEXT("UDialogueSystem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDialogueSystem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
