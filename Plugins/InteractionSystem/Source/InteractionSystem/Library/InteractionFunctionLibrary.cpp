// Fill out your copyright notice in the Description page of Project Settings.

// 			UE_LOG(LogTemp,Error,TEXT("%s"),*Pawn->GetName());


#include "InteractionFunctionLibrary.h"

#include "Blueprint/UserWidget.h"
#include "InteractionSystem/Components/MainComponent.h"

UUserWidget* UInteractionFunctionLibrary::GetMasterWidget(const AActor* InActor,
                                                          TSubclassOf<UActorComponent> MainComponentClass,
                                                          bool& bOutSuccess)
{
	UActorComponent* MasterComponent = GetMainComponent(InActor, MainComponentClass, bOutSuccess);

	if (bOutSuccess)
	{
		return GetAddMasterWidget(MasterComponent, bOutSuccess);
	}

	bOutSuccess = false;
	return nullptr;
}

UActorComponent* UInteractionFunctionLibrary::GetMainComponent(const AActor* InActor,
                                                               TSubclassOf<UActorComponent> MainComponentClass,
                                                               bool& bOutSuccess)
{
	if (const APawn* Pawn = Cast<APawn>(InActor))
	{
		if (Pawn->IsLocallyControlled())
		{
			UActorComponent* Component = Pawn->GetComponentByClass(MainComponentClass);
			if (Component)
			{
				bOutSuccess = true;
				return Component;
			}
		}
	}
	bOutSuccess = false;
	return nullptr;
}

UUserWidget* UInteractionFunctionLibrary::GetAddMasterWidget(const UActorComponent* InComponent, bool& bOutSuccess)
{
	if (bOutSuccess && IsValid(InComponent))
	{
		if (const UMainComponent* MainComponent = Cast<UMainComponent>(InComponent))
		{
			if (MainComponent->MasterWidget->IsValidLowLevel())
			{
				bOutSuccess = true;
				return MainComponent->MasterWidget;
			}
			else if (MainComponent->MasterWidgetClass)
			{
				APlayerController* OwningController = Cast<APlayerController>(InComponent->GetOwner()->GetInstigatorController());
				if (OwningController)
				{
					UUserWidget* Widget = CreateWidget(OwningController, MainComponent->MasterWidgetClass);
					if (Widget)
					{
						Widget->AddToViewport();
						MainComponent->MasterWidget = Widget;
						bOutSuccess = true;
						return Widget;
					}
				}
			}
		}
	}

	bOutSuccess = false;
	return nullptr;
}
