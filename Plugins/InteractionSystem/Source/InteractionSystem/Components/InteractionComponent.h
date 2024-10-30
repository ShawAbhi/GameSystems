// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InteractionComponent.generated.h"
 

UCLASS(Blueprintable, ClassGroup=(ByShaw), meta=(BlueprintSpawnableComponent))
class INTERACTIONSYSTEM_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInteractionComponent();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent )
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintNativeEvent )
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                  int32 OtherBodyIndex);

	UPROPERTY(BlueprintReadWrite)
	UShapeComponent* OverlapComponent{nullptr};

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = " ")
	TSubclassOf<UShapeComponent> OverlapComponentClass;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = " ")
	FVector OverlapComponentScale{10};
};
