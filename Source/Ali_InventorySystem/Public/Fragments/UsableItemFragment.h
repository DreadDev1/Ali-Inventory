// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemFragment.h"
#include "UsableItemFragment.generated.h"

class UItemAction;
/**
 * 
 */
UCLASS()
class ALI_INVENTORYSYSTEM_API UUsableItemFragment : public UInventoryItemFragment
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable)
	bool Use(AActor* ItemOwner);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Options")
	bool bConsumeOnUse = true;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Actions")
	TArray<TObjectPtr<UItemAction>> OnUseActions;
};
