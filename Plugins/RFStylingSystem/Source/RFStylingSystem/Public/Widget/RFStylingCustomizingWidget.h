// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "RFStylingBaseWidget.h"
#include "RFStylingCustomizingThemeButton.h"
#include "RFStylingCustomizngWidgetSwitcher.h"
#include "../Interface/CustomizingWidgetInterface.h"
#include "RFStylingCustomizingTypeSelector.h"
#include "RFStylingCustomizingWidget.generated.h"



DECLARE_DELEGATE_OneParam(HelloDelegate, FString);

UCLASS(Blueprintable)
class URFStylingCustomizingWidget : public URFStylingBaseWidget, public ICustomizingWidgetInterface
{
	GENERATED_BODY()

public:
	URFStylingCustomizingWidget();

	// Init
	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCustomizingMannequin(ACharacter* Mannequin) {CustomizingMannequin = Mannequin;}

	void SetThemeButton(TArray<URFStylingCustomizingThemeButton*> Buttons) {ThemeButtons = Buttons;}

	// Callback
	virtual void SetOnClickThemeButton(FRFStylingItemID ButtonID) override;

	virtual int32 SetOnClickTypeButton(bool IsNext, TArray<int32> ValueList, int32 CurrentValue) override;

	virtual void SetAgeType(ERFStylingPresetsAgeType Age) override;

	virtual void SetBodyType(ERFStylingPresetsBodyType Body) override;

	virtual void SetExpressType(ERFStylingPresetsExpressType Express) override;

	virtual void SetPoseType(ERFStylingPresetsPoseType Pose) override;

	// Function
	UFUNCTION(BlueprintCallable, Category = RFStyling)
	URFStylingCustomizingThemeButton* GetCurrentThemeButton() { return CurrentThemeButton; }

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCurrentThemeButton(URFStylingCustomizingThemeButton* Button) { CurrentThemeButton = Button; }

private:
	TObjectPtr<ACharacter> CustomizingMannequin;

public:
	UPROPERTY(BlueprintReadWrite, Category = RFStyling, meta = (BindWidget))
	TArray<URFStylingCustomizingThemeButton*> ThemeButtons;

	UPROPERTY(BlueprintReadWrite, Category = RFStyling, meta = (BindWidget))
	TObjectPtr<URFStylingCustomizngWidgetSwitcher> ThemeViewerSwitcher;

	UPROPERTY(BlueprintReadWrite, Category = RFStyling, meta = (BindWidget))
	TObjectPtr<URFStylingCustomizingTypeSelector> TypeSelector;

private:
	TObjectPtr<URFStylingCustomizingThemeButton> CurrentThemeButton;
};

