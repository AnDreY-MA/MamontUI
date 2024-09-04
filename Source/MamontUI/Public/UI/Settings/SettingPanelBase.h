// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "SettingPanelBase.generated.h"


UCLASS(Abstract)
class MAMONTUI_API USettingPanelBase : public UActivatableWidgetBase
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintPure, meta=(BlueprintProtected))
	class USettingControlComponent* TryGetSettingComponent() const;

	
};