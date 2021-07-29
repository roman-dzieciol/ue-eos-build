
#pragma once

#include "CoreMinimal.h"
#include "SwiftAST.h"

class FSwiftType;

class FSwiftDecl: public FSwiftAST {
public:
	FSwiftDecl(
		FString Name,
		TSet<FString> Attributes,
		TArray<TSharedPtr<FSwiftAST>> Inner
	)
		: FSwiftAST(Name, Attributes, Inner)
	{
	}

	virtual ~FSwiftDecl() override {}



	virtual TSharedPtr<const FSwiftType> CanonicalType() const {
		return nullptr;
	}


public:
};
