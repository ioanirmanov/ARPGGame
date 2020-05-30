// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARPG_MapTile_generated_h
#error "MapTile.generated.h already included, missing '#pragma once' in MapTile.h"
#endif
#define ARPG_MapTile_generated_h

#define ARPG_Source_ARPG_MapTile_h_11_RPC_WRAPPERS
#define ARPG_Source_ARPG_MapTile_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define ARPG_Source_ARPG_MapTile_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMapTile(); \
	friend ARPG_API class UClass* Z_Construct_UClass_AMapTile(); \
public: \
	DECLARE_CLASS(AMapTile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(AMapTile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_MapTile_h_11_INCLASS \
private: \
	static void StaticRegisterNativesAMapTile(); \
	friend ARPG_API class UClass* Z_Construct_UClass_AMapTile(); \
public: \
	DECLARE_CLASS(AMapTile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(AMapTile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_MapTile_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMapTile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMapTile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMapTile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMapTile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMapTile(AMapTile&&); \
	NO_API AMapTile(const AMapTile&); \
public:


#define ARPG_Source_ARPG_MapTile_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMapTile(AMapTile&&); \
	NO_API AMapTile(const AMapTile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMapTile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMapTile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMapTile)


#define ARPG_Source_ARPG_MapTile_h_11_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__gameManComp() { return STRUCT_OFFSET(AMapTile, gameManComp); } \
	FORCEINLINE static uint32 __PPO__Sprite() { return STRUCT_OFFSET(AMapTile, Sprite); } \
	FORCEINLINE static uint32 __PPO__DynamicSprite() { return STRUCT_OFFSET(AMapTile, DynamicSprite); } \
	FORCEINLINE static uint32 __PPO__IsBlocked() { return STRUCT_OFFSET(AMapTile, IsBlocked); } \
	FORCEINLINE static uint32 __PPO__IsTrigger() { return STRUCT_OFFSET(AMapTile, IsTrigger); } \
	FORCEINLINE static uint32 __PPO__TriggerCommand() { return STRUCT_OFFSET(AMapTile, TriggerCommand); }


#define ARPG_Source_ARPG_MapTile_h_8_PROLOG
#define ARPG_Source_ARPG_MapTile_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_MapTile_h_11_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_MapTile_h_11_RPC_WRAPPERS \
	ARPG_Source_ARPG_MapTile_h_11_INCLASS \
	ARPG_Source_ARPG_MapTile_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ARPG_Source_ARPG_MapTile_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_MapTile_h_11_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_MapTile_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	ARPG_Source_ARPG_MapTile_h_11_INCLASS_NO_PURE_DECLS \
	ARPG_Source_ARPG_MapTile_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ARPG_Source_ARPG_MapTile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
