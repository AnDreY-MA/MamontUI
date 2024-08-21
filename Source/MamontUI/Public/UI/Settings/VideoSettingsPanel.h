// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "VideoSettingsPanel.generated.h"

class UMamontOptionCheckBoxBase;
class UMamontButtonBase;
class UMamontOptionSwitcher;
/**
 * 
 */
UCLASS()
class MAMONTUI_API UVideoSettingsPanel : public UActivatableWidgetBase
{
	GENERATED_BODY()

public:
	
	virtual void NativePreConstruct() override;

private:
	UFUNCTION()
	void OnWindowModeChanged(const FText& OptionText, const int32 OptionID);
	
	UFUNCTION()
	void OnResolutionChanged(const FText& OptionText, const int32 OptionID);

	UFUNCTION()
	void OnVSyncChanged(const bool bChecked);

	void OnAppled();

	class USettingControlComponent* TryGetSettingComponent() const;

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