// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MamontHUDInterface.h"
#include "GameFramework/HUD.h"
#include "UI/MamontWidgetContainerBase.h"
#include "MamontHUD.generated.h"

/**
 * 
 */
UCLASS()
class MAMONTUI_API AMamontHUD : public AHUD, public IMamontHUDInterface
{
	GENERATED_BODY()

public:

	explicit AMamontHUD(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	// IMamontHUDPromptInterface Implementation
	virtual void ShowPrompt_Implementation(const FPromptData& InPromptData) override;

	virtual void ActionPrompt_Implementation(const int32 InPromptID, const bool bResult) override;

protected:
	virtual void BeginPlay() override;
	
private:
	void QuitGame();
	void ReturnMainMenu();

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UUserWidget> WidgetContainerClass;
	
	UPROPERTY()
	TObjectPtr<UMamontWidgetContainerBase> WidgetContainer;
	
};