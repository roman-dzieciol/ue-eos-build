
#pragma once

#include "CoreMinimal.h"
#include "SwiftType.h"

class FSwiftDeclRefType : public FSwiftType {
public:
	FSwiftDeclRefType(
		TOptional<bool> isOptional,
		TSet<FString> Attributes,
		TSharedRef<FSwiftDecl> Decl
	)
		: FSwiftType(ESwiftType::DeclRef, isOptional, Attributes)
		, Decl(Decl)
	{
	}

	virtual TSharedRef<const FSwiftType> Canonical() const override
	{
		TSharedPtr<const FSwiftType> DeclCanonicalType = Decl->CanonicalType();
		if (DeclCanonicalType.IsValid()) {
			return DeclCanonicalType.ToSharedRef();
		}
		return AsShared();
	}

	virtual bool operator==(const FSwiftType& RHS) const
	{
		if (SwiftType == RHS.SwiftType)
		{
			const FSwiftDeclRefType& Other = static_cast<const FSwiftDeclRefType&>(RHS);
			return FSwiftType::operator==(RHS)
				&& Decl == Other.Decl
				;
		}
		return false;
	}

	virtual ~FSwiftDeclRefType() override {}

	virtual TSharedRef<const FSwiftType> Clone() const override {
		return MakeShareable(new FSwiftDeclRefType(*this));
	}

public:
	const TSharedRef<FSwiftDecl> Decl;
};
