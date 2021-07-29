
#pragma once

#include "CoreMinimal.h"
#include "AST/SwiftTypeDecl.h"
#include "AST/Type/SwiftType.h"

class FSwiftVarDecl : public FSwiftTypeDecl {
public:
	FSwiftVarDecl(
		FString Name,
		TSet<FString> Attributes,
		TArray<TSharedPtr<FSwiftAST>> Inner,
		TSharedRef<FSwiftType> Type,
		bool isMutable
	)
		: FSwiftTypeDecl(Name, Attributes, Inner, Type)
		, isMutable(isMutable)
	{
	}

	virtual ~FSwiftVarDecl() override {}


public:
	bool isMutable;
};
