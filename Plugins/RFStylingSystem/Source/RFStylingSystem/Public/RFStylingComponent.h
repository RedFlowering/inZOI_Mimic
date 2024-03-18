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

	FEquipmentCacheData() = default;

	FEquipmentCacheData(FRFStylingItemID ID, TObjectPtr<USkeletalMesh> SKM)
	{
		IteamID = ID;
		SkeletalMesh = SKM;
	}

public:
	FRFStylingItemID IteamID;

	TObjectPtr<USkeletalMesh> SkeletalMesh;
};

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Styling), meta = (BlueprintSpawnableComponent))
class RFSTYLINGSYSTEM_API URFStylingComponent : public UActorComponent
{
	GENERATED_UCLASS_BODY()

public:
	virtual void BeginPlay() override;

	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	ARFStylingActor* GetStylingActor() { return StylingActorInstance; }

	void MergeStylingMesh();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "RF Styling System")
	bool GetCharacterData(FRFStylingItemID StylingPresetID, FCharacterData& CharacterDataRef) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "RF Styling System")
	bool GetStylingPartData(FRFStylingItemID StylingPresetID, FStylingPartData& StylingPartDataRef) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "RF Styling System")
	bool GetBodyPartData(FRFStylingItemID StylingPresetID, FBodyPartData& BodyPartDataRef) const;
	
	void SetEquipmentItem(FGameplayTag ItemTag, FEquipmentCacheData EquipData);

protected:
	UFUNCTION()
	bool MergeStylingVisualMesh();

private:
	void DebugStylingActor();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Styling", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ARFStylingActor> StylingActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Styling", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ARFStylingActor> StylingActorInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Styling", meta = (AllowPrivateAccess = "true"))
	FRFStylingItemID StylingID;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Styling", meta = (AllowPrivateAccess = "true"))
	TMap<FGameplayTag, FEquipmentCacheData> EquipmentSlot;

private:
	TObjectPtr<ACharacter> RootCharacter;

	FCharacterData CharacterData;

private:
	UPROPERTY(Category = Debug, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> DebugVisualMesh;

	UPROPERTY(Category = Debug, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAnimInstance> DebugVisualAnim;
};

