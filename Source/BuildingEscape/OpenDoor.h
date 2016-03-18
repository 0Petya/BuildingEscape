// Copyright Peter Tran 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent {

	GENERATED_BODY()

public:	
	UOpenDoor();
  void Open(bool);
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
  UPROPERTY(EditAnywhere)
  float OpenAngle = 90.0f;
  UPROPERTY(EditAnywhere)
  ATriggerVolume* PressurePlate = nullptr;
  UPROPERTY(EditAnywhere)
  float DoorCloseDelay = 0.5f;
  float LastDoorOpenTime;
  UPROPERTY(EditAnywhere)
  float TriggerMass = 50.0f;

  float GetTotalMassOfActorsOnPlate();
};
