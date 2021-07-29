
#pragma once

#include "CoreMinimal.h"

enum class ESwiftType {
	Array,
	Builtin,
	DeclRef,
	FunctionParam,
	Function,
	Generic,
	Opaque,
	Pointer
};

class FSwiftType : public TSharedFromThis<FSwiftType> {
public:
	FSwiftType(
		ESwiftType SwiftType,
		TOptional<bool> isOptional,
		TSet<FString> Attributes
	)
		: SwiftType(SwiftType)
		, isOptional(isOptional)
		, Attributes(Attributes)
	{
	}

	virtual ~FSwiftType() {}

	virtual TSharedRef<const FSwiftType> Clone() const {
		return MakeShareable(new FSwiftType(*this));
	}

	virtual bool operator==(const FSwiftType& RHS) const {
		SwiftType == RHS.SwiftType
			&& isOptional == RHS.isOptional
			&& Attributes.Num() == RHS.Attributes.Num()
			&& (Attributes.Difference(RHS.Attributes).Num() == 0)
			;
	}

	virtual TSharedRef<const FSwiftType> Canonical() const
	{
		return AsShared();
	}

	virtual TSharedRef<const FSwiftType> Immutable() const
	{
		return AsShared();
	}

	virtual TSharedRef<const FSwiftType> Mutable() const
	{
		return AsShared();
	}

	virtual TSharedRef<const FSwiftType> Optional() const 
	{
		return WithOptional(TOptional<bool>(true));
	}

	virtual TSharedRef<const FSwiftType> NonOptional() const
	{
		return WithOptional(TOptional<bool>(false));
	}

	virtual TSharedRef<const FSwiftType> ExplicitlyOptional() const
	{
		if (isOptional != TOptional<bool>()) 
		{
			return AsShared();
		}
		return Optional();
	}

	TSharedRef<const FSwiftType> WithOptional(TOptional<bool> Optional) const
	{
		if (isOptional == Optional) {
			return AsShared();
		}
		TSharedRef<const FSwiftType> CloneRef = Clone();
		ConstCastSharedRef<FSwiftType>(CloneRef)->SetOptional(Optional);
		return CloneRef;
	}

private:

	void SetOptional(TOptional<bool> Optional) {
		const_cast<TOptional<bool>&>(isOptional) = Optional;
	}

public:
	const ESwiftType SwiftType;
	const TOptional<bool> isOptional;
	const TSet<FString> Attributes;
};
