// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "RFStylingBaseWidget.h"
#include "RFStylingCustomizingThemeButton.h"
#include "RFStylingCustomizngWidgetSwitcher.h"
#include "RFStylingCustomizingWidget.generated.h"



DECLARE_DELEGATE_OneParam(HelloDelegate, FString);

UCLASS(Blueprintable)
class URFStylingCustomizingWidget : public URFStylingBaseWidget
{
	GENERATED_BODY()

public:
	URFStylingCustomizingWidget();

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCustomizingMannequin(ACharacter* Mannequin) {CustomizingMannequin = Mannequin;}

private:
	TObjectPtr<ACharacter> CustomizingMannequin;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	TArray<URFStylingCustomizingThemeButton*> ThemeButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	TObjectPtr<URFStylingCustomizngWidgetSwitcher> ThemeViewer;
};

