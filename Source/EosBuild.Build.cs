// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EosBuild : ModuleRules
{
	public EosBuild(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicIncludePaths.Add("../../../Engine/Source/Runtime/Launch/Public");

		PrivateIncludePaths.Add("../../../Engine/Source/Runtime/Launch/Public");
		PrivateIncludePaths.Add("../../../Engine/Source/Runtime/Launch/Private");		// For LaunchEngineLoop.cpp include

		PrivateDependencyModuleNames.Add("Core");
		PrivateDependencyModuleNames.Add("Projects");
		
		//bEnableExceptions = true;

		UnsafeTypeCastWarningLevel = WarningLevel.Warning;
	}
}
