// Copyright Peter Tran 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	UOpenDoor();
  void Open();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
  UPROPERTY(VisibleAnywhere)
  float OpenAngle = 90.0f;

  UPROPERTY(EditAnywhere)
  ATriggerVolume* PressurePlate;

  AActor* ActorThatOpens;
};
