// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ScrollBox.h"
#include "Components/VerticalBox.h"
#include "AchievementSubsystem.h"
#include "AchievementListWidget.generated.h"


/**
 * 
 */
UCLASS()
class ACHIEVEMENTSYSTEM_API UAchievementListWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta = (BindWidget))
	UScrollBox* ScrollBox;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* VerticalBox;
protected:
	void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> AchievementWidgetClass;

	UFUNCTION()
	void OnAchievementUnlocked(const FAchievement& Achievement);
};
