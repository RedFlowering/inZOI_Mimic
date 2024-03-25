// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "GameplayTagContainer.h"
#include "../RFStylingItemID.h"
#include "Styling/SlateTypes.h"
#include "Fonts/SlateFontInfo.h"
#include "Math/Color.h"
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
// 그냥 스트링 테이블 쓰는게 나을 듯 ㅋ
// 테이블로 정리 되어있어도 꾸미는건 역시 보면서 해야..
USTRUCT(BlueprintType)
struct RFSTYLINGSYSTEM_API FStylingButtonData : public FTableRowBase
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
	FSlateFontInfo TextFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Button Style")
	FLinearColor TextColorAndOpacity = FLinearColor(0.0f, 0.0f, 0.0f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Button Style")
	FButtonStyle ButtonStyle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Button Style")
	FLinearColor ButtonColorAndOpacity = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Button Style")
	FLinearColor ButtonBackgroundColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);
};
