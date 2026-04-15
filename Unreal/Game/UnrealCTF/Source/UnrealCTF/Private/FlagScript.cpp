// Fill out your copyright notice in the Description page of Project Settings.

#include "FlagScript.h"
#include <UnrealCTF/UnrealCTFCharacter.h>
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
UFlagScript::UFlagScript()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//// Create the collision component
	//CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
	//CollisionComponent->SetCollisionProfileName(TEXT("Trigger"));
	////RootComponent = CollisionComponent;
	//
	//// Bind the overlap event
	//CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &UFlagScript::OnOverlapBegin);
	server = AServerManager::instance;
}


// Called when the game starts
void UFlagScript::BeginPlay()
{
	Super::BeginPlay();
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
			CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &UFlagScript::OnOverlapBegin);
		}
	}

	CarryFlag->SetActorHiddenInGame(true);  // Hides the carried flag

}


// Called every frame
void UFlagScript::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (carrierID != 0)
	{
		TArray<AActor*> FoundPlayers;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), UPlayerClientScript::StaticClass(), FoundPlayers);

		for (int i = 0; i < AServerManager::instance->NetworkObjects.Num(); i++)
		{
			UPlayerClientScript* player = AServerManager::instance->NetworkObjects[i];
			if (player->ID == carrierID)
			{
				CarryFlag->SetActorHiddenInGame(false);  // Shows the flag

				CarryFlag->AttachToComponent(player->CarryPos, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

				CarryFlag->SetActorRelativeLocation(FVector::ZeroVector);
			}
		}

		if (GetOwner()->GetComponentByClass<UStaticMeshComponent>()->IsVisible())
		{
			GetOwner()->GetComponentByClass<UStaticMeshComponent>()->SetVisibility(false);
		}
	}
	else 
	{
		if (GetOwner()->GetComponentByClass<UStaticMeshComponent>()->IsVisible() == false)
		{
			GetOwner()->GetComponentByClass<UStaticMeshComponent>()->SetVisibility(true);
		}
	}
}

void UFlagScript::Reset()
{
	carrierID = 0;
	CarryFlag->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	CarryFlag->SetActorHiddenInGame(true);  // Hides the carried flag

}

// Overlap event function
void UFlagScript::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetOwner() && carrierID == 0)
	{
		AUnrealCTFCharacter* Player = Cast<AUnrealCTFCharacter>(OtherActor);
		UPlayerClientScript* script = Player->FindComponentByClass<UPlayerClientScript>();

		if (Player && script->team == team)
		{
			UE_LOG(LogTemp, Warning, TEXT("Player %s picked up the flag!"), *Player->GetName());

			CarryFlag->SetActorHiddenInGame(false);  // Shows the flag

			carrierID = script->ID;
			server->FlagCapture(FString::FromInt(script->ID), FString::FromInt(script->team), 0);

			CarryFlag->AttachToComponent(script->CarryPos, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

			CarryFlag->SetActorRelativeLocation(FVector::ZeroVector);
		}
	}
}

