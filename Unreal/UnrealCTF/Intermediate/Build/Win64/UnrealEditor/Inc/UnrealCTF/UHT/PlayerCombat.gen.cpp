// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealCTF/Public/PlayerCombat.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerCombat() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	UNREALCTF_API UClass* Z_Construct_UClass_UPlayerCombat();
	UNREALCTF_API UClass* Z_Construct_UClass_UPlayerCombat_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealCTF();
// End Cross Module References
	DEFINE_FUNCTION(UPlayerCombat::execShoot)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Shoot();
		P_NATIVE_END;
	}
	void UPlayerCombat::StaticRegisterNativesUPlayerCombat()
	{
		UClass* Class = UPlayerCombat::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Shoot", &UPlayerCombat::execShoot },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPlayerCombat_Shoot_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPlayerCombat_Shoot_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PlayerCombat.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayerCombat_Shoot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPlayerCombat, nullptr, "Shoot", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerCombat_Shoot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPlayerCombat_Shoot_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPlayerCombat_Shoot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPlayerCombat_Shoot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPlayerCombat);
	UClass* Z_Construct_UClass_UPlayerCombat_NoRegister()
	{
		return UPlayerCombat::StaticClass();
	}
	struct Z_Construct_UClass_UPlayerCombat_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IAShoot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IAShoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IAGrenade_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IAGrenade;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MySceneComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MySceneComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GrenadePrefab_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_GrenadePrefab;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPlayerCombat_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealCTF,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCombat_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPlayerCombat_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPlayerCombat_Shoot, "Shoot" }, // 1767024903
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCombat_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerCombat_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "PlayerCombat.h" },
		{ "ModuleRelativePath", "Public/PlayerCombat.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerCombat_Statics::NewProp_IAShoot_MetaData[] = {
		{ "Category", "Inputs" },
		{ "ModuleRelativePath", "Public/PlayerCombat.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayerCombat_Statics::NewProp_IAShoot = { "IAShoot", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerCombat, IAShoot), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCombat_Statics::NewProp_IAShoot_MetaData), Z_Construct_UClass_UPlayerCombat_Statics::NewProp_IAShoot_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerCombat_Statics::NewProp_IAGrenade_MetaData[] = {
		{ "Category", "Inputs" },
		{ "ModuleRelativePath", "Public/PlayerCombat.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayerCombat_Statics::NewProp_IAGrenade = { "IAGrenade", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerCombat, IAGrenade), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCombat_Statics::NewProp_IAGrenade_MetaData), Z_Construct_UClass_UPlayerCombat_Statics::NewProp_IAGrenade_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerCombat_Statics::NewProp_MySceneComponent_MetaData[] = {
		{ "Category", "PlayerCombat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PlayerCombat.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPlayerCombat_Statics::NewProp_MySceneComponent = { "MySceneComponent", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerCombat, MySceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCombat_Statics::NewProp_MySceneComponent_MetaData), Z_Construct_UClass_UPlayerCombat_Statics::NewProp_MySceneComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerCombat_Statics::NewProp_GrenadePrefab_MetaData[] = {
		{ "Category", "Prefabs" },
		{ "ModuleRelativePath", "Public/PlayerCombat.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UPlayerCombat_Statics::NewProp_GrenadePrefab = { "GrenadePrefab", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPlayerCombat, GrenadePrefab), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCombat_Statics::NewProp_GrenadePrefab_MetaData), Z_Construct_UClass_UPlayerCombat_Statics::NewProp_GrenadePrefab_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlayerCombat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerCombat_Statics::NewProp_IAShoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerCombat_Statics::NewProp_IAGrenade,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerCombat_Statics::NewProp_MySceneComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerCombat_Statics::NewProp_GrenadePrefab,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPlayerCombat_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayerCombat>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPlayerCombat_Statics::ClassParams = {
		&UPlayerCombat::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPlayerCombat_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCombat_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCombat_Statics::Class_MetaDataParams), Z_Construct_UClass_UPlayerCombat_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerCombat_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPlayerCombat()
	{
		if (!Z_Registration_Info_UClass_UPlayerCombat.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPlayerCombat.OuterSingleton, Z_Construct_UClass_UPlayerCombat_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPlayerCombat.OuterSingleton;
	}
	template<> UNREALCTF_API UClass* StaticClass<UPlayerCombat>()
	{
		return UPlayerCombat::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayerCombat);
	UPlayerCombat::~UPlayerCombat() {}
	struct Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPlayerCombat, UPlayerCombat::StaticClass, TEXT("UPlayerCombat"), &Z_Registration_Info_UClass_UPlayerCombat, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPlayerCombat), 4109881244U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_2991820596(TEXT("/Script/UnrealCTF"),
		Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_PlayerCombat_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
