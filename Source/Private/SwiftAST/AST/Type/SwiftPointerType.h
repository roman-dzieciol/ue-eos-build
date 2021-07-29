
#pragma once

#include "CoreMinimal.h"
#include "SwiftType.h"

class FSwiftPointerType : public FSwiftType {
public:
	FSwiftPointerType(
		TOptional<bool> isOptional,
		TSet<FString> Attributes,
		TSharedRef<const FSwiftType> PointeeType,
		bool isMutable
	)
		: FSwiftType(ESwiftType::Pointer, isOptional, Attributes)
		, PointeeType(PointeeType)
		, isMutable(isMutable)
	{
	}

	virtual TSharedRef<const FSwiftType> Canonical() const override
	{
		return MakeShared<FSwiftPointerType>(isOptional, Attributes, PointeeType->Canonical(), isMutable);
	}

	virtual bool operator==(const FSwiftType& RHS) const
	{
		if (SwiftType == RHS.SwiftType)
		{
			const FSwiftPointerType& Other = static_cast<const FSwiftPointerType&>(RHS);
			return FSwiftType::operator==(RHS)
				&& PointeeType.Get() == Other.PointeeType.Get()
				&& isMutable == Other.isMutable;
		}
		return false;
	}


	virtual ~FSwiftPointerType() override {}

	virtual TSharedRef<const FSwiftType> Clone() const override {
		return MakeShareable(new FSwiftPointerType(*this));
	}

	virtual TSharedRef<const FSwiftType> Immutable() const override
	{
		return WithMutability(false);
	}

	virtual TSharedRef<const FSwiftType> Mutable() const override
	{
		return WithMutability(true);
	}

	TSharedRef<const FSwiftType> WithMutability(bool Mutable) const
	{
		if (isMutable == Mutable) {
			return AsShared();
		}
		TSharedRef<const FSwiftPointerType> CloneRef = StaticCastSharedRef<const FSwiftPointerType>(Clone());
		ConstCastSharedRef<FSwiftPointerType>(CloneRef)->SetMutable(Mutable);
		return CloneRef;
	}

private:
	void SetMutable(bool Mutable) {
		const_cast<bool&>(isMutable) = Mutable;
	}

public:
	const TSharedRef<const FSwiftType> PointeeType;
	const bool isMutable;
};

