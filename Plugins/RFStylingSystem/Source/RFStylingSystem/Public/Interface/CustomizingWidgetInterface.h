// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "UObject/Interface.h"
#include "../Widget/RFStylingWidgetData.h"
#include "CustomizingWidgetInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCustomizingWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

class RFSTYLINGSYSTEM_API ICustomizingWidgetInterface
{
	GENERATED_BODY()

public:
	virtual void SetOnClickThemeButton(FRFStylingItemID ButtonID);
};