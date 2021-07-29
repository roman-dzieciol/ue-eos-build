
#pragma once

#include "CoreMinimal.h"
#include "SwiftType.h"

class FSwiftFunctionParamType : public FSwiftType {
public:
	FSwiftFunctionParamType(
		TOptional<bool> isOptional,
		TSet<FString> Attributes,
		TOptional<FString> Label,
		TSharedRef<const FSwiftType> ParamType,
		bool isMutable
	)
		: FSwiftType(ESwiftType::FunctionParam, isOptional, Attributes)
		, Label(Label)
		, ParamType(ParamType)
		, isMutable(isMutable)
	{
	}

	virtual TSharedRef<const FSwiftType> Canonical() const override
	{
		return MakeShared<FSwiftFunctionParamType>(isOptional, Attributes, Label, ParamType->Canonical(), isMutable);
	}

	virtual bool operator==(const FSwiftType& RHS) const
	{
		if (SwiftType == RHS.SwiftType)
		{
			const FSwiftFunctionParamType& Other = static_cast<const FSwiftFunctionParamType&>(RHS);
			return FSwiftType::operator==(RHS)
				&& Label == Other.Label
				&& ParamType.Get() == Other.ParamType.Get()
				&& isMutable == Other.isMutable
				;
		}
		return false;
	}

	virtual ~FSwiftFunctionParamType() override {}

	virtual TSharedRef<const FSwiftType> Clone() const override {
		return MakeShareable(new FSwiftFunctionParamType(*this));
	}

public:
	const TOptional<FString> Label;
	const TSharedRef<const FSwiftType> ParamType;
	const bool isMutable;
};
