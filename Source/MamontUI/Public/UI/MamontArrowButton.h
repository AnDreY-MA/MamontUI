// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "MamontArrowButton.generated.h"

class UImage;
/**
 * 
 */
UCLASS()
class MAMONTUI_API UMamontArrowButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;

	virtual void NativeOnHovered() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UImage> Image;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	TObjectPtr<UTexture2D> ArrowImage;
	
};