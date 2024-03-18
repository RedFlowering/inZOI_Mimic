// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "Engine/DataTable.h"
#include "RFStylingItemID.h"
#include "GameplayTagContainer.h"
#include "RFStylingData.generated.h"

// Styling ID
USTRUCT(BlueprintType)
struct RFSTYLINGSYSTEM_API FRFStylingData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Styling System")
	FRFStylingItemID RetargetMeshID = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RF Styling System")
	TArray<FRFStylingItemID> StylingMeshPartIDs;
};

// Retarget Mesh Data
USTRUCT(BlueprintType)
struct RFSTYLINGSYSTEM_API FCharacterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling")
	FGameplayTag CharacterTypeTag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling")
	TSoftObjectPtr<USkeletalMesh> VisualMeshClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling")
	TSubclassOf<UAnimInstance> AnimClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling", meta = (Categories = "RF Styling System"))
	TMap<FGameplayTag, FRFStylingItemID> DefaultPresetTags;
};

// Body Parts
USTRUCT(BlueprintType)
struct RFSTYLINGSYSTEM_API FBodyPartData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling", meta = (Categories = "RF Styling System"))
	FGameplayTag BodyPartTag;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling")
	bool bMergeable = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling")
	TSoftObjectPtr<USkeletalMesh> BodyPartClass = nullptr;
};

// Styling Part Data
USTRUCT(BlueprintType)
struct RFSTYLINGSYSTEM_API FStylingPartData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling", meta = (Categories = "RF Styling System"))
	FGameplayTag StylingPartTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling", meta = (Categories = "RF Styling System"))
	TArray<FRFStylingItemID> RemovePartIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mergeable")
	bool bMergeable = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling", meta = (EditCondition = "!bMergeable"))
	bool bUseOffsetTransform = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling", meta = (EditCondition = "bUseCustomTransform"))
	FTransform OffsetTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling")
	TSoftObjectPtr<USkeletalMesh> StylingPartClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling", meta = (EditCondition = "!bMergeable"))
	TSubclassOf<UAnimInstance> AnimClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Styling")
	TArray<TSoftObjectPtr<UMaterialInterface>> Materials;
};

