
#pragma once

#include "CoreMinimal.h"
#include "AST/SwiftVarDecl.h"
#include "AST/Type/SwiftType.h"
#include "AST/Expr/SwiftExpr.h"

class FSwiftFunctionParam : public FSwiftVarDecl {
public:
	FSwiftFunctionParam(
		FString Name,
		TSet<FString> Attributes,
		TArray<TSharedPtr<FSwiftAST>> Inner,
		TSharedRef<FSwiftType> Type,
		bool isMutable,
		TOptional<FString> Label,
		TOptional<FString> DefaultValue
	)
		: FSwiftVarDecl(Name, Attributes, Inner, Type, isMutable)
		, Label(Label)
		, DefaultValue(DefaultValue)
	{
	}

	virtual ~FSwiftFunctionParam() override {}

public:
	TOptional<FString> Label;
	TOptional<FString> DefaultValue;
};