// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "MamontOptionSwitcher.generated.h"

class UMamontArrowButton;
class UCommonTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOptionSwitched, const FText&, OptionText, const int32, OptionID);

UCLASS(Abstract, Blueprintable)
class MAMONTUI_API UMamontOptionSwitcher : public UActivatableWidgetBase
{
	GENERATED_BODY()

public:
	explicit UMamontOptionSwitcher(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	virtual void NativePreConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetOption(const FText& InOptionText, const int32 InOptionID);

	UPROPERTY(BlueprintAssignable)
	FOnOptionSwitched OnOptionSwitched;

private:
	void OnRightArrowClick();
	void OnLeftArrowClick();

	void SwitchOption(const bool bDecrease);

	void UpdateOption();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", meta=(BindWidget, AllowPrivateAccess="true"))
	FText SettingName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", meta=(BindWidget, AllowPrivateAccess="true"))
	TArray<FText> Options;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", meta=(BindWidget, AllowPrivateAccess="true"))
	int32 SelectedOption;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UCommonTextBlock> SettingNameText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UCommonTextBlock> OptionNameText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontArrowButton> LeftArrowButton;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontArrowButton> RightArrowButton;
	
};