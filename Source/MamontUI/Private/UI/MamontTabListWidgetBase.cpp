// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MamontTabListWidgetBase.h"

#include "CommonButtonBase.h"
#include "Components/HorizontalBox.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MamontTabListWidgetBase)

void UMamontTabListWidgetBase::HandleTabCreation_Implementation(FName InTabNameID, UCommonButtonBase* InTabButton)
{
	Super::HandleTabCreation_Implementation(InTabNameID, InTabButton);

	ButtonContainer->AddChild(InTabButton);
	InTabButton->SetIsFocusable(false);
	
}

void UMamontTabListWidgetBase::HandleTabRemoval_Implementation(FName InTabNameID, UCommonButtonBase* InTabButton)
{
	Super::HandleTabRemoval_Implementation(InTabNameID, InTabButton);

	ButtonContainer->RemoveChild(InTabButton);

}