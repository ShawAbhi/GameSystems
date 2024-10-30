// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GS_Main.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONSYSTEM_API UGS_Main : public UActorComponent
{
	GENERATED_BODY()

public:
	UGS_Main();

protected:
	virtual void BeginPlay() override;

};
