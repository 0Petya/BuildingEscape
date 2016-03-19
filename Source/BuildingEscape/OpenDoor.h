// Copyright Peter Tran 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent {

	GENERATED_BODY()

public:	
	UOpenDoor();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

  UPROPERTY(BlueprintAssignable)
  FDoorEvent OnOpen;
  UPROPERTY(BlueprintAssignable)
  FDoorEvent OnClose;

private:
  UPROPERTY(EditAnywhere)
  ATriggerVolume* PressurePlate = nullptr;
  UPROPERTY(EditAnywhere)
  float TriggerMass = 50.0f;

  float GetTotalMassOfActorsOnPlate();
};
