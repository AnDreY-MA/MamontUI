// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "PromptData.h"
#include "MamontWidgetContainerBase.generated.h"

class UPromptWidgetBase;
class UCommonActivatableWidgetStack;

UCLASS()
class MAMONTUI_API UMamontWidgetContainerBase : public UActivatableWidgetBase
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category="UI")
	void PushPrompt(const FPromptData& InPromptData) const;

	UFUNCTION(BlueprintCallable, Category="UI")
	void PushMenuWidget() const;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI|Stack", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UCommonActivatableWidgetStack> MenuStack;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI|Stack", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UCommonActivatableWidgetStack> PromptStack;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI|Stack|ClassWidgets", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UPromptWidgetBase> PromptWidgetClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI|Stack|ClassWidgets", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UCommonActivatableWidget> MenuWidgetClass;

};