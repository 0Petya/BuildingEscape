// Copyright Peter Tran 2016.

#include "BuildingEscape.h"
#include "Grabber.h"

UGrabber::UGrabber() {
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrabber::BeginPlay() {
	Super::BeginPlay();
}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
