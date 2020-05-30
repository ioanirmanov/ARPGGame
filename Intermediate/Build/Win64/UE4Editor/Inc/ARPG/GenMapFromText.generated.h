// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARPG_GenMapFromText_generated_h
#error "GenMapFromText.generated.h already included, missing '#pragma once' in GenMapFromText.h"
#endif
#define ARPG_GenMapFromText_generated_h

#define ARPG_Source_ARPG_GenMapFromText_h_17_RPC_WRAPPERS
#define ARPG_Source_ARPG_GenMapFromText_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define ARPG_Source_ARPG_GenMapFromText_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenMapFromText(); \
	friend ARPG_API class UClass* Z_Construct_UClass_UGenMapFromText(); \
public: \
	DECLARE_CLASS(UGenMapFromText, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(UGenMapFromText) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_GenMapFromText_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUGenMapFromText(); \
	friend ARPG_API class UClass* Z_Construct_UClass_UGenMapFromText(); \
public: \
	DECLARE_CLASS(UGenMapFromText, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(UGenMapFromText) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_GenMapFromText_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGenMapFromText(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenMapFromText) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGenMapFromText); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenMapFromText); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGenMapFromText(UGenMapFromText&&); \
	NO_API UGenMapFromText(const UGenMapFromText&); \
public:


#define ARPG_Source_ARPG_GenMapFromText_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGenMapFromText(UGenMapFromText&&); \
	NO_API UGenMapFromText(const UGenMapFromText&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGenMapFromText); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenMapFromText); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenMapFromText)


#define ARPG_Source_ARPG_GenMapFromText_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__UniversalTileSet() { return STRUCT_OFFSET(UGenMapFromText, UniversalTileSet); } \
	FORCEINLINE static uint32 __PPO__TileSet() { return STRUCT_OFFSET(UGenMapFromText, TileSet); } \
	FORCEINLINE static uint32 __PPO__ObjectSet() { return STRUCT_OFFSET(UGenMapFromText, ObjectSet); } \
	FORCEINLINE static uint32 __PPO__Tiles() { return STRUCT_OFFSET(UGenMapFromText, Tiles); } \
	FORCEINLINE static uint32 __PPO__Objects() { return STRUCT_OFFSET(UGenMapFromText, Objects); } \
	FORCEINLINE static uint32 __PPO__NPCMap() { return STRUCT_OFFSET(UGenMapFromText, NPCMap); } \
	FORCEINLINE static uint32 __PPO__MapName() { return STRUCT_OFFSET(UGenMapFromText, MapName); }


#define ARPG_Source_ARPG_GenMapFromText_h_14_PROLOG
#define ARPG_Source_ARPG_GenMapFromText_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_GenMapFromText_h_17_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_GenMapFromText_h_17_RPC_WRAPPERS \
	ARPG_Source_ARPG_GenMapFromText_h_17_INCLASS \
	ARPG_Source_ARPG_GenMapFromText_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ARPG_Source_ARPG_GenMapFromText_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_GenMapFromText_h_17_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_GenMapFromText_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	ARPG_Source_ARPG_GenMapFromText_h_17_INCLASS_NO_PURE_DECLS \
	ARPG_Source_ARPG_GenMapFromText_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ARPG_Source_ARPG_GenMapFromText_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
