// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "MamontOptionCheckBoxBase.generated.h"

class UCheckBox;
class UCommonTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCheckBoxChanged, const bool, bChecked);

UCLASS(Abstract)
class MAMONTUI_API UMamontOptionCheckBoxBase : public UActivatableWidgetBase
{
	GENERATED_BODY()

public:
	explicit UMamontOptionCheckBoxBase(const FObjectInitializer& InInitializer = FObjectInitializer::Get());
	
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	UPROPERTY()
	FOnCheckBoxChanged OnCheckBoxChanged;

private:
	UFUNCTION()
	void CheckBoxChanged(bool bIsChecked);
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CheckBox", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UCommonTextBlock> NameTextBox;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CheckBox", meta=(BindWidget, AllowPrivateAccess=true))
	TObjectPtr<UCheckBox> CheckBox;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CheckBox", meta=(AllowPrivateAccess=true))
	FText SettingName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CheckBox", meta=(AllowPrivateAccess=true))
	ECheckBoxState CheckStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CheckBox", meta=(AllowPrivateAccess=true))
	bool bChecked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CheckBox", meta=(AllowPrivateAccess=true))
	bool bCanInteract;
	
};