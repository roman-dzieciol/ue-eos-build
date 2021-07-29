
#pragma once

#include "CoreMinimal.h"

class FSwiftAST;

class FSwiftPrinter {
public:
	FSwiftPrinter(TSharedPtr<FSwiftAST> SwiftAST) : SwiftAST(SwiftAST) {}
	virtual ~FSwiftPrinter() {}


public:
	TSharedPtr<FSwiftAST> SwiftAST;
};
