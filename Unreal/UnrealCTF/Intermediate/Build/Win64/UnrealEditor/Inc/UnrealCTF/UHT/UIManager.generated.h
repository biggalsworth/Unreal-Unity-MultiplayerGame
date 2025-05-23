// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UIManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCTF_UIManager_generated_h
#error "UIManager.generated.h already included, missing '#pragma once' in UIManager.h"
#endif
#define UNREALCTF_UIManager_generated_h

#define FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_18_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FClientStats_Statics; \
	UNREALCTF_API static class UScriptStruct* StaticStruct();


template<> UNREALCTF_API UScriptStruct* StaticStruct<struct FClientStats>();

#define FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_SPARSE_DATA
#define FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateText);


#define FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAUIManager(); \
	friend struct Z_Construct_UClass_AUIManager_Statics; \
public: \
	DECLARE_CLASS(AUIManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealCTF"), NO_API) \
	DECLARE_SERIALIZER(AUIManager)


#define FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AUIManager(AUIManager&&); \
	NO_API AUIManager(const AUIManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUIManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUIManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AUIManager) \
	NO_API virtual ~AUIManager();


#define FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_51_PROLOG
#define FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_SPARSE_DATA \
	FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_INCLASS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_54_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCTF_API UClass* StaticClass<class AUIManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
