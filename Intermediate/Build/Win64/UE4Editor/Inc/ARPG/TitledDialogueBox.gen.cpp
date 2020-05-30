// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "TitledDialogueBox.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTitledDialogueBox() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_ATitledDialogueBox_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_ATitledDialogueBox();
	ARPG_API UClass* Z_Construct_UClass_ADialogueBox();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
// End Cross Module References
	void ATitledDialogueBox::StaticRegisterNativesATitledDialogueBox()
	{
	}
	UClass* Z_Construct_UClass_ATitledDialogueBox_NoRegister()
	{
		return ATitledDialogueBox::StaticClass();
	}
	UClass* Z_Construct_UClass_ATitledDialogueBox()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ADialogueBox,
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "TitledDialogueBox.h" },
				{ "ModuleRelativePath", "TitledDialogueBox.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
				{ "Category", "Dialogue Box Properties" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "TitledDialogueBox.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Title = { UE4CodeGen_Private::EPropertyClass::Object, "Title", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000080009, 1, nullptr, STRUCT_OFFSET(ATitledDialogueBox, Title), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(NewProp_Title_MetaData, ARRAY_COUNT(NewProp_Title_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Title,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ATitledDialogueBox>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ATitledDialogueBox::StaticClass,
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
	IMPLEMENT_CLASS(ATitledDialogueBox, 237332329);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATitledDialogueBox(Z_Construct_UClass_ATitledDialogueBox, &ATitledDialogueBox::StaticClass, TEXT("/Script/ARPG"), TEXT("ATitledDialogueBox"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATitledDialogueBox);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
