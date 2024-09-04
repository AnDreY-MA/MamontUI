// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SettingControlComponent.h"

#include "GameFramework/GameUserSettings.h"
#include "Kismet/KismetSystemLibrary.h"

USettingControlComponent::USettingControlComponent(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;


}

void USettingControlComponent::ChangeScreenResolution(const FText& InOptionText, const int32 InOptionID)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	check(GameSetting);

	TArray<FIntPoint> SupportResolutions;
	UKismetSystemLibrary::GetSupportedFullscreenResolutions(SupportResolutions);
	int Index{0};
	for(const auto& Resolution : SupportResolutions)
	{
		if(Index == InOptionID)
		{
			GameSetting->SetScreenResolution(Resolution);
			break;
		}
		++Index;
	}
	
}

void USettingControlComponent::ChangeWindowMode(const FText& InOptionText, const int32 InOptionID)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	check(GameSetting);

	GameSetting->SetFullscreenMode(static_cast<EWindowMode::Type>(InOptionID));
	
}

void USettingControlComponent::ApplySetting()
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	check(GameSetting);

	GameSetting->ApplySettings(false);
	
}

void USettingControlComponent::ChangeVSync(bool bChecked)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	check(GameSetting);
	GameSetting->SetVSyncEnabled(bChecked);
	GameSetting->ApplyNonResolutionSettings();
	
}

void USettingControlComponent::ChangeAudioVolume(const FName& InNameAudio, const float InValue)
{
	if(!MixMaps.Contains(InNameAudio)) return;

	
}

void USettingControlComponent::SetOverallScalabilityLevel(const int32 InValue)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	check(GameSetting);
	GameSetting->SetOverallScalabilityLevel(InValue);

}

void USettingControlComponent::ChangeTextureQuality(const int32 InValue)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	GameSetting->SetTextureQuality(InValue);
	GameSetting->ApplyNonResolutionSettings();
}

void USettingControlComponent::ChangeVisibilityQuality(const int32 InValue)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
//	GameSetting->Set(InValue);
	GameSetting->ApplyNonResolutionSettings();
}

void USettingControlComponent::ChangeAntialiasingQuality(const int32 InValue)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	GameSetting->SetAntiAliasingQuality(InValue);
	GameSetting->ApplyNonResolutionSettings();
}

void USettingControlComponent::ChangeShadowQuality(const int32 InValue)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	GameSetting->SetShadowQuality(InValue);
	GameSetting->ApplyNonResolutionSettings();
}

void USettingControlComponent::ChangePostProcessingQuality(const int32 InValue)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	GameSetting->SetPostProcessingQuality(InValue);
	GameSetting->ApplyNonResolutionSettings();
}

void USettingControlComponent::ChangeEffectQuality(const int32 InValue)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	GameSetting->SetVisualEffectQuality(InValue);
	GameSetting->ApplyNonResolutionSettings();
}

void USettingControlComponent::ChangeShadingQuality(const int32 InValue)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	GameSetting->SetShadingQuality(InValue);
	GameSetting->ApplyNonResolutionSettings();
}

void USettingControlComponent::ChangeVegetationQuality(const int32 InValue)
{
	auto* GameSetting{UGameUserSettings::GetGameUserSettings()};
	GameSetting->SetFoliageQuality(InValue);
	GameSetting->ApplyNonResolutionSettings();
}