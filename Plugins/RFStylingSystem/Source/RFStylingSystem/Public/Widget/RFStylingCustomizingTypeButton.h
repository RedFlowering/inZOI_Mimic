// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "RFStylingBaseButton.h"
#include "RFStylingWidgetData.h"
#include "RFStylingCustomizingTypeButton.generated.h"

class URFStylingCustomizingWidget;
class URFStylingCustomizingTypeSelector;

UCLASS()
class URFStylingCustomizingTypeButton : public URFStylingBaseButton
{
	GENERATED_BODY()
	URFStylingCustomizingTypeButton(const FObjectInitializer& ObjectInitializer);

public:
	virtual void OnClick() override;

	virtual void OnClickEvent() override;

public:
	UPROPERTY(EditAnywhere, Category = RFStyling)
	ERFStylingPresetsGroup PresetGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	bool IsNextButton = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	TArray<int32> ValueList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	int32 CurrentValue = 0;

	UPROPERTY(BlueprintReadWrite, Category = RFStyling)
	TObjectPtr<URFStylingCustomizingWidget> CustomizingOwner;

	UPROPERTY(BlueprintReadWrite, Category = RFStyling)
	TObjectPtr<URFStylingCustomizingTypeSelector> TypeOwner;
};

