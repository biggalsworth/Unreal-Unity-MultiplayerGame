// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlayerCombat.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCTF_PlayerCombat_generated_h
#error "PlayerCombat.generated.h already included, missing '#pragma once' in PlayerCombat.h"
#endif
#define UNREALCTF_PlayerCombat_generated_h

#define FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_SPARSE_DATA
#define FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execShoot);


#define FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlayerCombat(); \
	friend struct Z_Construct_UClass_UPlayerCombat_Statics; \
public: \
	DECLARE_CLASS(UPlayerCombat, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealCTF"), NO_API) \
	DECLARE_SERIALIZER(UPlayerCombat)


#define FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPlayerCombat(UPlayerCombat&&); \
	NO_API UPlayerCombat(const UPlayerCombat&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlayerCombat); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlayerCombat); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPlayerCombat) \
	NO_API virtual ~UPlayerCombat();


#define FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_16_PROLOG
#define FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_SPARSE_DATA \
	FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_INCLASS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCTF_API UClass* StaticClass<class UPlayerCombat>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
