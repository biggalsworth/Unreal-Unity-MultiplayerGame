// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealCTF/UnrealCTFGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealCTFGameMode() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UNREALCTF_API UClass* Z_Construct_UClass_AUnrealCTFGameMode();
	UNREALCTF_API UClass* Z_Construct_UClass_AUnrealCTFGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealCTF();
// End Cross Module References
	void AUnrealCTFGameMode::StaticRegisterNativesAUnrealCTFGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUnrealCTFGameMode);
	UClass* Z_Construct_UClass_AUnrealCTFGameMode_NoRegister()
	{
		return AUnrealCTFGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AUnrealCTFGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUnrealCTFGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealCTF,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealCTFGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnrealCTFGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "UnrealCTFGameMode.h" },
		{ "ModuleRelativePath", "UnrealCTFGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnrealCTFGameMode_Statics::NewProp_PlayerClass_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "UnrealCTFGameMode.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AUnrealCTFGameMode_Statics::NewProp_PlayerClass = { "PlayerClass", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnrealCTFGameMode, PlayerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealCTFGameMode_Statics::NewProp_PlayerClass_MetaData), Z_Construct_UClass_AUnrealCTFGameMode_Statics::NewProp_PlayerClass_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AUnrealCTFGameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnrealCTFGameMode_Statics::NewProp_PlayerClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUnrealCTFGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnrealCTFGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AUnrealCTFGameMode_Statics::ClassParams = {
		&AUnrealCTFGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AUnrealCTFGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealCTFGameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealCTFGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AUnrealCTFGameMode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealCTFGameMode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AUnrealCTFGameMode()
	{
		if (!Z_Registration_Info_UClass_AUnrealCTFGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUnrealCTFGameMode.OuterSingleton, Z_Construct_UClass_AUnrealCTFGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AUnrealCTFGameMode.OuterSingleton;
	}
	template<> UNREALCTF_API UClass* StaticClass<AUnrealCTFGameMode>()
	{
		return AUnrealCTFGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUnrealCTFGameMode);
	AUnrealCTFGameMode::~AUnrealCTFGameMode() {}
	struct Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_UnrealCTFGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_UnrealCTFGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AUnrealCTFGameMode, AUnrealCTFGameMode::StaticClass, TEXT("AUnrealCTFGameMode"), &Z_Registration_Info_UClass_AUnrealCTFGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUnrealCTFGameMode), 958573188U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_UnrealCTFGameMode_h_4168990015(TEXT("/Script/UnrealCTF"),
		Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_UnrealCTFGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_UnrealCTFGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
