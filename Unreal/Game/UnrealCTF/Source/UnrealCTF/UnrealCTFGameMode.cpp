// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealCTFGameMode.h"
#include "UnrealCTFCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineUtils.h" // For TActorIterator

AUnrealCTFGameMode::AUnrealCTFGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Player"));
	//UE_LOG(LogTemp, Warning, TEXT("PlayerPawnBPClass found: %s"), *PlayerPawnBPClass.Class->GetName());
    
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}

    DefaultPawnClass = nullptr; // Disable spawning a default pawn
    if (PlayerPawnBPClass.Class != nullptr)
    {
        PlayerClass = PlayerPawnBPClass.Class; // Store it as a UClass*
    }
}

//AUnrealCTFGameMode::AUnrealCTFGameMode()
//{
//    // Set default pawn class to our Blueprinted character
//    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Player"));
//    if (PlayerPawnBPClass.Class != NULL)
//    {
//        DefaultPawnClass = PlayerPawnBPClass.Class;
//
//        // Debug log to verify pawn is set
//        UE_LOG(LogTemp, Warning, TEXT("DefaultPawnClass set to: %s"), *PlayerPawnBPClass.Class->GetName());
//    }
//    else
//    {
//        UE_LOG(LogTemp, Error, TEXT("PlayerPawnBPClass NOT found!"));
//    }
//}
#include "Kismet/GameplayStatics.h"

void AUnrealCTFGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Find the existing player pawn in the scene
    APawn* ExistingPawn = nullptr;
    for (TActorIterator<APawn> It(GetWorld()); It; ++It)
    {
        if (It->IsA(PlayerClass)) // Replace with your actual pawn class
        {
            ExistingPawn = *It;
            break;
        }
    }

    if (ExistingPawn)
    {
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
        if (PlayerController)
        {
            PlayerController->Possess(ExistingPawn);
        }
    }

    //if (DefaultPawnClass)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("Spawning DefaultPawnClass: %s"), *DefaultPawnClass->GetName());

    //    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    //    if (PC)
    //    {
    //        FActorSpawnParameters SpawnParams;
    //        SpawnParams.Owner = PC;

    //        FVector Location = FVector(0.f, 0.f, 100.f); // Adjust to your Player Start location
    //        FRotator Rotation = FRotator::ZeroRotator;

    //        // Destroy existing pawn and spawn the correct one
    //        if (APawn* ExistingPawn = PC->GetPawn())
    //        {
    //            ExistingPawn->Destroy();
    //        }

    //        APawn* NewPawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, Location, Rotation, SpawnParams);
    //        PC->Possess(NewPawn);
    //    }
    //}
}

