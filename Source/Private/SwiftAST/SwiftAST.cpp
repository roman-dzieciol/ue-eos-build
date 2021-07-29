
#include "SwiftAST.h"
#include "EosBuild.h"

#include "AST/Expr/SwiftExpr.h"

#include "AST/SwiftDecl.h"
#include "AST/SwiftMember.h"
#include "AST/SwiftModule.h"
#include "AST/SwiftTypealias.h"
#include "AST/SwiftTypeDecl.h"
#include "AST/SwiftVarDecl.h"
#include "AST/Object/SwiftObject.h"
#include "AST/Function/SwiftFunction.h"
#include "AST/Function/SwiftFunctionParam.h"

#include "AST/Type/SwiftArrayType.h"
#include "AST/Type/SwiftBuiltinType.h"
#include "AST/Type/SwiftDeclRefType.h"
#include "AST/Type/SwiftFunctionParmType.h"
#include "AST/Type/SwiftFunctionType.h"
#include "AST/Type/SwiftGenericType.h"
#include "AST/Type/SwiftOpaqueType.h"
#include "AST/Type/SwiftPointerType.h"
#include "AST/Type/SwiftType.h"


FSwiftAST::~FSwiftAST() {
}

const TCHAR* ESwiftTagToString(ESwiftTag SwiftTag)
{
	switch (SwiftTag)
	{
	case ESwiftTag::SwiftActor:
		return TEXT("actor");
	case ESwiftTag::SwiftClass:
		return TEXT("class");
	case ESwiftTag::SwiftEnum:
		return TEXT("enum");
	case ESwiftTag::SwiftStruct:
		return TEXT("struct");
	case ESwiftTag::SwiftUnion:
		return TEXT("struct");
	default:
		return TEXT("<unknown>");
	}
}

ESwiftTag ESwiftTagFromString(const TCHAR* String)
{
	if (FCString::Stricmp(String, TEXT("actor")) == 0)
	{
		return ESwiftTag::SwiftActor;
	}
	else if (FCString::Stricmp(String, TEXT("class")) == 0)
	{
		return ESwiftTag::SwiftClass;
	}
	else if (FCString::Stricmp(String, TEXT("struct")) == 0)
	{
		return ESwiftTag::SwiftStruct;
	}
	else if (FCString::Stricmp(String, TEXT("enum")) == 0)
	{
		return ESwiftTag::SwiftEnum;
	}
	else if (FCString::Stricmp(String, TEXT("union")) == 0)
	{
		return ESwiftTag::SwiftUnion;
	}
	else {
		return ESwiftTag::SwiftStruct;
	}
}
