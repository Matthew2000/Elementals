// Fill out your copyright notice in the Description page of Project Settings.

#include "Elementals.h"
#include "MyInventory.h"
#include "string"


// Sets default values for this component's properties
UMyInventory::UMyInventory() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//bWantsBeginPlay = true;
	//PrimaryComponentTick.bCanEverTick = true;

	// ...
	nullProp.Stackable = false;
	nullProp.Details = FString(TEXT("NULL"));
	nullProp.Name = FString(TEXT("NULL"));
	nullProp.Weight = -1;
	nullProp.Value = -1;
	nullProp.Stack = -1;
}

FString UMyInventory::DisplayName(int32 i) {

	FString tmp1 = FString();
	tmp1.Append(FString::Printf(TEXT("%s (%d)"), *Inventory[i].Name, Inventory[i].Stack));
	return tmp1;
}

FInvItemProp& UMyInventory::getInvItem(int32 i) {
	if (i < Inventory.Num()) {
		return Inventory[i];
	}
	return nullProp;
}

int32 UMyInventory::length() {
	return int32(Inventory.Num());
}

// Called when the game starts
void UMyInventory::BeginPlay() {
	Super::BeginPlay();
	std::string tmp[] = { "ball", "box" };
	AcceptedTypes.Append(tmp, ARRAY_COUNT(tmp));

	// ...

}

bool UMyInventory::Find(FInvItemProp & Inv, int32 & i) {
	i = 0;
	for (FInvItemProp & Inv1 : Inventory) {
		if (Inv1.Name == Inv.Name) {
			return true;
		}
		++i;
	}
	return false;
}

bool UMyInventory::Add(FInvItemProp Inv) {
	int32 i = (int32)0;
	//((int) Inventory.Num() < 1)||
	if (!(Inv.Stackable)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("not stackable"));
		return false;
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("stackable"));

	if (Find(Inv, i)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("found"));
		++(&Inventory[i])->Stack;
		return true;
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black,
			TEXT("not found"));
		(&Inventory)->Emplace(Inv);
		return true;
	}
	return false;
}

bool operator==(const FInvItemProp& a, const FInvItemProp& b) {
	return a.Name == b.Name;
}

// Called every frame
/*void UMyInventory::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
 {
 Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

 // ...
 }*/

