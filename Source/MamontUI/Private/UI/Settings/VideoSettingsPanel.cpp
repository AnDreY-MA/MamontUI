// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Settings/VideoSettingsPanel.h"

#include "Components/SettingControlComponent.h"
#include "GameFramework/HUD.h"
#include "Interfaces/SettingControlComponentInterface.h"
#include "UI/MamontButtonBase.h"
#include "UI/MamontOptionCheckBoxBase.h"
#include "UI/MamontOptionSwitcher.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(VideoSettingsPanel)


void UVideoSettingsPanel::NativePreConstruct()
{
	Super::NativePreConstruct();

	WindowsModeSwitcher->OnOptionSwitched.AddDynamic(this, &UVideoSettingsPanel::OnWindowModeChanged);
	ResolutionSwitcher->OnOptionSwitched.AddDynamic(this, &UVideoSettingsPanel::OnResolutionChanged);
	VSyncCheckBox->OnCheckBoxChanged.AddDynamic(this, &UVideoSettingsPanel::OnVSyncChanged);

	ApplyButton->OnClicked().AddUObject(this, &UVideoSettingsPanel::OnAppled);
	
}

void UVideoSettingsPanel::OnWindowModeChanged(const FText& OptionText, const int32 OptionID)
{
	auto* SettingComponent {TryGetSettingComponent()};
	SettingComponent->ChangeWindowMode(OptionText, OptionID);
	
}

void UVideoSettingsPanel::OnResolutionChanged(const FText& OptionText, const int32 OptionID)
{
	auto* SettingComponent {TryGetSettingComponent()};
	SettingComponent->ChangeScreenResolution(OptionText, OptionID);
	
}

void UVideoSettingsPanel::OnVSyncChanged(const bool bChecked)
{
	auto* SettingComponent {TryGetSettingComponent()};
	SettingComponent->ChangeVSync(bChecked);
}

void UVideoSettingsPanel::OnAppled()
{
	auto* SettingComponent{TryGetSettingComponent()};
	SettingComponent->ApplySetting();
	
}

USettingControlComponent* UVideoSettingsPanel::TryGetSettingComponent() const
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
