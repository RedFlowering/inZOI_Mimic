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

// Localization �� ���� ���̺� ����
// Button Style Table
// �׳� ��Ʈ�� ���̺� ���°� ���� �� ��
// ���̺�� ���� �Ǿ��־ �ٹ̴°� ���� ���鼭 �ؾ�..
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
