// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealCTF/Public/GrenadeScript.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGrenadeScript() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
	UNREALCTF_API UClass* Z_Construct_UClass_UGrenadeScript();
	UNREALCTF_API UClass* Z_Construct_UClass_UGrenadeScript_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealCTF();
// End Cross Module References
	void UGrenadeScript::StaticRegisterNativesUGrenadeScript()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGrenadeScript);
	UClass* Z_Construct_UClass_UGrenadeScript_NoRegister()
	{
		return UGrenadeScript::StaticClass();
	}
	struct Z_Construct_UClass_UGrenadeScript_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraEffect_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NiagaraEffect;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGrenadeScript_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealCTF,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGrenadeScript_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGrenadeScript_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "GrenadeScript.h" },
		{ "ModuleRelativePath", "Public/GrenadeScript.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGrenadeScript_Statics::NewProp_NiagaraEffect_MetaData[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Public/GrenadeScript.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGrenadeScript_Statics::NewProp_NiagaraEffect = { "NiagaraEffect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGrenadeScript, NiagaraEffect), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGrenadeScript_Statics::NewProp_NiagaraEffect_MetaData), Z_Construct_UClass_UGrenadeScript_Statics::NewProp_NiagaraEffect_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGrenadeScript_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGrenadeScript_Statics::NewProp_NiagaraEffect,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGrenadeScript_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGrenadeScript>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGrenadeScript_Statics::ClassParams = {
		&UGrenadeScript::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGrenadeScript_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGrenadeScript_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGrenadeScript_Statics::Class_MetaDataParams), Z_Construct_UClass_UGrenadeScript_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGrenadeScript_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UGrenadeScript()
	{
		if (!Z_Registration_Info_UClass_UGrenadeScript.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGrenadeScript.OuterSingleton, Z_Construct_UClass_UGrenadeScript_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGrenadeScript.OuterSingleton;
	}
	template<> UNREALCTF_API UClass* StaticClass<UGrenadeScript>()
	{
		return UGrenadeScript::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGrenadeScript);
	UGrenadeScript::~UGrenadeScript() {}
	struct Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_GrenadeScript_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_GrenadeScript_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGrenadeScript, UGrenadeScript::StaticClass, TEXT("UGrenadeScript"), &Z_Registration_Info_UClass_UGrenadeScript, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGrenadeScript), 1908989932U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_GrenadeScript_h_3261139239(TEXT("/Script/UnrealCTF"),
		Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_GrenadeScript_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_GrenadeScript_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
