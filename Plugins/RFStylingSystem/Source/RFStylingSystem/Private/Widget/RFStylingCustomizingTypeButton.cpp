// Copyright 2024 RedFlowering, All Rights Reserved.

#include "Widget/RFStylingCustomizingTypeButton.h"
#include "Widget/RFStylingCustomizingWidget.h"
#include "Widget/RFStylingCustomizingTypeSelector.h"
#include "Interface/CustomizingWidgetInterface.h"
#include "Blueprint/WidgetTree.h"

URFStylingCustomizingTypeButton::URFStylingCustomizingTypeButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void URFStylingCustomizingTypeButton::OnClick()
{
	Super::OnClick();
}

void URFStylingCustomizingTypeButton::OnClickEvent()
{
	// Super::OnClickEvent()

	ICustomizingWidgetInterface* Interface;

	if (CustomizingOwner)
	{
		Interface = Cast<ICustomizingWidgetInterface>(CustomizingOwner);

		if (!Interface)
			return;

		int32 TargetValue = Interface->SetOnClickTypeButton(IsNextButton, ValueList, CurrentValue);

		switch (PresetGroup)
		{
		case ERFStylingPresetsGroup::Age:
			break;
		case ERFStylingPresetsGroup::Body:
			TypeOwner->SetCurrentBodyType((ERFStylingPresetsBodyType)TargetValue);
			break;
		case ERFStylingPresetsGroup::Express:
			TypeOwner->SetCurrentExpressType((ERFStylingPresetsExpressType)TargetValue);
			break;
		case ERFStylingPresetsGroup::Pose:
			TypeOwner->SetCurrentPoseType((ERFStylingPresetsPoseType)TargetValue);
			break;
		}
	}
}

