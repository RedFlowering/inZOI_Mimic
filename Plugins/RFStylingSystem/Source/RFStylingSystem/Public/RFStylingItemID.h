// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "RFStylingItemID.generated.h"

UENUM(BlueprintType)
enum class ERFStylingItemIDPartType : uint8
{		
	PartTypeA = 0,	// 99 000000	// 9 is compare, 0 is ignore
	PartTypeB,		// 00 99 0000 
	PartTypeC,		// 0000 99 00 
	PartTypeD,		// 000000 99 
	PartTypeAB,		// 9999 0000
	PartTypeBC,		// 00 9999 00
	PartTypeCD,		// 0000 9999
	PartTypeABC,	// 999999 00
	PartTypeBCD,	// 00 999999
	PartTypeAll,	// 99999999
};

USTRUCT(BlueprintType)
struct RFSTYLINGSYSTEM_API FRFStylingItemID
{
	GENERATED_BODY()

public:
	FRFStylingItemID() = default;
	FRFStylingItemID(int32 ID);
	FRFStylingItemID(const FRFStylingItemID& ID) : Identifier(ID.Identifier) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RFStyling Item Identifier")
	int32 Identifier = -1; // must be 8 Digits

public:
	bool IsValid() { return Identifier >= 0 && Identifier < 100000000; }

	int32 GetID_PartTypeAll();

	int32 GetID_PartTypeA();

	int32 GetID_PartTypeB();

	int32 GetID_PartTypeC();

	int32 GetID_PartTypeD();

	int32 GetID_PartTypeAB();

	int32 GetID_PartTypeBC();

	int32 GetID_PartTypeCD();

	int32 GetID_PartTypeABC();

	int32 GetID_PartTypeBCD();
};

inline bool operator==(const FRFStylingItemID& Lhs, const FRFStylingItemID& Rhs) { return Lhs.Identifier == Rhs.Identifier; }
inline bool operator!=(const FRFStylingItemID& Lhs, const FRFStylingItemID& Rhs) { return Lhs.Identifier != Rhs.Identifier; }
