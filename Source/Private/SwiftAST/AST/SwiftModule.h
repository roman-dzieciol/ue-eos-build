
#pragma once

#include "CoreMinimal.h"
#include "AST/SwiftDecl.h"

class FSwiftModule : public FSwiftDecl {
public:
	FSwiftModule(
		FString Name,
		TSet<FString> Attributes,
		TArray<TSharedPtr<FSwiftAST>> Inner
	)
		: FSwiftDecl(Name, Attributes, Inner)
	{
	}

	virtual ~FSwiftModule() override {}


public:
};
