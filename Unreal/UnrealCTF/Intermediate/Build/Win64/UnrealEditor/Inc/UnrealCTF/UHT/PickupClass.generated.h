// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PickupClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef UNREALCTF_PickupClass_generated_h
#error "PickupClass.generated.h already included, missing '#pragma once' in PickupClass.h"
#endif
#define UNREALCTF_PickupClass_generated_h

#define FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_SPARSE_DATA
#define FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPickupClass(); \
	friend struct Z_Construct_UClass_UPickupClass_Statics; \
public: \
	DECLARE_CLASS(UPickupClass, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealCTF"), NO_API) \
	DECLARE_SERIALIZER(UPickupClass)


#define FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPickupClass(UPickupClass&&); \
	NO_API UPickupClass(const UPickupClass&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPickupClass); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPickupClass); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPickupClass) \
	NO_API virtual ~UPickupClass();


#define FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_11_PROLOG
#define FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_SPARSE_DATA \
	FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_INCLASS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCTF_API UClass* StaticClass<class UPickupClass>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealCTF_Source_UnrealCTF_Public_PickupClass_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
