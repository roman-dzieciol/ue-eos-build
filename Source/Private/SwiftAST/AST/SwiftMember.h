
#pragma once

#include "CoreMinimal.h"
#include "AST/SwiftVarDecl.h"
#include "AST/Type/SwiftType.h"
#include "AST/Expr/SwiftExpr.h"

class FSwiftMember : public FSwiftVarDecl {
public:
	FSwiftMember(
		FString Name,
		TSet<FString> Attributes,
		TArray<TSharedPtr<FSwiftAST>> Inner,
		TSharedRef<FSwiftType> Type,
		bool isMutable,
		TSharedPtr<FSwiftExpr> Getter
	)
		: FSwiftVarDecl(Name, Attributes, Inner, Type, isMutable)
		, Getter(Getter)
	{
	}

	virtual ~FSwiftMember() override {}


public:
	TSharedPtr<FSwiftExpr> Getter;
};
