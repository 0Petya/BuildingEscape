// Copyright Peter Tran 2016.

#include "BuildingEscape.h"
#include "UPositionReporter.h"

UUPositionReporter::UUPositionReporter() {
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UUPositionReporter::BeginPlay() {
	Super::BeginPlay();

  UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *GetOwner()->GetName(), *GetOwner()->GetTransform().GetLocation().ToString());
}

void UUPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
