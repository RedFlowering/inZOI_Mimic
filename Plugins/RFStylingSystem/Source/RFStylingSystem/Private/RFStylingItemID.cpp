// Copyright 2024 RedFlowering, All Rights Reserved.

#include "RFStylingItemID.h"
#include "RFStylingSystem.h"

FRFStylingItemID::FRFStylingItemID(int32 ID)
{
	if (ID > 99999999)
	{
		UE_LOG(RFLogSystem, Error, TEXT("[%d] ID Must Be 8 Character"), ID);

		ID = ID % 100000000;
	}

	Identifier = ID;
}

inline int32 FRFStylingItemID::GetID_PartTypeAll()
{
	return Identifier;
}

inline int32 FRFStylingItemID::GetID_PartTypeA()
{
	return Identifier - (Identifier % 1000000);
}

inline int32 FRFStylingItemID::GetID_PartTypeB()
{
	return (Identifier % 1000000) - (Identifier % 10000);
}

inline int32 FRFStylingItemID::GetID_PartTypeC()
{
	return (Identifier % 10000) - (Identifier % 100);
}

inline int32 FRFStylingItemID::GetID_PartTypeD()
{
	return Identifier % 100;
}

inline int32 FRFStylingItemID::GetID_PartTypeAB()
{
	return Identifier - (Identifier % 10000);
}

inline int32 FRFStylingItemID::GetID_PartTypeBC()
{
	return (Identifier - (Identifier % 100)) % 1000000;
}

inline int32 FRFStylingItemID::GetID_PartTypeCD()
{
	return Identifier % 10000;
}

inline int32 FRFStylingItemID::GetID_PartTypeABC()
{
	return Identifier - (Identifier % 100);
}

inline int32 FRFStylingItemID::GetID_PartTypeBCD()
{
	return Identifier % 1000000;
}
