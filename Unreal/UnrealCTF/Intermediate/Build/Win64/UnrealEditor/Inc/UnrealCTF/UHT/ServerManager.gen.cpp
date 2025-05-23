// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealCTF/Public/ServerManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeServerManager() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UNREALCTF_API UClass* Z_Construct_UClass_AServerManager();
	UNREALCTF_API UClass* Z_Construct_UClass_AServerManager_NoRegister();
	UNREALCTF_API UEnum* Z_Construct_UEnum_UnrealCTF_ObjTypes();
	UPackage* Z_Construct_UPackage__Script_UnrealCTF();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ObjTypes;
	static UEnum* ObjTypes_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ObjTypes.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ObjTypes.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_UnrealCTF_ObjTypes, (UObject*)Z_Construct_UPackage__Script_UnrealCTF(), TEXT("ObjTypes"));
		}
		return Z_Registration_Info_UEnum_ObjTypes.OuterSingleton;
	}
	template<> UNREALCTF_API UEnum* StaticEnum<ObjTypes>()
	{
		return ObjTypes_StaticEnum();
	}
	struct Z_Construct_UEnum_UnrealCTF_ObjTypes_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_UnrealCTF_ObjTypes_Statics::Enumerators[] = {
		{ "ObjTypes::bubble", (int64)ObjTypes::bubble },
		{ "ObjTypes::grenade", (int64)ObjTypes::grenade },
		{ "ObjTypes::H_Pickup", (int64)ObjTypes::H_Pickup },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_UnrealCTF_ObjTypes_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "bubble.DisplayName", "bubble" },
		{ "bubble.Name", "ObjTypes::bubble" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Allows the enum to be used in Blueprints\n// Use uint8 for memory efficiency\n" },
#endif
		{ "grenade.DisplayName", "grenade" },
		{ "grenade.Name", "ObjTypes::grenade" },
		{ "H_Pickup.DisplayName", "H_Pickup" },
		{ "H_Pickup.Name", "ObjTypes::H_Pickup" },
		{ "ModuleRelativePath", "Public/ServerManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allows the enum to be used in Blueprints\nUse uint8 for memory efficiency" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_UnrealCTF_ObjTypes_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_UnrealCTF,
		nullptr,
		"ObjTypes",
		"ObjTypes",
		Z_Construct_UEnum_UnrealCTF_ObjTypes_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_UnrealCTF_ObjTypes_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_UnrealCTF_ObjTypes_Statics::Enum_MetaDataParams), Z_Construct_UEnum_UnrealCTF_ObjTypes_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_UnrealCTF_ObjTypes()
	{
		if (!Z_Registration_Info_UEnum_ObjTypes.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ObjTypes.InnerSingleton, Z_Construct_UEnum_UnrealCTF_ObjTypes_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ObjTypes.InnerSingleton;
	}
	void AServerManager::StaticRegisterNativesAServerManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AServerManager);
	UClass* Z_Construct_UClass_AServerManager_NoRegister()
	{
		return AServerManager::StaticClass();
	}
	struct Z_Construct_UClass_AServerManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ObjectPrefabs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectPrefabs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ObjectPrefabs;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AServerManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealCTF,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AServerManager_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AServerManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ServerManager.h" },
		{ "ModuleRelativePath", "Public/ServerManager.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AServerManager_Statics::NewProp_ObjectPrefabs_Inner = { "ObjectPrefabs", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AServerManager_Statics::NewProp_ObjectPrefabs_MetaData[] = {
		{ "Category", "Assets" },
		{ "ModuleRelativePath", "Public/ServerManager.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AServerManager_Statics::NewProp_ObjectPrefabs = { "ObjectPrefabs", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AServerManager, ObjectPrefabs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AServerManager_Statics::NewProp_ObjectPrefabs_MetaData), Z_Construct_UClass_AServerManager_Statics::NewProp_ObjectPrefabs_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AServerManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AServerManager_Statics::NewProp_ObjectPrefabs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AServerManager_Statics::NewProp_ObjectPrefabs,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AServerManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AServerManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AServerManager_Statics::ClassParams = {
		&AServerManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AServerManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AServerManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AServerManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AServerManager_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AServerManager_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AServerManager()
	{
		if (!Z_Registration_Info_UClass_AServerManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AServerManager.OuterSingleton, Z_Construct_UClass_AServerManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AServerManager.OuterSingleton;
	}
	template<> UNREALCTF_API UClass* StaticClass<AServerManager>()
	{
		return AServerManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AServerManager);
	AServerManager::~AServerManager() {}
	struct Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_Statics::EnumInfo[] = {
		{ ObjTypes_StaticEnum, TEXT("ObjTypes"), &Z_Registration_Info_UEnum_ObjTypes, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 562922801U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AServerManager, AServerManager::StaticClass, TEXT("AServerManager"), &Z_Registration_Info_UClass_AServerManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AServerManager), 1781598767U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_1098123550(TEXT("/Script/UnrealCTF"),
		Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ServerManager_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
