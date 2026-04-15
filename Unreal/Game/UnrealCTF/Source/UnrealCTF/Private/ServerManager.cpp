// Fill out your copyright notice in the Description page of Project Settings.
#include "ServerManager.h"
#include <Interfaces/IPv4/IPv4Endpoint.h>
#include <Common/UdpSocketBuilder.h>
#include "CoreMinimal.h"
#include <Kismet/GameplayStatics.h>
#include <UIManager.h>
#include <UnrealCTF/UnrealCTFCharacter.h>
#include "FlagScript.h"
#include <ClientObject.h>

AServerManager* AServerManager::instance = nullptr;

void SplitStringByNewline(const FString& InputString, TArray<FString>& OutStrings)
{
	// Split the string by "\n" into an array of strings
	InputString.ParseIntoArray(OutStrings, TEXT("\n"), true);
}


// Sets default values
AServerManager::AServerManager()
{
	instance = this;

	//UE_LOG(LogTemp, Error, TEXT("CREATING CLIENT CONNECTOR"));
	//
	//TArray<AActor*> TaggedActors;
	//UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player"), TaggedActors);
	//if (TaggedActors.Num() > 0)
	//{
	//	//NetworkObjects.Add(TaggedActors[0]->FindComponentByClass<UPlayerClientScript>());
	//
	//	UE_LOG(LogTemp, Log, TEXT("Player Found"));
	//}
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void AServerManager::AddClient(UPlayerClientScript* c)
{
	UE_LOG(LogTemp, Log, TEXT("Player Found"));

	AUIManager::instance->AddPlayer(c->ID, c->GetOwner()); //add this player to the stats list

	NetworkObjects.Add(c);
	//
	//UE_LOG(LogTemp, Log, TEXT("%s"), NetworkObjects[0]->GetOwner()->GetFName());
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("PLAYER FOUND: ") + NetworkObjects[0]->GetOwner()->GetFName().ToString());

}

int AServerManager::LocalIDRequest()
{
	localID++;
	return localID;
}


// Called when the game starts or when spawned
void AServerManager::BeginPlay()
{
	Super::BeginPlay();

	manager = AUIManager::instance;

	FIPv4Address address;
	FIPv4Address::Parse("127.0.0.1", address);
	serverep = FIPv4Endpoint(address, 9050);
	localep = FIPv4Endpoint(FIPv4Address::Any, 9040);
	//localep = FIPv4Endpoint(FIPv4Address::Any, 0); //this lets the Operating System pick a port

	socket = FUdpSocketBuilder("Player").BoundToEndpoint(localep);

	messageQueue->Empty();

	if (socket)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("SocketAttachted"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("Our Endpoint: ") + localep.ToString());
		UE_LOG(LogTemp, Log, TEXT("Client Connected"));

		//SendMessage("ID_REQUEST", socket);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Client not connected"));

	}

	//sending a message
	FString myMessage = "I'm the unreal client - hiiii!";
	TCHAR* charMessage = myMessage.GetCharArray().GetData();
	uint8* array = (uint8*)TCHAR_TO_UTF8(charMessage);
	int32 arrayLength = FCString::Strlen(charMessage);
	int32 bytesSentAmount;

	//convert here and send packet
	remoteAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	remoteAddr->SetIp(serverep.Address.Value);
	remoteAddr->SetPort(serverep.Port);

	// Send the packet
	bool success = socket->SendTo(array, arrayLength, bytesSentAmount, *remoteAddr);
	if (success)
	{
		UE_LOG(LogTemp, Log, TEXT("Message sent successfully, Bytes sent: %d"), bytesSentAmount);

		myMessage = "ID_REQUEST\n";
		charMessage = myMessage.GetCharArray().GetData();
		array = (uint8*)TCHAR_TO_UTF8(charMessage);
		arrayLength = FCString::Strlen(charMessage);
		bytesSentAmount;
		socket->SendTo(array, arrayLength, bytesSentAmount, *remoteAddr);

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to send message"));
	}

	if (socket != NULL)
	{
		LoopThread = true;
		//begin a loop that reads messages
		Async(EAsyncExecution::Thread, [this]()
		{
				MessageRecieverThread();
		});
	}
}

