// Copyright 2024 RedFlowering, All Rights Reserved.

#include "Widget/RFStylingCustomizingWidget.h"

URFStylingCustomizingWidget::URFStylingCustomizingWidget()
	:Super()
{
}

void URFStylingCustomizingWidget::SetOnClickThemeButton(FRFStylingItemID ButtonID)
{
	if(ThemeButtons.Num() <= 0)
		return;

	for (URFStylingCustomizingThemeButton* elem : ThemeButtons)
	{
		if (elem->ButtonID == ButtonID)
		{
			// ���� Ȱ��ȭ�� ��ư üũ
			if(GetCurrentThemeButton() == elem)
				break;

			// ���� ��ư ��Ȱ��
			GetCurrentThemeButton()->SetDeactivateThemeButton();

			// ���� ��ư ��ü
			SetCurrentThemeButton(elem);
			GetCurrentThemeButton()->SetActivateThemeButton();

			// �ش� ��ư�� �´� ThemeViewer Switching
			if(!ThemeViewerSwitcher)
				break;

			ThemeViewerSwitcher->SetActiveWidgetIndex((int32)elem->ThemeType);
			break;
		}
	}
}
