// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemInstance/ItemInstance.h"
#include "UObject/Object.h"
#include "EquipmentInstance.generated.h"

class UEquipmentDefinition;
class UItemInstance;

UCLASS(BlueprintType)
class ALI_INVENTORYSYSTEM_API UEquipmentInstance : public UObject
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadOnly, Category = "Equipment|Equipment Instance")
	TSubclassOf<UEquipmentDefinition> EquipmentDefinition;
	
	UPROPERTY(BlueprintReadOnly, Category = "Equipment|Equipment Instance")
	TObjectPtr<UItemInstance> SourceItemInstance;
	
	UPROPERTY(BlueprintReadOnly, Category = "Equipment|Equipment Instance")
	TObjectPtr<AActor> SpawnedEquipmentActor;
	
	UFUNCTION(BlueprintCallable)
	void Initialize(UItemInstance* ItemInstance, ACharacter* Character);
	
	UFUNCTION(BlueprintCallable)
	void HandleEquipItem(ACharacter* Character);
	
	UFUNCTION(BlueprintCallable)
	void HandleUnEquipItem(ACharacter* Character);
};