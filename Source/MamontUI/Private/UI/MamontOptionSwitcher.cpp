// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MamontOptionSwitcher.h"

#include "CommonTextBlock.h"
#include "UI/MamontArrowButton.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MamontOptionSwitcher)

void UMamontOptionSwitcher::NativePreConstruct()
{
	NameBlock->SetText(Name);

	if(Options.IsValidIndex(SelectedOption))
	{
		OptionNameText->SetText(Options[SelectedOption]);
	}
}

void UMamontOptionSwitcher::NativeConstruct()
{
	LeftArrowButton->OnClicked().AddUObject(this, &UMamontOptionSwitcher::OnLeftButton);
	RightArrowButton->OnClicked().AddUObject(this, &UMamontOptionSwitcher::OnRightButton);
}

void UMamontOptionSwitcher::SetOption(const FText& InOptionText, const int32 InOptionID)
{
	OptionNameText->SetText(InOptionText);
	SelectedOption = InOptionID;
}

void UMamontOptionSwitcher::OnLeftButton()
{
	if(SelectedOption > 0)
	{
		SelectedOption = FMath::Clamp(--SelectedOption, 0, Options.Max());
	}
	UpdateOption();
}

void UMamontOptionSwitcher::OnRightButton()
{
	if(SelectedOption < Options.Max())
	{
		SelectedOption = FMath::Clamp(++SelectedOption, 0, Options.Max());
	}
	UpdateOption();
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