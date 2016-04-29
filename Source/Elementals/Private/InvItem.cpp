// Fill out your copyright notice in the Description page of Project Settings.

#include "Elementals.h"
#include "InvItem.h"

// Sets default values
AInvItem::AInvItem() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Props.Stackable = false;
	Props.Details = FString(TEXT("Nothing of importance"));
	Props.Name = FString(TEXT("Obj1"));
	Props.Weight = 99.99;
	Props.Value = 999.99;
	Props.Stack = 1;

}

FString AInvItem::Name() {
	//char * tmp = "";
	//sprintf(tmp,"%s (x%d)", TCHAR_TO_ANSI(*Props.Name), Props.Stack);
	//Props.Name         

	FString tmp1 = FString();
	tmp1.Append(FString::Printf(TEXT("%s (%d)"), *Props.Name, Props.Stack));
	//tmp1.AppendInt(Props.Stack);
	return tmp1;
}

// Called when the game starts or when spawned
void AInvItem::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
/*void AInvItem::Tick( float DeltaTime )
 {
 Super::Tick( DeltaTime );

 }*/

