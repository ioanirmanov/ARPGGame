// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDialogueSystem;
#ifdef ARPG_GameManagment_generated_h
#error "GameManagment.generated.h already included, missing '#pragma once' in GameManagment.h"
#endif
#define ARPG_GameManagment_generated_h

#define ARPG_Source_ARPG_GameManagment_h_29_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetDialogueSystem) \
	{ \
		P_GET_OBJECT(UDialogueSystem,Z_Param_DiagPtr); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetDialogueSystem(Z_Param_DiagPtr); \
		P_NATIVE_END; \
	}


#define ARPG_Source_ARPG_GameManagment_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetDialogueSystem) \
	{ \
		P_GET_OBJECT(UDialogueSystem,Z_Param_DiagPtr); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetDialogueSystem(Z_Param_DiagPtr); \
		P_NATIVE_END; \
	}


#define ARPG_Source_ARPG_GameManagment_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameManagment(); \
	friend ARPG_API class UClass* Z_Construct_UClass_UGameManagment(); \
public: \
	DECLARE_CLASS(UGameManagment, USceneComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(UGameManagment) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_GameManagment_h_29_INCLASS \
private: \
	static void StaticRegisterNativesUGameManagment(); \
	friend ARPG_API class UClass* Z_Construct_UClass_UGameManagment(); \
public: \
	DECLARE_CLASS(UGameManagment, USceneComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(UGameManagment) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_GameManagment_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameManagment(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameManagment) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameManagment); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameManagment); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameManagment(UGameManagment&&); \
	NO_API UGameManagment(const UGameManagment&); \
public:


#define ARPG_Source_ARPG_GameManagment_h_29_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameManagment(UGameManagment&&); \
	NO_API UGameManagment(const UGameManagment&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameManagment); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameManagment); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGameManagment)


#define ARPG_Source_ARPG_GameManagment_h_29_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__DialogueSystem() { return STRUCT_OFFSET(UGameManagment, DialogueSystem); } \
	FORCEINLINE static uint32 __PPO__DefaultMap() { return STRUCT_OFFSET(UGameManagment, DefaultMap); } \
	FORCEINLINE static uint32 __PPO__Maps() { return STRUCT_OFFSET(UGameManagment, Maps); }


#define ARPG_Source_ARPG_GameManagment_h_26_PROLOG
#define ARPG_Source_ARPG_GameManagment_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_GameManagment_h_29_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_GameManagment_h_29_RPC_WRAPPERS \
	ARPG_Source_ARPG_GameManagment_h_29_INCLASS \
	ARPG_Source_ARPG_GameManagment_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ARPG_Source_ARPG_GameManagment_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_GameManagment_h_29_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_GameManagment_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	ARPG_Source_ARPG_GameManagment_h_29_INCLASS_NO_PURE_DECLS \
	ARPG_Source_ARPG_GameManagment_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ARPG_Source_ARPG_GameManagment_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
