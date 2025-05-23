// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ServerManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCTF_ServerManager_generated_h
#error "ServerManager.generated.h already included, missing '#pragma once' in ServerManager.h"
#endif
#define UNREALCTF_ServerManager_generated_h

#define FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_SPARSE_DATA
#define FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_ACCESSORS
#define FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAServerManager(); \
	friend struct Z_Construct_UClass_AServerManager_Statics; \
public: \
	DECLARE_CLASS(AServerManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealCTF"), NO_API) \
	DECLARE_SERIALIZER(AServerManager)


#define FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AServerManager(AServerManager&&); \
	NO_API AServerManager(const AServerManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AServerManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AServerManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AServerManager) \
	NO_API virtual ~AServerManager();


#define FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_24_PROLOG
#define FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_SPARSE_DATA \
	FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_ACCESSORS \
	FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_INCLASS_NO_PURE_DECLS \
	FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCTF_API UClass* StaticClass<class AServerManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h


#define FOREACH_ENUM_OBJTYPES(op) \
	op(ObjTypes::bubble) \
	op(ObjTypes::grenade) \
	op(ObjTypes::H_Pickup) 

enum class ObjTypes : uint8;
template<> struct TIsUEnumClass<ObjTypes> { enum { Value = true }; };
template<> UNREALCTF_API UEnum* StaticEnum<ObjTypes>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
