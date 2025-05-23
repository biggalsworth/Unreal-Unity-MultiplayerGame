// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ServerManager.h"
#include "ClientObject.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, DefaultToInstanced)
class UNREALCTF_API UClientObject : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UClientObject();
	UClientObject(bool local);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	void SetLocal();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


	UPROPERTY(EditAnywhere, Category = "Type Settings")
	ObjTypes type;

	UPROPERTY(EditAnywhere, Category = "Parameters")
	bool IsLocal;


	UPROPERTY(VisibleAnywhere)
	int LocalID;
	UPROPERTY(VisibleAnywhere)
	int GlobalID;

	AServerManager* manager;
};
