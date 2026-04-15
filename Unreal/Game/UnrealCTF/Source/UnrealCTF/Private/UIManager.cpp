// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Components/Widget.h"
#include "Components/Border.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include <PlayerClientScript.h>
#include <ServerManager.h>

// Define the static TMap
//TMap<int32, FClientStats> AUIManager::ClientStatMap;

// Define the static instance
AUIManager* AUIManager::instance = nullptr;

// Sets default values
AUIManager::AUIManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    instance = this;

}

// Called when the game starts or when spawned
void AUIManager::BeginPlay()
{
	Super::BeginPlay();

    //ClientStatMap.Empty();

    scoreA = 0;
    scoreB = 0;

    if (WidgetClass)
    {
        CreatedWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
        if (CreatedWidget)
        {
            CreatedWidget->AddToViewport();
        }
    }

    if (CreatedWidget && CreatedWidget->WidgetTree)
    {
        TArray<UWidget*> AllWidgets;
        CreatedWidget->WidgetTree->GetAllWidgets(AllWidgets);

        for (UWidget* Widget : AllWidgets)
        {
            UE_LOG(LogTemp, Log, TEXT("Widget Name: %s"), *Widget->GetName());
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("CreatedWidget or WidgetTree is null."));
    }

    UBorder* Leaderboard = Cast<UBorder>(CreatedWidget->WidgetTree->FindWidget(FName("LeaderboardPanel")));
    Leaderboard->SetVisibility(ESlateVisibility::Hidden);

    
	// Get the player's controller
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!PlayerController) return;

    // Get the Enhanced Input System
    UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
    if (InputSubsystem && IALeaderboard)
    {
        // Bind the Input Action
        UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);
        if (EnhancedInput)
        {
            EnhancedInput->BindAction(IALeaderboard, ETriggerEvent::Started, this, &AUIManager::Leaderboard, true);
            EnhancedInput->BindAction(IALeaderboard, ETriggerEvent::Completed, this, &AUIManager::Leaderboard, false);
            //EnhancedInput->BindAction(IALeaderboard, ETriggerEvent::Canceled, this, &AUIManager::Leaderboard, false);
        }
    }
}

// Called every frame
void AUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    UpdateText(FText::FromString(FString::FromInt(scoreA)), 0);
    UpdateText(FText::FromString(FString::FromInt(scoreB)), 1);

}

void AUIManager::Leaderboard(bool show)
{
    TArray<UWidget*> playerEntries;

    UVerticalBox* TeamA = Cast<UVerticalBox>(CreatedWidget->WidgetTree->FindWidget(FName("TeamA")));
    UVerticalBox* TeamB = Cast<UVerticalBox>(CreatedWidget->WidgetTree->FindWidget(FName("TeamB")));
    if (!TeamA || !TeamB)
    {
        UE_LOG(LogTemp, Error, TEXT("Teams are null!"));
        return;
    }


    for (const auto& KeyValuePair : AServerManager::instance->NetworkObjects)
    {
        // Create a widget for this player
        UUserWidget* PlayerWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerLayout);

        if (PlayerWidget)
        {
            // Optionally, set up the widget with player-specific data (e.g., player name)
            UTextBlock* PlayerNameTextBlock = Cast<UTextBlock>(PlayerWidget->GetWidgetFromName("PlayerName"));
            UTextBlock* PlayerKillsTextBlock = Cast<UTextBlock>(PlayerWidget->GetWidgetFromName("PlayerKills"));
            UTextBlock* PlayerDeathsTextBlock = Cast<UTextBlock>(PlayerWidget->GetWidgetFromName("PlayerDeaths"));
            if(KeyValuePair->ID != 0)
                PlayerNameTextBlock->Text = FText::FromString("Player " + FString::FromInt(KeyValuePair->ID));
            else
                PlayerNameTextBlock->Text = FText::FromString("You");

            PlayerKillsTextBlock->Text = FText::FromString(FString::FromInt(KeyValuePair->kills));
            PlayerDeathsTextBlock->Text = FText::FromString(FString::FromInt(KeyValuePair->deaths));
        }
        if (KeyValuePair->team == 0)
        {
            // Add the widget to the horizontal box (TeamA)
            UVerticalBoxSlot* NewSlot = TeamA->AddChildToVerticalBox(PlayerWidget);
        }
        else 
        {
            UVerticalBoxSlot* NewSlot = TeamB->AddChildToVerticalBox(PlayerWidget);
        }
        //if (NewSlot)
        //{
        //    // Optionally, configure the slot properties (e.g., padding, alignment)
        //    //NewSlot->SetPadding(FMargin(5.0f));
        //    NewSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Center);
        //    NewSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
        //}
    }
    

    UBorder* Leaderboard = Cast<UBorder>(CreatedWidget->WidgetTree->FindWidget(FName("LeaderboardPanel")));
    if (Leaderboard)
    {
        // Set the visibility of the border
        //Leaderboard->SetVisibility(ESlateVisibility::Visible);  // To show the border
        //Leaderboard->SetVisibility(ESlateVisibility::Hidden);   // To hide the border
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("LeaderboardPanel not found!"));
    }

    if (show)
    {
        Leaderboard->SetVisibility(ESlateVisibility::Visible);  // To show the border
        UE_LOG(LogTemp, Warning, TEXT("Show"));
    }
    else
    {
        Leaderboard->SetVisibility(ESlateVisibility::Hidden);   // To hide the border
        UE_LOG(LogTemp, Warning, TEXT("Hide"));
        TeamA->ClearChildren();
        TeamB->ClearChildren();
    }

}

