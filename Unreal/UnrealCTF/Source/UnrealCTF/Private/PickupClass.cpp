// Fill out your copyright notice in the Description page of Project Settings.
#include "PickupClass.h"
#include <Components/SphereComponent.h>
#include <PlayerClientScript.h>
#include <ClientObject.h>

// Sets default values for this component's properties
UPickupClass::UPickupClass()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPickupClass::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->GetComponentByClass<USphereComponent>()->OnComponentBeginOverlap.AddDynamic(this, &UPickupClass::OnOverlapBegin);

	// ...
	
}


// Called every frame
void UPickupClass::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPickupClass::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetOwner())
	{ 
		UE_LOG(LogTemp, Log, TEXT("TRYING HEAL"))
		AActor* Player = Cast<AActor>(OtherActor);
		UPlayerClientScript* script = Player->FindComponentByClass<UPlayerClientScript>();

		if (Player && script && Player->FindComponentByClass<UPlayerStats>())
		{
			if (Player->FindComponentByClass<UPlayerStats>()->health <= 0)
				return;

			AServerManager::instance->SendMessage("HEAL\n" + FString::FromInt(script->ID));
			AServerManager::instance->SendMessage("OBJECT_DESTROYED\n" + FString::FromInt(GetOwner()->GetComponentByClass<UClientObject>()->GlobalID));

		}
	}

}

