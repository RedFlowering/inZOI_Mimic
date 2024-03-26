// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "RFStylingBaseButton.h"
#include "RFStylingWidgetData.h"
#include "RFStylingCustomizingThemeButton.generated.h"

class URFStylingCustomizingWidget;

UCLASS()
class URFStylingCustomizingThemeButton : public URFStylingBaseButton
{
	GENERATED_BODY()
	URFStylingCustomizingThemeButton(const FObjectInitializer& ObjectInitializer);

public:
	virtual void OnClick() override;

	virtual void OnClickEvent() override;

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetActivateThemeButton();

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetDeactivateThemeButton();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	ERFStylingCustomizingTheme ThemeType;

	UPROPERTY(BlueprintReadWrite, Category = RFStyling)
	TObjectPtr<URFStylingCustomizingWidget> Owner;
};