// Called every frame
void AServerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if connected to a server, begin communication function
	if (socket != NULL && NetworkObjects.Num() > 0)
	{
		//max amount of messages to process each tick
		int maxMessagesToProcess = 10;
		int processedMessages = 0;

		//is there a message?
		while (messageQueue->Peek() != nullptr && processedMessages < maxMessagesToProcess)
		{
			FString Message;
			Mutex.Lock();
			//while (messageQueue->Dequeue(Message))
			{
				messageQueue->Dequeue(Message);
				//AsyncTask(ENamedThreads::GameThread, [this, Message]()
					//{
				ReadServerMessage(Message);
					//});

				//UE_LOG(LogTemp, Warning, TEXT("Received Message: %s"), *Message);
				//ReadServerMessage(Message);
				//processedMessages++;
			}
			Mutex.Unlock();
		}

		//try and send out new positions as long as we are getting messages from the server	
		try
		{
			SendNewPositions();
		}
		catch (FString e)
		{
			//do nothing
		}
	}
}

void AServerManager::MessageRecieverThread()
{
	TSharedRef<FInternetAddr> sender = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr(); //the sender
	TArray<FString> message;

	while(LoopThread)
	{
		uint32 dataSize = 0;
		if (socket->HasPendingData(dataSize))
		{
			TArray<uint8> receivedData;
			receivedData.SetNumUninitialized(FMath::Min(dataSize, 1024u));

			int32 bytesRead = 0;
			//if (socket->Recv(ReceivedData.GetData(), ReceivedData.Num(), BytesRead))
			if (socket->RecvFrom(receivedData.GetData(), dataSize, bytesRead, *sender))
			{
				FString Message = FString(UTF8_TO_TCHAR(reinterpret_cast<const char*>(receivedData.GetData())));

				Mutex.Lock();
				messageQueue->Enqueue(Message);
				Mutex.Unlock();
				

			}
		}
		//FPlatformProcess::Sleep(0.001f);  // Small delay to prevent high CPU usage


	}
}

void AServerManager::SendMessage(FString Message)
{
	//sending a message
	FString myMessage = (*Message) + FString("\n");
	TCHAR* charMessage = myMessage.GetCharArray().GetData();
	uint8* array = (uint8*)TCHAR_TO_UTF8(charMessage);
	int32 arrayLength = FCString::Strlen(charMessage);
	int32 bytesSentAmount;
	
	////convert here and send packet
	//TSharedPtr<FInternetAddr> remoteAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	//remoteAddr->SetIp(serverep.Address.Value);
	//remoteAddr->SetPort(serverep.Port);
	
	//FSocket* Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_DGram, TEXT("UDP Client"), true);
	
	// Send the packet
	bool success = socket->SendTo(array, arrayLength, bytesSentAmount, *remoteAddr);

}

