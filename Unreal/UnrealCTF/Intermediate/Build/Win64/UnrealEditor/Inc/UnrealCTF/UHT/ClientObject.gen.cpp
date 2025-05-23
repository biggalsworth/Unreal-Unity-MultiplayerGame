// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealCTF/Public/ClientObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClientObject() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UNREALCTF_API UClass* Z_Construct_UClass_UClientObject();
	UNREALCTF_API UClass* Z_Construct_UClass_UClientObject_NoRegister();
	UNREALCTF_API UEnum* Z_Construct_UEnum_UnrealCTF_ObjTypes();
	UPackage* Z_Construct_UPackage__Script_UnrealCTF();
// End Cross Module References
	void UClientObject::StaticRegisterNativesUClientObject()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UClientObject);
	UClass* Z_Construct_UClass_UClientObject_NoRegister()
	{
		return UClientObject::StaticClass();
	}
	struct Z_Construct_UClass_UClientObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_type_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_type_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_type;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsLocal_MetaData[];
#endif
		static void NewProp_IsLocal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsLocal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_LocalID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlobalID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_GlobalID;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UClientObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealCTF,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClientObject_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UClientObject_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "ClientObject.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ClientObject.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UClientObject_Statics::NewProp_type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UClientObject_Statics::NewProp_type_MetaData[] = {
		{ "Category", "Type Settings" },
		{ "ModuleRelativePath", "Public/ClientObject.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UClientObject_Statics::NewProp_type = { "type", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UClientObject, type), Z_Construct_UEnum_UnrealCTF_ObjTypes, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClientObject_Statics::NewProp_type_MetaData), Z_Construct_UClass_UClientObject_Statics::NewProp_type_MetaData) }; // 562922801
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UClientObject_Statics::NewProp_IsLocal_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Public/ClientObject.h" },
	};
#endif
	void Z_Construct_UClass_UClientObject_Statics::NewProp_IsLocal_SetBit(void* Obj)
	{
		((UClientObject*)Obj)->IsLocal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UClientObject_Statics::NewProp_IsLocal = { "IsLocal", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UClientObject), &Z_Construct_UClass_UClientObject_Statics::NewProp_IsLocal_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClientObject_Statics::NewProp_IsLocal_MetaData), Z_Construct_UClass_UClientObject_Statics::NewProp_IsLocal_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UClientObject_Statics::NewProp_LocalID_MetaData[] = {
		{ "Category", "ClientObject" },
		{ "ModuleRelativePath", "Public/ClientObject.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UClientObject_Statics::NewProp_LocalID = { "LocalID", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UClientObject, LocalID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClientObject_Statics::NewProp_LocalID_MetaData), Z_Construct_UClass_UClientObject_Statics::NewProp_LocalID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UClientObject_Statics::NewProp_GlobalID_MetaData[] = {
		{ "Category", "ClientObject" },
		{ "ModuleRelativePath", "Public/ClientObject.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UClientObject_Statics::NewProp_GlobalID = { "GlobalID", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UClientObject, GlobalID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClientObject_Statics::NewProp_GlobalID_MetaData), Z_Construct_UClass_UClientObject_Statics::NewProp_GlobalID_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UClientObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClientObject_Statics::NewProp_type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClientObject_Statics::NewProp_type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClientObject_Statics::NewProp_IsLocal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClientObject_Statics::NewProp_LocalID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClientObject_Statics::NewProp_GlobalID,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UClientObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UClientObject>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UClientObject_Statics::ClassParams = {
		&UClientObject::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UClientObject_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UClientObject_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClientObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UClientObject_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClientObject_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UClientObject()
	{
		if (!Z_Registration_Info_UClass_UClientObject.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UClientObject.OuterSingleton, Z_Construct_UClass_UClientObject_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UClientObject.OuterSingleton;
	}
	template<> UNREALCTF_API UClass* StaticClass<UClientObject>()
	{
		return UClientObject::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UClientObject);
	UClientObject::~UClientObject() {}
	struct Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ClientObject_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ClientObject_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UClientObject, UClientObject::StaticClass, TEXT("UClientObject"), &Z_Registration_Info_UClass_UClientObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UClientObject), 1989574406U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ClientObject_h_2466404276(TEXT("/Script/UnrealCTF"),
		Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ClientObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_ClientObject_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
