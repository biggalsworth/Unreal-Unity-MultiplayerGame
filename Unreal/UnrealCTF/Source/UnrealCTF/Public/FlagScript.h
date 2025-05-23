// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/ActorComponent.h"
#include "ServerManager.h"
#include "FlagScript.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCTF_API UFlagScript : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFlagScript();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    void Reset();

    void Carry();

    // Root component
    UPROPERTY(VisibleAnywhere, Category = "Components")
    class USceneComponent* Root;

    // Collision box
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* CollisionBox;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision") UBoxComponent* CollisionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flag Settings")
    AActor* CarryFlag;
    AServerManager* server;

    UPROPERTY(EditAnywhere) int team = 0;

    UPROPERTY(EditAnywhere) int carrierID = 0;

    // Called when something enters the collision box
    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

		
};
