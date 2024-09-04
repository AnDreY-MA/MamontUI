// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MamontOptionSwitcher.h"

#include "CommonTextBlock.h"
#include "UI/MamontArrowButton.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MamontOptionSwitcher)

UMamontOptionSwitcher::UMamontOptionSwitcher(const FObjectInitializer& InInitializer) :
	Super(InInitializer), SelectedOption(0)

{
}

void UMamontOptionSwitcher::NativePreConstruct()
{
	Super::NativePreConstruct();

	if(Options.IsValidIndex(SelectedOption))
	{
		OptionNameText->SetText(Options[SelectedOption]);
	}
	
	SettingNameText->SetText(SettingName);

	RightArrowButton->OnClicked().AddUObject(this, &UMamontOptionSwitcher::OnRightArrowClick);
	LeftArrowButton->OnClicked().AddUObject(this, &UMamontOptionSwitcher::OnLeftArrowClick);

}

void UMamontOptionSwitcher::SetOption(const FText& InOptionText, const int32 InOptionID)
{
	OptionNameText->SetText(InOptionText);
	SelectedOption = InOptionID;
}

void UMamontOptionSwitcher::OnRightArrowClick()
{
	if(SelectedOption < Options.Max())
	{
		SelectedOption = FMath::Clamp(++SelectedOption, 0, Options.Max());
	}
	UpdateOption();

}

void UMamontOptionSwitcher::OnLeftArrowClick()
{
	if(SelectedOption > 0)
	{
		SelectedOption = FMath::Clamp(--SelectedOption, 0, Options.Max());
	}
	UpdateOption();

}

void UMamontOptionSwitcher::SwitchOption(const bool bDecrease)
{
	
}

void UMamontOptionSwitcher::UpdateOption()
{
	if(Options.IsValidIndex(SelectedOption))
	{
		const FText Option = Options[SelectedOption];
		OptionNameText->SetText(Option);
		OnOptionSwitched.Broadcast(Option, SelectedOption);
	}
	
}
