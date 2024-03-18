// Copyright 2024 RedFlowering, All Rights Reserved.

#include "RFStylingComponent.h"
#include "RFStylingSystem.h"
#include "GameFramework/Character.h"
#include "SkeletalMeshMerge.h"

URFStylingComponent::URFStylingComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void URFStylingComponent::BeginPlay()
{
	Super::BeginPlay();

	RootCharacter = GetOwner<ACharacter>();

	if(!IsValid(RootCharacter) || !IsValid(StylingActor))
		return;

	UChildActorComponent* ChildActorComp = NewObject<UChildActorComponent>(RootCharacter);

	if (IsValid(ChildActorComp))
	{
		ChildActorComp->SetupAttachment(RootCharacter->GetMesh());
		ChildActorComp->SetChildActorClass(StylingActor);
		ChildActorComp->RegisterComponent();

		ARFStylingActor* ChildActor = Cast<ARFStylingActor>(ChildActorComp->GetChildActor());

		if (IsValid(ChildActor))
		{
			StylingActorInstance = ChildActor;
			StylingActorInstance->SetOwner(RootCharacter);
		}
	}

	// Init Character Styling
	InitStylingMesh();

	// Child Actor Debug
	DebugStylingActor();
}

void URFStylingComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	StylingActorInstance = nullptr;

	Super::EndPlay(EndPlayReason);
}

void URFStylingComponent::InitStylingMesh()
{
	if (!IsValid(RootCharacter))
		return;

	// CharacterData : 메인 골조 먼저 세팅
	if (GetCharacterData(StylingID, CharacterData))
	{
		USkeletalMesh* CharacterMeshData = CharacterData.VisualMeshClass.LoadSynchronous();
		SetEquipmentItem(CharacterData.CharacterTypeTag, FEquipmentCacheData(StylingID, CharacterMeshData));

		for (auto& Elem : CharacterData.DefaultPresetTags)
		{
			// StylingData : 메인 골조에 옷 입히기
			FRFStylingItemID StylingItemID = Elem.Value.GetID_PartTypeAll();
			FStylingPartData StylingPartData;
			FBodyPartData BodyPartData;

			if (GetStylingPartData(StylingItemID, StylingPartData))
			{
				if (StylingPartData.StylingPartTag.MatchesTag(Elem.Key))
				{
					USkeletalMesh* StylingMeshData = StylingPartData.StylingPartClass.LoadSynchronous();
					SetEquipmentItem(StylingPartData.StylingPartTag, FEquipmentCacheData(StylingItemID, StylingMeshData));

					continue;
				}
			}

			// BodyPartData : 메인 골조와 옷 입히고 난 후 남는 부분 바디 파츠로 채우기
			if (GetBodyPartData(StylingItemID, BodyPartData))
			{
				if (!BodyPartData.BodyPartTag.MatchesTag(Elem.Key))
					continue;

				USkeletalMesh* BodyMeshData = BodyPartData.BodyPartClass.LoadSynchronous();
				SetEquipmentItem(BodyPartData.BodyPartTag, FEquipmentCacheData(StylingItemID, BodyMeshData));
			}
		}
	}
}

void URFStylingComponent::SetEquipmentItem(FGameplayTag ItemTag, FEquipmentCacheData EquipData)
{
	EquipmentSlot.Emplace(ItemTag, EquipData);

	MergeStylingVisualMesh();
}

bool URFStylingComponent::MergeStylingVisualMesh()
{
	if (EquipmentSlot.Num() > 0)
	{
		USkeletalMesh* TargetMesh = NewObject<USkeletalMesh>(RootCharacter->GetWorld(), MakeUniqueObjectName(RootCharacter->GetWorld(), USkeletalMesh::StaticClass(), TEXT("NewMesh_")));

		TArray<FSkelMeshMergeSectionMapping> SectionMappings;

		if (!IsValid(TargetMesh))
			return false;

		FEquipmentCacheData* CharacterCacheData = EquipmentSlot.Find(CharacterData.CharacterTypeTag);

		USkeleton* BaseSkeleton = CharacterCacheData->SkeletalMesh->GetSkeleton();

		if (!IsValid(BaseSkeleton))
			return false;

		TargetMesh->SetSkeleton(BaseSkeleton);

		TArray<USkeletalMesh*> MergeMeshes;
		MergeMeshes.Empty();

		for (auto& Elem : EquipmentSlot)
		{
			MergeMeshes.Add(Elem.Value.SkeletalMesh);
		}

		FSkeletalMeshMerge Merger(TargetMesh, MergeMeshes, SectionMappings, 0);

		if (Merger.DoMerge())
		{
			StylingActorInstance->GetVisualMesh()->SetSkeletalMesh(TargetMesh);
			StylingActorInstance->GetVisualMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
			StylingActorInstance->GetVisualMesh()->SetAnimClass(CharacterData.AnimClass);
			return true;
		}
		else
		{
			UE_LOG(RFLogSystem, Warning, TEXT("[RF Styling System] Skeltal Mesh Merge Failed!"));

			return false;
		}
	}

	return false;
}

// Debug : 차일듸 액터의 머지 결과물 보는 용도
void URFStylingComponent::DebugStylingActor()
{
	DebugVisualMesh = StylingActorInstance->GetVisualMesh();
	DebugVisualAnim = StylingActorInstance->GetVisualMesh()->GetAnimInstance();
}
