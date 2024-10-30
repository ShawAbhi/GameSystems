// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"

#include "Components/ShapeComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!OverlapComponentClass)
	{
		return;
	}
	OverlapComponent = NewObject<UShapeComponent>(this, OverlapComponentClass);
	if (!OverlapComponent)
	{
		return;
	}
	OverlapComponent->RegisterComponent();
	OverlapComponent->AttachToComponent(GetOwner()->GetRootComponent(),
	                                    FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	OverlapComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	if (UGameplayStatics::GetPlayerCharacter(this, 0)->IsLocallyControlled() && GetNetMode() != NM_DedicatedServer)
	{
		OverlapComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	}
	OverlapComponent->SetHiddenInGame(false);
	OverlapComponent->SetWorldScale3D(OverlapComponentScale);

	OverlapComponent->OnComponentBeginOverlap.AddDynamic(this, &UInteractionComponent::OnOverlapBegin);
	OverlapComponent->OnComponentEndOverlap.AddDynamic(this, &UInteractionComponent::OnOverlapEnd);
}

void UInteractionComponent::OnOverlapBegin_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                                                          bool bFromSweep, const FHitResult& SweepResult)
{
	//OtherActor->FindComponentByClass<>()
}

void UInteractionComponent::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
