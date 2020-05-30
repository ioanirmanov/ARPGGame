// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARPG_DialogueBox_generated_h
#error "DialogueBox.generated.h already included, missing '#pragma once' in DialogueBox.h"
#endif
#define ARPG_DialogueBox_generated_h

#define ARPG_Source_ARPG_DialogueBox_h_12_RPC_WRAPPERS
#define ARPG_Source_ARPG_DialogueBox_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define ARPG_Source_ARPG_DialogueBox_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADialogueBox(); \
	friend ARPG_API class UClass* Z_Construct_UClass_ADialogueBox(); \
public: \
	DECLARE_CLASS(ADialogueBox, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(ADialogueBox) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_DialogueBox_h_12_INCLASS \
private: \
	static void StaticRegisterNativesADialogueBox(); \
	friend ARPG_API class UClass* Z_Construct_UClass_ADialogueBox(); \
public: \
	DECLARE_CLASS(ADialogueBox, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(ADialogueBox) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_DialogueBox_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADialogueBox(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADialogueBox) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADialogueBox); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADialogueBox); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADialogueBox(ADialogueBox&&); \
	NO_API ADialogueBox(const ADialogueBox&); \
public:


#define ARPG_Source_ARPG_DialogueBox_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADialogueBox(ADialogueBox&&); \
	NO_API ADialogueBox(const ADialogueBox&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADialogueBox); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADialogueBox); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADialogueBox)


#define ARPG_Source_ARPG_DialogueBox_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Sprite() { return STRUCT_OFFSET(ADialogueBox, Sprite); } \
	FORCEINLINE static uint32 __PPO__Text() { return STRUCT_OFFSET(ADialogueBox, Text); } \
	FORCEINLINE static uint32 __PPO__BoxWidth() { return STRUCT_OFFSET(ADialogueBox, BoxWidth); } \
	FORCEINLINE static uint32 __PPO__BoxHeight() { return STRUCT_OFFSET(ADialogueBox, BoxHeight); } \
	FORCEINLINE static uint32 __PPO__DisplayHeight() { return STRUCT_OFFSET(ADialogueBox, DisplayHeight); }


#define ARPG_Source_ARPG_DialogueBox_h_9_PROLOG
#define ARPG_Source_ARPG_DialogueBox_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_DialogueBox_h_12_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_DialogueBox_h_12_RPC_WRAPPERS \
	ARPG_Source_ARPG_DialogueBox_h_12_INCLASS \
	ARPG_Source_ARPG_DialogueBox_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ARPG_Source_ARPG_DialogueBox_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_DialogueBox_h_12_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_DialogueBox_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ARPG_Source_ARPG_DialogueBox_h_12_INCLASS_NO_PURE_DECLS \
	ARPG_Source_ARPG_DialogueBox_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ARPG_Source_ARPG_DialogueBox_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
