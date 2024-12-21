// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "MamontInputKeyInput.generated.h"

class UCommonTextBlock;
class UInputKeySelector;
class UMamontButtonBase;

UCLASS(Abstract, Blueprintable)
class MAMONTUI_API UMamontInputKeyInput : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UCommonTextBlock> InputName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UInputKeySelector> InputSelector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UMamontButtonBase> ResetButton;
};
