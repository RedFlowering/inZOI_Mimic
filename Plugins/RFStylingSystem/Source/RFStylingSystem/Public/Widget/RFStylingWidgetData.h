// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "GameplayTagContainer.h"
#include "../RFStylingItemID.h"
#include "RFStylingWidgetData.generated.h"

// Customizing Widget Switcher Index
UENUM()
enum class ERFStylingCustomizingTheme : uint8
{
	Presets,
	Face,
	Body,
	Clothes,
	ClothesCreating,
};

// Localization 을 위한 테이블 정리
// Button Style Table
USTRUCT(BlueprintType)
struct RFSTYLINGSYSTEM_API FButtonStylingData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// String Table Key (for Export CSV)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Button Style")
	FRFStylingItemID ButtonID;
	
	// String Table String (for Export CSV)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Button Style")
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Button Style")
	FButtonStyle Style;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Button Style")
	FLinearColor ColorAndOpacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Button Style")
	FLinearColor BackgroundColor;
};
