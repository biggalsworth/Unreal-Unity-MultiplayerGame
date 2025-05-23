// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerClientScript.h"

// Sets default values for this component's properties
UPlayerClientScript::UPlayerClientScript()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerClientScript::BeginPlay()
{
	Super::BeginPlay();


	//find components int the owner
	TArray<UActorComponent*> Components;
	GetOwner()->GetComponents(USceneComponent::StaticClass(), Components);

	for (UActorComponent* Component : Components)
	{
		// Find the FlagAttach point
		if (Component && Component->GetName() == "FlagAttach")
		{
			CarryPos = Cast<USceneComponent>(Component);
			UE_LOG(LogTemp, Log, TEXT("FlagAttach found: %s"), *CarryPos->GetName());
			break;
		}
	}

	if (!CarryPos)
	{
		UE_LOG(LogTemp, Warning, TEXT("FlagAttach not found!"));
	}
	// ...
	
}


// Called every frame
void UPlayerClientScript::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

