// Copyright Peter Tran 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "UOpenDoor.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UUOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	UUOpenDoor();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
