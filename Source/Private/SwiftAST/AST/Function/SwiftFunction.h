
#pragma once

#include "CoreMinimal.h"
#include "AST/SwiftDecl.h"
#include "AST/Type/SwiftType.h"

class FSwiftFunction : public FSwiftDecl {
public:
	FSwiftFunction(
		FString Name,
		TSet<FString> Attributes,
		TArray<TSharedPtr<FSwiftAST>> Inner,
		TArray<FString> GenericTypes,
		TSharedRef<FSwiftType> ReturnType,
		TSharedRef<FSwiftType> Code,
		bool isThrowing,
		bool isRethrowing,
		bool isAsync,
		bool isOptional
	)
		: FSwiftDecl(Name, Attributes, Inner)
		, GenericTypes(GenericTypes)
		, ReturnType(ReturnType)
		, Code(Code)
		, isThrowing(isThrowing)
		, isRethrowing(isRethrowing)
		, isAsync(isAsync)
		, isOptional(isOptional)
	{
	}

	virtual ~FSwiftFunction() override {}


public:
	TArray<FString> GenericTypes;
	TSharedRef<FSwiftType> ReturnType;
	TSharedRef<FSwiftType> Code;
	bool isThrowing;
	bool isRethrowing;
	bool isAsync;
	bool isOptional;
};
