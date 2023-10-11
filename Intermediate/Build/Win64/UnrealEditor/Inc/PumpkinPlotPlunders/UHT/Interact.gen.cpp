// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PumpkinPlotPlunders/Interfaces/Interact.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteract() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	PUMPKINPLOTPLUNDERS_API UClass* Z_Construct_UClass_UInteract();
	PUMPKINPLOTPLUNDERS_API UClass* Z_Construct_UClass_UInteract_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PumpkinPlotPlunders();
// End Cross Module References
	void UInteract::StaticRegisterNativesUInteract()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInteract);
	UClass* Z_Construct_UClass_UInteract_NoRegister()
	{
		return UInteract::StaticClass();
	}
	struct Z_Construct_UClass_UInteract_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInteract_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_PumpkinPlotPlunders,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInteract_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteract_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Interfaces/Interact.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInteract_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInteract>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInteract_Statics::ClassParams = {
		&UInteract::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInteract_Statics::Class_MetaDataParams), Z_Construct_UClass_UInteract_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInteract()
	{
		if (!Z_Registration_Info_UClass_UInteract.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInteract.OuterSingleton, Z_Construct_UClass_UInteract_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInteract.OuterSingleton;
	}
	template<> PUMPKINPLOTPLUNDERS_API UClass* StaticClass<UInteract>()
	{
		return UInteract::StaticClass();
	}
	UInteract::UInteract(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInteract);
	UInteract::~UInteract() {}
	struct Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_Interfaces_Interact_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_Interfaces_Interact_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInteract, UInteract::StaticClass, TEXT("UInteract"), &Z_Registration_Info_UClass_UInteract, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInteract), 3133360785U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_Interfaces_Interact_h_1785441601(TEXT("/Script/PumpkinPlotPlunders"),
		Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_Interfaces_Interact_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_Interfaces_Interact_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
