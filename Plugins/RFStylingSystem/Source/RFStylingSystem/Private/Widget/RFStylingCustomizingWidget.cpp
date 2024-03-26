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
	// CustomizingMannequin ���� ����
	// Face ���� BlendShape �Ķ���� �� ����
}

void URFStylingCustomizingWidget::SetBodyType(ERFStylingPresetsBodyType Body)
{
	// CustomizingMannequin ü�� ����
	// Body ���� BlendShape �Ķ���� �� ����
}

void URFStylingCustomizingWidget::SetExpressType(ERFStylingPresetsExpressType Express)
{
	// CustomizingMannequin ǥ�� ����
	// head�� ���� VisualMesh�� �־ RFStylingcomponent���� ����
	// head SkeletalMesh�� Body SkeletalMesh�� ���������� 
	// �ִϸ��̼� ����ϵ� head ���� ���� ���� ���鸸 �÷��� �ؾ���
}

void URFStylingCustomizingWidget::SetPoseType(ERFStylingPresetsPoseType Pose)
{
	// CustomizingMannequin ���� �ִϸ��̼� ���
	// Switch������ PalyMontage �Ǵ� Ŀ���͸���¡ ���� AnimBlueprint ����
}
