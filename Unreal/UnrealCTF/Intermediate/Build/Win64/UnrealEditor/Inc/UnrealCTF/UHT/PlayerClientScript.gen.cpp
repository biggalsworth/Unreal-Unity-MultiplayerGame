// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealCTF/Public/PlayerClientScript.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerClientScript() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	UNREALCTF_API UClass* Z_Construct_UClass_UPlayerClientScript();
	UNREALCTF_API UClass* Z_Construct_UClass_UPlayerClientScript_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealCTF();
// End Cross Module References
	void UPlayerClientScript::StaticRegisterNativesUPlayerClientScript()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPlayerClientScript);
	UClass* Z_Construct_UClass_UPlayerClientScript_NoRegister()
	{
		return UPlayerClientScript::StaticClass();
	}
	struct Z_Construct_UClass_UPlayerClientScript_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_LocalID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isLocal_MetaData[];
#endif
		static void NewProp_isLocal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isLocal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_team_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_team;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CarryPos_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CarryPos;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_health_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_health;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_kills_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_kills;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_deaths_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_deaths;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPlayerClientScript_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealCTF,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerClientScript_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "PlayerClientScript.h" },
		{ "ModuleRelativePath", "Public/PlayerClientScript.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_ID_MetaData[] = {
		{ "Category", "PlayerClientScript" },
		{ "ModuleRelativePath", "Public/PlayerClientScript.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerClientScript, ID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_ID_MetaData), Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_ID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_LocalID_MetaData[] = {
		{ "Category", "PlayerClientScript" },
		{ "ModuleRelativePath", "Public/PlayerClientScript.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_LocalID = { "LocalID", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerClientScript, LocalID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_LocalID_MetaData), Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_LocalID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_isLocal_MetaData[] = {
		{ "Category", "PlayerClientScript" },
		{ "ModuleRelativePath", "Public/PlayerClientScript.h" },
	};
#endif
	void Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_isLocal_SetBit(void* Obj)
	{
		((UPlayerClientScript*)Obj)->isLocal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_isLocal = { "isLocal", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPlayerClientScript), &Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_isLocal_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_isLocal_MetaData), Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_isLocal_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_team_MetaData[] = {
		{ "Category", "PlayerClientScript" },
		{ "ModuleRelativePath", "Public/PlayerClientScript.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_team = { "team", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerClientScript, team), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_team_MetaData), Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_team_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_CarryPos_MetaData[] = {
		{ "Category", "PlayerClientScript" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PlayerClientScript.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_CarryPos = { "CarryPos", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerClientScript, CarryPos), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_CarryPos_MetaData), Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_CarryPos_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_health_MetaData[] = {
		{ "Category", "PlayerClientScript" },
		{ "ModuleRelativePath", "Public/PlayerClientScript.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_health = { "health", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerClientScript, health), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_health_MetaData), Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_health_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_kills_MetaData[] = {
		{ "Category", "PlayerClientScript" },
		{ "ModuleRelativePath", "Public/PlayerClientScript.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_kills = { "kills", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerClientScript, kills), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_kills_MetaData), Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_kills_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_deaths_MetaData[] = {
		{ "Category", "PlayerClientScript" },
		{ "ModuleRelativePath", "Public/PlayerClientScript.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_deaths = { "deaths", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerClientScript, deaths), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_deaths_MetaData), Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_deaths_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlayerClientScript_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_ID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_LocalID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_isLocal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_team,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_CarryPos,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_health,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_kills,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerClientScript_Statics::NewProp_deaths,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPlayerClientScript_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayerClientScript>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlayerClientScript_Statics::ClassParams = {
		&UPlayerClientScript::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPlayerClientScript_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlayerClientScript_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerClientScript_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPlayerClientScript()
	{
		if (!Z_Registration_Info_UClass_UPlayerClientScript.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlayerClientScript.OuterSingleton, Z_Construct_UClass_UPlayerClientScript_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPlayerClientScript.OuterSingleton;
	}
	template<> UNREALCTF_API UClass* StaticClass<UPlayerClientScript>()
	{
		return UPlayerClientScript::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayerClientScript);
	UPlayerClientScript::~UPlayerClientScript() {}
	struct Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerClientScript_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerClientScript_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPlayerClientScript, UPlayerClientScript::StaticClass, TEXT("UPlayerClientScript"), &Z_Registration_Info_UClass_UPlayerClientScript, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlayerClientScript), 647823404U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerClientScript_h_1970764636(TEXT("/Script/UnrealCTF"),
		Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerClientScript_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerClientScript_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
