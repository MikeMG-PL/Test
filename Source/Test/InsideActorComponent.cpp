// Fill out your copyright notice in the Description page of Project Settings.


#include "InsideActorComponent.h"

// Sets default values for this component's properties
UInsideActorComponent::UInsideActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInsideActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UInsideActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UInsideActorComponent::CheckIfInside(UCapsuleComponent* C1, AActor* A)
{
	FVector Origin1, Extent1, Origin2, Extent2;

	//C1->GetActorBounds(false, Origin1, Extent1);
	//C2->GetActorBounds(false, Origin2, Extent2);

	FBox BB1;

	BB1 = C1->GetLocalBounds();
	A->GetActorBounds(false, Origin1, Extent1);

	//FBox BoxBounds1(Origin1 - Extent1, Origin1 + Extent1);
	FBox BB2(Origin1 - Extent1, Origin1 + Extent1);

	if (BB2.IsInside(BB1))
	{
		return true;
	}
	return false;
}
