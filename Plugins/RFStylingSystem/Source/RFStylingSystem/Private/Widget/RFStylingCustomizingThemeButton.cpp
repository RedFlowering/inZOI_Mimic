// Copyright 2024 RedFlowering, All Rights Reserved.

#include "Widget/RFStylingCustomizingThemeButton.h"

void URFStylingCustomizingThemeButton::OnClick()
{
	Super::OnClick();
}

void URFStylingCustomizingThemeButton::OnClickEvent()
{
	// �׸��� ���� Main UI ����
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
