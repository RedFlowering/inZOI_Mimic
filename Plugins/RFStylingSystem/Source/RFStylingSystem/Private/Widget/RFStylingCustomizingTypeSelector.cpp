#include "Widget/RFStylingCustomizingTypeSelector.h"
#include "Widget/RFStylingCustomizingWidget.h"
#include "Interface/CustomizingWidgetInterface.h"

URFStylingCustomizingTypeSelector::URFStylingCustomizingTypeSelector()
	: Super(),
	CurrentAge(ERFStylingPresetsAgeType::Youth),
	CurrentBody(ERFStylingPresetsBodyType::BodyType1),
	CurrentExpress(ERFStylingPresetsExpressType::ExpressType1),
	CurrentPose(ERFStylingPresetsPoseType::PoseType1)
{
}

int32 URFStylingCustomizingTypeSelector::NextPresetsType(TArray<int32> PresetsType, int32 CurrentType)
{
	if((CurrentType + 1) >= PresetsType.Num())
		return CurrentType = 0;
	else
		return CurrentType += 1;

	return 0;
}

int32 URFStylingCustomizingTypeSelector::PrevPresetsType(TArray<int32> PresetsType, int32 CurrentType)
{
	if ((CurrentType - 1) < 0)
		return CurrentType = PresetsType.Num()-1;
	else
		return CurrentType -= 1;

	return 0;
}

void URFStylingCustomizingTypeSelector::InitTypeSelector()
{
	if (AgeType.Num() > 0)
	{
		CurrentAge = AgeType[0];
	}

	for (int i = 0; i < BodyType.Num(); i++)
	{
		if (i == 0)
		{
			CurrentBody = BodyType[0];

			if(!PrevBodyTypeButton || !NextBodyTypeButton)
				break;

			PrevBodyTypeButton->CurrentValue = i;
			NextBodyTypeButton->CurrentValue = i;
		}

		if (!PrevBodyTypeButton || !NextBodyTypeButton)
			break;

		PrevBodyTypeButton->ValueList.Add(i);
		NextBodyTypeButton->ValueList.Add(i);
	}

	for (int i = 0; i < ExpressType.Num(); i++)
	{
		if (i == 0)
		{
			CurrentExpress = ExpressType[0];

			if (!PrevExpressTypeButton || !NextExpressTypeButton)
				break;

			PrevExpressTypeButton->CurrentValue = i;
			NextExpressTypeButton->CurrentValue = i;
		}

		if (!PrevExpressTypeButton || !NextExpressTypeButton)
			break;

		PrevExpressTypeButton->ValueList.Add(i);
		NextExpressTypeButton->ValueList.Add(i);
	}

	for (int i = 0; i < PoseType.Num(); i++)
	{
		if (i == 0)
		{
			CurrentPose = PoseType[0];

			if (!NextPoseTypeButton || !PrevPoseTypeButton)
				break;

			NextPoseTypeButton->CurrentValue = i;
			PrevPoseTypeButton->CurrentValue = i;
		}

		if (!NextPoseTypeButton || !PrevPoseTypeButton)
			break;

		NextPoseTypeButton->ValueList.Add(i);
		PrevPoseTypeButton->ValueList.Add(i);
	}
}

void URFStylingCustomizingTypeSelector::SetCurrentAgeType(ERFStylingPresetsAgeType type)
{
	CurrentAge = type;

	ICustomizingWidgetInterface* Interface;

	if (Owner)
	{
		Interface = Cast<ICustomizingWidgetInterface>(Owner);

		if (!Interface)
			return;

		Interface->SetAgeType(CurrentAge);
	}
}

void URFStylingCustomizingTypeSelector::SetCurrentBodyType(ERFStylingPresetsBodyType type)
{
	CurrentBody = type;

	ICustomizingWidgetInterface* Interface;

	if (Owner)
	{
		Interface = Cast<ICustomizingWidgetInterface>(Owner);

		if (!Interface)
			return;

		Interface->SetBodyType(CurrentBody);
	}
}

void URFStylingCustomizingTypeSelector::SetCurrentExpressType(ERFStylingPresetsExpressType type)
{
	CurrentExpress = type;

	ICustomizingWidgetInterface* Interface;

	if (Owner)
	{
		Interface = Cast<ICustomizingWidgetInterface>(Owner);

		if (!Interface)
			return;

		Interface->SetExpressType(CurrentExpress);
	}
}

void URFStylingCustomizingTypeSelector::SetCurrentPoseType(ERFStylingPresetsPoseType type)
{
	CurrentPose = type;

	ICustomizingWidgetInterface* Interface;

	if (Owner)
	{
		Interface = Cast<ICustomizingWidgetInterface>(Owner);

		if (!Interface)
			return;

		Interface->SetPoseType(CurrentPose);
	}
}
