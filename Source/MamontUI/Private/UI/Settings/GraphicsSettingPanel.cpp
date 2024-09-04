// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Settings/GraphicsSettingPanel.h"

#include "Components/SettingControlComponent.h"
#include "UI/MamontOptionSwitcher.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GraphicsSettingPanel)


UGraphicsSettingPanel::UGraphicsSettingPanel(const FObjectInitializer& InInitializer)
	: Super(InInitializer)
{
}

void UGraphicsSettingPanel::NativeConstruct()
{
	Super::NativeConstruct();

	PresetsQualitySwitcher->OnOptionSwitched.AddDynamic(this, &UGraphicsSettingPanel::OnPresetsChanged);
	TextureSwitcher->OnOptionSwitched.AddDynamic(this, &UGraphicsSettingPanel::OnTextureChanged);
	AntialiasingSwitcher->OnOptionSwitched.AddDynamic(this, &UGraphicsSettingPanel::OnAntialiasingChanged);
	ShadowSwitcher->OnOptionSwitched.AddDynamic(this, &UGraphicsSettingPanel::OnShadowChanged);
	PostProcessingSwitcher->OnOptionSwitched.AddDynamic(this, &UGraphicsSettingPanel::OnPostProcessingChanged);
	EffectSwitcher->OnOptionSwitched.AddDynamic(this, &UGraphicsSettingPanel::OnEffectChanged);
	ShadingSwitcher->OnOptionSwitched.AddDynamic(this, &UGraphicsSettingPanel::OnShadingChanged);
	VegetationSwitcher->OnOptionSwitched.AddDynamic(this, &UGraphicsSettingPanel::OnVegetationChanged);
}

void UGraphicsSettingPanel::OnPresetsChanged(const FText& OptionText, const int32 OptionID)
{
	auto* SettingComponent{TryGetSettingComponent()};
	SettingComponent->SetOverallScalabilityLevel(OptionID);

	PresetsQualitySwitcher->SetOption(OptionText, OptionID);
	VisibilitySwitcher->SetOption(OptionText, OptionID);
	TextureSwitcher->SetOption(OptionText, OptionID);
	AntialiasingSwitcher->SetOption(OptionText, OptionID);
	ShadowSwitcher->SetOption(OptionText, OptionID);
	PostProcessingSwitcher->SetOption(OptionText, OptionID);
	EffectSwitcher->SetOption(OptionText, OptionID);
	ShadingSwitcher->SetOption(OptionText, OptionID);
	VegetationSwitcher->SetOption(OptionText, OptionID);
	
}

void UGraphicsSettingPanel::OnTextureChanged(const FText& OptionText, const int32 OptionID)
{
	auto* SettingComponent{TryGetSettingComponent()};
	SettingComponent->ChangeTextureQuality(OptionID);
	PresetsQualitySwitcher->SetOption(CustomText, 0);

}

void UGraphicsSettingPanel::OnAntialiasingChanged(const FText& OptionText, const int32 OptionID)
{
	auto* SettingComponent{TryGetSettingComponent()};
	SettingComponent->ChangeAntialiasingQuality(OptionID);
	PresetsQualitySwitcher->SetOption(CustomText, 0);

}

void UGraphicsSettingPanel::OnShadowChanged(const FText& OptionText, const int32 OptionID)
{
    auto* SettingComponent{TryGetSettingComponent()};
	SettingComponent->ChangeShadowQuality(OptionID);
	PresetsQualitySwitcher->SetOption(CustomText, 0);

}

void UGraphicsSettingPanel::OnPostProcessingChanged(const FText& OptionText, const int32 OptionID)
{
	auto* SettingComponent{TryGetSettingComponent()};
	SettingComponent->ChangePostProcessingQuality(OptionID);
	PresetsQualitySwitcher->SetOption(CustomText, 0);

}

void UGraphicsSettingPanel::OnEffectChanged(const FText& OptionText, const int32 OptionID)
{
	auto* SettingComponent{TryGetSettingComponent()};
	SettingComponent->ChangeEffectQuality(OptionID);
	PresetsQualitySwitcher->SetOption(CustomText, 0);

}

void UGraphicsSettingPanel::OnShadingChanged(const FText& OptionText, const int32 OptionID)
{
	auto* SettingComponent{TryGetSettingComponent()};
	SettingComponent->ChangeShadingQuality(OptionID);
	PresetsQualitySwitcher->SetOption(CustomText, 0);

}

void UGraphicsSettingPanel::OnVegetationChanged(const FText& OptionText, const int32 OptionID)
{
	auto* SettingComponent{TryGetSettingComponent()};
	SettingComponent->ChangeVegetationQuality(OptionID);
	PresetsQualitySwitcher->SetOption(CustomText, 0);

}