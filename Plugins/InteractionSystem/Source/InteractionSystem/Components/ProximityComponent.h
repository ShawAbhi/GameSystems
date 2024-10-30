// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionComponent.h"
#include "ProximityComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONSYSTEM_API UProximityComponent : public UInteractionComponent
{
	GENERATED_BODY()

public:
	UProximityComponent();

protected:
	virtual void BeginPlay() override;

	virtual void OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                                           const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                                         UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
