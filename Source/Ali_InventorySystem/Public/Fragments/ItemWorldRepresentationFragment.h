// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemFragment.h"
#include "ItemWorldRepresentationFragment.generated.h"

UCLASS()
class ALI_INVENTORYSYSTEM_API UItemWorldRepresentationFragment : public UInventoryItemFragment
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<UStaticMesh> ItemMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Options")
	bool bCanBeDropped = true;
};
