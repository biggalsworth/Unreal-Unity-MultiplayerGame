// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerClientScript.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCTF_API UPlayerClientScript : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerClientScript();
	UPROPERTY(EditAnywhere) int ID = 0;
	UPROPERTY(EditAnywhere) int LocalID;
	UPROPERTY(EditAnywhere) bool isLocal;
	UPROPERTY(EditAnywhere) int team;
	UPROPERTY(EditAnywhere) USceneComponent* CarryPos;

	UPROPERTY(EditAnywhere) int health = 100;
	UPROPERTY(EditAnywhere) int kills = 0;
	UPROPERTY(EditAnywhere) int deaths = 0;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
