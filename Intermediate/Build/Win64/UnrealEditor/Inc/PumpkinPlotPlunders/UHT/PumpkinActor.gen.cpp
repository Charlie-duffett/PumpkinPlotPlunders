// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PumpkinPlotPlunders/PumpkinActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePumpkinActor() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	PUMPKINPLOTPLUNDERS_API UClass* Z_Construct_UClass_APumpkinActor();
	PUMPKINPLOTPLUNDERS_API UClass* Z_Construct_UClass_APumpkinActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_PumpkinPlotPlunders();
// End Cross Module References
	DEFINE_FUNCTION(APumpkinActor::execUpdatePumpkinTransform)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdatePumpkinTransform();
		P_NATIVE_END;
	}
	void APumpkinActor::StaticRegisterNativesAPumpkinActor()
	{
		UClass* Class = APumpkinActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdatePumpkinTransform", &APumpkinActor::execUpdatePumpkinTransform },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APumpkinActor_UpdatePumpkinTransform_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APumpkinActor_UpdatePumpkinTransform_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// When pumpkin Evil state is changed in editor set the location and rotation variables\n" },
#endif
		{ "ModuleRelativePath", "PumpkinActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When pumpkin Evil state is changed in editor set the location and rotation variables" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APumpkinActor_UpdatePumpkinTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APumpkinActor, nullptr, "UpdatePumpkinTransform", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APumpkinActor_UpdatePumpkinTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_APumpkinActor_UpdatePumpkinTransform_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_APumpkinActor_UpdatePumpkinTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APumpkinActor_UpdatePumpkinTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APumpkinActor);
	UClass* Z_Construct_UClass_APumpkinActor_NoRegister()
	{
		return APumpkinActor::StaticClass();
	}
	struct Z_Construct_UClass_APumpkinActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PumpkinStaticMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PumpkinStaticMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsEnemyTeam_MetaData[];
#endif
		static void NewProp_bIsEnemyTeam_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsEnemyTeam;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnemyPumpkinLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EnemyPumpkinLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnemyPumpkinRotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EnemyPumpkinRotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlliedPumpkinLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AlliedPumpkinLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlliedPumpkinRotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AlliedPumpkinRotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APumpkinActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_PumpkinPlotPlunders,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_APumpkinActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APumpkinActor_UpdatePumpkinTransform, "UpdatePumpkinTransform" }, // 1017539432
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PumpkinActor.h" },
		{ "ModuleRelativePath", "PumpkinActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinActor_Statics::NewProp_PumpkinStaticMeshComponent_MetaData[] = {
		{ "Category", "PumpkinActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PumpkinActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APumpkinActor_Statics::NewProp_PumpkinStaticMeshComponent = { "PumpkinStaticMeshComponent", nullptr, (EPropertyFlags)0x001000000009000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinActor, PumpkinStaticMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::NewProp_PumpkinStaticMeshComponent_MetaData), Z_Construct_UClass_APumpkinActor_Statics::NewProp_PumpkinStaticMeshComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinActor_Statics::NewProp_bIsEnemyTeam_MetaData[] = {
		{ "Category", "PumpkinSettings" },
		{ "ModuleRelativePath", "PumpkinActor.h" },
	};
#endif
	void Z_Construct_UClass_APumpkinActor_Statics::NewProp_bIsEnemyTeam_SetBit(void* Obj)
	{
		((APumpkinActor*)Obj)->bIsEnemyTeam = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APumpkinActor_Statics::NewProp_bIsEnemyTeam = { "bIsEnemyTeam", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APumpkinActor), &Z_Construct_UClass_APumpkinActor_Statics::NewProp_bIsEnemyTeam_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::NewProp_bIsEnemyTeam_MetaData), Z_Construct_UClass_APumpkinActor_Statics::NewProp_bIsEnemyTeam_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinActor_Statics::NewProp_EnemyPumpkinLocation_MetaData[] = {
		{ "Category", "PumpkinSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Location and rotation of pumpkin when it is on the Enemy Team\n" },
#endif
		{ "ModuleRelativePath", "PumpkinActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Location and rotation of pumpkin when it is on the Enemy Team" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APumpkinActor_Statics::NewProp_EnemyPumpkinLocation = { "EnemyPumpkinLocation", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinActor, EnemyPumpkinLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::NewProp_EnemyPumpkinLocation_MetaData), Z_Construct_UClass_APumpkinActor_Statics::NewProp_EnemyPumpkinLocation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinActor_Statics::NewProp_EnemyPumpkinRotation_MetaData[] = {
		{ "Category", "PumpkinSettings" },
		{ "ModuleRelativePath", "PumpkinActor.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APumpkinActor_Statics::NewProp_EnemyPumpkinRotation = { "EnemyPumpkinRotation", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinActor, EnemyPumpkinRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::NewProp_EnemyPumpkinRotation_MetaData), Z_Construct_UClass_APumpkinActor_Statics::NewProp_EnemyPumpkinRotation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinActor_Statics::NewProp_AlliedPumpkinLocation_MetaData[] = {
		{ "Category", "PumpkinSettings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Location and rotation of pumpkin when it is on the Allied Team\n" },
#endif
		{ "ModuleRelativePath", "PumpkinActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Location and rotation of pumpkin when it is on the Allied Team" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APumpkinActor_Statics::NewProp_AlliedPumpkinLocation = { "AlliedPumpkinLocation", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinActor, AlliedPumpkinLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::NewProp_AlliedPumpkinLocation_MetaData), Z_Construct_UClass_APumpkinActor_Statics::NewProp_AlliedPumpkinLocation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APumpkinActor_Statics::NewProp_AlliedPumpkinRotation_MetaData[] = {
		{ "Category", "PumpkinSettings" },
		{ "ModuleRelativePath", "PumpkinActor.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APumpkinActor_Statics::NewProp_AlliedPumpkinRotation = { "AlliedPumpkinRotation", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APumpkinActor, AlliedPumpkinRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::NewProp_AlliedPumpkinRotation_MetaData), Z_Construct_UClass_APumpkinActor_Statics::NewProp_AlliedPumpkinRotation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APumpkinActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinActor_Statics::NewProp_PumpkinStaticMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinActor_Statics::NewProp_bIsEnemyTeam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinActor_Statics::NewProp_EnemyPumpkinLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinActor_Statics::NewProp_EnemyPumpkinRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinActor_Statics::NewProp_AlliedPumpkinLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APumpkinActor_Statics::NewProp_AlliedPumpkinRotation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APumpkinActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APumpkinActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APumpkinActor_Statics::ClassParams = {
		&APumpkinActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APumpkinActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::Class_MetaDataParams), Z_Construct_UClass_APumpkinActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APumpkinActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_APumpkinActor()
	{
		if (!Z_Registration_Info_UClass_APumpkinActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APumpkinActor.OuterSingleton, Z_Construct_UClass_APumpkinActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APumpkinActor.OuterSingleton;
	}
	template<> PUMPKINPLOTPLUNDERS_API UClass* StaticClass<APumpkinActor>()
	{
		return APumpkinActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APumpkinActor);
	APumpkinActor::~APumpkinActor() {}
	struct Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APumpkinActor, APumpkinActor::StaticClass, TEXT("APumpkinActor"), &Z_Registration_Info_UClass_APumpkinActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APumpkinActor), 1180479756U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinActor_h_1669447211(TEXT("/Script/PumpkinPlotPlunders"),
		Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_charlie_Documents_SkillChallenge_PumpkinPlotPlunders_Source_PumpkinPlotPlunders_PumpkinActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
