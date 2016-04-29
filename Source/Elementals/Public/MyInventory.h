// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "InvItem.h"
#include "MyInventory.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ELEMENTALS_API UMyInventory : public UActorComponent
{
	GENERATED_BODY()

	TArray<std::string> AcceptedTypes;
	bool Find(FInvItemProp & Inv, int32 & i);

public:
	// Sets default values for this component's properties
	UMyInventory();
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FInvItemProp> Inventory;

	UFUNCTION(BlueprintCallable, Category = "Inv Item")
		FString DisplayName(int32 i);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		FInvItemProp& getInvItem(int32 i);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 length();

	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Inventory")
		bool Add(FInvItemProp Inv);

	// Called every frame
	//virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
private:
	FInvItemProp nullProp;

};
