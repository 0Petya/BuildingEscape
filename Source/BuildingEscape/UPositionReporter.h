// Copyright Peter Tran 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "UPositionReporter.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UUPositionReporter : public UActorComponent
{
	GENERATED_BODY()

public:	
	UUPositionReporter();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
