// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "DialogueBox.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialogueBox() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_ADialogueBox_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_ADialogueBox();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
// End Cross Module References
	void ADialogueBox::StaticRegisterNativesADialogueBox()
	{
	}
	UClass* Z_Construct_UClass_ADialogueBox_NoRegister()
	{
		return ADialogueBox::StaticClass();
	}
	UClass* Z_Construct_UClass_ADialogueBox()
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
				{ "IncludePath", "DialogueBox.h" },
				{ "ModuleRelativePath", "DialogueBox.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DisplayHeight_MetaData[] = {
				{ "Category", "Dialogue Box Properties" },
				{ "ModuleRelativePath", "DialogueBox.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DisplayHeight = { UE4CodeGen_Private::EPropertyClass::Float, "DisplayHeight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(ADialogueBox, DisplayHeight), METADATA_PARAMS(NewProp_DisplayHeight_MetaData, ARRAY_COUNT(NewProp_DisplayHeight_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoxHeight_MetaData[] = {
				{ "Category", "Dialogue Box Properties" },
				{ "ModuleRelativePath", "DialogueBox.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BoxHeight = { UE4CodeGen_Private::EPropertyClass::Float, "BoxHeight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(ADialogueBox, BoxHeight), METADATA_PARAMS(NewProp_BoxHeight_MetaData, ARRAY_COUNT(NewProp_BoxHeight_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoxWidth_MetaData[] = {
				{ "Category", "Dialogue Box Properties" },
				{ "ModuleRelativePath", "DialogueBox.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BoxWidth = { UE4CodeGen_Private::EPropertyClass::Float, "BoxWidth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(ADialogueBox, BoxWidth), METADATA_PARAMS(NewProp_BoxWidth_MetaData, ARRAY_COUNT(NewProp_BoxWidth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
				{ "Category", "Dialogue Box Properties" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "DialogueBox.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Text = { UE4CodeGen_Private::EPropertyClass::Object, "Text", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000080009, 1, nullptr, STRUCT_OFFSET(ADialogueBox, Text), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(NewProp_Text_MetaData, ARRAY_COUNT(NewProp_Text_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sprite_MetaData[] = {
				{ "Category", "Dialogue Box Properties" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "DialogueBox.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Sprite = { UE4CodeGen_Private::EPropertyClass::Object, "Sprite", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000080009, 1, nullptr, STRUCT_OFFSET(ADialogueBox, Sprite), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_Sprite_MetaData, ARRAY_COUNT(NewProp_Sprite_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DisplayHeight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BoxHeight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BoxWidth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Text,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Sprite,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ADialogueBox>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ADialogueBox::StaticClass,
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
	IMPLEMENT_CLASS(ADialogueBox, 2355611359);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADialogueBox(Z_Construct_UClass_ADialogueBox, &ADialogueBox::StaticClass, TEXT("/Script/ARPG"), TEXT("ADialogueBox"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADialogueBox);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
