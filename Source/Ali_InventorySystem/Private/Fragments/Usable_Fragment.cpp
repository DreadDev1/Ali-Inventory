// Fill out your copyright notice in the Description page of Project Settings.


#include "Fragments/Usable_Fragment.h"

#include "ItemActions/ItemAction.h"

bool UUsable_Fragment::Use(AActor* ItemOwner)
{
	
	bool bAnySuccess = false;
	for (const TObjectPtr<UItemAction>& Action : UseActions)
	{
		if (Action && Action->Execute(ItemOwner)) { bAnySuccess = true; }
	}
	return bAnySuccess;
}
