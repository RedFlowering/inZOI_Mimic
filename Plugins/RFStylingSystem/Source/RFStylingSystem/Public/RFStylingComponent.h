// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "Components/ActorComponent.h"
#include "RFStylingItemID.h"
#include "RFStylingActor.h"
#include "RFStylingComponent.generated.h"

class ACharacter;

// Equipment Data
USTRUCT(BlueprintType)
struct RFSTYLINGSYSTEM_API FEquipmentCacheData
{
	GENERATED_BODY()

public:
	FRFStylingItemID ItemID;

	TObjectPtr<USkeletalMesh> SkeletalMesh;

	bool bMergeable = true;

	FTransform OffsetTransform = FTransform(FQuat::Identity, FVector::ZeroVector, FVector::ZeroVector);

	TSubclassOf<UAnimInstance> AnimClass = nullptr;
};

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Styling), meta = (BlueprintSpawnableComponent))
class RFSTYLINGSYSTEM_API URFStylingComponent : public UActorComponent
{
	GENERATED_UCLASS_BODY()

public:
	virtual void BeginPlay() override;

	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	ARFStylingActor* GetStylingActorInstancne() { return StylingActorInstance; }

	UFUNCTION(BlueprintCallable, Category = "RF Styling System")
	void SetEquipmentItem(FGameplayTag ItemTag, FEquipmentCacheData EquipData);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "RF Styling System")
	bool GetCharacterData(FRFStylingItemID StylingPresetID, FCharacterData& CharacterDataRef) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "RF Styling System")
	bool GetStylingPartData(FRFStylingItemID StylingPresetID, FStylingPartData& StylingPartDataRef) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "RF Styling System")
	bool GetBodyPartData(FRFStylingItemID StylingPresetID, FBodyPartData& BodyPartDataRef) const;

protected:
	void InitStylingMesh();

	bool MergeStylingVisualMesh();

private:
	void DebugStylingActor();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Styling", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ARFStylingActor> StylingActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Styling", meta = (AllowPrivateAccess = "true"))
	FRFStylingItemID StylingID;
	
private:
	TObjectPtr<ACharacter> RootCharacter;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ARFStylingActor> StylingActorInstance;

	FCharacterData CharacterData;

	TMap<FGameplayTag, FEquipmentCacheData> EquipmentSlot;

private:
	UPROPERTY(Category = Debug, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> DebugVisualMesh;

	UPROPERTY(Category = Debug, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAnimInstance> DebugVisualAnim;
};

