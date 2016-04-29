// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "string"
#include "InvItem.generated.h"

//using std::string;

USTRUCT()
struct FInvItemProp
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inv Item")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inv Item")
	float Weight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inv Item")
	float Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inv Item")
	FString Details;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	//UTexture2D Thumbnail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inv Item")
	bool Stackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inv Item")
	int32 Stack;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ELEMENTALS_API AInvItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's propertiese
	AInvItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inv Item")
	FInvItemProp Props;

	UFUNCTION(BlueprintCallable, Category = "Inv Item")
	FString Name();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	//virtual void Tick( float DeltaSeconds ) override;

};
