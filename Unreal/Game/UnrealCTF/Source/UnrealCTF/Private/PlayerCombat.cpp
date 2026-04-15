// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCombat.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include <PlayerClientScript.h>

#include <Camera/CameraActor.h>
#include <Camera/CameraComponent.h>
#include <ClientObject.h>


// Sets default values for this component's properties
UPlayerCombat::UPlayerCombat()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    server = AServerManager::instance;

	MySceneComponent = CreateDefaultSubobject<USceneComponent>("Shootpoint");

    UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(IAShoot);
    UEnhancedInputComponent* GrenadeAction = Cast<UEnhancedInputComponent>(IAGrenade);
    //Input->BindAction(IAShoot, ETriggerEvent::Triggered, this, &UPlayerCombat::Shoot);

}


// Called when the game starts
void UPlayerCombat::BeginPlay()
{
	Super::BeginPlay();

    //// Assuming you are inside a class that has access to the world (e.g., AActor, UActorComponent, etc.)
    //UWorld* World = GetWorld();
    //for (TObjectIterator<AServerManager> It; It; ++It)
    //{
    //    AServerManager* MeshComp = *It;
    //    if (MeshComp && MeshComp->GetWorld() == World)
    //    {
    //        UE_LOG(LogTemp, Log, TEXT("Found StaticMeshComponent in Actor: %s"), *MeshComp->GetOwner()->GetName());
    //    }
    //}

	// Get the owner of this component
	AActor* Owner = GetOwner();
	if (!Owner) return;

	// Get the player's controller
	APlayerController* PlayerController = Cast<APlayerController>(Owner->GetInstigatorController());
	if (!PlayerController) return;

	// Get the Enhanced Input System
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	if (InputSubsystem && IAShoot && IAGrenade)
	{
		// Bind the Input Action
		UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);
		if (EnhancedInput)
		{
			EnhancedInput->BindAction(IAShoot, ETriggerEvent::Started, this, &UPlayerCombat::Shoot);
			EnhancedInput->BindAction(IAGrenade, ETriggerEvent::Started, this, &UPlayerCombat::Grenade);
		}
	}
	
}


// Called every frame
void UPlayerCombat::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (PlayerPawn)
    {
        UCameraComponent* CameraComponent = PlayerPawn->FindComponentByClass<UCameraComponent>();
        if (CameraComponent)
        {
            FVector CameraForward = CameraComponent->GetForwardVector();
            FRotator CameraRotation = CameraComponent->GetComponentRotation();
            FRotator NewRotation = FRotator(0.0f, CameraRotation.Yaw, 0.0f); // Use camera's yaw
            GetOwner()->SetActorRotation(NewRotation);
            //UE_LOG(LogTemp, Warning, TEXT("Camera Forward Vector: %s"), *CameraForward.ToString());
        }
    }

    //FRotator CameraRotation = FollowCamera->GetComponentRotation();
    //
    //FRotator NewRotation = FRotator(0.0f, CameraRotation.Yaw, 0.0f); // Use camera's yaw
    //SetActorRotation(NewRotation);

	// ...
}

void UPlayerCombat::Shoot()
{

    if (canShoot == false)
        return;

	UE_LOG(LogTemp, Log, TEXT("Shooting!"));

    UE_LOG(LogTemp, Warning, TEXT("Shooting Raycast!"));

    AActor* Owner = GetOwner();
    if (!Owner) return;

    APlayerController* PlayerController = Cast<APlayerController>(Owner->GetInstigatorController());
    if (!PlayerController) return;

    FVector CameraLocation;
    FRotator CameraRotation;

    // Get the camera viewpoint
    PlayerController->GetPlayerViewPoint(CameraLocation, CameraRotation);

    // Define the raycast parameters
    FVector Start = CameraLocation;
    FVector End = Start + (CameraRotation.Vector() * 10000.0f); // 5000 units forward

    FHitResult HitResult;
    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(Owner); // Ignore the player itself

    // Perform the line trace (raycast)
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, QueryParams);

    // Draw debug line for visualization
    DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.0f, 0, 2.0f);

    if (bHit)
    {
        // Log what was hit
        UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitResult.GetActor()->GetName());
        AActor* actor = HitResult.GetActor();
        if (HitResult.GetActor()->FindComponentByClass<UPlayerClientScript>() != NULL)
        {
            if (actor->GetComponentByClass<UPlayerClientScript>()->team != Owner->GetComponentByClass<UPlayerClientScript>()->team)
            {
                UE_LOG(LogTemp, Warning, TEXT("Hit an enemy"));

                AServerManager::instance->PlayerHit(actor->GetComponentByClass<UPlayerClientScript>(), false);
            }
        }
        else 
        {
            UE_LOG(LogTemp, Warning, TEXT("Not an enemy"));

        }
    }

}

void UPlayerCombat::Grenade()
{
    if (!canGrenade)
        return;

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = NULL;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    //
    //AActor* obj = Cast<AActor>(GrenadePrefab);
    //obj->GetComponentByClass<UClientObject>()->IsLocal = true;
    //
    ////(GetWorld()->SpawnActor<AActor>(GrenadePrefab, GetOwner()->GetActorLocation() + (GetOwner()->GetActorForwardVector() * 70.0f), FRotator::ZeroRotator, SpawnParams))->GetComponentByClass<UClientObject>()->IsLocal = true;;
    //GetWorld()->SpawnActor<AActor>(obj->GetClass(), GetOwner()->GetActorLocation() + (GetOwner()->GetActorForwardVector() * 70.0f), FRotator::ZeroRotator, SpawnParams);


    AActor* SpawnedGrenade = GetWorld()->SpawnActorDeferred<AActor>(
        GrenadePrefab,
        FTransform(GetOwner()->GetActorRotation(),  // Rotation
            GetOwner()->GetActorLocation() + (GetOwner()->GetActorForwardVector() * 70.0f)) // Position
    );

    if (!SpawnedGrenade)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to spawn grenade!"));
        return;
    }


    UClientObject* ClientComponent = SpawnedGrenade->FindComponentByClass<UClientObject>();

    if (ClientComponent)
    {
        ClientComponent->IsLocal = true;
        UE_LOG(LogTemp, Log, TEXT("Grenade component modified before initialization!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Grenade spawned, but no UClientObject component found!"));
    }


    SpawnedGrenade->FinishSpawning(FTransform(GetOwner()->GetActorRotation(),
        GetOwner()->GetActorLocation() + (GetOwner()->GetActorForwardVector() * 70.0f)));
}
