
#pragma once

#include "CoreMinimal.h"
#include "SwiftType.h"

class FSwiftGenericType : public FSwiftType {
public:
	FSwiftGenericType(
		TOptional<bool> isOptional,
		TSet<FString> Attributes,
		TSharedRef<const FSwiftType> GenericType,
		TArray<TSharedRef<const FSwiftType>> SpecializationTypes
	)
		: FSwiftType(ESwiftType::Generic, isOptional, Attributes)
		, GenericType(GenericType)
		, SpecializationTypes(SpecializationTypes)
	{
	}

	virtual TSharedRef<const FSwiftType> Canonical() const override
	{
		TArray<TSharedRef<const FSwiftType>> CanonicalSpecializationTypes;
		CanonicalSpecializationTypes.Reserve(SpecializationTypes.Num());
		Algo::Transform(SpecializationTypes, CanonicalSpecializationTypes, [](auto& Item) {
			return Item->Canonical();
		});
		return MakeShared<FSwiftGenericType>(isOptional, Attributes, GenericType->Canonical(), CanonicalSpecializationTypes);
	}

	virtual bool operator==(const FSwiftType& RHS) const
	{
		if (SwiftType == RHS.SwiftType)
		{
			const FSwiftGenericType& Other = static_cast<const FSwiftGenericType&>(RHS);
			return FSwiftType::operator==(RHS)
				&& GenericType.Get() == Other.GenericType.Get()
				&& Algo::CompareByPredicate(SpecializationTypes, Other.SpecializationTypes, [](auto& L, auto& R) { return L.Get() == R.Get(); })
				;
		}
		return false;
	}

	virtual ~FSwiftGenericType() override {}

	virtual TSharedRef<const FSwiftType> Clone() const override {
		return MakeShareable(new FSwiftGenericType(*this));
	}

public:
	const TSharedRef<const FSwiftType> GenericType;
	const TArray<TSharedRef<const FSwiftType>> SpecializationTypes;
};
