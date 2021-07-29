
#pragma once

#include "CoreMinimal.h"
#include "SwiftType.h"
#include "Algo/Compare.h"
#include "Algo/Transform.h"

class FSwiftFunctionType : public FSwiftType {
public:
	FSwiftFunctionType(
		TOptional<bool> isOptional,
		TSet<FString> Attributes,
		TSharedRef<const FSwiftType> ReturnType,
		TArray<TSharedRef<const FSwiftType>> ParamTypes,
		bool isThrowing
	)
		: FSwiftType(ESwiftType::Function, isOptional, Attributes)
		, ReturnType(ReturnType)
		, ParamTypes(ParamTypes)
		, isThrowing(isThrowing)
	{
	}

	virtual TSharedRef<const FSwiftType> Canonical() const override
	{
		TArray<TSharedRef<const FSwiftType>> CanonicalParamTypes;
		CanonicalParamTypes.Reserve(ParamTypes.Num());
		Algo::Transform(ParamTypes, CanonicalParamTypes, [](auto& Item) {
			return Item->Canonical();
		});
		return MakeShared<FSwiftFunctionType>(isOptional, Attributes, ReturnType->Canonical(), CanonicalParamTypes, isThrowing);
	}

	virtual bool operator==(const FSwiftType& RHS) const
	{
		if (SwiftType == RHS.SwiftType)
		{
			const FSwiftFunctionType& Other = static_cast<const FSwiftFunctionType&>(RHS);
			return FSwiftType::operator==(RHS)
				&& ReturnType.Get() == Other.ReturnType.Get()
				&& Algo::CompareByPredicate(ParamTypes, Other.ParamTypes, [](auto& L, auto& R) { return L.Get() == R.Get(); })
				&& isThrowing == Other.isThrowing
				;
		}
		return false;
	}

	virtual ~FSwiftFunctionType() override {}

	virtual TSharedRef<const FSwiftType> Clone() const override {
		return MakeShareable(new FSwiftFunctionType(*this));
	}

public:
	const TSharedRef<const FSwiftType> ReturnType;
	const TArray<TSharedRef<const FSwiftType>> ParamTypes;
	const bool isThrowing;
};
