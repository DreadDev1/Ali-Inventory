// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDefinition/ItemDefinition.h"

const UInventoryItemFragment* UItemDefinition::FindFragmentByClass(TSubclassOf<UItemDefinition> ItemDefinition, TSubclassOf<UInventoryItemFragment> FragmentClass)
{
	if (ItemDefinition && FragmentClass)
	{
		UItemDefinition* ItemCDO = ItemDefinition.GetDefaultObject();
		
		for (const TObjectPtr<UInventoryItemFragment>& Fragment : ItemCDO->ItemFragments)
		{
			if (Fragment->IsA(FragmentClass))
			{
				return Fragment;
			}
		}
	}
	return nullptr;
}
