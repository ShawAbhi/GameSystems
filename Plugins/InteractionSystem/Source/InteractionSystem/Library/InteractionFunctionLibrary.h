// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InteractionFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup=(ByShaw))
class INTERACTIONSYSTEM_API UInteractionFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UUserWidget* GetMasterWidget(const AActor* InActor, TSubclassOf<UActorComponent> MainComponentClass,
	                             bool& bOutSuccess);

private:
	UActorComponent* GetMainComponent(const AActor* InActor, TSubclassOf<UActorComponent> MainComponentClass,
	                                  bool& bOutSuccess);
	UUserWidget* GetAddMasterWidget(const UActorComponent* InComponent, bool& bOutSuccess);
};
