
#pragma once

#include "CoreMinimal.h"

class FClangAST;

class FSwiftFromClang {
public:
	FSwiftFromClang(TSharedPtr<FClangAST> ClangAST) : ClangAST(ClangAST) {}
	virtual ~FSwiftFromClang() {}


public:
	TSharedPtr<FClangAST> ClangAST;
};
