// Fill out your copyright notice in the Description page of Project Settings.


#include "DropZone.h"

// Sets default values for this component's properties
UDropZone::UDropZone()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDropZone::BeginPlay()
{
	Super::BeginPlay();
	TeamFlag = TeamFlagActor->FindComponentByClass<UFlagScript>();

	AActor* Owner = GetOwner();
	if (Owner)
	{
		CollisionComponent = NewObject<UBoxComponent>(Owner);
		if (CollisionComponent)
		{
			CollisionComponent->RegisterComponent();
			CollisionComponent->AttachToComponent(Owner->GetRootComponent(),
				FAttachmentTransformRules::KeepRelativeTransform);
			CollisionComponent->SetCollisionProfileName(TEXT("Trigger"));

			// Bind the overlap event
			CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &UDropZone::OnOverlapBegin);
		}
	}
	
}


// Called every frame
void UDropZone::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


// Overlap event function
void UDropZone::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	///if (OtherActor && OtherActor != GetOwner())
	if (OtherActor && Cast<AUnrealCTFCharacter>(OtherActor)->FindComponentByClass<UPlayerClientScript>() != NULL)
	{
		AUnrealCTFCharacter* Player = Cast<AUnrealCTFCharacter>(OtherActor);
		UPlayerClientScript* script = Player->FindComponentByClass<UPlayerClientScript>();

		if (Player && script->ID == TeamFlag->carrierID && script->team == team)
		{
			AServerManager::instance->FlagCapture(FString::FromInt(team), "NO", 1);
			TeamFlag->Reset();
		}
	}
}



