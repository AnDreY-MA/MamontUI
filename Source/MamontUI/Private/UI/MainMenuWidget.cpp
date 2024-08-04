// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"

#include "MamontHUDInterface.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/HUD.h"
#include "UI/MamontButtonBase.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MainMenuWidget)

void UMainMenuWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	QuitButton->OnClicked().AddUObject(this, &UMainMenuWidget::OnQuit);

	if(auto* FocusTarget {GetDesiredFocusTarget()}; FocusTarget)
	{
		FocusTarget->SetFocus();
		UE_LOG(LogTemp, Warning, TEXT("FOCUS = %d"), IsValid(FocusTarget));
	}
	auto* PlayerController{GetOwningPlayer()};
	if(!PlayerController) return;
	
	PlayerController->SetShowMouseCursor(true);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, this);
	
}

void UMainMenuWidget::OnQuit()
{
	if(auto* Hud{GetOwningPlayer()->GetHUD()}; Hud && Hud->Implements<UMamontHUDInterface>())
	{
		IMamontHUDInterface::Execute_ShowPrompt(Hud, QuitButton->GetPromptData());
	}
	
}