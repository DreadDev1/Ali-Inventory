// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fragments/InventoryItemFragment.h"
#include "UObject/Object.h"
#include "ItemInstance.generated.h"

class UItemDefinition;
/**
 * 
 */
UCLASS(BlueprintType)
class ALI_INVENTORYSYSTEM_API UItemInstance : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Item Instance")
	TSubclassOf<UItemDefinition> ItemDefinition;
	
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Item Instance|Stats")
	TMap<FGameplayTag, float> StatsMap;
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Inventory|Item Instance|Item Stats", meta = (Categories = "Item.Stat"))
	float GetStatValue(FGameplayTag StatTag);
	
	UFUNCTION(BlueprintCallable, Category = "Inventory|Item Instance|Item Stats", meta = (Categories = "Item.Stat"))
	void SetStatValue(FGameplayTag StatTag, float StatValue);
	
	UFUNCTION(BlueprintCallable, Category = "Inventory|Item Instance")
	void Initialize(TSubclassOf<UItemDefinition> ItemDef);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DeterminesOutputType = "FragmentClass"), Category = "Inventory|Item Definition")
	const UInventoryItemFragment* FindFragmentByClass(const TSubclassOf<UInventoryItemFragment> FragmentClass);
	
};
