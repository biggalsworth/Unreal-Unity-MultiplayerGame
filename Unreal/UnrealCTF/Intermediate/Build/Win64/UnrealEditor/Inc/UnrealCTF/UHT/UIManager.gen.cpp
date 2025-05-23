// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealCTF/Public/UIManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUIManager() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UNREALCTF_API UClass* Z_Construct_UClass_AUIManager();
	UNREALCTF_API UClass* Z_Construct_UClass_AUIManager_NoRegister();
	UNREALCTF_API UScriptStruct* Z_Construct_UScriptStruct_FClientStats();
	UPackage* Z_Construct_UPackage__Script_UnrealCTF();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ClientStats;
class UScriptStruct* FClientStats::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ClientStats.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ClientStats.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClientStats, (UObject*)Z_Construct_UPackage__Script_UnrealCTF(), TEXT("ClientStats"));
	}
	return Z_Registration_Info_UScriptStruct_ClientStats.OuterSingleton;
}
template<> UNREALCTF_API UScriptStruct* StaticStruct<FClientStats>()
{
	return FClientStats::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FClientStats_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Player_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Player;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Kills_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Kills;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Deaths_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Deaths;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Ping_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Ping;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FClientStats_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/UIManager.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FClientStats_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClientStats>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Player_MetaData[] = {
		{ "Category", "Player Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Properties\n" },
#endif
		{ "ModuleRelativePath", "Public/UIManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Properties" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClientStats, Player), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Player_MetaData), Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Player_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Kills_MetaData[] = {
		{ "Category", "Player Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Use AActor* to represent a player object in Unreal\n" },
#endif
		{ "ModuleRelativePath", "Public/UIManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Use AActor* to represent a player object in Unreal" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Kills = { "Kills", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClientStats, Kills), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Kills_MetaData), Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Kills_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Deaths_MetaData[] = {
		{ "Category", "Player Stats" },
		{ "ModuleRelativePath", "Public/UIManager.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Deaths = { "Deaths", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClientStats, Deaths), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Deaths_MetaData), Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Deaths_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Ping_MetaData[] = {
		{ "Category", "Player Stats" },
		{ "ModuleRelativePath", "Public/UIManager.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Ping = { "Ping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClientStats, Ping), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Ping_MetaData), Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Ping_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClientStats_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Player,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Kills,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Deaths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClientStats_Statics::NewProp_Ping,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClientStats_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealCTF,
		nullptr,
		&NewStructOps,
		"ClientStats",
		Z_Construct_UScriptStruct_FClientStats_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClientStats_Statics::PropPointers),
		sizeof(FClientStats),
		alignof(FClientStats),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClientStats_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClientStats_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClientStats_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FClientStats()
	{
		if (!Z_Registration_Info_UScriptStruct_ClientStats.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ClientStats.InnerSingleton, Z_Construct_UScriptStruct_FClientStats_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ClientStats.InnerSingleton;
	}
	DEFINE_FUNCTION(AUIManager::execUpdateText)
	{
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_NewText);
		P_GET_PROPERTY(FIntProperty,Z_Param_team);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateText(Z_Param_Out_NewText,Z_Param_team);
		P_NATIVE_END;
	}
	void AUIManager::StaticRegisterNativesAUIManager()
	{
		UClass* Class = AUIManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateText", &AUIManager::execUpdateText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AUIManager_UpdateText_Statics
	{
		struct UIManager_eventUpdateText_Parms
		{
			FText NewText;
			int32 team;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewText_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_NewText;
		static const UECodeGen_Private::FIntPropertyParams NewProp_team;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AUIManager_UpdateText_Statics::NewProp_NewText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_AUIManager_UpdateText_Statics::NewProp_NewText = { "NewText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIManager_eventUpdateText_Parms, NewText), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AUIManager_UpdateText_Statics::NewProp_NewText_MetaData), Z_Construct_UFunction_AUIManager_UpdateText_Statics::NewProp_NewText_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AUIManager_UpdateText_Statics::NewProp_team = { "team", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIManager_eventUpdateText_Parms, team), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AUIManager_UpdateText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUIManager_UpdateText_Statics::NewProp_NewText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUIManager_UpdateText_Statics::NewProp_team,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AUIManager_UpdateText_Statics::Function_MetaDataParams[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/UIManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AUIManager_UpdateText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUIManager, nullptr, "UpdateText", nullptr, nullptr, Z_Construct_UFunction_AUIManager_UpdateText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AUIManager_UpdateText_Statics::PropPointers), sizeof(Z_Construct_UFunction_AUIManager_UpdateText_Statics::UIManager_eventUpdateText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AUIManager_UpdateText_Statics::Function_MetaDataParams), Z_Construct_UFunction_AUIManager_UpdateText_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AUIManager_UpdateText_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AUIManager_UpdateText_Statics::UIManager_eventUpdateText_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AUIManager_UpdateText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AUIManager_UpdateText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUIManager);
	UClass* Z_Construct_UClass_AUIManager_NoRegister()
	{
		return AUIManager::StaticClass();
	}
	struct Z_Construct_UClass_AUIManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WidgetClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_WidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerLayout_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerLayout;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CreatedWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CreatedWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IALeaderboard_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IALeaderboard;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TextToDisplay_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_TextToDisplay;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUIManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealCTF,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUIManager_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AUIManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AUIManager_UpdateText, "UpdateText" }, // 2237161259
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUIManager_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUIManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UIManager.h" },
		{ "ModuleRelativePath", "Public/UIManager.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUIManager_Statics::NewProp_WidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/UIManager.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AUIManager_Statics::NewProp_WidgetClass = { "WidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUIManager, WidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUIManager_Statics::NewProp_WidgetClass_MetaData), Z_Construct_UClass_AUIManager_Statics::NewProp_WidgetClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUIManager_Statics::NewProp_PlayerLayout_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/UIManager.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AUIManager_Statics::NewProp_PlayerLayout = { "PlayerLayout", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUIManager, PlayerLayout), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUIManager_Statics::NewProp_PlayerLayout_MetaData), Z_Construct_UClass_AUIManager_Statics::NewProp_PlayerLayout_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUIManager_Statics::NewProp_CreatedWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UIManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUIManager_Statics::NewProp_CreatedWidget = { "CreatedWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUIManager, CreatedWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUIManager_Statics::NewProp_CreatedWidget_MetaData), Z_Construct_UClass_AUIManager_Statics::NewProp_CreatedWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUIManager_Statics::NewProp_IALeaderboard_MetaData[] = {
		{ "Category", "Leaderboard" },
		{ "ModuleRelativePath", "Public/UIManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUIManager_Statics::NewProp_IALeaderboard = { "IALeaderboard", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUIManager, IALeaderboard), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUIManager_Statics::NewProp_IALeaderboard_MetaData), Z_Construct_UClass_AUIManager_Statics::NewProp_IALeaderboard_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUIManager_Statics::NewProp_TextToDisplay_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/UIManager.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_AUIManager_Statics::NewProp_TextToDisplay = { "TextToDisplay", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUIManager, TextToDisplay), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUIManager_Statics::NewProp_TextToDisplay_MetaData), Z_Construct_UClass_AUIManager_Statics::NewProp_TextToDisplay_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AUIManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUIManager_Statics::NewProp_WidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUIManager_Statics::NewProp_PlayerLayout,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUIManager_Statics::NewProp_CreatedWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUIManager_Statics::NewProp_IALeaderboard,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUIManager_Statics::NewProp_TextToDisplay,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUIManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUIManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AUIManager_Statics::ClassParams = {
		&AUIManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AUIManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AUIManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUIManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AUIManager_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUIManager_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AUIManager()
	{
		if (!Z_Registration_Info_UClass_AUIManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUIManager.OuterSingleton, Z_Construct_UClass_AUIManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AUIManager.OuterSingleton;
	}
	template<> UNREALCTF_API UClass* StaticClass<AUIManager>()
	{
		return AUIManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUIManager);
	AUIManager::~AUIManager() {}
	struct Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_Statics::ScriptStructInfo[] = {
		{ FClientStats::StaticStruct, Z_Construct_UScriptStruct_FClientStats_Statics::NewStructOps, TEXT("ClientStats"), &Z_Registration_Info_UScriptStruct_ClientStats, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClientStats), 2838796020U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AUIManager, AUIManager::StaticClass, TEXT("AUIManager"), &Z_Registration_Info_UClass_AUIManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUIManager), 2798788892U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_1650325643(TEXT("/Script/UnrealCTF"),
		Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealCTF_Source_UnrealCTF_Public_UIManager_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
