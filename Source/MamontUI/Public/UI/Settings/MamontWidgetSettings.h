// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivatableWidgetBase.h"
#include "MamontWidgetSettings.generated.h"

class UMamontSettingsWidgetPanel;
class UMamontTabListWidgetBase;

USTRUCT(BlueprintType)
struct FTabData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName TabNameID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class UCommonButtonBase> WidgetButtonClass;
	
};

UCLASS(Abstract, Blueprintable)
class MAMONTUI_API UMamontWidgetSettings : public UActivatableWidgetBase
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontTabListWidgetBase> OptionsTabList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UMamontSettingsWidgetPanel> SettingsPanel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI|DataTab", meta=(BindWidget, AllowPrivateAccess="true"))
	TArray<FTabData> DataTabs;
	
};