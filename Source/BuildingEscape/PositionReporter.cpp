// Copyright Peter Tran 2016.

#include "BuildingEscape.h"
#include "PositionReporter.h"

UPositionReporter::UPositionReporter() {
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UPositionReporter::BeginPlay() {
	Super::BeginPlay();

  UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *GetOwner()->GetName(), *GetOwner()->GetTransform().GetLocation().ToString());
}

void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
