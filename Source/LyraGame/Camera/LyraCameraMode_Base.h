// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LyraCameraMode.h"
#include "LyraCameraMode_Base.generated.h"

class UCurveVector;
class USpringArmComponentBase;

/**
 * ULyraCameraMode_Base
 *
 *	A basic third person camera mode.
 */

UCLASS(Abstract, Blueprintable)
class ULyraCameraMode_Base : public ULyraCameraMode
{
	GENERATED_BODY()

public:
	ULyraCameraMode_Base();

	void OnActivation() override;

	void OnDeactivation() override;

protected:
	virtual void UpdateView(float DeltaTime) override;

	virtual FVector GetPivotLocation() const;

	virtual FRotator GetPivotRotation() const;

	float GetSpringArmLength() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Third Person")
	float AdjustPivotHeight = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Third Person")
	float AdjustPivotRight = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Third Person")
	FRotator AdjustPivotRotate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Third Person|Spring Arm")
	float SpringArmLength = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Third Person|Spring Arm")
	float ZoomSensitivity = 50.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Third Person|Spring Arm")
	float MinZoomValue = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Third Person|Spring Arm")
	float MaxZoomValue = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Third Person|Control")
	bool bUsePawnControlRotation = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lag")
	bool bEnableCameraLag = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lag")
	bool bEnableCameraRotationLag = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lag", meta = (editcondition = "bEnableCameraLag", ClampMin = "0.0", ClampMax = "1000.0", UIMin = "0.0", UIMax = "1000.0"))
	float CameraLagSpeed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lag", meta = (editcondition = "bEnableCameraRotationLag", ClampMin = "0.0", ClampMax = "1000.0", UIMin = "0.0", UIMax = "1000.0"))
	float CameraRotationLagSpeed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lag", AdvancedDisplay)
	bool bUseSpringArmLagSubstepping = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lag", AdvancedDisplay, meta = (editcondition = "bUseSpringArmLagSubstepping", ClampMin = "0.005", ClampMax = "0.5", UIMin = "0.005", UIMax = "0.5"))
	float SpringArmLagMaxTimeStep = 0.016667f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lag", AdvancedDisplay)
	bool bUseCameraLagSubstepping = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lag", AdvancedDisplay, meta = (editcondition = "bUseCameraLagSubstepping", ClampMin = "0.005", ClampMax = "0.5", UIMin = "0.005", UIMax = "0.5"))
	float CameraLagMaxTimeStep = 0.016667f;

protected:	
	TObjectPtr<USpringArmComponentBase> SpringArm = nullptr;
};
