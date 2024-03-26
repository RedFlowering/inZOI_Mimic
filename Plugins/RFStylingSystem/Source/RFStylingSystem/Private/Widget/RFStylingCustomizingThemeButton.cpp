// Copyright 2024 RedFlowering, All Rights Reserved.

#include "Widget/RFStylingCustomizingThemeButton.h"
#include "Widget/RFStylingCustomizingWidget.h"
#include "Interface/CustomizingWidgetInterface.h"
#include "Blueprint/WidgetTree.h"

URFStylingCustomizingThemeButton::URFStylingCustomizingThemeButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void URFStylingCustomizingThemeButton::OnClick()
{
	Super::OnClick();
}

void URFStylingCustomizingThemeButton::OnClickEvent()
{
	// Super::OnClickEvent()

	UE_LOG(LogTemp, Warning, TEXT("ButtonID : %d Click!"), ButtonID.GetID_PartTypeAll());

	ICustomizingWidgetInterface* Interface;

	if (Owner)
	{
		Interface = Cast<ICustomizingWidgetInterface>(Owner);

		if(!Interface)
			return;

		Interface->SetOnClickThemeButton(ButtonID);
	}
}

void URFStylingCustomizingThemeButton::SetActivateThemeButton()
{
	SelectedButton();
}

void URFStylingCustomizingThemeButton::SetDeactivateThemeButton()
{
	UnselectedButton();
}