void AServerManager::ReadServerMessage(FString m)
{
	TArray<FString> message;
	 
	SplitStringByNewline(m, message);

	if (message.Num() == 0) return;  // Prevent empty messages

	if (message[0] == "RESET")
	{
		UWorld* World = GetWorld();
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsWithTag(World, "Flag", FoundActors);
		UFlagScript* f1 = FoundActors[0]->GetComponentByClass<UFlagScript>();
		UFlagScript* f2 = FoundActors[1]->GetComponentByClass<UFlagScript>();

		f1->Reset();
		f2->Reset();
		
	}
	if (message[0] == "YOUR_ID")
	{
		//NetworkObject[0] will always be the client player
		//UE_LOG(LogTemp, Log, TEXT("YOUR ID: %s"), *message[1]);
		//UE_LOG(LogTemp, Log, TEXT("YOUR TEAM: %s"), *message[2]);

		NetworkObjects[0]->ID = FCString::Atoi(*message[1]);
		NetworkObjects[0]->team = FCString::Atoi(*message[2]);

		//// "Change" the key from "OldKey" to "NewKey"
		//if (manager->ClientStatMap.Contains(0))
		//{
		//	manager->ClientStatMap.Remove(0);
		//	manager->ClientStatMap.Add(NetworkObjects[0]->ID, NetworkObjects[0]->GetOwner());
		//	//MyMap.Add("NewKey", Value);
		//}

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("NEW ID: ") + message[1]);

		//SendMessage("POSITION_REQUEST\n" + NetworkObjects[0]->ID);
	}
	if (message[0] == "PLAYER_STATS")
	{
		//manager->ClientStatMap.Empty();

		for (int i = 0; i < NetworkObjects.Num(); i++)
		{
			if (NetworkObjects[i]->ID == FCString::Atof(*message[1]) && i != 0)
			{
				NetworkObjects[i]->GetOwner()->GetComponentByClass<UPlayerClientScript>()->kills = FCString::Atoi(*message[2]);
				NetworkObjects[i]->GetOwner()->GetComponentByClass<UPlayerClientScript>()->deaths = FCString::Atoi(*message[3]);
				NetworkObjects[i]->GetOwner()->GetComponentByClass<UPlayerClientScript>()->health = FCString::Atoi(*message[4]);
				try
				{
					if(NetworkObjects[i]->GetOwner()->GetComponentByClass<UPlayerStats>() != nullptr)
						NetworkObjects[i]->GetOwner()->GetComponentByClass<UPlayerStats>()->health = FCString::Atoi(*message[4]);
				}
				catch (...) {};
				//reset the leaderboard clients
				//manager->ClientStatMap.Add(NetworkObjects[i]->ID, NetworkObjects[i]->GetOwner());
				//manager->ClientStatMap[NetworkObjects[i]->ID].Kills = FCString::Atoi(*message[2]);
				//manager->ClientStatMap[NetworkObjects[i]->ID].Deaths = FCString::Atoi(*message[3]);
				
			}
		}
	}
	if (message[0] == "PLAYERS")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "we got some players:\n" + m);
		CreatePlayers(message[1], message[2]);
	}
	if (message[0] == "NEW_POSITIONS")
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Server Message!:\n%s" + m);

		//Debug.Log(receiveString);
		for (int i = 0; i < NetworkObjects.Num(); i++)
		{
			if (NetworkObjects[i]->ID == FCString::Atof(*message[1]) && i != 0)
			{
				AActor* OwnerActor = NetworkObjects[i]->GetOwner();
				if (!OwnerActor) continue;  // Ensure actor is valid

				//the position in message section 4 and 3 are swapped because the vector message will come in the unity position format
				//this means the y will be the up and down instead of the z - which neeeds to be swapped
				//unity vector - X right and le	ft, Y Up and Down, Z Forward and back
				//unreal vector - X right and left, Y Forward and back, Z Up and Down
				// 
				//Also multiply by 100 to convert from meters (Unity) to centimeters (Unreal)
				//instead i changed the unit metric in project settings - Editor - Appearence
				FVector NewLocation(FCString::Atof(*message[2]) * -100.0f, FCString::Atof(*message[4]) * 100.0f, FCString::Atof(*message[3]) * 100.0f);

				//FVector NewLocation(FCString::Atof(*message[2]), FCString::Atof(*message[4]), FCString::Atof(*message[3]));

				//UE_LOG(LogTemp, Log, TEXT("Moving Actor ID %d to Location: %s"), NetworkObjects[i]->ID, *NewLocation.ToString());

				OwnerActor->SetActorLocation(NewLocation);
			}

			//if (NetworkObjects[i]->ID == FCString::Atoi(*message[1]))
			//{
			//	NetworkObjects[i]->GetOwner()->SetActorLocation(FVector(FCString::Atof(*message[2]), FCString::Atof(*message[3]), FCString::Atof(*message[4])));
			//}
		}
	}
	if (message[0] == "NEW_ROTATIONS")
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Server Message!:\n%s" + m);

		//Debug.Log(receiveString);
		for (int i = 0; i < NetworkObjects.Num(); i++)
		{
			if (NetworkObjects[i]->ID == FCString::Atof(*message[1]) && i != 0)
			{
				AActor* OwnerActor = NetworkObjects[i]->GetOwner();
				if (!OwnerActor) continue;  // Ensure actor is valid

				float Pitch = FCString::Atof(*message[2]); // Convert to float
				float Yaw = FCString::Atof(*message[3]);
				float Roll = FCString::Atof(*message[4]);

				// Convert to FRotator
				FQuat NewRotation = FRotator(Pitch, Yaw, Roll).Quaternion();

				OwnerActor->SetActorRotation(NewRotation);
			}

			//if (NetworkObjects[i]->ID == FCString::Atoi(*message[1]))
			//{
			//	NetworkObjects[i]->GetOwner()->SetActorLocation(FVector(FCString::Atof(*message[2]), FCString::Atof(*message[3]), FCString::Atof(*message[4])));
			//}
		}
	}
	if (message[0] == "DAMAGE")
	{
		if (FCString::Atoi(*message[1]) == NetworkObjects[0]->ID)
		{
			UE_LOG(LogTemp, Warning, TEXT("FULL MESSAGE: %s"), *m);

			NetworkObjects[0]->GetOwner()->GetComponentByClass<UPlayerStats>()->health = FCString::Atoi(*message[2]); //assign players new health

			//we have been respawned if our health is reset
			if (FCString::Atoi(*message[2]) == 100)
			{
				
			}
		}
	}
	if (message[0] == "DIED")
	{
		//if (FCString::Atoi(*message[2]) == NetworkObjects[0]->ID)
		//	SendMessage("RESPAWN\n" + NetworkObjects[0]->ID);
		UE_LOG(LogTemp, Warning, TEXT("WE HAVE RESPAWED"));

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = NULL;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		if (NetworkObjects[0]->ID == FCString::Atof(*message[1]))
		{

			AActor* SpawnedActor;

			for (TSubclassOf<AActor> PrefabClass : ObjectPrefabs)
			{

				//currObj = Cast<AActor>(ObjectPrefabs[i]);
				//currObj = ObjectPrefabs[i]->GetDefaultObject<AActor>();
				UE_LOG(LogTemp, Warning, TEXT("WE HAVE RESPAWED"));


				// Spawn Blueprint Actor from a TSubclassOf<AActor>
				SpawnedActor = GetWorld()->SpawnActor<AActor>(PrefabClass, NetworkObjects[0]->GetOwner()->GetActorLocation(), FRotator::ZeroRotator);

				if (SpawnedActor)
				{
					UClientObject* ClientComponent = SpawnedActor->FindComponentByClass<UClientObject>();
					if (ClientComponent && ClientComponent->type == ObjTypes::H_Pickup)
					{
						ClientComponent->SetLocal();
						break;
					}
					else
					{
						Objects.Remove(SpawnedActor);
						SpawnedActor->Destroy();
					}
				}
			}
		}

		//manager->ClientStatMap[FCString::Atoi(*message[1])].Died();
		//manager->ClientStatMap[FCString::Atoi(*message[2])].Killed();

	}
	if (message[0] == "MOVE")
	{
		AActor* player = NetworkObjects[0]->GetOwner();

		ACharacter* HitCharacter = Cast<ACharacter>(player);
		player->SetActorLocation(FVector(FCString::Atof(*message[1]) * - 100.0f, FCString::Atof(*message[3]) * 100.0f, FCString::Atof(*message[2]) * 100.0f));
		//Debug.Log("New Position: " + GameObject.FindWithTag("Player").transform.position);
	}
	if (message[0] == "KICKED")
	{
		//if (NetworkObjects[0]->ID != FCString::Atoi(*message[1]))
		//{
		//	UE_LOG(LogTemp, Log, TEXT("PLAYER %s HAS BEEN KICKED"), *message[1]);
		//}
		//else
		//{
		//	//client.Client.Disconnect(false);
		//	//Debug.Log("YOU'VE BEEN KICKED");
		//	//s = new UdpState();
		//}
		//NetworkObjects.Empty();
	}


	if (message[0] == "FLAG_CAPTURED")
	{
		UE_LOG(LogTemp, Log, TEXT("Flag has been taken"));

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Flag Taken Data:"));

		UWorld* World = GetWorld();

		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsWithTag(World, "Flag", FoundActors);

		if (FoundActors.Num() > 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Found actors");

		}

		UFlagScript* f1 = FoundActors[0]->GetComponentByClass<UFlagScript>();
		UFlagScript* f2 = FoundActors[1]->GetComponentByClass<UFlagScript>();

		if (f1 == NULL || f2 == NULL)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("NO FLAGS"));
		}
		else 
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("FOUND"));

			if (FCString::Atoi(*message[2]) == f1->team)
			{
				f1->carrierID = FCString::Atoi(*message[1]);
			}
			else if (FCString::Atoi(*message[2]) == f2->team)
			{
				f2->carrierID = FCString::Atoi(*message[1]);
			}
		}

		//UFlagScript* f1 = FoundFlags[0]->GetComponentByClass<UFlagScript>();
		//UFlagScript* f2 = FoundFlags[1]->GetComponentByClass<UFlagScript>();
		//
		//if (FCString::Atoi(*message[2]) != f1->team)
		//{
		//	f1->carrierID = FCString::Atoi(*message[1]);
		//}
		//else if(FCString::Atoi(*message[2]) != f2->team)
		//{
		//	f2->carrierID = FCString::Atoi(*message[1]);
		//}
	}
	if (message[0] == "FLAG_DROPPED")
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
			if (FCString::Atoi(*message[1]) == f1->team)
			{
				f1->Reset();
			}
			else if (FCString::Atoi(*message[1]) == f2->team)
			{
				f2->Reset();
			}
		}
	}

	if (message[0] == "NEW_SCORE")
	{
		//Debug.Log("Team A: " + message[1]);
		//Debug.Log("Team B: " + message[2]);
		//
		//MatchManager.instance.UpdateScore(int.Parse(message[1]), int.Parse(message[2]));

		UWorld* World = GetWorld();
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsWithTag(World, "Flag", FoundActors);
		if (FoundActors.Num() > 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Found actors");
		}
		
		manager->scoreA = FCString::Atoi(*message[1]);
		manager->scoreB = FCString::Atoi(*message[2]);

		UFlagScript* f1 = FoundActors[0]->GetComponentByClass<UFlagScript>();
		UFlagScript* f2 = FoundActors[1]->GetComponentByClass<UFlagScript>();

		if (f1->team == FCString::Atoi(*message[3]))
		{
			f1->Reset();
		}
		else if (f2->team == FCString::Atoi(*message[3]))
		{
			f2->Reset();
		}

	}


	if (message[0] == "OBJ_ID")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("ADDING OBJECT ID: " + message[1]));

		for (AActor* Obj : Objects)
		{
			UClientObject* script = Obj->GetComponentByClass<UClientObject>();
			if (script && script->LocalID == FCString::Atoi(*message[1]))
			{
				script->GlobalID = FCString::Atoi(*message[2]);
				return;
			}
		}
	}
	if (message[0] == "NEW_OBJ")
	{
		for (AActor* Obj : Objects)
		{
			UClientObject* script = Obj->GetComponentByClass<UClientObject>();

			if (script && script->GlobalID == FCString::Atoi(*message[1]))
			{
				return;
			}
		}


		AActor* newObj = nullptr;
		//FActorSpawnParameters SpawnParams;
		//SpawnParams.Owner = NULL;
		//SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		// Object not found, spawn a new one
		for (TSubclassOf<AActor> Prefab : ObjectPrefabs)
		{
			//currObj = Cast<AActor>(ObjectPrefabs[i]);
			//currObj = ObjectPrefabs[i]->GetDefaultObject<AActor>();
			UE_LOG(LogTemp, Warning, TEXT("WE HAVE RESPAWED"));


			// Spawn Blueprint Actor from a TSubclassOf<AActor>
			newObj = GetWorld()->SpawnActor<AActor>(Prefab, FVector::ZeroVector, FRotator::ZeroRotator);

			if (newObj)
			{
				UClientObject* ClientComponent = newObj->FindComponentByClass<UClientObject>();
				if (ClientComponent && UEnum::GetDisplayValueAsText(ClientComponent->type).ToString() == message[2])
				{
					ClientComponent->GlobalID = FCString::Atoi(*message[1]);
					ClientComponent->IsLocal = false;
				}
				else
				{
					Objects.Remove(newObj);
					newObj->Destroy();
				}
			}

			//AActor* newObj = nullptr;
			//FActorSpawnParameters SpawnParams;
			//SpawnParams.Owner = NULL;
			//SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			//
			//Cast<AActor>(Prefab)->GetComponentByClass<UClientObject>()->IsLocal = true;
			//
			//newObj = GetWorld()->SpawnActor<AActor>(Prefab, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			//
			//UClientObject* ObjComponent = newObj->GetComponentByClass<UClientObject>();
			//
			//if (ObjComponent == nullptr)
			//	return;
			//
			//ObjComponent->GlobalID = FCString::Atoi(*message[1]);
			//
			//
			//if (ObjComponent->type == ObjTypes::bubble && message[2] == "bubble" )
			//{
			//	Objects.Add(newObj);
			//
			//}
			//else if (ObjComponent->type == ObjTypes::grenade && message[2] == "grenade")
			//{
			//	Objects.Add(newObj);
			//}
			//else 
			//{
			//	newObj->Destroy();
			//}

			
		}
	}
	if (message[0] == "OBJECT_UPDATE")
	{
		UE_LOG(LogTemp, Log, TEXT("Update to %s"), *m);
		if (Objects.Num() <= 0)
			return;

		for(AActor* Obj : Objects)
		{
			try
			{
				UE_LOG(LogTemp, Log, TEXT("ITEM FOUND %s"), *Obj->GetName());
				if (Obj->FindComponentByClass<UClientObject>() != nullptr)
				{
					UClientObject* script = Obj->FindComponentByClass<UClientObject>();

					if (script && script->GlobalID == FCString::Atoi(*message[1]) && !script->IsLocal)
					{
						FVector NewPosition = FVector(
							FCString::Atof(*message[2]) * -100.0f,
							FCString::Atof(*message[4]) * 100.0f,
							FCString::Atof(*message[3]) * 100.0f
						);
						Obj->SetActorLocation(NewPosition);
					}
				}
				throw(505);
			}
			catch (...)
			{
				UE_LOG(LogTemp, Log, TEXT("Problem with object update"));
			}
		}
	}
	if (message[0] == "OBJECT_REMOVED")
	{
		for (AActor* CurrObj : Objects)
		{
			UClientObject* Obj = CurrObj->FindComponentByClass<UClientObject>();
			if (Obj && Obj->GlobalID == FCString::Atoi(*message[1]))
			{
				Objects.RemoveAt(Objects.Find(CurrObj)); // Remove the object from the array
				Obj->GetOwner()->Destroy();
				//GetWorld()->DestroyActor(Obj->GetOwner());
				break;
			}
		}
	}
}

