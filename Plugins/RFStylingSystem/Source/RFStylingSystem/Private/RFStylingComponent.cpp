// Copyright 2024 RedFlowering, All Rights Reserved.

#include "RFStylingComponent.h"
#include "GameFramework/Character.h"

URFStylingComponent::URFStylingComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void URFStylingComponent::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* RootCharacter = GetOwner<ACharacter>();

	if(!IsValid(RootCharacter) || !IsValid(StylingActor))
		return;

	MergeStylingMesh();
}

void URFStylingComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void URFStylingComponent::MergeStylingMesh()
{
	// CharacterData
	
	// BodyPartData

	// StylingData

	// Merge
}
