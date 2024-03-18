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

	ACharacter* RootCharacter = GetOwner<ACharacter>();

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

	MergeStylingMesh(RootCharacter);

	// Child Actor Debug
	DebugStylingActor();
}

void URFStylingComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	StylingActorInstance = nullptr;

	Super::EndPlay(EndPlayReason);
}

void URFStylingComponent::MergeStylingMesh(ACharacter* RootCharacter)
{
	if(!IsValid(RootCharacter))
		return;

	TArray<USkeletalMesh*> MergeMeshes;
	MergeMeshes.Empty();

	// CharacterData : 메인 골조 먼저 세팅
	FCharacterData CharData;

	if(GetCharacterData(StylingID, CharData))
	{
		USkeletalMesh* CharMeshData = CharData.VisualMeshClass.LoadSynchronous();
		MergeMeshes.Add(CharMeshData);

		for (auto& Elem : CharData.DefaultPresetTags)
		{
			// StylingData : 메인 골조에 옷 입히기
			FRFStylingItemID StylingItemID = Elem.Value.GetID_PartTypeAll();
			FStylingPartData StylingPartData;
			FBodyPartData BodyPartData;

			if (GetStylingPartData(StylingItemID, StylingPartData))
			{
				if (StylingPartData.StylingPartTag.HasTag(Elem.Key))
				{
					USkeletalMesh* StylingPartMeshData = StylingPartData.StylingPartClass.LoadSynchronous();

					if (StylingPartData.bMergeable)
					{
						MergeMeshes.Add(StylingPartMeshData);
					}
					else
					{
						if (StylingPartData.bUseOffsetTransform)
						{
							TArray<FGameplayTag> Array = StylingPartData.StylingPartTag.GetGameplayTagArray();

							USkeletalMeshComponent* SKMComp = NewObject<USkeletalMeshComponent>(StylingActorInstance->GetVisualMesh(), USkeletalMeshComponent::StaticClass(), Array.FindByKey(Elem.Key)->GetTagName());
							SKMComp->AttachToComponent(StylingActorInstance->GetVisualMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("root"));
							SKMComp->RegisterComponent();

							SKMComp->SetLeaderPoseComponent(StylingActorInstance->GetVisualMesh());

							SKMComp->SetRelativeTransform(StylingPartData.OffsetTransform);
							SKMComp->SetSkeletalMesh(StylingPartMeshData);
							SKMComp->SetAnimClass(StylingPartData.AnimClass);
						}
					}

					continue;
				}
			}

			// BodyPartData : 메인 골조와 옷 입히고 난 후 남는 부분 바디 파츠로 채우기
			if (GetBodyPartData(StylingItemID, BodyPartData))
			{
				if (!BodyPartData.BodyPartTag.MatchesTag(Elem.Key))
					continue;

				if (BodyPartData.bMergeable)
				{
					USkeletalMesh* BodyPartMeshData = BodyPartData.BodyPartClass.LoadSynchronous();
					MergeMeshes.Add(BodyPartMeshData);
				}
			}
		}
	}

	// Merge
	if(MergeMeshes.Num() > 0)
	{
		USkeletalMesh* TargetMesh = NewObject<USkeletalMesh>(RootCharacter->GetWorld(), MakeUniqueObjectName(RootCharacter->GetWorld(), USkeletalMesh::StaticClass(), TEXT("NewMesh_")));

		TArray<FSkelMeshMergeSectionMapping> SectionMappings;

		if(!IsValid(TargetMesh))
			return;

		USkeleton* BaseSkeleton = MergeMeshes[0]->GetSkeleton();

		if(!IsValid(BaseSkeleton))
			return;

		TargetMesh->SetSkeleton(BaseSkeleton);

		FSkeletalMeshMerge Merger(TargetMesh, MergeMeshes, SectionMappings, 0);

		if (Merger.DoMerge())
		{
			StylingActorInstance->GetVisualMesh()->SetSkeletalMesh(TargetMesh);
			StylingActorInstance->GetVisualMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
			StylingActorInstance->GetVisualMesh()->SetAnimClass(CharData.AnimClass);
		}
		else
		{
			UE_LOG(RFLogSystem, Warning, TEXT("[RF Styling System] Skeltal Mesh Merge Failed!"))
		}
	}
}

void URFStylingComponent::DebugStylingActor()
{
	DebugVisualMesh = StylingActorInstance->GetVisualMesh();
	DebugVisualAnim = StylingActorInstance->GetVisualMesh()->GetAnimInstance();
}
