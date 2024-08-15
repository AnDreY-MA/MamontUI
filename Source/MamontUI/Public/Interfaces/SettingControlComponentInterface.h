// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SettingControlComponentInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USettingControlComponentInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MAMONTUI_API ISettingControlComponentInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Setting Control Component Interface")
	class USettingControlComponent* GetSettingComponent() const;
	
};