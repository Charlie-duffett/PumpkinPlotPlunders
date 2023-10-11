// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PumpkinPlotPlunders/PumpkinPlotPlundersGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePumpkinPlotPlundersGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	PUMPKINPLOTPLUNDERS_API UClass* Z_Construct_UClass_APumpkinPlotPlundersGameMode();
	PUMPKINPLOTPLUNDERS_API UClass* Z_Construct_UClass_APumpkinPlotPlundersGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PumpkinPlotPlunders();
// End Cross Module References
	void APumpkinPlotPlundersGameMode::StaticRegisterNativesAPumpkinPlotPlundersGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APumpkinPlotPlundersGameMode);
	UClass* Z_Construct_UClass_APumpkinPlotPlundersGameMode_NoRegister()
	{
		return APumpkinPlotPlundersGameMode::StaticClass();
	}
	struct Z_Construct_UClass_APumpkinPlotPlundersGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APumpkinPlotPlundersGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_PumpkinPlotPlunders,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinPlotPlundersGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PumpkinPlotPlundersGameMode.h" },
		{ "ModuleRelativePath", "PumpkinPlotPlundersGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APumpkinPlotPlundersGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APumpkinPlotPlundersGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APumpkinPlotPlundersGameMode_Statics::ClassParams = {
		&APumpkinPlotPlundersGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_APumpkinPlotPlundersGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_APumpkinPlotPlundersGameMode()
	{
		if (!Z_Registration_Info_UClass_APumpkinPlotPlundersGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APumpkinPlotPlundersGameMode.OuterSingleton, Z_Construct_UClass_APumpkinPlotPlundersGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APumpkinPlotPlundersGameMode.OuterSingleton;
	}
	template<> PUMPKINPLOTPLUNDERS_API UClass* StaticClass<APumpkinPlotPlundersGameMode>()
	{
		return APumpkinPlotPlundersGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APumpkinPlotPlundersGameMode);
	APumpkinPlotPlundersGameMode::~APumpkinPlotPlundersGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinPlotPlundersGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinPlotPlundersGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APumpkinPlotPlundersGameMode, APumpkinPlotPlundersGameMode::StaticClass, TEXT("APumpkinPlotPlundersGameMode"), &Z_Registration_Info_UClass_APumpkinPlotPlundersGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APumpkinPlotPlundersGameMode), 3290679344U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinPlotPlundersGameMode_h_4239822087(TEXT("/Script/PumpkinPlotPlunders"),
		Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinPlotPlundersGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinPlotPlundersGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
