// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemAction.generated.h"

UCLASS(Blueprintable, BlueprintType, Abstract, DefaultToInstanced, EditInlineNew)
class ALI_INVENTORYSYSTEM_API UItemAction : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintNativeEvent, Category = "Item Action")
	bool Execute(AActor* ItenOwner);
};
