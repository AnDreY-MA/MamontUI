// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenuWidget.h"

#include "MamontHUDInterface.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/HUD.h"
#include "HUD/HUDMainMenuInterface.h"
#include "UI/MamontButtonBase.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MainMenuWidget)

void UMainMenuWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	StartNewGameButton->OnClicked().AddUObject(this, &UMainMenuWidget::OnStartNewGame);
	OptionsButton->OnClicked().AddUObject(this, &UMainMenuWidget::OnOpenOptions);
	QuitButton->OnClicked().AddUObject(this, &UMainMenuWidget::OnQuit);

	if(auto* FocusTarget {GetDesiredFocusTarget()}; FocusTarget)
	{
		FocusTarget->SetFocus();
	}
	
	auto* PlayerController{GetOwningPlayer()};
	if(!PlayerController) return;
	
	PlayerController->SetShowMouseCursor(true);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController, this);
	
}

void UMainMenuWidget::OnStartNewGame() const
{
	if(auto* Hud{GetOwningPlayer()->GetHUD()}; Hud && Hud->Implements<UHUDMainMenuInterface>())
	{
		IHUDMainMenuInterface::Execute_StartNewGame(Hud);
	}
	
}

void UMainMenuWidget::OnOpenOptions() const
{
	if(auto* Hud{GetOwningPlayer()->GetHUD()}; Hud && Hud->Implements<UMamontHUDInterface>())
	{
		IMamontHUDInterface::Execute_OpenOptions(Hud);
	}	
}

void UMainMenuWidget::OnQuit() const
{
	if(auto* Hud{GetOwningPlayer()->GetHUD()}; Hud && Hud->Implements<UMamontHUDInterface>())
	{
		IMamontHUDInterface::Execute_ShowPrompt(Hud, QuitButton->GetPromptData());
	}
	
}
