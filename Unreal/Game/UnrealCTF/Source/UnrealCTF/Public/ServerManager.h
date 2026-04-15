// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Interfaces/IPv4/IPv4Address.h>
#include <Interfaces/IPv4/IPv4Endpoint.h>
#include "PlayerClientScript.h"
#include "PlayerStats.h"
#include "Containers/Queue.h"
#include "UIManager.h"
#include "ServerManager.generated.h"


UENUM(BlueprintType) // Allows the enum to be used in Blueprints
enum class ObjTypes : uint8 // Use uint8 for memory efficiency
{
	bubble UMETA(DisplayName = "bubble"),
	grenade UMETA(DisplayName = "grenade"),
	H_Pickup UMETA(DisplayName = "H_Pickup")
};


UCLASS()
class UNREALCTF_API AServerManager : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AServerManager();
	FIPv4Endpoint serverep;
	FIPv4Endpoint localep; 
	TSharedPtr<FInternetAddr> remoteAddr;
	FSocket* socket;

	TArray<UPlayerClientScript*> NetworkObjects;

	int localID = 1000;
	TArray<AActor*> Objects;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Assets")
	TArray<TSubclassOf<AActor>> ObjectPrefabs; // Array of actor classes


	static AServerManager* instance;
	TQueue<FString>* messageQueue = new TQueue<FString>();
	FCriticalSection Mutex;  // Synchronization
	bool LoopThread;
	void MessageRecieverThread();

	//UPROPERTY(EditAnywhere)AActor* playerClient;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SendMessage(FString myMessage);
	virtual void EndPlay(const EEndPlayReason::Type reason) override;

	void ReadServerMessage(FString m);
	void SendNewPositions();
	void AddClient(UPlayerClientScript* c);
	int LocalIDRequest();
	void CreatePlayers(FString id, FString team);

	void FlagCapture(FString id, FString team, int code);
	void PlayerHit(UPlayerClientScript* script, bool respawn, int damage = 10);


	AUIManager* manager;

};
