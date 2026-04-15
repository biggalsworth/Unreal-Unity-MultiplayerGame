// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"  // Ensure USceneComponent is recognized
#include "InputAction.h"                // Required for UInputAction
#include "ServerManager.h"
#include "PlayerCombat.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCTF_API UPlayerCombat : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerCombat();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool canShoot = true;
	float cooldown = 0.5f;
	bool canGrenade = true;
	float grenadeCooldown = 20.0f;


	UFUNCTION()
	void Shoot();
	void Grenade();

	AServerManager* server;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs") UInputAction* IAShoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs") UInputAction* IAGrenade;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) USceneComponent* MySceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prefabs") TSubclassOf<AActor> GrenadePrefab;
		
};
