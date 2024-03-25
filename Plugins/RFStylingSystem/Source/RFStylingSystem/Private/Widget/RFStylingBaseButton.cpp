// Copyright 2024 RedFlowering, All Rights Reserved.

#include "Widget/RFStylingBaseButton.h"
#include "Widget/RFStylingWidgetData.h"
#include "Blueprint/WidgetBlueprintGeneratedClass.h"
#include "WidgetBlueprint.h"
#include "Blueprint/WidgetTree.h"
#include "Kismet2/BlueprintEditorUtils.h"



URFStylingBaseButton::URFStylingBaseButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void URFStylingBaseButton::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Button->OnClicked.AddDynamic(this, &URFStylingBaseButton::OnClick);

	ClickEvent.AddDynamic(this, &URFStylingBaseButton::OnClickEvent);
}

void URFStylingBaseButton::OnClick()
{
	ClickEvent.Broadcast();
}

void URFStylingBaseButton::OnClickEvent()
{
	UE_LOG(LogTemp, Warning, TEXT("Click!"));
}

bool URFStylingBaseButton::InitButtonStyle(float ButtonAlpha)
{
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
	FStylingButtonData ButtonData;

	if (GetButtonStyle(ButtonID, ButtonData))
	{
		Button->SetStyle(ButtonData.ButtonStyle);
		Button->SetColorAndOpacity(ButtonData.ButtonColorAndOpacity);
		ButtonData.ButtonBackgroundColor.A = ButtonAlpha;
		Button->SetBackgroundColor(ButtonData.ButtonBackgroundColor);

		Text->SetStyle(nullptr);
		Text->SetText(FText::FromString(ButtonData.Text));
		Text->SetFont(ButtonData.TextFont);
		Text->SetColorAndOpacity(ButtonData.TextColorAndOpacity);

		return true;
	}

	return false;
}

bool URFStylingBaseButton::SelectedButton()
{
	return InitButtonStyle(1.0f);
}

bool URFStylingBaseButton::UnselectedButton()
{
	return InitButtonStyle(0.0f);
}
