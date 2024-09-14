// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "MamontOptionSwitcher.generated.h"

class UMamontArrowButton;
class UCommonTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSwitched, const FText&, OptionText, const int32, OptionID);

UCLASS()
class MAMONTUI_API UMamontOptionSwitcher : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetOption(const FText& InOptionText, const int32 InOptionID);

	UPROPERTY(BlueprintAssignable)
	FOnSwitched OnOptionSwitched;

private:
	
	void OnLeftButton();
	void OnRightButton();

	void UpdateOption();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Option Switcher", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UCommonTextBlock> NameBlock;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Option Switcher", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UCommonTextBlock> OptionNameText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Option Switcher", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UMamontArrowButton> LeftArrowButton;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Option Switcher", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UMamontArrowButton> RightArrowButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Option Switcher", meta=(AllowPrivateAccess=true))
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Option Switcher", meta=(AllowPrivateAccess=true))
	TArray<FText> Options;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Option Switcher", meta=(AllowPrivateAccess=true))
	int32 SelectedOption{0};
	
};