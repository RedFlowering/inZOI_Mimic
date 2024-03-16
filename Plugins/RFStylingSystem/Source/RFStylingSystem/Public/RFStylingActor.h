// Copyright 2024 RedFlowering, All Rights Reserved.

#pragma once 

#include "GameFramework/Actor.h"
#include "RFStylingData.h"
#include "RFStylingActor.generated.h"

UCLASS(Blueprintable, ClassGroup = (Styling))
class RFSTYLINGSYSTEM_API ARFStylingActor : public AActor
{
	GENERATED_BODY()

public:
	ARFStylingActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	USkeletalMeshComponent* GetVisualMesh() {return VisualMesh;}

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "RF Styling System")
	bool SetStylingData() const;

protected:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> VisualMesh;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDataTable> CharacterData;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDataTable> BodyParts;

	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDataTable> StylingParts;
};