void AServerManager::SendNewPositions()
{
	//if IDs haven't been assigned, dont send positions
	if (NetworkObjects[0]->ID == 0)
	{
		return;
	}
	// the z and y are swapped so unity can interpret the z as the up axis
	// divide by 100 to get the meters for unity conversion
	FString PositionMessage = FString::Printf(
		TEXT("POSITIONS\n%d\n%f\n%f\n%f\n"),
		NetworkObjects[0]->ID,
		-float(NetworkObjects[0]->GetOwner()->GetActorLocation().X) / 100.0f,
		float(NetworkObjects[0]->GetOwner()->GetActorLocation().Z) / 100.0f,
		float(NetworkObjects[0]->GetOwner()->GetActorLocation().Y) / 100.0f
	);

	FVector RotVector = NetworkObjects[0]->GetOwner()->GetActorRotation().Euler();

	FString Rotation = FString::Printf(
		TEXT("ROTATIONS\n%d\n%f\n%f\n%f\n"),
		NetworkObjects[0]->ID,
		float(RotVector.X),
		float(RotVector.Z) - 90.0f,
		float(RotVector.Y)
	);
	
	// Convert FString to ANSI (ASCII) string
	//FTCHARToANSI Converter(*PositionMessage);
	//const char* MessageData = Converter.Get();
	//int32 MessageLength = FCStringAnsi::Strlen(MessageData);
	
	// Define the endpoint and send the message
	//TSharedRef<FInternetAddr> EndPoint = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	//EndPoint->SetAnyAddress();
	//EndPoint->SetPort(0);
	
	//convert here and send packet#
	remoteAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	remoteAddr->SetIp(serverep.Address.Value);
	remoteAddr->SetPort(serverep.Port);
	
	// Create a socket
	FSocket* Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_DGram, TEXT("UDP Client"), true);
	
	if (socket)
	{
		//FString myMessage = ("%sI'm the unreal client - hiiii!", *PositionMessage);
		FString myMessage = (*PositionMessage);
		FString myMessage2 = (*Rotation);
		TCHAR* charMessage = myMessage.GetCharArray().GetData();
		uint8* array = (uint8*)TCHAR_TO_UTF8(charMessage);
		int32 arrayLength = FCString::Strlen(charMessage);
		int32 BytesSent = 0;
	
		//SendMessage(myMessage, socket);
		bool bIsSent = socket->SendTo(array, arrayLength, BytesSent, *remoteAddr);

		charMessage = myMessage2.GetCharArray().GetData();
		array = (uint8*)TCHAR_TO_UTF8(charMessage);

		bIsSent = socket->SendTo(array, arrayLength, BytesSent, *remoteAddr);
	
		//if (bIsSent)
		//{
		//	UE_LOG(LogTemp, Log, TEXT("Message sent successfully. Bytes: %d"), BytesSent);
		//}
		//else
		//{
		//	UE_LOG(LogTemp, Warning, TEXT("Failed to send message."));
		//}
	
		// Close and destroy the socket
		//Socket->Close();
		//ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	}
}


