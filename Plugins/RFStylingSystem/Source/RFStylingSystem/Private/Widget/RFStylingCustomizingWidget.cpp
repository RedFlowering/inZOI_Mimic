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
			// 현재 활성화된 버튼 체크
			if(GetCurrentThemeButton() == elem)
				break;

			// 이전 버튼 비활성
			GetCurrentThemeButton()->SetDeactivateThemeButton();

			// 현재 버튼 교체
			SetCurrentThemeButton(elem);
			GetCurrentThemeButton()->SetActivateThemeButton();

			// 해당 버튼에 맞는 ThemeViewer Switching
			if(!ThemeViewerSwitcher)
				break;

			ThemeViewerSwitcher->SetActiveWidgetIndex((int32)elem->ThemeType);
			break;
		}
	}
}
