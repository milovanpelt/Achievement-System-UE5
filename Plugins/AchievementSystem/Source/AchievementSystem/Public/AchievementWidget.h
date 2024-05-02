// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Textblock.h"
#include "Components/Image.h"
#include "AchievementSubsystem.h"
#include "AchievementWidget.generated.h"


/**
 * 
 */
UCLASS()
class ACHIEVEMENTSYSTEM_API UAchievementWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetupAchievement(UTexture2D* newIcon, const FString& newName, const FString& newDescription);
protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Name;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Description;

	UPROPERTY(meta = (BindWidget))
	UImage* Icon;
protected:
	void NativeConstruct() override;
};