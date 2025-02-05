// Copyright Peter Tran 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UGrabber : public UActorComponent {

	GENERATED_BODY()

public:	
	UGrabber();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
  UPROPERTY(EditAnywhere)
  float Reach = 100.0f;

  UPhysicsHandleComponent* PhysicsHandle = nullptr;
  UInputComponent* Input = nullptr;

  FVector GetReachLine(bool);
  const FHitResult GetFirstPhysicsBodyInReach();
  void Grab();
  void Release();
};