void AServerManager::FlagCapture(FString id, FString team, int code)
{
	if (code == 0) // flag has been picked up
	{
		FString myMessage = "FLAG_CAPTURED\n" + id + "\n" + team + "\n";

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Flag Captured:\n" + myMessage));

		SendMessage(myMessage);
		//byte[] array = Encoding.ASCII.GetBytes(myMessage);
		//client.Send(array, array.Length);
	}
	if (code == 1) // flag has been won
	{
		FString myMessage = "FLAG_WON\n" + id;
		try
		{
			SendMessage(myMessage);
			//byte[] array = Encoding.ASCII.GetBytes(myMessage);
			//client.Send(array, array.Length);
		}
		catch(FString e)
		{
			UE_LOG(LogTemp, Error, TEXT("Error sending flag won message"));
		}
	}
}


void AServerManager::PlayerHit(UPlayerClientScript* script, bool respawn, int damage)
{
	UE_LOG(LogTemp, Log, TEXT("Sending hit message"))

	FString message;
	//if (socket != NULL || socket->GetConnectionState() != EConnectionState::USOCK_Open)
	//{
	//	//Nobody to send data to
	//	return;
	//}
	//else
	//{
	if (respawn)
	{
		//the player health has reached zero, we need to respawn him;
		//message = FString::Printf(TEXT("RESPAWN\n%s\n%s"), script->ID, NetworkObjects[0]->ID);
		message = "RESPAWN\n" + FString::FromInt(script->ID) + "\n" + FString::FromInt(NetworkObjects[0]->ID);

		SendMessage(message);
		return;
	}
	else
	{
		message = "HIT\n" + FString::FromInt(script->ID) + "\n" + FString::FromInt(NetworkObjects[0]->ID) + "\n" + FString::FromInt(damage);

		//message = FString::Printf(TEXT("HIT\n%s\n%s"),script->ID, NetworkObjects[0]->ID);
		UE_LOG(LogTemp, Log, TEXT("Sending hit message now"));
		SendMessage(message);

	}
	//}

}


