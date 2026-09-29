// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentInstance/EquipmentInstance.h"

#include "EquipmentDefinition/EquipmentDefinition.h"
#include "Fragments/EquippableFragment.h"
#include "GameFramework/Character.h"

void UEquipmentInstance::Initialize(UItemInstance* ItemInstance, ACharacter* Character)
{
	if (!ItemInstance) return;
	SourceItemInstance = ItemInstance;
	
	const UEquippableFragment* EquippableFragment = Cast<UEquippableFragment>(
		ItemInstance->FindFragmentByClass(UEquippableFragment::StaticClass()));
	
	if (!EquippableFragment) return;
	EquipmentDefinition = EquippableFragment->EquipmentDefinition;
	HandleEquipItem(Character);
}

void UEquipmentInstance::HandleEquipItem(ACharacter* Character)
{
	UEquipmentDefinition* DefinitionCDO = EquipmentDefinition.GetDefaultObject();
	
	if (!DefinitionCDO) return;
	SpawnedEquipmentActor = GetWorld()->SpawnActor(DefinitionCDO->EquipmentActorClass);
	
	if (!SpawnedEquipmentActor) return;
	SpawnedEquipmentActor->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, DefinitionCDO->AttachSocketName);
}

void UEquipmentInstance::HandleUnEquipItem(ACharacter* Character)
{
	if (SpawnedEquipmentActor)
	{
		SpawnedEquipmentActor->Destroy();
		SpawnedEquipmentActor = nullptr;
	}
}
