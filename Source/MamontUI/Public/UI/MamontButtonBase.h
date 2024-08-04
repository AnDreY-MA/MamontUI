// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "PromptData.h"
#include "MamontButtonBase.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, Blueprintable)
class MAMONTUI_API UMamontButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	explicit UMamontButtonBase(const FObjectInitializer& InInitializer = FObjectInitializer::Get());
	
	virtual void NativeOnHovered() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, meta=(BlueprintProtected))
	void UpdateButtonText(const FText& InText);

	FPromptData GetPromptData() const
	{
		return PromptData;
	}

protected:
	virtual void NativePreConstruct() override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UCommonTextBlock> TextBlock;

	UPROPERTY(EditAnywhere, Category="UI", meta=(AllowPrivateAccess))
	FText ButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI|Prompt", meta=(AllowPrivateAccess="true"))
	FPromptData PromptData;
	
};