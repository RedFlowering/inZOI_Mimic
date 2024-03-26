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

int32 URFStylingCustomizingWidget::SetOnClickTypeButton(bool IsNext, TArray<int32> ValueList, int32 CurrentValue)
{
	if (IsNext)
	{
		return TypeSelector->NextPresetsType(ValueList, CurrentValue);
	}
	else
	{
		return TypeSelector->PrevPresetsType(ValueList, CurrentValue);
	}

	return 0;
}

void URFStylingCustomizingWidget::SetAgeType(ERFStylingPresetsAgeType Age)
{
	// CustomizingMannequin 나이 조절
	// Face 관련 BlendShape 파라미터 등 세팅
}

void URFStylingCustomizingWidget::SetBodyType(ERFStylingPresetsBodyType Body)
{
	// CustomizingMannequin 체형 조절
	// Body 관련 BlendShape 파라미터 등 세팅
}

void URFStylingCustomizingWidget::SetExpressType(ERFStylingPresetsExpressType Express)
{
	// CustomizingMannequin 표정 조절
	// head의 본은 VisualMesh에 있어서 RFStylingcomponent에서 참조
	// head SkeletalMesh를 Body SkeletalMesh에 머지했으면 
	// 애니메이션 재생하되 head 본의 하위 계층 본들만 플레이 해야함
}

void URFStylingCustomizingWidget::SetPoseType(ERFStylingPresetsPoseType Pose)
{
	// CustomizingMannequin 포즈 애니메이션 재생
	// Switch문으로 PalyMontage 또는 커스터마이징 전용 AnimBlueprint 제작
}
