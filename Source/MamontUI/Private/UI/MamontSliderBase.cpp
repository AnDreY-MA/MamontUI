// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/MamontSliderBase.h"

#include "CommonTextBlock.h"
#include "Components/Slider.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MamontSliderBase)

UMamontSliderBase::UMamontSliderBase(const FObjectInitializer& InInitializer) :
	Super(InInitializer), SettingName(FText::FromString("{SettingName}")), MixName("MixName"), MinValue(0), MaxValue(1), CurrentValue(0), StepSize(0.01), ControllerStepSize(1),
	VisualMultiplyer(1)
{
}

void UMamontSliderBase::NativePreConstruct()
{
	Super::NativePreConstruct();

	NameTextBox->SetText(SettingName);

	Slider->SetMinValue(MinValue);
	Slider->SetMaxValue(MaxValue);
	Slider->SetValue(CurrentValue);
	Slider->SetStepSize(StepSize);
	Slider->OnValueChanged.AddDynamic(this, &UMamontSliderBase::SliderValueChanged);

	ValueTextBox->SetText(FText::AsNumber(CurrentValue));
	
}

void UMamontSliderBase::SliderValueChanged(float Value)
{
	CurrentValue = Value;
	Slider->SetValue(CurrentValue);
	ValueTextBox->SetText(FText::AsNumber(CurrentValue * VisualMultiplyer));
	if(OnSliderValueChanged.IsBound())
	{
		OnSliderValueChanged.Broadcast(MixName, CurrentValue);
	}
	
}