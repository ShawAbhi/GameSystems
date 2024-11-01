// Fill out your copyright notice in the Description page of Project Settings.


#include "MainComponent.h"


UMainComponent::UMainComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UMainComponent::BeginPlay()
{
	Super::BeginPlay();
}
