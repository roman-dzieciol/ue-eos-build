
#pragma once

#include "CoreMinimal.h"
#include "SwiftType.h"

class FSwiftOpaqueType : public FSwiftType {
public:
	FSwiftOpaqueType(
		TOptional<bool> isOptional,
		TSet<FString> Attributes,
		FString TypeName
	)
		: FSwiftType(ESwiftType::Opaque, isOptional, Attributes)
		, TypeName(TypeName)
	{
	}

	virtual bool operator==(const FSwiftType& RHS) const
	{
		if (SwiftType == RHS.SwiftType)
		{
			const FSwiftOpaqueType& Other = static_cast<const FSwiftOpaqueType&>(RHS);
			return FSwiftType::operator==(RHS)
				&& TypeName == Other.TypeName
				;
		}
		return false;
	}

	virtual ~FSwiftOpaqueType() override {}

	virtual TSharedRef<const FSwiftType> Clone() const override {
		return MakeShareable(new FSwiftOpaqueType(*this));
	}

public:
	const FString TypeName;
};
