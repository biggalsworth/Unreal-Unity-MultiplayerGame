// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealCTFGameMode.generated.h"

UCLASS(minimalapi)
class AUnrealCTFGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnrealCTFGameMode();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UClass* PlayerClass;

};



