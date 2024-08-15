// Fill out your copyright notice in the Description page of Project Settings.


#include "MamontHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/MamontWidgetContainerBase.h"
#include "CommonInputSubsystem.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/SettingControlComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

AMamontHUD::AMamontHUD(const FObjectInitializer& InInitializer) :
	Super(InInitializer), WidgetContainerClass(nullptr), WidgetContainer(nullptr)
{
	SettingControlComponent = CreateDefaultSubobject<USettingControlComponent>("SettingControlComponent");
}

void AMamontHUD::BeginPlay()
{
	Super::BeginPlay();

	if(!WidgetContainerClass) return;
	
	WidgetContainer = Cast<UMamontWidgetContainerBase>(CreateWidget(GetOwningPlayerController(), WidgetContainerClass));
	WidgetContainer->AddToViewport();
	WidgetContainer->PushMenuWidget(MainMenuWidgetClass);

}

void AMamontHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	WidgetContainer->RemoveFromParent();
}

void AMamontHUD::ShowPrompt_Implementation(const FPromptData& InPromptData)
{
	WidgetContainer->PushPrompt(InPromptData);
	
}

void AMamontHUD::ActionPrompt_Implementation(const int32 InPromptID, const bool bResult)
{
	switch (InPromptID)
	{
	case 0:
		if(bResult)
		{
			QuitGame();
		}
		break;
	default: break;
	}
}

void AMamontHUD::StartNewGame_Implementation()
{
	auto* PlayerController {GetOwningPlayerController()};
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, NewGameLevel);
}

void AMamontHUD::OpenOptions_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("OPEN"));
	WidgetContainer->PushMenuWidget(SettingsWidgetClass);
	
}

USettingControlComponent* AMamontHUD::GetSettingComponent_Implementation() const
{
	return SettingControlComponent.Get();
}

void AMamontHUD::QuitGame()
{
	if(auto* CommonInput {UCommonInputSubsystem::Get(GetOwningPlayerController()->GetLocalPlayer())}; CommonInput)
	{
		constexpr ECommonInputType InputType = ECommonInputType::MouseAndKeyboard;
		CommonInput->SetCurrentInputType(InputType);
	}

	UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayerController(), EQuitPreference::Quit, false);
	
}

void AMamontHUD::ReturnMainMenu()
{
}