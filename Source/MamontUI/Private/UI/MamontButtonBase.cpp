// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MamontButtonBase.h"
#include "CommonTextBlock.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MamontButtonBase)

UMamontButtonBase::UMamontButtonBase(const FObjectInitializer& InInitializer) :
	Super(InInitializer), ButtonText(FText()), PromptData()
{
}

void UMamontButtonBase::NativePreConstruct()
{
	Super::NativePreConstruct();

	UpdateButtonText_Implementation(ButtonText);
	
}

void UMamontButtonBase::NativeOnHovered()
{
	Super::NativeOnHovered();

	SetKeyboardFocus();
	
}

void UMamontButtonBase::UpdateButtonText_Implementation(const FText& InText)
{
	TextBlock->SetText(InText);
	
}