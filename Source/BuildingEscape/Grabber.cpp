// Copyright Peter Tran 2016.

#include "BuildingEscape.h"
#include "Grabber.h"

UGrabber::UGrabber() {
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

FVector UGrabber::GetReachLine(bool bEnd) {
  FVector PlayerViewPointLocation;
  FRotator PlayerViewPointRotation;
  GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);

  return bEnd ? PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach : PlayerViewPointLocation;
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach() {
  FHitResult Hit;
  GetWorld()->LineTraceSingleByObjectType(Hit, GetReachLine(false), GetReachLine(true), FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), FCollisionQueryParams(FName(TEXT("")), false, GetOwner()));

  return Hit;
}

void UGrabber::Grab() {
  FHitResult Hit = GetFirstPhysicsBodyInReach();
  UPrimitiveComponent* ComponentToGrab = Hit.GetComponent();

  if (Hit.GetActor())
    PhysicsHandle->GrabComponent(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation(), true);
}

void UGrabber::Release() {
  PhysicsHandle->ReleaseComponent();
}

void UGrabber::BeginPlay() {
	Super::BeginPlay();

  PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

  Input = GetOwner()->FindComponentByClass<UInputComponent>();
  if (Input) {
    Input->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
    Input->BindAction("Grab", IE_Released, this, &UGrabber::Release);
  }
}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  if (PhysicsHandle->GrabbedComponent)
    PhysicsHandle->SetTargetLocation(GetReachLine(true));
}
