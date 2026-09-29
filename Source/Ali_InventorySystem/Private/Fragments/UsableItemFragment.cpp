// Fill out your copyright notice in the Description page of Project Settings.


#include "Fragments/UsableItemFragment.h"

#include "ItemActions/ItemAction.h"

bool UUsableItemFragment::Use(AActor* ItemOwner, UItemInstance* ItemInstance)
{
	bool bAnySucceeded = false;
	for (const TObjectPtr<UItemAction>& Action : OnUseActions)
	{
		if (Action && Action->Execute(ItemOwner, ItemInstance)) { bAnySucceeded = true; }
	}
	return bAnySucceeded;	
}
