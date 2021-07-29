
#pragma once

#include "CoreMinimal.h"

enum class ESwiftTag {
	SwiftActor,
	SwiftClass,
	SwiftEnum,
	SwiftStruct,
	SwiftUnion
};

extern const TCHAR* ESwiftTagToString(ESwiftTag SwiftTag);
extern ESwiftTag ESwiftTagFromString(const TCHAR* String);

class FSwiftAST {
public:
	FSwiftAST(
		FString Name,
		TSet<FString> Attributes,
		TArray<TSharedPtr<FSwiftAST>> Inner
	) 
		: Name(Name)
		, Attributes(Attributes)
		, Inner(Inner)
	{
	}

	virtual ~FSwiftAST() = 0;


protected:
	FString Name;
	TSet<FString> Attributes;
	TArray<TSharedPtr<FSwiftAST>> Inner;
};
