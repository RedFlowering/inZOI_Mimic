// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "RFStylingBaseButton.h"
#include "RFStylingWidgetData.h"
#include "RFStylingCustomizingThemeButton.generated.h"

UCLASS()
class URFStylingCustomizingThemeButton : public URFStylingBaseButton
{
	GENERATED_BODY()

public:
	virtual void OnClick() override;

	virtual void OnClickEvent() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	ERFStylingCustomizingTheme ButtonTheme;
};

