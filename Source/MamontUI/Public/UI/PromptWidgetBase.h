// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "PromptData.h"
#include "PromptWidgetBase.generated.h"

class UCommonTextBlock;
class UMamontButtonBase;

UINTERFACE(MinimalAPI)
class UPromptWidgetInterface : public UInterface
{
	GENERATED_BODY()
};


class MAMONTUI_API IPromptWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Prompt WidgetInterface")
	void InitPrompt(const FPromptData& InPromptData);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Prompt WidgetInterface")
	UMamontButtonBase* GetYesButton() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Prompt WidgetInterface")
	UMamontButtonBase* GetNoButton() const;
	
};

UCLASS()
class MAMONTUI_API UPromptWidgetBase : public UActivatableWidgetBase, public IPromptWidgetInterface
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;
	
	virtual void NativeOnActivated() override;

	virtual void InitPrompt_Implementation(const FPromptData& InPromptData) override;

	virtual UMamontButtonBase* GetNoButton_Implementation() const override;

private:
	void OnClickYesButton();
	void OnClickNoButton();

	void TryDeactivate(const bool InValue);
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontButtonBase> YesButton;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontButtonBase> NoButton;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UCommonTextBlock> TitleTextBlock;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UCommonTextBlock> PromptTextBlock;

	UPROPERTY()
	FPromptData PromptData;
	
};