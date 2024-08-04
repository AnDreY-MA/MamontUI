// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PromptWidgetBase.h"

#include "CommonTextBlock.h"
#include "UI/MamontButtonBase.h"
#include "MamontHUDInterface.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/HUD.h"
#include "UI/MamontWidgetContainerBase.h"
#include "Widgets/CommonActivatableWidgetContainer.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(PromptWidgetBase)

void UPromptWidgetBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	YesButton->OnClicked().AddUObject(this, &UPromptWidgetBase::OnClickYesButton);
	NoButton->OnClicked().AddUObject(this, &UPromptWidgetBase::OnClickNoButton);
	
}

void UPromptWidgetBase::NativeOnActivated()
{
	Super::NativeOnActivated();

	SetDesiredFocusWidget(GetDesiredFocusTarget());
}

void UPromptWidgetBase::InitPrompt_Implementation(const FPromptData& InPromptData)
{
	PromptData = InPromptData;

	TitleTextBlock->SetText(PromptData.TitleText);
	PromptTextBlock->SetText(PromptData.Text);
	YesButton->UpdateButtonText(PromptData.YesButtonText);
	NoButton->UpdateButtonText(PromptData.NoButtonText);
	
}

void UPromptWidgetBase::OnClickYesButton()
{
	if(auto* Hud {GetOwningPlayer()->GetHUD()}; Hud && Hud->Implements<UMamontHUDInterface>())
	{
		IMamontHUDInterface::Execute_ActionPrompt(Hud, PromptData.ID, true);
	}

	TryDeactivate(PromptData.bYesDeactivate);
	
	
}

void UPromptWidgetBase::OnClickNoButton()
{
	if(auto* Hud {GetOwningPlayer()->GetHUD()}; Hud && Hud->Implements<UMamontHUDInterface>())
	{
		IMamontHUDInterface::Execute_ActionPrompt(Hud, PromptData.ID, false);
	}
	TryDeactivate(PromptData.bNoDeactivate);
	
	
}

void UPromptWidgetBase::TryDeactivate(const bool InValue)
{
	if(InValue)
	{
		DeactivateWidget();
	}
}
