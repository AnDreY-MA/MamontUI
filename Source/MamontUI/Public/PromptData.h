#pragma once

#include "CoreMinimal.h"
#include "PromptData.generated.h"

USTRUCT(BlueprintType)
struct FPromptData
{
	GENERATED_BODY()

	FPromptData() :
		ID(0), TitleText(FText::FromString("TitleText")), Text(FText::FromString("Text")), YesButtonText(FText::FromString("YesText")), NoButtonText(FText::FromString("NoText")),
		bYesDeactivate(false), bNoDeactivate(false)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt", meta=(AllowPrivateAccess="true"))
	int32 ID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt", meta=(AllowPrivateAccess="true"))
	FText TitleText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt", meta=(AllowPrivateAccess="true"))
	FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt", meta=(AllowPrivateAccess="true"))
	FText YesButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt", meta=(AllowPrivateAccess="true"))
	FText NoButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt", meta=(AllowPrivateAccess="true"))
	bool bYesDeactivate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Prompt", meta=(AllowPrivateAccess="true"))
	bool bNoDeactivate;
	
};