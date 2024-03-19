// Copyright 2024 RedFlowering, All Rights Reserved.

#include "Widget/RFStylingCustomizingThemeButton.h"

void URFStylingCustomizingThemeButton::OnClick()
{
	Super::OnClick();
}

void URFStylingCustomizingThemeButton::OnClickEvent()
{
	// 테마에 따라 Main UI 변경
	switch (ButtonTheme)
	{
	case ERFStylingCustomizingTheme::Presets:
		break;
	case ERFStylingCustomizingTheme::Face:
		break;
	case ERFStylingCustomizingTheme::Body:
		break;
	case ERFStylingCustomizingTheme::Clothes:
		break;
	case ERFStylingCustomizingTheme::ClothesCreating:
		break;
	}
}
