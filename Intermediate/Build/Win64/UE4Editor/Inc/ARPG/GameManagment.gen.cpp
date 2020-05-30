// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "GameManagment.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameManagment() {}
// Cross Module References
	ARPG_API UClass* Z_Construct_UClass_UGameManagment_NoRegister();
	ARPG_API UClass* Z_Construct_UClass_UGameManagment();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	UPackage* Z_Construct_UPackage__Script_ARPG();
	ARPG_API UFunction* Z_Construct_UFunction_UGameManagment_SetDialogueSystem();
	ARPG_API UClass* Z_Construct_UClass_UDialogueSystem_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ARPG_API UClass* Z_Construct_UClass_AMapObject_NoRegister();
// End Cross Module References
	void UGameManagment::StaticRegisterNativesUGameManagment()
	{
		UClass* Class = UGameManagment::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetDialogueSystem", &UGameManagment::execSetDialogueSystem },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UGameManagment_SetDialogueSystem()
	{
		struct GameManagment_eventSetDialogueSystem_Parms
		{
			UDialogueSystem* DiagPtr;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DiagPtr_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DiagPtr = { UE4CodeGen_Private::EPropertyClass::Object, "DiagPtr", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GameManagment_eventSetDialogueSystem_Parms, DiagPtr), Z_Construct_UClass_UDialogueSystem_NoRegister, METADATA_PARAMS(NewProp_DiagPtr_MetaData, ARRAY_COUNT(NewProp_DiagPtr_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DiagPtr,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Set Up" },
				{ "ModuleRelativePath", "GameManagment.h" },
				{ "ToolTip", "TODO: Make these private, use proper encapsulation" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameManagment, "SetDialogueSystem", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GameManagment_eventSetDialogueSystem_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGameManagment_NoRegister()
	{
		return UGameManagment::StaticClass();
	}
	UClass* Z_Construct_UClass_UGameManagment()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_USceneComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_ARPG,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UGameManagment_SetDialogueSystem, "SetDialogueSystem" }, // 162679434
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "ClassGroupNames", "Custom" },
				{ "HideCategories", "Trigger PhysicsVolume" },
				{ "IncludePath", "GameManagment.h" },
				{ "ModuleRelativePath", "GameManagment.h" },
				{ "ToolTip", "USTRUCT()\nstruct Map\n{\n       GENERATED_BODY()\n               UPROPERTY(EditAnywhere)\n               TSubclassOf<AMapTile> Map;\n\n};" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Maps_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "GameManagment.h" },
				{ "ToolTip", "Stores other maps that will b used" },
			};
#endif
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_Maps = { UE4CodeGen_Private::EPropertyClass::Map, "Maps", RF_Public|RF_Transient|RF_MarkAsNative, 0x0044000000000001, 1, nullptr, STRUCT_OFFSET(UGameManagment, Maps), METADATA_PARAMS(NewProp_Maps_MetaData, ARRAY_COUNT(NewProp_Maps_MetaData)) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Maps_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "Maps_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000001, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_Maps_ValueProp = { UE4CodeGen_Private::EPropertyClass::Class, "Maps", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000001, 1, nullptr, 1, Z_Construct_UClass_AMapObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultMap_MetaData[] = {
				{ "Category", "Player Properties" },
				{ "ModuleRelativePath", "GameManagment.h" },
				{ "ToolTip", "Stores which map is the default map" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_DefaultMap = { UE4CodeGen_Private::EPropertyClass::Class, "DefaultMap", RF_Public|RF_Transient|RF_MarkAsNative, 0x0044000000000001, 1, nullptr, STRUCT_OFFSET(UGameManagment, DefaultMap), Z_Construct_UClass_AMapObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_DefaultMap_MetaData, ARRAY_COUNT(NewProp_DefaultMap_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DialogueSystem_MetaData[] = {
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "GameManagment.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DialogueSystem = { UE4CodeGen_Private::EPropertyClass::Object, "DialogueSystem", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000080008, 1, nullptr, STRUCT_OFFSET(UGameManagment, DialogueSystem), Z_Construct_UClass_UDialogueSystem_NoRegister, METADATA_PARAMS(NewProp_DialogueSystem_MetaData, ARRAY_COUNT(NewProp_DialogueSystem_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Maps,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Maps_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Maps_ValueProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DefaultMap,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DialogueSystem,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UGameManagment>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UGameManagment::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(UGameManagment, 928758710);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameManagment(Z_Construct_UClass_UGameManagment, &UGameManagment::StaticClass, TEXT("/Script/ARPG"), TEXT("UGameManagment"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameManagment);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
