// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "MamontSettingsWidgetPanel.generated.h"

class UGraphicsSettingPanel;
class UAudioSettingPanel;
class UVideoSettingsPanel;
class UCommonActivatableWidgetSwitcher;


UCLASS(Abstract)
class MAMONTUI_API UMamontSettingsWidgetPanel : public UActivatableWidgetBase
{
	GENERATED_BODY()


private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> WidgetSwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UVideoSettingsPanel> VideoSettingsPanel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UGraphicsSettingPanel> GraphicsSettingPanel;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UAudioSettingPanel> AudioSettingPanel;

	
};