// Fill out your copyright notice in the Description page of Project Settings.
#include "PlayerStats.h"
#include "ServerManager.h"
#include <Kismet/GameplayStatics.h>
#include "FlagScript.h"


// Sets default values for this component's properties
UPlayerStats::UPlayerStats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerStats::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	script = Owner->GetComponentByClass<UPlayerClientScript>();

	health = 100;

	// ...
	
}


// Called every frame
void UPlayerStats::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (health <= 0 && !dead)
	{

		UWorld* World = GetWorld();
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsWithTag(World, "Flag", FoundActors);
		UFlagScript* f1 = FoundActors[0]->GetComponentByClass<UFlagScript>();
		UFlagScript* f2 = FoundActors[1]->GetComponentByClass<UFlagScript>();
		if (f1 == NULL || f2 == NULL)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("NO FLAGS"));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("FLAGS"));
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("FLAG ID: " + FString::FromInt(f1->carrierID) + " Current ID: " + FString::FromInt(GetOwner()->GetComponentByClass<UPlayerClientScript>()->ID)));
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("FLAG 2 ID: " + FString::FromInt(f2->carrierID)));

			if (f1->carrierID == GetOwner()->GetComponentByClass<UPlayerClientScript>()->ID)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("FLAG DROPPED "));

				f1->Reset();
				AServerManager::instance->SendMessage("FLAG_DROPPED\n" + FString::FromInt(f1->team));

			}
			if (f2->carrierID == GetOwner()->GetComponentByClass<UPlayerClientScript>()->ID)
			{
				f2->Reset();
				AServerManager::instance->SendMessage("FLAG_DROPPED\n" + FString::FromInt(f2->team));
			}
		}

		UE_LOG(LogTemp, Log, TEXT("DIED"));
		AServerManager::instance->PlayerHit(script, true);
		//health = 100;
		dead = true;
	}
	if (health >= 100)
	{
		dead = false;
	}
	// ...
}

