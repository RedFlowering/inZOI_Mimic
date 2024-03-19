// Copyright 2024 RedFlowering, All Rights Reserved.

#include "Widget/RFStylingBaseButton.h"
#include "Widget/RFStylingWidgetData.h"
#include "Blueprint/WidgetBlueprintGeneratedClass.h"
#include "WidgetBlueprint.h"
#include "Blueprint/WidgetTree.h"
#include "Kismet2/BlueprintEditorUtils.h"

void URFStylingBaseButton::NativeConstruct()
{
	Super::NativeConstruct();
	/*
	UWidgetBlueprintGeneratedClass* WidgetBGC = Cast<UWidgetBlueprintGeneratedClass>(GetClass());

	UPackage* Package = WidgetBGC->GetPackage();
	UWidgetBlueprint* MainAsset = Cast<UWidgetBlueprint>(Package->FindAssetInPackage());

	Button = MainAsset->WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
	Text = MainAsset->WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());

	MainAsset->Modify();
	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(MainAsset);

	if (!IsValid(Button) && !IsValid(Text))
		return;

	Button->AddChild(Text);
	*/

	// 위젯 텍스트와 텍스쳐는 Localization을 위해 Table 작성 필요
	FButtonStylingData ButtonData;

	if (GetThemeButtonStyle(ButtonID, ButtonData))
	{
		Button->SetStyle(ButtonData.Style);
		Button->SetColorAndOpacity(ButtonData.ColorAndOpacity);
		Button->SetBackgroundColor(ButtonData.BackgroundColor);

		Text->SetText(FText::FromString(ButtonData.Text));
	}

	Button->OnClicked.AddDynamic(this, &URFStylingBaseButton::OnClick);

	ClickEvent.AddDynamic(this, &URFStylingBaseButton::OnClickEvent);
}

void URFStylingBaseButton::OnClick()
{
	ClickEvent.Broadcast();
}

void URFStylingBaseButton::OnClickEvent()
{

}
