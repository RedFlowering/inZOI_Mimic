// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "RFStylingBaseWidget.h"
#include "RFStylingWidgetData.h"
#include "RFStylingCustomizingTypeSelector.generated.h"

UCLASS()
class URFStylingCustomizingTypeSelector : public URFStylingBaseWidget
{
	GENERATED_BODY()

	URFStylingCustomizingTypeSelector();
	
public:
	template <typename T>
	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void NextPresetsType(TArray<T>& PresetsType, T& CurrentType);

	template <typename T>
	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void PrevPresetsType(TArray<T>& PresetsType, T& CurrentType);
	
	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCurrentAgeType(ERFStylingPresetsAgeType type) {CurrentAge = type;}

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCurrentBodyType(ERFStylingPresetsBodyType type) { CurrentBody = type; }

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCurrentExpressType(ERFStylingPresetsExpressType type) { CurrentExpress = type; }

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	void SetCurrentPoseType(ERFStylingPresetsPosesType type) { CurrentPose = type; }

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	ERFStylingPresetsAgeType GetCurrentAgeType() { return CurrentAge; }

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	ERFStylingPresetsBodyType GetCurrentBodyType() { return CurrentBody; }

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	ERFStylingPresetsExpressType GetCurrentExpressType() { return CurrentExpress; }

	UFUNCTION(BlueprintCallable, Category = RFStyling)
	ERFStylingPresetsPosesType GetCurrentPoseType() { return CurrentPose; }

public:
	// Type Select
	TArray<ERFStylingPresetsAgeType> AgeType;

	TArray<ERFStylingPresetsBodyType> BodyType;

	TArray<ERFStylingPresetsExpressType> ExpressType;

	TArray<ERFStylingPresetsPosesType> PoseType;

	// Color Picker
	
private:
	ERFStylingPresetsAgeType CurrentAge = ERFStylingPresetsAgeType::Youth;

	ERFStylingPresetsBodyType CurrentBody = ERFStylingPresetsBodyType::BodyType1;

	ERFStylingPresetsExpressType CurrentExpress = ERFStylingPresetsExpressType::ExpressType1;

	ERFStylingPresetsPosesType CurrentPose = ERFStylingPresetsPosesType::PosesType1;
};