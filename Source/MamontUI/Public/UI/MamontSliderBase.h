// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "MamontSliderBase.generated.h"

class USlider;
class UCommonTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSliderValueChanged, const FName&, NameSlider, const float, Value);


UCLASS()
class MAMONTUI_API UMamontSliderBase : public UActivatableWidgetBase
{
    GENERATED_BODY()

public:
	explicit UMamontSliderBase(const FObjectInitializer& InInitializer = FObjectInitializer::Get());
	
	virtual void NativePreConstruct() override;

	UPROPERTY()
	FOnSliderValueChanged OnSliderValueChanged;

private:
	UFUNCTION()
	void SliderValueChanged(float Value);
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slider", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UCommonTextBlock> NameTextBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slider", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UCommonTextBlock> ValueTextBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slider", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<USlider> Slider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider|Data", meta=(AllowPrivateAccess=true))
	FText SettingName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider|Data", meta=(AllowPrivateAccess=true))
	FName MixName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider|Data", meta=(AllowPrivateAccess=true))
	float MinValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider|Data", meta=(AllowPrivateAccess=true))
	float MaxValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider|Data", meta=(AllowPrivateAccess=true))
	float CurrentValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider|Data", meta=(AllowPrivateAccess=true))
	float StepSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider|Data", meta=(AllowPrivateAccess=true))
	float ControllerStepSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slider|Data", meta=(AllowPrivateAccess=true))
	float VisualMultiplyer;
	
};