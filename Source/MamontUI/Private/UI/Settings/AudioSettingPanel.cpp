// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Settings/AudioSettingPanel.h"

#include "Components/SettingControlComponent.h"
#include "GameFramework/HUD.h"
#include "Interfaces/SettingControlComponentInterface.h"
#include "UI/MamontSliderBase.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AudioSettingPanel)

void UAudioSettingPanel::NativePreConstruct()
{
	Super::NativePreConstruct();

	MasterSlider->OnSliderValueChanged.AddDynamic(this, &UAudioSettingPanel::OnSliderChanged);
	MusicSlider->OnSliderValueChanged.AddDynamic(this, &UAudioSettingPanel::OnSliderChanged);
	VoiceSlider->OnSliderValueChanged.AddDynamic(this, &UAudioSettingPanel::OnSliderChanged);
	SoundEffectSlider->OnSliderValueChanged.AddDynamic(this, &UAudioSettingPanel::OnSliderChanged);
	UISlider->OnSliderValueChanged.AddDynamic(this, &UAudioSettingPanel::OnSliderChanged);

}

USettingControlComponent* UAudioSettingPanel::TryGetSettingComponent() const
{
	const auto* Player{GetOwningPlayer()};
	check(Player);
	
	const auto* Hud{Player->GetHUD()};
	check(Hud);
	
	if(Hud->Implements<USettingControlComponentInterface>())
	{
		return ISettingControlComponentInterface::Execute_GetSettingComponent(Hud);
	}
	
	return Hud->FindComponentByClass<USettingControlComponent>();
	
}

void UAudioSettingPanel::OnSliderChanged(const FName& NameSlider, const float Value)
{
	auto* SettingComponent{TryGetSettingComponent()};
	SettingComponent->ChangeAudioVolume(NameSlider, Value);
	
}