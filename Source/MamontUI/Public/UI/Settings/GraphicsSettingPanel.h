// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SettingPanelBase.h"
#include "GraphicsSettingPanel.generated.h"

class UMamontOptionSwitcher;


UCLASS(Abstract, Blueprintable)
class MAMONTUI_API UGraphicsSettingPanel : public USettingPanelBase
{
	GENERATED_BODY()

public:
	explicit UGraphicsSettingPanel(const FObjectInitializer& InInitializer = FObjectInitializer::Get());
	
	virtual void NativeConstruct() override;

protected:
	UFUNCTION()
	void OnPresetsChanged(const FText& OptionText, const int32 OptionID);
	
	UFUNCTION()
	void OnTextureChanged(const FText& OptionText, const int32 OptionID);

	UFUNCTION()
	void OnAntialiasingChanged(const FText& OptionText, const int32 OptionID);
	UFUNCTION()
	void OnShadowChanged(const FText& OptionText, const int32 OptionID);
	UFUNCTION()
	void OnPostProcessingChanged(const FText& OptionText, const int32 OptionID);
	UFUNCTION()
	void OnEffectChanged(const FText& OptionText, const int32 OptionID);
	UFUNCTION()
	void OnShadingChanged(const FText& OptionText, const int32 OptionID);
	UFUNCTION()
	void OnVegetationChanged(const FText& OptionText, const int32 OptionID);


private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> PresetsQualitySwitcher;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> VisibilitySwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> TextureSwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> AntialiasingSwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> ShadowSwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> PostProcessingSwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> EffectSwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> ShadingSwitcher;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontOptionSwitcher> VegetationSwitcher;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", meta=(BindWidget, AllowPrivateAccess="true"))
	FText CustomText;
};