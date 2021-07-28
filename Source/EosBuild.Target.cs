// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Desktop)]
public class EosBuildTarget : TargetRules
{
	public EosBuildTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Program;
		LinkType = TargetLinkType.Monolithic;
		LaunchModuleName = "EosBuild";
		DefaultBuildSettings = BuildSettingsVersion.V2;

		// Lean and mean
		bBuildDeveloperTools = false;

		// Never use malloc profiling in Unreal Header Tool.  We set this because often UHT is compiled right before the engine
		// automatically by Unreal Build Tool, but if bUseMallocProfiler is defined, UHT can operate incorrectly.
		bUseMallocProfiler = false;

		// Editor-only data, however, is needed
		bBuildWithEditorOnlyData = true;

		// Currently this app is not linking against the engine, so we'll compile out references from Core to the rest of the engine
		bCompileAgainstEngine = false;
		bCompileAgainstCoreUObject = false;
		bCompileAgainstApplicationCore = false;
		
		// Logs are still useful to print the results
		bUseLoggingInShipping = true;
		
		bUseChecksInShipping = true;

		// UnrealHeaderTool is a console application, not a Windows app (sets entry point to main(), instead of WinMain())
		bIsBuildingConsoleApplication = true;
		
		bHasExports = false;
		bWithServerCode = false;
		bCompileICU = false;
		
		// Force exception handling across all modules.
		//bForceEnableExceptions = true;
		
        GlobalDefinitions.Add("USE_LOCALIZED_PACKAGE_CACHE=0");
		GlobalDefinitions.Add("STATS=0");

		// We disable compilation of GC related code since it takes a very long time (up to 30 seconds on typical hardware at the time of writing)
		GlobalDefinitions.Add("UE_WITH_GC=0");
		GlobalDefinitions.Add("UE_WITH_SAVEPACKAGE=0");
		GlobalDefinitions.Add("UE_WITH_CORE_REDIRECTS=0");
		
		GlobalDefinitions.Add("ALLOW_LOG_FILE=0");
	}
}
