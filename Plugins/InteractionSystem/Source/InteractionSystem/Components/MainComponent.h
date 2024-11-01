// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MainComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(ByShaw), meta=(BlueprintSpawnableComponent))
class INTERACTIONSYSTEM_API UMainComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMainComponent();

	UPROPERTY()
	mutable UUserWidget* MasterWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Important")
	TSubclassOf<UUserWidget> MasterWidgetClass;
	

protected:
	virtual void BeginPlay() override;
};
