// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "RFStylingBaseWidget.h"
#include "RFStylingWidgetData.h"
#include "RFStylingCustomizingTypeButton.h"
#include "RFStylingCustomizingTypeSelector.generated.h"

class URFStylingCustomizingWidget;

UCLASS()
class URFStylingCustomizingTypeSelector : public URFStylingBaseWidget
{
	GENERATED_BODY()

	URFStylingCustomizingTypeSelector();
	
public:
	int32 NextPresetsType(TArray<int32> PresetsType, int32 CurrentType);

	int32 PrevPresetsType(TArray<int32> PresetsType, int32 CurrentType);
	
	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void InitTypeSelector();

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCurrentAgeType(ERFStylingPresetsAgeType type);

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCurrentBodyType(ERFStylingPresetsBodyType type);

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCurrentExpressType(ERFStylingPresetsExpressType type);

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCurrentPoseType(ERFStylingPresetsPoseType type);

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	ERFStylingPresetsAgeType GetCurrentAgeType() { return CurrentAge; }

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	ERFStylingPresetsBodyType GetCurrentBodyType() { return CurrentBody; }

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	ERFStylingPresetsExpressType GetCurrentExpressType() { return CurrentExpress; }

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	ERFStylingPresetsPoseType GetCurrentPoseType() { return CurrentPose; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = RFStyling)
	URFStylingCustomizingTypeButton* GetPrevBodyTypeButton() { return PrevBodyTypeButton; }

	// for SetText
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = RFStyling)
	void ChangeCurrentAgeValue(ERFStylingPresetsAgeType CurrentType) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = RFStyling)
	void ChangeCurrentBodyValue(ERFStylingPresetsBodyType CurrentType) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = RFStyling)
	void ChangeCurrentExpressValue(ERFStylingPresetsExpressType CurrentType) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = RFStyling)
	void ChangeCurrentPoseValue(ERFStylingPresetsPoseType CurrentType) const;

public:
	// Type Select
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	TArray<ERFStylingPresetsAgeType> AgeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	TArray<ERFStylingPresetsBodyType> BodyType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	TArray<ERFStylingPresetsExpressType> ExpressType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RFStyling)
	TArray<ERFStylingPresetsPoseType> PoseType;

	// Color Picker
	

	// Bind Button
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class URFStylingCustomizingTypeButton* NextBodyTypeButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class URFStylingCustomizingTypeButton* PrevBodyTypeButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class URFStylingCustomizingTypeButton* NextExpressTypeButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class URFStylingCustomizingTypeButton* PrevExpressTypeButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class URFStylingCustomizingTypeButton* NextPoseTypeButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class URFStylingCustomizingTypeButton* PrevPoseTypeButton;

	// System
	UPROPERTY(BlueprintReadWrite, Category = RFStyling)
	TObjectPtr<URFStylingCustomizingWidget> Owner;

	UPROPERTY(BlueprintReadWrite, Category = RFStyling)
	TArray<URFStylingCustomizingTypeButton*> TypeButtons;

private:
	ERFStylingPresetsAgeType CurrentAge;

	ERFStylingPresetsBodyType CurrentBody;

	ERFStylingPresetsExpressType CurrentExpress;

	ERFStylingPresetsPoseType CurrentPose;
};