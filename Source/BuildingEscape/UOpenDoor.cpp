// Copyright Peter Tran 2016.

#include "BuildingEscape.h"
#include "UOpenDoor.h"

UUOpenDoor::UUOpenDoor() {
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UUOpenDoor::BeginPlay() {
	Super::BeginPlay();

  FRotator Rotation = FRotator(0.0f, 90.0f, 0.0f);
  GetOwner()->SetActorRotation(Rotation);
}

void UUOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
