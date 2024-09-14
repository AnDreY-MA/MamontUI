// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Settings/SettingPanelBase.h"

#include "Components/SettingControlComponent.h"
#include "GameFramework/HUD.h"
#include "Interfaces/SettingControlComponentInterface.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(SettingPanelBase)

USettingControlComponent* USettingPanelBase::TryGetSettingComponent() const
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