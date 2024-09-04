// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SettingControlComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAMONTUI_API USettingControlComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit USettingControlComponent(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	void ChangeScreenResolution(const FText& InOptionText, const int32 InOptionID);
	void ChangeWindowMode(const FText& InOptionText, const int32 InOptionID);

	void ApplySetting();
	
	void ChangeVSync(bool bChecked);

	void ChangeAudioVolume(const FName& InNameAudio, const float InValue);

	void SetOverallScalabilityLevel(const int32 InValue);
	
	void ChangeTextureQuality(const int32 InValue);
	void ChangeVisibilityQuality(const int32 InValue);
	void ChangeAntialiasingQuality(const int32 InValue);
	void ChangeShadowQuality(const int32 InValue);
	void ChangePostProcessingQuality(const int32 InValue);
	void ChangeEffectQuality(const int32 InValue);
	void ChangeShadingQuality(const int32 InValue);
	void ChangeVegetationQuality(const int32 InValue);

private:
	UPROPERTY(EditDefaultsOnly, Category="Settings|Audio")
	TMap<FName, TObjectPtr<USoundMix>> MixMaps;
	
};