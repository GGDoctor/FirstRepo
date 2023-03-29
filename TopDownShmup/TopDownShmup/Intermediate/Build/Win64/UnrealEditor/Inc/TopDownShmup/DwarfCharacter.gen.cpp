// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TopDownShmup/DwarfCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDwarfCharacter() {}
// Cross Module References
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_ADwarfCharacter_NoRegister();
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_ADwarfCharacter();
	TOPDOWNSHMUP_API UClass* Z_Construct_UClass_AEnemyCharacter();
	UPackage* Z_Construct_UPackage__Script_TopDownShmup();
// End Cross Module References
	void ADwarfCharacter::StaticRegisterNativesADwarfCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADwarfCharacter);
	UClass* Z_Construct_UClass_ADwarfCharacter_NoRegister()
	{
		return ADwarfCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ADwarfCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADwarfCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemyCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_TopDownShmup,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADwarfCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "DwarfCharacter.h" },
		{ "ModuleRelativePath", "DwarfCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADwarfCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADwarfCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADwarfCharacter_Statics::ClassParams = {
		&ADwarfCharacter::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADwarfCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADwarfCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADwarfCharacter()
	{
		if (!Z_Registration_Info_UClass_ADwarfCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADwarfCharacter.OuterSingleton, Z_Construct_UClass_ADwarfCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADwarfCharacter.OuterSingleton;
	}
	template<> TOPDOWNSHMUP_API UClass* StaticClass<ADwarfCharacter>()
	{
		return ADwarfCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADwarfCharacter);
	struct Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_DwarfCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_DwarfCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADwarfCharacter, ADwarfCharacter::StaticClass, TEXT("ADwarfCharacter"), &Z_Registration_Info_UClass_ADwarfCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADwarfCharacter), 2548368558U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_DwarfCharacter_h_2807785184(TEXT("/Script/TopDownShmup"),
		Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_DwarfCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TopDownShmup_Source_TopDownShmup_DwarfCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
