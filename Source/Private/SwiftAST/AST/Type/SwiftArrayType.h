
#pragma once

#include "CoreMinimal.h"
#include "SwiftType.h"

class FSwiftArrayType: public FSwiftType {

public:
	const TSharedRef<const FSwiftType> ElementType;

public:
	FSwiftArrayType(
		TOptional<bool> isOptional,
		TSet<FString> Attributes,
		TSharedRef<const FSwiftType> ElementType
	)
		: FSwiftType(ESwiftType::Array, isOptional, Attributes)
		, ElementType(ElementType)
	{
	}

	virtual TSharedRef<const FSwiftType> Canonical() const override
	{
		return MakeShared<FSwiftArrayType>(isOptional, Attributes, ElementType->Canonical());
	}

	virtual bool operator==(const FSwiftType& RHS) const
	{
		if (SwiftType == RHS.SwiftType)
		{
			const FSwiftArrayType& Other = static_cast<const FSwiftArrayType&>(RHS);
			return FSwiftType::operator==(RHS)
				&& ElementType.Get() == Other.ElementType.Get();
		}
		return false;
	}

	virtual ~FSwiftArrayType() override {}

	virtual TSharedRef<const FSwiftType> Clone() const override {
		return MakeShareable(new FSwiftArrayType(*this));
	}
};
