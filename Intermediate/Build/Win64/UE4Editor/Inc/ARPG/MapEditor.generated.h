// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARPG_MapEditor_generated_h
#error "MapEditor.generated.h already included, missing '#pragma once' in MapEditor.h"
#endif
#define ARPG_MapEditor_generated_h

#define ARPG_Source_ARPG_MapEditor_h_14_GENERATED_BODY \
	friend ARPG_API class UScriptStruct* Z_Construct_UScriptStruct_FTileSetTile(); \
	ARPG_API static class UScriptStruct* StaticStruct();


#define ARPG_Source_ARPG_MapEditor_h_37_RPC_WRAPPERS
#define ARPG_Source_ARPG_MapEditor_h_37_RPC_WRAPPERS_NO_PURE_DECLS
#define ARPG_Source_ARPG_MapEditor_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMapEditor(); \
	friend ARPG_API class UClass* Z_Construct_UClass_UMapEditor(); \
public: \
	DECLARE_CLASS(UMapEditor, USceneComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(UMapEditor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_MapEditor_h_37_INCLASS \
private: \
	static void StaticRegisterNativesUMapEditor(); \
	friend ARPG_API class UClass* Z_Construct_UClass_UMapEditor(); \
public: \
	DECLARE_CLASS(UMapEditor, USceneComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(UMapEditor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ARPG_Source_ARPG_MapEditor_h_37_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMapEditor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMapEditor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMapEditor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMapEditor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMapEditor(UMapEditor&&); \
	NO_API UMapEditor(const UMapEditor&); \
public:


#define ARPG_Source_ARPG_MapEditor_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMapEditor(UMapEditor&&); \
	NO_API UMapEditor(const UMapEditor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMapEditor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMapEditor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMapEditor)


#define ARPG_Source_ARPG_MapEditor_h_37_PRIVATE_PROPERTY_OFFSET
#define ARPG_Source_ARPG_MapEditor_h_34_PROLOG
#define ARPG_Source_ARPG_MapEditor_h_37_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_MapEditor_h_37_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_MapEditor_h_37_RPC_WRAPPERS \
	ARPG_Source_ARPG_MapEditor_h_37_INCLASS \
	ARPG_Source_ARPG_MapEditor_h_37_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ARPG_Source_ARPG_MapEditor_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_MapEditor_h_37_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_MapEditor_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	ARPG_Source_ARPG_MapEditor_h_37_INCLASS_NO_PURE_DECLS \
	ARPG_Source_ARPG_MapEditor_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ARPG_Source_ARPG_MapEditor_h


#define FOREACH_ENUM_EEDITORMODE(op) \
	op(SelectTile) \
	op(ChangeTile) \
	op(DeleteTile) \
	op(MoveCamera) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
