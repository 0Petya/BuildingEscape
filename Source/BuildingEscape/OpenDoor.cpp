// Copyright Peter Tran 2016.

#include "BuildingEscape.h"
#include "OpenDoor.h"

UOpenDoor::UOpenDoor() {
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UOpenDoor::BeginPlay() {
	Super::BeginPlay();

  if (!PressurePlate) UE_LOG(LogTemp, Error, TEXT("%s missing PressurePlate."), *GetOwner()->GetName());
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() {
  float TotalMass = 0.0f;

  if (!PressurePlate) return 0.0f;
  TArray<AActor*> Actors;
  PressurePlate->GetOverlappingActors(Actors);

  for (AActor* Actor : Actors)
    TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();

  return TotalMass;
}

void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  if (GetTotalMassOfActorsOnPlate() > TriggerMass) OnOpen.Broadcast();
  else OnClose.Broadcast();
}
