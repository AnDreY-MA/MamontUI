// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "Components/SettingControlComponent.h"
#include "AudioSettingPanel.generated.h"

class UMamontSliderBase;
class USettingControlComponent;


UCLASS(Abstract)
class MAMONTUI_API UAudioSettingPanel : public UActivatableWidgetBase
{
	GENERATED_BODY()

public:
	
	virtual void NativePreConstruct() override;

private:
	USettingControlComponent* TryGetSettingComponent() const;

	UFUNCTION()
	void OnSliderChanged(const FName& NameSlider, const float Value);
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio Setting", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UMamontSliderBase> MasterSlider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio Setting", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UMamontSliderBase> MusicSlider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio Setting", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UMamontSliderBase> VoiceSlider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio Setting", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UMamontSliderBase> SoundEffectSlider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio Setting", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UMamontSliderBase> UISlider;
	
};
