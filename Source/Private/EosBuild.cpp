// Copyright Epic Games, Inc. All Rights Reserved.

#include "EosBuild.h"
#include "RequiredProgramMainCPPInclude.h"

DEFINE_LOG_CATEGORY_STATIC(LogEosBuild, Log, All);

IMPLEMENT_APPLICATION(EosBuild, "EosBuild");

INT32_MAIN_INT32_ARGC_TCHAR_ARGV()
{
	GEngineLoop.PreInit(ArgC, ArgV);
	UE_LOG(LogEosBuild, Display, TEXT("Hello Eos"));
	return 0;
}
