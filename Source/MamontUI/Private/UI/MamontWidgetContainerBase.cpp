// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MamontWidgetContainerBase.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "UI/PromptWidgetBase.h"
#include "Widgets/CommonActivatableWidgetContainer.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MamontWidgetContainerBase)

void UMamontWidgetContainerBase::NativeConstruct()
{
	Super::NativeConstruct();
	auto* PlayerController{GetOwningPlayer()};
	PlayerController->SetShowMouseCursor(true);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, this);
	
	PushMenuWidget();
	
}

void UMamontWidgetContainerBase::PushPrompt(const FPromptData& InPromptData) const
{
	if(!PromptWidgetClass) return;
	
	if(auto* PromptWidget = PromptStack->AddWidget(PromptWidgetClass); PromptWidget && PromptWidget->Implements<UPromptWidgetInterface>())
	{
		IPromptWidgetInterface::Execute_InitPrompt(PromptWidget, InPromptData);
		MenuStack->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
	
}

void UMamontWidgetContainerBase::PushMenuWidget() const
{
	MenuStack->AddWidget(MenuWidgetClass);
	
}