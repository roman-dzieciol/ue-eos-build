
#pragma once

#include "CoreMinimal.h"
#include "SwiftType.h"

class FSwiftBuiltinType : public FSwiftType {
public:
	FSwiftBuiltinType(
		TOptional<bool> isOptional,
		TSet<FString> Attributes,
		FString BuiltinName
	)
		: FSwiftType(ESwiftType::Builtin, isOptional, Attributes)
		, BuiltinName(BuiltinName)
	{
	}

	virtual bool operator==(const FSwiftType& RHS) const
	{
		if (SwiftType == RHS.SwiftType)
		{
			const FSwiftBuiltinType& Other = static_cast<const FSwiftBuiltinType&>(RHS);
			return FSwiftType::operator==(RHS)
				&& BuiltinName == Other.BuiltinName
				;
		}
		return false;
	}

	virtual ~FSwiftBuiltinType() override {}

	virtual TSharedRef<const FSwiftType> Clone() const override {
		return MakeShareable(new FSwiftBuiltinType(*this));
	}

public:
	const FString BuiltinName;
};

