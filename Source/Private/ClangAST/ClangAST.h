
#pragma once

#include "CoreMinimal.h"
#include "Json.h"

class FClangAST {
public:
	FClangAST(TSharedPtr<FJsonObject> Root): Root(Root){}
	virtual ~FClangAST() {}

	static TSharedPtr<FClangAST> Deserialize(const FString& AstPath);

	const TArray<TSharedPtr<FJsonValue>>* Inner();

public:
	TSharedPtr<FJsonObject> Root;
};