void AServerManager::CreatePlayers(FString id, FString t)
{
	//NewObject<AUnrealCTFCharacter>();

	//Debug.Log("NEW ID: " + id);
	//Debug.Log("NEW ID INT: " + int.Parse(id));

	//PlayerClientScript[] obj = GameObject.FindObjectsByType<PlayerClientScript>(FindObjectsSortMode.None);

	bool found = false;
	for (int i = 0; i < NetworkObjects.Num(); i++)
	{
		if (NetworkObjects[i]->ID == FCString::Atoi(*id))
		{
			NetworkObjects[i]->team = FCString::Atoi(*t);

			found = true;
		}
		if (NetworkObjects[0]->ID == 0)
		{
			NetworkObjects[i]->ID = FCString::Atoi(*id);
			NetworkObjects[i]->team = FCString::Atoi(*t);

			found = true;
			break;
		}
	}	

	if (!found)
	{
		UE_LOG(LogTemp, Log, TEXT("WE NEED TO MAKE A NEW PLAYER"));
		//static ConstructorHelpers::FClassFinder<AActor> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/PlayerClient"));

		//GetWorld()->SpawnActor<APlayerClient>(PlayerClient::staticCast(0))
		//CreatePlayers(id);

		UWorld* World = GetWorld();
		if (World)
		{
			// Load class dynamically (Avoid using FClassFinder outside constructor)
			UClass* PlayerClass = LoadObject<UClass>(nullptr, TEXT("/Game/ThirdPerson/PlayerClient.PlayerClient_C"));

			if (!PlayerClass)
			{
				UE_LOG(LogTemp, Error, TEXT("Player class not found! Check the path."));
				return;
			}

			// Spawn Parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

			// Spawn the Actor
			AActor* SpawnedActor = World->SpawnActor<AActor>(PlayerClass, FVector(0, 0, 100), FRotator::ZeroRotator, SpawnParams);

			if (SpawnedActor)
			{
				UE_LOG(LogTemp, Log, TEXT("Player spawned successfully!"));
				SpawnedActor->FindComponentByClass<UPlayerClientScript>()->ID = FCString::Atoi(*id);
				SpawnedActor->FindComponentByClass<UPlayerClientScript>()->team = FCString::Atoi(*t);
				AddClient(SpawnedActor->FindComponentByClass<UPlayerClientScript>());
				//NetworkObjects.Add(SpawnedActor->FindComponentByClass<UPlayerClientScript>());
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to spawn player!"));
			}
		}

	}
}

void AServerManager::EndPlay(const EEndPlayReason::Type reason)
{
	Super::EndPlay(reason);

	LoopThread = false;

	//SendMessage("DISCONNECTED\n" + NetworkObjects[0]->ID);
	if (socket)
		socket->Close();

}

