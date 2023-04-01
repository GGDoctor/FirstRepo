// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TopDownShmup/AIEnemyController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAIEnemyController() {}
// Cross Module References
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_AAIEnemyController_NoRegister();
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_AAIEnemyController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_TopDownShmup();
// End Cross Module References
	void AAIEnemyController::StaticRegisterNativesAAIEnemyController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAIEnemyController);
	UClass* Z_Construct_UClass_AAIEnemyController_NoRegister()
	{
		return AAIEnemyController::StaticClass();
	}
	struct Z_Construct_UClass_AAIEnemyController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAIEnemyController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_TopDownShmup,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAIEnemyController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AIEnemyController.h" },
		{ "ModuleRelativePath", "AIEnemyController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAIEnemyController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAIEnemyController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAIEnemyController_Statics::ClassParams = {
		&AAIEnemyController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAIEnemyController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAIEnemyController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAIEnemyController()
	{
		if (!Z_Registration_Info_UClass_AAIEnemyController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAIEnemyController.OuterSingleton, Z_Construct_UClass_AAIEnemyController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAIEnemyController.OuterSingleton;
	}
	template<> TOPDOWNSHMUP_API UClass* StaticClass<AAIEnemyController>()
	{
		return AAIEnemyController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAIEnemyController);
	struct Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AIEnemyController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AIEnemyController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAIEnemyController, AAIEnemyController::StaticClass, TEXT("AAIEnemyController"), &Z_Registration_Info_UClass_AAIEnemyController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAIEnemyController), 3782642811U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AIEnemyController_h_3843499029(TEXT("/Script/TopDownShmup"),
		Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AIEnemyController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_AIEnemyController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
