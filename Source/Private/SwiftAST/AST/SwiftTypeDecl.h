
#pragma once

#include "CoreMinimal.h"
#include "AST/SwiftDecl.h"
#include "AST/Type/SwiftType.h"

class FSwiftTypeDecl : public FSwiftDecl {
public:
	FSwiftTypeDecl(
		FString Name,
		TSet<FString> Attributes,
		TArray<TSharedPtr<FSwiftAST>> Inner,
		TSharedRef<const FSwiftType> Type
	)
		: FSwiftDecl(Name, Attributes, Inner)
		, Type(Type)
	{
	}

	virtual ~FSwiftTypeDecl() override {}

	virtual TSharedPtr<const FSwiftType> CanonicalType() const override {
		return Type->Canonical();
	}


public:
	TSharedRef<const FSwiftType> Type;
};

