// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"  // Ensure USceneComponent is recognized
#include "InputAction.h" 
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"
#include "UIManager.generated.h"

USTRUCT(BlueprintType)
struct FClientStats
{
	GENERATED_BODY()

	// Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	AActor* Player; // Use AActor* to represent a player object in Unreal

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int32 Kills;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int32 Deaths;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int32 Ping;

	// Default constructor
	FClientStats()
		: Player(nullptr), Kills(0), Deaths(0), Ping(0)
	{
	}

	// Parameterized constructor
	FClientStats(AActor* PlayerObj)
		: Player(PlayerObj), Kills(0), Deaths(0), Ping(0)
	{
	}

	// Functions
	void Died() { Deaths++; }
	void Killed() { Kills++; }
};


UCLASS()
class UNREALCTF_API AUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	static AUIManager* instance;

	int scoreA, scoreB;

	//static TMap<int32, FClientStats> ClientStatMap;

	void AddPlayer(int32 PlayerID, AActor* PlayerActor)
	{
		// Create a new PlayerStats object and add it to the map
		FClientStats NewStats(PlayerActor);
		//ClientStatMap.Emplace(PlayerID, NewStats);
	}


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> WidgetClass;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PlayerLayout;

	UPROPERTY()
	UUserWidget* CreatedWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Leaderboard") 
	UInputAction* IALeaderboard; //An FVector2D	
	void Leaderboard(bool show);


	UPROPERTY(BlueprintReadWrite, Category = "UI")
	FText TextToDisplay;

	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateText(const FText& NewText, int team)
	{
		if(team == 0)
		{

			UTextBlock* TextBox = Cast<UTextBlock>(CreatedWidget->WidgetTree->FindWidget(FName("ScoreA")));
			if (TextBox)
			{
				TextBox->SetText(NewText);
			}
		}
		if(team == 1)
		{
			UTextBlock*
				TextBox = Cast<UTextBlock>(CreatedWidget->WidgetTree->FindWidget(FName("ScoreB")));
			if (TextBox)
			{
				TextBox->SetText(NewText);
			}
		}

		TextToDisplay = NewText;
	}
};
