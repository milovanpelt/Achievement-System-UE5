// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ScrollBox.h"
#include "Components/VerticalBox.h"
#include "AchievementListWidget.generated.h"


/**
 * 
 */
UCLASS()
class ACHIEVEMENTSYSTEM_API UAchievementListWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitializeAchievements();

protected:
	UPROPERTY(meta = (BindWidget))
	UScrollBox* ScrollBox;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* VerticalBox;
};
