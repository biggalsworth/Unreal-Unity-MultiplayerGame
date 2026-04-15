// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "ServerManager.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "GrenadeScript.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCTF_API UGrenadeScript : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrenadeScript();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void CheckExplosion();
	void Explode();

	float throwStrength = 50000.0f;
	float timer = 7.0f;
	float currTime = 0.0f;
	float radius = 500.0f;
	bool explode = true;
	bool dead = false;
	

	UCameraComponent* CameraComponent;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	UNiagaraSystem* NiagaraEffect;
};
