// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MamontHUDInterface.h"
#include "GameFramework/HUD.h"
#include "HUD/HUDMainMenuInterface.h"
#include "Interfaces/SettingControlComponentInterface.h"
#include "UI/MamontWidgetContainerBase.h"
#include "MamontHUD.generated.h"

/**
 * 
 */
UCLASS()
class MAMONTUI_API AMamontHUD : public AHUD, public IMamontHUDInterface, public IHUDMainMenuInterface, public ISettingControlComponentInterface
{
	GENERATED_BODY()

public:

	explicit AMamontHUD(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	// IMamontHUDPromptInterface Implementation
	virtual void ShowPrompt_Implementation(const FPromptData& InPromptData) override;

	virtual void ActionPrompt_Implementation(const int32 InPromptID, const bool bResult) override;

	// IHUDMainMenuInterface Implementation
	virtual void StartNewGame_Implementation() override;

	virtual void OpenOptions_Implementation() override;

	// ISettingControlComponentInterface Implementation
	virtual USettingControlComponent* GetSettingComponent_Implementation() const override;

protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
private:
	void QuitGame();
	void ReturnMainMenu();

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UUserWidget> WidgetContainerClass;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UCommonActivatableWidget> MainMenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UCommonActivatableWidget> SettingsWidgetClass;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> NewGameLevel;
	
	UPROPERTY()
	TObjectPtr<UMamontWidgetContainerBase> WidgetContainer;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USettingControlComponent> SettingControlComponent;
	
};