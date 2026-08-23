// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fragments/InventoryItemFragment.h"
#include "UObject/Object.h"
#include "ItemDefinition.generated.h"

UCLASS(Blueprintable, BlueprintType, Abstract, Const)
class ALI_INVENTORYSYSTEM_API UItemDefinition : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Item Definition")
	FText ItemName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Item Definition")
	FText ItemDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Item Definition")
	TObjectPtr<UTexture2D> ItemIcon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Inventory|Fragments Array")
	TArray<TObjectPtr<UInventoryItemFragment>> ItemFragments;
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DeterminesOutputType = "FragmentClass"), Category = "Inventory|Item Definition")
	static const UInventoryItemFragment* FindFragmentByClass(const TSubclassOf<UItemDefinition> ItemDefinition, const TSubclassOf<UInventoryItemFragment> FragmentClass);
};
