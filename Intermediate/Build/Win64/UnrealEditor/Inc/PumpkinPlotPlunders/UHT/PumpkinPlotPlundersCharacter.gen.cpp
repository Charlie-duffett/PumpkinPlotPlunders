// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PumpkinPlotPlunders/PumpkinPlotPlundersCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePumpkinPlotPlundersCharacter() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	PUMPKINPLOTPLUNDERS_API UClass* Z_Construct_UClass_APumpkinPlotPlundersCharacter();
	PUMPKINPLOTPLUNDERS_API UClass* Z_Construct_UClass_APumpkinPlotPlundersCharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PumpkinPlotPlunders();
// End Cross Module References
	void APumpkinPlotPlundersCharacter::StaticRegisterNativesAPumpkinPlotPlundersCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APumpkinPlotPlundersCharacter);
	UClass* Z_Construct_UClass_APumpkinPlotPlundersCharacter_NoRegister()
	{
		return APumpkinPlotPlundersCharacter::StaticClass();
	}
	struct Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_PumpkinPlotPlunders,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PumpkinPlotPlundersCharacter.h" },
		{ "ModuleRelativePath", "PumpkinPlotPlundersCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PumpkinPlotPlundersCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinPlotPlundersCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_CameraBoom_MetaData), Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_CameraBoom_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Follow camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PumpkinPlotPlundersCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Follow camera" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinPlotPlundersCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_FollowCamera_MetaData), Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_FollowCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** MappingContext */" },
#endif
		{ "ModuleRelativePath", "PumpkinPlotPlundersCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MappingContext" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinPlotPlundersCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_DefaultMappingContext_MetaData), Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_DefaultMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump Input Action */" },
#endif
		{ "ModuleRelativePath", "PumpkinPlotPlundersCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinPlotPlundersCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move Input Action */" },
#endif
		{ "ModuleRelativePath", "PumpkinPlotPlundersCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinPlotPlundersCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_MoveAction_MetaData), Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_MoveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Input Action */" },
#endif
		{ "ModuleRelativePath", "PumpkinPlotPlundersCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinPlotPlundersCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_LookAction_MetaData), Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_LookAction_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::NewProp_LookAction,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APumpkinPlotPlundersCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::ClassParams = {
		&APumpkinPlotPlundersCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_APumpkinPlotPlundersCharacter()
	{
		if (!Z_Registration_Info_UClass_APumpkinPlotPlundersCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APumpkinPlotPlundersCharacter.OuterSingleton, Z_Construct_UClass_APumpkinPlotPlundersCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APumpkinPlotPlundersCharacter.OuterSingleton;
	}
	template<> PUMPKINPLOTPLUNDERS_API UClass* StaticClass<APumpkinPlotPlundersCharacter>()
	{
		return APumpkinPlotPlundersCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APumpkinPlotPlundersCharacter);
	APumpkinPlotPlundersCharacter::~APumpkinPlotPlundersCharacter() {}
	struct Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinPlotPlundersCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinPlotPlundersCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APumpkinPlotPlundersCharacter, APumpkinPlotPlundersCharacter::StaticClass, TEXT("APumpkinPlotPlundersCharacter"), &Z_Registration_Info_UClass_APumpkinPlotPlundersCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APumpkinPlotPlundersCharacter), 383736130U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinPlotPlundersCharacter_h_2787412623(TEXT("/Script/PumpkinPlotPlunders"),
		Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinPlotPlundersCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinPlotPlundersCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
