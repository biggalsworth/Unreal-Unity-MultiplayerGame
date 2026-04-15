#include "ClientObject.h"

// Sets default values for this component's properties
UClientObject::UClientObject()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

UClientObject::UClientObject(bool local)
{
	IsLocal = local;
}


// Called when the game starts
void UClientObject::BeginPlay()
{
	Super::BeginPlay();

	manager = AServerManager::instance;
	manager->Objects.Add(this->GetOwner());

	if (IsLocal)
	{
		LocalID = manager->LocalIDRequest();

		//UE_LOG(LogTemp, Log, TEXT("OBJ TYPE: %s"), UEnum::GetDisplayValueAsText(type).ToString());
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("OBJ TYPE: ") + UEnum::GetDisplayValueAsText(type).ToString());
		manager->SendMessage(FString("NEW_OBJECT\n" + FString::FromInt(LocalID) + "\n" + UEnum::GetDisplayValueAsText(type).ToString()));

		//switch (type)
		//{
		//case ObjTypes::bubble:
		//	manager->SendMessage(FString("NEW_OBJECT\n" + FString::FromInt(LocalID) + "\n" + "bubble"));
		//	break;
		//case ObjTypes::grenade:
		//	manager->SendMessage(FString("NEW_OBJECT\n" + FString::FromInt(LocalID) + "\n" + "grenade"));
		//	break;
		//default:
		//	break;
		//}

	}

	// ...
	
}


void UClientObject::SetLocal()
{
	IsLocal = true;
	LocalID = manager->LocalIDRequest();

	//UE_LOG(LogTemp, Log, TEXT("OBJ TYPE: %s"), UEnum::GetDisplayValueAsText(type).ToString());
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString("OBJ TYPE: ") + UEnum::GetDisplayValueAsText(type).ToString());
	manager->SendMessage(FString("NEW_OBJECT\n" + FString::FromInt(LocalID) + "\n" + UEnum::GetDisplayValueAsText(type).ToString()));
}

// Called every frame
void UClientObject::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if(IsLocal && GlobalID != 0)
	if (GlobalID != 0 && IsLocal && GetOwner()->IsActorBeingDestroyed() == false)
	{
		UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(GetOwner()->GetComponentByClass<UStaticMeshComponent>());

		FString Pos = FString::Printf(TEXT("%f\n%f\n%f"),
			-float(MeshComp->GetComponentLocation().X) / 100.0f,
			float(MeshComp->GetComponentLocation().Z) / 100.0f,
			float(MeshComp->GetComponentLocation().Y) / 100.0f);
		manager->SendMessage("OBJECT_POSITION\n" + FString::FromInt(GlobalID) + "\n" + Pos);

	}

	// ...
}

void UClientObject::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (EndPlayReason == EEndPlayReason::Destroyed)
	{
		if (IsLocal)
		{
			//manager->SendMessage("OBJECT_DESTROYED\n" + GlobalID);
		}
	}
}

