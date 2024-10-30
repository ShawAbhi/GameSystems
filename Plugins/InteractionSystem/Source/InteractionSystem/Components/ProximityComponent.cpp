// Fill out your copyright notice in the Description page of Project Settings.


#include "ProximityComponent.h"


// Sets default values for this component's properties
UProximityComponent::UProximityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProximityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UProximityComponent::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin_Implementation(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep,
	                                     SweepResult);
}

void UProximityComponent::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd_Implementation(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}


// Called every frame
void UProximityComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

