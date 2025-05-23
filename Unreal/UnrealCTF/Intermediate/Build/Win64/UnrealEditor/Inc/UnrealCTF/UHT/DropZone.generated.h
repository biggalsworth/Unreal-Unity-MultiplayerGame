// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DropZone.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef UNREALCTF_DropZone_generated_h
#error "DropZone.generated.h already included, missing '#pragma once' in DropZone.h"
#endif
#define UNREALCTF_DropZone_generated_h

#define FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_SPARSE_DATA
#define FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDropZone(); \
	friend struct Z_Construct_UClass_UDropZone_Statics; \
public: \
	DECLARE_CLASS(UDropZone, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealCTF"), NO_API) \
	DECLARE_SERIALIZER(UDropZone)


#define FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDropZone(UDropZone&&); \
	NO_API UDropZone(const UDropZone&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDropZone); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDropZone); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDropZone) \
	NO_API virtual ~UDropZone();


#define FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_13_PROLOG
#define FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_SPARSE_DATA \
	FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_INCLASS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCTF_API UClass* StaticClass<class UDropZone>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealCTF_Source_UnrealCTF_Public_DropZone_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
