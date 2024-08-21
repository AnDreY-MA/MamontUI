// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MamontOptionCheckBoxBase.h"

#include "CommonTextBlock.h"
#include "Components/CheckBox.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MamontOptionCheckBoxBase)


UMamontOptionCheckBoxBase::UMamontOptionCheckBoxBase(const FObjectInitializer& InInitializer)
	: Super(InInitializer), SettingName(FText::FromString("{CheckBox}")), CheckStatus(ECheckBoxState::Unchecked), bChecked(false), bCanInteract(false)
{
}

void UMamontOptionCheckBoxBase::NativePreConstruct()
{
	Super::NativePreConstruct();

	NameTextBox->SetText(SettingName);
	CheckBox->SetCheckedState(CheckStatus);
	CheckBox->OnCheckStateChanged.AddDynamic(this, &UMamontOptionCheckBoxBase::CheckBoxChanged);
	
}

void UMamontOptionCheckBoxBase::CheckBoxChanged(bool bIsChecked)
{
	if(OnCheckBoxChanged.IsBound())
	{
		OnCheckBoxChanged.Broadcast(bIsChecked);
	}
	
}