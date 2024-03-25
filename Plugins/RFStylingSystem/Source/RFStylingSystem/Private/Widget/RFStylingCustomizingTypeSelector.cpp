#include "Widget/RFStylingCustomizingTypeSelector.h"

URFStylingCustomizingTypeSelector::URFStylingCustomizingTypeSelector()
{
}

template <typename T>
void URFStylingCustomizingTypeSelector::NextPresetsType(TArray<T>& PresetsType, T& CurrentType)
{
	int32 MaxIndex = PresetsType.Num() - 1;

	for (int32 index = 0; index < MaxIndex; index++)
	{
		if (PresetsType[index] != CurrentType)
			continue;

		int32 TargetIndex = index + 1;

		if (TargetIndex >= MaxIndex)
			CurrentType = PresetsType[0];
		else
			CurrentType = PresetsType[TargetIndex];

		break;
	}
}

template <typename T>
void URFStylingCustomizingTypeSelector::PrevPresetsType(TArray<T>& PresetsType, T& CurrentType)
{
	int32 MaxIndex = PresetsType.Num() - 1;

	for (int32 index = 0; index < MaxIndex; index++)
	{
		if (PresetsType[index] != CurrentType)
			continue;

		int32 TargetIndex = index - 1;

		if (TargetIndex < 0)
			CurrentType = PresetsType[MaxIndex - 1];
		else
			CurrentType = PresetsType[TargetIndex];

		break;
	}
}
