// Copyright 2024 RedFlowering, All Rights Reserved.

#include "RFStylingActor.h"

ARFStylingActor::ARFStylingActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	VisualMesh = CreateOptionalDefaultSubobject<USkeletalMeshComponent>(TEXT("VisualMesh"));
}