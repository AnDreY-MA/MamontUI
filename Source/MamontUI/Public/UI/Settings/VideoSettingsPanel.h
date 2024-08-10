// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "VideoSettingsPanel.generated.h"

class UMamontOptionSwitcher;
/**
 * 
 */
UCLASS()
class MAMONTUI_API UVideoSettingsPanel : public UActivatableWidgetBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> WindowsModeSwitcher;
};
