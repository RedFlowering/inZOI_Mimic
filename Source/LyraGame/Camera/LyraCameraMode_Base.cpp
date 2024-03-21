// Copyright 2024 RedFlowering, All Rights Reserved.

#include "LyraCameraMode_Base.h"
#include "GameFramework/Character.h"
#include "SpringArmComponentBase.h"
#include "Components/CapsuleComponent.h"

ULyraCameraMode_Base::ULyraCameraMode_Base()
{

}

void ULyraCameraMode_Base::OnActivation()
{
	SpringArm = GetTargetActor()->FindComponentByClass<USpringArmComponentBase>();

	if (SpringArm)
	{
		SpringArm->SetViewPitchMinMax(ViewPitchMin, ViewPitchMax);
		SpringArm->SetRelativeLocation(FVector::ZeroVector);
		
		SpringArm->TargetArmLength = SpringArmLength;
		SpringArm->SetZoomSensitivity(ZoomSensitivity);
		SpringArm->SetMinZoomValue(MinZoomValue);
		SpringArm->SetMaxZoomValue(MaxZoomValue);

		SpringArm->bUsePawnControlRotation = bUsePawnControlRotation;

		SpringArm->bDoCollisionTest = true;
		SpringArm->bEnableCameraLag = bEnableCameraLag;
		SpringArm->bEnableCameraRotationLag = bEnableCameraRotationLag;
		SpringArm->CameraLagSpeed = CameraLagSpeed;
		SpringArm->CameraRotationLagSpeed = CameraRotationLagSpeed;
		SpringArm->SetUseTargetArmLagSubstepping(bUseSpringArmLagSubstepping);
		SpringArm->SetTargetArmLagMaxTimeStep(SpringArmLagMaxTimeStep);
		SpringArm->bUseCameraLagSubstepping = bUseCameraLagSubstepping;
		SpringArm->CameraLagMaxTimeStep = CameraLagMaxTimeStep;
	}	
}

void ULyraCameraMode_Base::OnDeactivation()
{
	SpringArm = nullptr;
}

void ULyraCameraMode_Base::UpdateView(float DeltaTime)
{		
	if (SpringArm)
	{		
		FTransform Trans = SpringArm->GetSocketTransform(USpringArmComponent::SocketName, ERelativeTransformSpace::RTS_World);
		
		// Camera
		View.Location = Trans.GetLocation();
		View.Rotation = Trans.GetRotation().Rotator();
		View.ControlRotation = View.Rotation;
		View.FieldOfView = FieldOfView;

		// Spring Arm
		Arm.Location = GetPivotLocation();
		Arm.Rotation = GetPivotRotation();
		Arm.Length = GetSpringArmLength();
	}
}

FVector ULyraCameraMode_Base::GetPivotLocation() const
{
	const AActor* TargetActor = GetTargetActor();
	check(TargetActor);

	if (const APawn* TargetPawn = Cast<APawn>(TargetActor))
	{
		// Height adjustments for characters to account for crouching.
		if (const ACharacter* TargetCharacter = Cast<ACharacter>(TargetPawn))
		{
			const ACharacter* TargetCharacterCDO = TargetCharacter->GetClass()->GetDefaultObject<ACharacter>();
			check(TargetCharacterCDO);

			const UCapsuleComponent* CapsuleComp = TargetCharacter->GetCapsuleComponent();
			check(CapsuleComp);

			const UCapsuleComponent* CapsuleCompCDO = TargetCharacterCDO->GetCapsuleComponent();
			check(CapsuleCompCDO);

			const float DefaultHalfHeight = CapsuleCompCDO->GetUnscaledCapsuleHalfHeight();
			const float ActualHalfHeight = CapsuleComp->GetUnscaledCapsuleHalfHeight();
			const float HeightAdjustment = (DefaultHalfHeight - ActualHalfHeight) + TargetCharacterCDO->BaseEyeHeight + AdjustPivotHeight;

			const FVector ActualCapsuleRight = CapsuleComp->GetRightVector();

			return (FVector::UpVector * HeightAdjustment) + (ActualCapsuleRight * AdjustPivotRight);
		}

		return FVector::ZeroVector;
	}

	return FVector::ZeroVector;
}

FRotator ULyraCameraMode_Base::GetPivotRotation() const
{
	const AActor* TargetActor = GetTargetActor();
	check(TargetActor);

	if (const APawn* TargetPawn = Cast<APawn>(TargetActor))
	{
		return FRotator3d::ZeroRotator + AdjustPivotRotate;
	}

	return FRotator3d::ZeroRotator;
}

float ULyraCameraMode_Base::GetSpringArmLength() const
{
	const AActor* TargetActor = GetTargetActor();
	check(TargetActor);

	USpringArmComponent* TargetArm = TargetActor->GetComponentByClass<USpringArmComponentBase>();

	return TargetArm->TargetArmLength;
}
