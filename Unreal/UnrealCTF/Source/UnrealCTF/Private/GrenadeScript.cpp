#include "GrenadeScript.h"
#include "NiagaraFunctionLibrary.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Components/SphereComponent.h>
#include "Engine/World.h"
#include "DrawDebugHelpers.h" // (Optional, for visual debugging)
#include <ClientObject.h>


// Sets default values for this component's properties
UGrenadeScript::UGrenadeScript()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrenadeScript::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn)
	{
		CameraComponent = PlayerPawn->FindComponentByClass<UCameraComponent>();
		if (CameraComponent)
		{
			FVector CameraForward = CameraComponent->GetForwardVector();
		}
	}

	if (GetOwner()->GetComponentByClass<UClientObject>()->IsLocal == true)
	{
		USphereComponent* MeshComp = Cast<USphereComponent>(GetOwner()->FindComponentByClass<USphereComponent>());
		UClientObject* clientScript = Cast<UClientObject>(GetOwner()->FindComponentByClass<UClientObject>());
		//MeshComp->SetSimulatePhysics(true);
		if (MeshComp && CameraComponent && clientScript->IsLocal)
		{
			// Apply force based on the camera's forward vector
			FVector ForceDirection = CameraComponent->GetForwardVector();
			MeshComp->AddForce(ForceDirection * throwStrength, NAME_None, true);

		}
	}

	// ...

}


// Called every frame
void UGrenadeScript::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (dead)
		return;

	// Ensure the actor hasn't already been marked for destruction
	if (GetOwner() == nullptr)
	{
		return;
	}

	currTime += DeltaTime;

	if (currTime >= timer + 2.0f && GetOwner()->FindComponentByClass<UClientObject>()->IsLocal)
	{
		AActor* Owner = GetOwner();
		if (Owner && !Owner->IsPendingKill())
		{
			int ID = GetOwner()->FindComponentByClass<UClientObject>()->GlobalID;
			AServerManager::instance->SendMessage("OBJECT_DESTROYED\n" + FString::FromInt(ID));
			dead = true;
		}
	}
	else if (currTime >= timer)
	{
		Explode();
	}
	// ...
}

void UGrenadeScript::Explode()
{
	if (!explode)
	{
		return;
	}
	else
	{

		explode = false;
		// Spawn the Niagara effect
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(),
			NiagaraEffect,
			GetOwner()->GetActorLocation(),
			FRotator::ZeroRotator
		);

		this->CheckExplosion();


		AServerManager::instance->SendMessage("OBJECT_DESTROYED\n" + GetOwner()->GetComponentByClass<UClientObject>()->GlobalID);

		UE_LOG(LogTemp, Warning, TEXT("Niagara effect spawned successfully!"));
	}
}

void UGrenadeScript::CheckExplosion()
{
	FVector3d explosionCentre = GetOwner()->GetActorLocation();

	// Array to store the hit results
	TArray<FOverlapResult> OverlapResults;

	// Define collision query parameters
	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;
	//QueryParams.AddIgnoredActor(this->GetOwner()); // Ignore the actor causing the explosion

	// Define collision object type (e.g., physics bodies)
	FCollisionObjectQueryParams ObjectQueryParams(ECollisionChannel::ECC_Pawn);

	// Perform the overlap check
	bool bHasHit = GetWorld()->OverlapMultiByObjectType(
		OverlapResults,               // Array to store results
		explosionCentre,              // Center of the sphere
		FQuat::Identity,              // Rotation
		ObjectQueryParams,            // Object types to query
		FCollisionShape::MakeSphere(radius), // The sphere shape and radius
		QueryParams                   // Query parameters
	);

	// Debug: Draw the explosion sphere
	DrawDebugSphere(GetWorld(), explosionCentre, radius, 32, FColor::Red, false, 2.0f);

	// Process hit results
	if (bHasHit)
	{

		for (const FOverlapResult& Result : OverlapResults)
		{
			AActor* HitActor = Result.GetActor();
			if (!HitActor)
				continue;


			ACharacter* HitCharacter = Cast<ACharacter>(HitActor);
			if (HitCharacter)
			{
				FVector LaunchForce = FVector(HitCharacter->GetActorLocation() - explosionCentre).GetSafeNormal() * 1000.0f;
				bool bXYOverride = true;  // Override current movement in X/Y
				bool bZOverride = true;   // Override current movement in Z

				HitCharacter->LaunchCharacter(LaunchForce, bXYOverride, bZOverride);

			}
			//else
			//{
			//	AActor* clientObj = Cast<AActor>(HitActor);
			//	if (clientObj)
			//	{
			//		
			//	}
			//}

			if (GetOwner()->GetComponentByClass<UClientObject>()->IsLocal && HitActor->FindComponentByClass<UPlayerClientScript>() != nullptr)
			{
				AServerManager::instance->PlayerHit(HitActor->GetComponentByClass<UPlayerClientScript>(), false, 80);
				GetOwner()->SetActorLocation(FVector(0.0f,0.0f,0.0f));
				//FPlatformProcess::Sleep(2.0f);
				//GetWorld()->DestroyActor(GetOwner());
			}
		}
	}
}

