// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MamontArrowButton.h"

#include "Components/Image.h"

void UMamontArrowButton::NativePreConstruct()
{
	Super::NativePreConstruct();

	Image->SetBrushFromTexture(ArrowImage.Get());
	Image->SetRenderTranslation(FVector2D(0.0, 0.0));
	
}

void UMamontArrowButton::NativeOnHovered()
{
	Super::NativeOnHovered();

	SetKeyboardFocus();
	
}