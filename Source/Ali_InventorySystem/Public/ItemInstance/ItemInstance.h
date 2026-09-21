// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "ItemInstance.generated.h"

class UInventoryItemFragment;
class UItemDefinition;
UCLASS(BlueprintType)
class ALI_INVENTORYSYSTEM_API UItemInstance : public UObject
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadOnly)
	TSubclassOf<UItemDefinition> ItemDefinition;
	
	UPROPERTY(BlueprintReadOnly)
	TMap<FGameplayTag, float> StatsMap; 
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Categories = "Item.Stat"), Category = "Inventory|Item Instance")
	float GetStatValue(FGameplayTag StatTag);
	
	UFUNCTION(BlueprintCallable, meta = (Categories = "Item.Stat"), Category = "Inventory|Item Instance")
	void SetStatValue(FGameplayTag StatTag, float StatValue);
	
	UFUNCTION(BlueprintCallable, Category = "Inventory|Item Instance")
	void Initialize(TSubclassOf<UItemDefinition> ItemDef);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DeterminesOutputType = "FragmentClass"), Category = "Inventory|Item Definition")
	const UInventoryItemFragment* FindFragmentByClass(const TSubclassOf<UInventoryItemFragment> FragmentClass);
};
