// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InventoryItemFragment.generated.h"

/** A fragment representing an item in the inventory. */


UCLASS(Blueprintable, BlueprintType, Abstract, DefaultToInstanced, EditInlineNew)
class ALI_INVENTORYSYSTEM_API UInventoryItemFragment : public UObject
{
	GENERATED_BODY()
};
