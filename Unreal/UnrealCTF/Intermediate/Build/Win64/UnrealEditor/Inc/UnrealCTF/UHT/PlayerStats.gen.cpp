// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealCTF/Public/PlayerStats.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerStats() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UNREALCTF_API UClass* Z_Construct_UClass_UPlayerStats();
	UNREALCTF_API UClass* Z_Construct_UClass_UPlayerStats_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealCTF();
// End Cross Module References
	void UPlayerStats::StaticRegisterNativesUPlayerStats()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPlayerStats);
	UClass* Z_Construct_UClass_UPlayerStats_NoRegister()
	{
		return UPlayerStats::StaticClass();
	}
	struct Z_Construct_UClass_UPlayerStats_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_health_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_health;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPlayerStats_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealCTF,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerStats_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerStats_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "PlayerStats.h" },
		{ "ModuleRelativePath", "Public/PlayerStats.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerStats_Statics::NewProp_health_MetaData[] = {
		{ "Category", "PlayerStats" },
		{ "ModuleRelativePath", "Public/PlayerStats.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPlayerStats_Statics::NewProp_health = { "health", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerStats, health), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerStats_Statics::NewProp_health_MetaData), Z_Construct_UClass_UPlayerStats_Statics::NewProp_health_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlayerStats_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerStats_Statics::NewProp_health,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPlayerStats_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayerStats>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlayerStats_Statics::ClassParams = {
		&UPlayerStats::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPlayerStats_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerStats_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerStats_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlayerStats_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerStats_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPlayerStats()
	{
		if (!Z_Registration_Info_UClass_UPlayerStats.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlayerStats.OuterSingleton, Z_Construct_UClass_UPlayerStats_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPlayerStats.OuterSingleton;
	}
	template<> UNREALCTF_API UClass* StaticClass<UPlayerStats>()
	{
		return UPlayerStats::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayerStats);
	UPlayerStats::~UPlayerStats() {}
	struct Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerStats_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerStats_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPlayerStats, UPlayerStats::StaticClass, TEXT("UPlayerStats"), &Z_Registration_Info_UClass_UPlayerStats, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlayerStats), 4283269338U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerStats_h_3318953707(TEXT("/Script/UnrealCTF"),
		Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerStats_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerStats_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
