
#pragma once

#include "CoreMinimal.h"
#include "AST/SwiftTypeDecl.h"
#include "AST/Type/SwiftType.h"

class FSwiftTypealias : public FSwiftTypeDecl {
public:
	FSwiftTypealias(
		FString Name,
		TSet<FString> Attributes,
		TArray<TSharedPtr<FSwiftAST>> Inner,
		TSharedRef<FSwiftType> Type
	)
		: FSwiftTypeDecl(Name, Attributes, Inner, Type)
	{
	}
	
	virtual ~FSwiftTypealias() override {}

public:
};
