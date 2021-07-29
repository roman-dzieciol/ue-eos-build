
#include "ClangAST.h"
#include "EosBuild.h"


TSharedPtr<FClangAST> FClangAST::Deserialize(const FString& AstPath)
{
	FString JsonString;
	check(FFileHelper::LoadFileToString(JsonString, *AstPath));

	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(JsonString);
	TSharedPtr<FJsonObject> Root = MakeShared<FJsonObject>();
	checkf(FJsonSerializer::Deserialize(Reader, Root),
		TEXT("Failed to parse '%s'. Errors: %s"), *AstPath, *Reader->GetErrorMessage());

	return MakeShared<FClangAST>(Root);
}


const TArray<TSharedPtr<FJsonValue>>* FClangAST::Inner() {

	const TArray<TSharedPtr<FJsonValue>>* Inner;

	if (Root->TryGetArrayField(TEXT("inner"), Inner))
	{
		return Inner;
	}
	else
	{
		return nullptr;
	}
}
