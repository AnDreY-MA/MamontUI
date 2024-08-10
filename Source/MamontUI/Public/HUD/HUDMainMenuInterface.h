// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HUDMainMenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHUDMainMenuInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MAMONTUI_API IHUDMainMenuInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="HUD Main Menu Interface")
	void StartNewGame();
	
};