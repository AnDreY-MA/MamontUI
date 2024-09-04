// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SettingPanelBase.h"
#include "VideoSettingsPanel.generated.h"

class UMamontOptionCheckBoxBase;
class UMamontButtonBase;
class UMamontOptionSwitcher;
/**
 * 
 */
UCLASS(Abstract)
class MAMONTUI_API UVideoSettingsPanel : public USettingPanelBase
{
	GENERATED_BODY()

public:
	
	virtual void NativePreConstruct() override;

private:
	void OnAppled();

	UFUNCTION()
	void OnVSyncChanged(const bool bChecked);
	
	UFUNCTION()
	void OnWindowModeChanged(const FText& OptionText, const int32 OptionID);
	
	UFUNCTION()
	void OnResolutionChanged(const FText& OptionText, const int32 OptionID);
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> ResolutionSwitcher;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> WindowsModeSwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionCheckBoxBase> VSyncCheckBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontButtonBase> ApplyButton;
	
};