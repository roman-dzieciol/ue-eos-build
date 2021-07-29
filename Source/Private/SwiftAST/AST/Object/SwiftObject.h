
#pragma once

#include "CoreMinimal.h"
#include "AST/SwiftDecl.h"


class FSwiftObject : public FSwiftDecl {
public:
	FSwiftObject(
		FString Name,
		TSet<FString> Attributes,
		TArray<TSharedPtr<FSwiftAST>> Inner,
		ESwiftTag TagName,
		TArray<FString> SuperTypes
	)
		: FSwiftDecl(Name, Attributes, Inner)
		, TagName(TagName)
		, SuperTypes(SuperTypes)
	{
	}

	virtual ~FSwiftObject() override {}


public:
	ESwiftTag TagName;
	TArray<FString> SuperTypes;
};
