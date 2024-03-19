// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "../RFStylingItemID.h"
#include "RFStylingBaseButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FClickEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FClickDelegate);

UCLASS()
class URFStylingBaseButton : public UUserWidget
{
	GENERATED_BODY()

private:
	virtual void NativeConstruct() override;

public:
	UFUNCTION()
	virtual void OnClick();

	UFUNCTION()
	virtual void OnClickEvent();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = RFStyling)
	bool GetThemeButtonStyle(FRFStylingItemID ButtonDataID, FButtonStylingData& ButtonDataRef) const;

public:
	UPROPERTY()
	FClickDelegate Click;

	UPROPERTY()
	FClickEvent ClickEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	FRFStylingItemID ButtonID;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* Button;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* Text;
};

