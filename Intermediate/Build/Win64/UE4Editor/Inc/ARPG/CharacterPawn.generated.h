// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARPG_CharacterPawn_generated_h
#error "CharacterPawn.generated.h already included, missing '#pragma once' in CharacterPawn.h"
#endif
#define ARPG_CharacterPawn_generated_h

#define ARPG_Source_ARPG_CharacterPawn_h_20_RPC_WRAPPERS
#define ARPG_Source_ARPG_CharacterPawn_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define ARPG_Source_ARPG_CharacterPawn_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACharacterPawn(); \
	friend ARPG_API class UClass* Z_Construct_UClass_ACharacterPawn(); \
public: \
	DECLARE_CLASS(ACharacterPawn, APawn, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(ACharacterPawn) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_CharacterPawn_h_20_INCLASS \
private: \
	static void StaticRegisterNativesACharacterPawn(); \
	friend ARPG_API class UClass* Z_Construct_UClass_ACharacterPawn(); \
public: \
	DECLARE_CLASS(ACharacterPawn, APawn, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(ACharacterPawn) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_CharacterPawn_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACharacterPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACharacterPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACharacterPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACharacterPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACharacterPawn(ACharacterPawn&&); \
	NO_API ACharacterPawn(const ACharacterPawn&); \
public:


#define ARPG_Source_ARPG_CharacterPawn_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACharacterPawn(ACharacterPawn&&); \
	NO_API ACharacterPawn(const ACharacterPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACharacterPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACharacterPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACharacterPawn)


#define ARPG_Source_ARPG_CharacterPawn_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Map() { return STRUCT_OFFSET(ACharacterPawn, Map); } \
	FORCEINLINE static uint32 __PPO__MapX() { return STRUCT_OFFSET(ACharacterPawn, MapX); } \
	FORCEINLINE static uint32 __PPO__MapY() { return STRUCT_OFFSET(ACharacterPawn, MapY); } \
	FORCEINLINE static uint32 __PPO__MoveSpeed() { return STRUCT_OFFSET(ACharacterPawn, MoveSpeed); } \
	FORCEINLINE static uint32 __PPO__Sprite() { return STRUCT_OFFSET(ACharacterPawn, Sprite); } \
	FORCEINLINE static uint32 __PPO__Cam() { return STRUCT_OFFSET(ACharacterPawn, Cam); } \
	FORCEINLINE static uint32 __PPO__WalkRightSprites() { return STRUCT_OFFSET(ACharacterPawn, WalkRightSprites); } \
	FORCEINLINE static uint32 __PPO__WalkLeftSprites() { return STRUCT_OFFSET(ACharacterPawn, WalkLeftSprites); } \
	FORCEINLINE static uint32 __PPO__WalkUpSprites() { return STRUCT_OFFSET(ACharacterPawn, WalkUpSprites); } \
	FORCEINLINE static uint32 __PPO__WalkDownSprites() { return STRUCT_OFFSET(ACharacterPawn, WalkDownSprites); }


#define ARPG_Source_ARPG_CharacterPawn_h_17_PROLOG
#define ARPG_Source_ARPG_CharacterPawn_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_CharacterPawn_h_20_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_CharacterPawn_h_20_RPC_WRAPPERS \
	ARPG_Source_ARPG_CharacterPawn_h_20_INCLASS \
	ARPG_Source_ARPG_CharacterPawn_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ARPG_Source_ARPG_CharacterPawn_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_CharacterPawn_h_20_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_CharacterPawn_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	ARPG_Source_ARPG_CharacterPawn_h_20_INCLASS_NO_PURE_DECLS \
	ARPG_Source_ARPG_CharacterPawn_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ARPG_Source_ARPG_CharacterPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
