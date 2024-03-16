// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "Components/ActorComponent.h"
#include "RFStylingItemID.h"
#include "RFStylingActor.h"
#include "RFStylingComponent.generated.h"

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
	bool GetCharacterData(FRFStylingItemID StylingPresetID, FCharacterData& CharacterData) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "RF Styling System")
	bool GetBodyPartData(FRFStylingItemID StylingPresetID, FBodyPartData& CharacterData) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "RF Styling System")
	bool GetStylingPartData(FRFStylingItemID StylingPresetID, FStylingPartData& CharacterData) const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Styling", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ARFStylingActor> StylingActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Styling", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ARFStylingActor> StylingActorInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Styling", meta = (AllowPrivateAccess = "true"))
	FRFStylingItemID StylingID;
};

