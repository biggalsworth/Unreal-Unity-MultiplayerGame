// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FlagScript.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef UNREALCTF_FlagScript_generated_h
#error "FlagScript.generated.h already included, missing '#pragma once' in FlagScript.h"
#endif
#define UNREALCTF_FlagScript_generated_h

#define FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_SPARSE_DATA
#define FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFlagScript(); \
	friend struct Z_Construct_UClass_UFlagScript_Statics; \
public: \
	DECLARE_CLASS(UFlagScript, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealCTF"), NO_API) \
	DECLARE_SERIALIZER(UFlagScript)


#define FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlagScript(UFlagScript&&); \
	NO_API UFlagScript(const UFlagScript&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlagScript); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlagScript); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UFlagScript) \
	NO_API virtual ~UFlagScript();


#define FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_12_PROLOG
#define FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_SPARSE_DATA \
	FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCTF_API UClass* StaticClass<class UFlagScript>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealCTF_Source_UnrealCTF_Public_FlagScript_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
