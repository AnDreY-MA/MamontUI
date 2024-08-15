// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SettingControlComponent.h"

#include "GameFramework/GameUserSettings.h"
#include "Kismet/KismetSystemLibrary.h"

USettingControlComponent::USettingControlComponent()
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