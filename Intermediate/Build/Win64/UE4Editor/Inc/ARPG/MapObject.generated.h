// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARPG_MapObject_generated_h
#error "MapObject.generated.h already included, missing '#pragma once' in MapObject.h"
#endif
#define ARPG_MapObject_generated_h

#define ARPG_Source_ARPG_MapObject_h_42_GENERATED_BODY \
	friend ARPG_API class UScriptStruct* Z_Construct_UScriptStruct_FnumRow(); \
	ARPG_API static class UScriptStruct* StaticStruct();


#define ARPG_Source_ARPG_MapObject_h_23_GENERATED_BODY \
	friend ARPG_API class UScriptStruct* Z_Construct_UScriptStruct_FTileProp(); \
	ARPG_API static class UScriptStruct* StaticStruct();


#define ARPG_Source_ARPG_MapObject_h_15_GENERATED_BODY \
	friend ARPG_API class UScriptStruct* Z_Construct_UScriptStruct_FRow(); \
	ARPG_API static class UScriptStruct* StaticStruct();


#define ARPG_Source_ARPG_MapObject_h_51_RPC_WRAPPERS
#define ARPG_Source_ARPG_MapObject_h_51_RPC_WRAPPERS_NO_PURE_DECLS
#define ARPG_Source_ARPG_MapObject_h_51_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMapObject(); \
	friend ARPG_API class UClass* Z_Construct_UClass_AMapObject(); \
public: \
	DECLARE_CLASS(AMapObject, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(AMapObject) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_MapObject_h_51_INCLASS \
private: \
	static void StaticRegisterNativesAMapObject(); \
	friend ARPG_API class UClass* Z_Construct_UClass_AMapObject(); \
public: \
	DECLARE_CLASS(AMapObject, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(AMapObject) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_MapObject_h_51_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMapObject(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMapObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMapObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMapObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMapObject(AMapObject&&); \
	NO_API AMapObject(const AMapObject&); \
public:


#define ARPG_Source_ARPG_MapObject_h_51_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMapObject(AMapObject&&); \
	NO_API AMapObject(const AMapObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMapObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMapObject); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMapObject)


#define ARPG_Source_ARPG_MapObject_h_51_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TileSet() { return STRUCT_OFFSET(AMapObject, TileSet); } \
	FORCEINLINE static uint32 __PPO__GenerateMapFromText() { return STRUCT_OFFSET(AMapObject, GenerateMapFromText); } \
	FORCEINLINE static uint32 __PPO__Generator() { return STRUCT_OFFSET(AMapObject, Generator); } \
	FORCEINLINE static uint32 __PPO__ObjectTileSet() { return STRUCT_OFFSET(AMapObject, ObjectTileSet); } \
	FORCEINLINE static uint32 __PPO__gameManComp() { return STRUCT_OFFSET(AMapObject, gameManComp); } \
	FORCEINLINE static uint32 __PPO__Tiles() { return STRUCT_OFFSET(AMapObject, Tiles); } \
	FORCEINLINE static uint32 __PPO__TilesMap() { return STRUCT_OFFSET(AMapObject, TilesMap); } \
	FORCEINLINE static uint32 __PPO__Objects() { return STRUCT_OFFSET(AMapObject, Objects); } \
	FORCEINLINE static uint32 __PPO__ObjectsMap() { return STRUCT_OFFSET(AMapObject, ObjectsMap); }


#define ARPG_Source_ARPG_MapObject_h_48_PROLOG
#define ARPG_Source_ARPG_MapObject_h_51_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_MapObject_h_51_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_MapObject_h_51_RPC_WRAPPERS \
	ARPG_Source_ARPG_MapObject_h_51_INCLASS \
	ARPG_Source_ARPG_MapObject_h_51_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ARPG_Source_ARPG_MapObject_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_MapObject_h_51_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_MapObject_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	ARPG_Source_ARPG_MapObject_h_51_INCLASS_NO_PURE_DECLS \
	ARPG_Source_ARPG_MapObject_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ARPG_Source_ARPG_MapObject_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
