// Copyright Epic Games, Inc. All Rights Reserved.

#include "EosBuild.h"
#include "RequiredProgramMainCPPInclude.h"

#include "ClangAST/ClangAST.h"

DEFINE_LOG_CATEGORY(LogEosBuild);

IMPLEMENT_APPLICATION(EosBuild, "EosBuild");

INT32_MAIN_INT32_ARGC_TCHAR_ARGV()
{
	GEngineLoop.PreInit(ArgC, ArgV);
	UE_LOG(LogEosBuild, Display, TEXT("Hello Eos"));
	
	FString OutputDir;
	check(FParse::Value(FCommandLine::Get(), TEXT("-output="), OutputDir));
	UE_LOG(LogEosBuild, Display, TEXT("OutputDir: %s"), *OutputDir);

	FString AstPath = OutputDir / TEXT("Temp") / TEXT("EOS-SDK-IOS-16697186-v1.13") / TEXT("AST") / TEXT("EOSSDK.ast.json");
	UE_LOG(LogEosBuild, Display, TEXT("AstPath: %s"), *AstPath);
	check(IFileManager::Get().FileExists(*AstPath));

	TSharedPtr<FClangAST> ClangAST = FClangAST::Deserialize(AstPath);
	
	for (const TSharedPtr<FJsonValue>& Value : *ClangAST->Inner()) 
	{
		const TSharedPtr<FJsonObject>& InnerObject = Value->AsObject();

		FString Name;
		if (InnerObject->TryGetStringField(TEXT("name"), Name)) {
			UE_LOG(LogEosBuild, Display, TEXT("name: %s"), *Name);

		}
	}


	UE_LOG(LogEosBuild, Display, TEXT("success"));
	return 0;
}
