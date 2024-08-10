// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonTabListWidgetBase.h"
#include "MamontTabListWidgetBase.generated.h"

class UHorizontalBox;
/**
 * 
 */
UCLASS()
class MAMONTUI_API UMamontTabListWidgetBase : public UCommonTabListWidgetBase
{
	GENERATED_BODY()

public:
	virtual void HandleTabCreation_Implementation(FName InTabNameID, UCommonButtonBase* InTabButton) override;

	virtual void HandleTabRemoval_Implementation(FName InTabNameID, UCommonButtonBase* InTabButton) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UHorizontalBox> ButtonContainer;
	
};