// Copyright Peter Tran 2016.

#include "BuildingEscape.h"
#include "OpenDoor.h"

UOpenDoor::UOpenDoor() {
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UOpenDoor::Open()
{
  FRotator Rotation = FRotator(0.0f, 90.0f, 0.0f);
  GetOwner()->SetActorRotation(Rotation);
}

void UOpenDoor::BeginPlay() {
	Super::BeginPlay();

  ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  if (PressurePlate->IsOverlappingActor(ActorThatOpens))
    Open();
}
