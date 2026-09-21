// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemFragment.h"
#include "Usable_Fragment.generated.h"

class UItemAction;

UCLASS()
class ALI_INVENTORYSYSTEM_API UUsable_Fragment : public UInventoryItemFragment
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable, Category = "Usable")
	bool Use(AActor* ItemOwner);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Options")
	bool bConsumeOnUse = true;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Actions")
	TArray<TObjectPtr<UItemAction>> UseActions;
};
