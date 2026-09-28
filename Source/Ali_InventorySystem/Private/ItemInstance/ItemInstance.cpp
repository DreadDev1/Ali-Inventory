// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemInstance/ItemInstance.h"

#include "ItemDefinition/ItemDefinition.h"

float UItemInstance::GetStatValue(FGameplayTag StatTag)
{
	return StatsMap.FindRef(StatTag);
}

void UItemInstance::SetStatValue(FGameplayTag StatTag, float StatValue)
{
	StatsMap.Add(StatTag, StatValue);
}

void UItemInstance::Initialize(TSubclassOf<UItemDefinition> ItemDef, const TMap<FGameplayTag, float>& InitialStats)
{
	if (!ItemDef) return;
	ItemDefinition = ItemDef;
	
	UItemDefinition* ItemCDO = ItemDefinition.GetDefaultObject();
		
	for (const TObjectPtr<UInventoryItemFragment>& Fragment : ItemCDO->ItemFragments)
	{
		Fragment->OnInstanceCreated(this);
	}
	
	if (!InitialStats.IsEmpty()) { StatsMap = InitialStats; }
}

const UInventoryItemFragment* UItemInstance::FindFragmentByClass(const TSubclassOf<UInventoryItemFragment> FragmentClass)
{
	if (!FragmentClass) return nullptr;
	UItemDefinition* ItemCDO = ItemDefinition.GetDefaultObject();
	return ItemCDO->FindFragmentByClass(ItemDefinition, FragmentClass);
}
