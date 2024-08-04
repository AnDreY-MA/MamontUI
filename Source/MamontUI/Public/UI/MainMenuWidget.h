// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "PromptData.h"
#include "MainMenuWidget.generated.h"


class UMamontButtonBase;

UCLASS(Abstract, Blueprintable)
class MAMONTUI_API UMainMenuWidget : public UActivatableWidgetBase
{
	GENERATED_BODY()

public:
	
	virtual void NativePreConstruct() override;

private:
	void OnQuit();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Widgets", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontButtonBase> QuitButton;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Widgets", meta=(AllowPrivateAccess="true"))
	FPromptData PromptData;
	
};