// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PromptData.h"
#include "UObject/Interface.h"
#include "MamontHUDInterface.generated.h"

UINTERFACE(MinimalAPI)
class UMamontHUDInterface : public UInterface
{
	GENERATED_BODY()
};


class MAMONTUI_API IMamontHUDInterface
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mamont HUD Interface")
	void ShowPrompt(const FPromptData& InPromptData);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, meta = (BlueprintProtected))
	void ActionPrompt(const int32 InPromptID, const bool bResult);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mamont HUD Interface")
	void OpenOptions();
	
};