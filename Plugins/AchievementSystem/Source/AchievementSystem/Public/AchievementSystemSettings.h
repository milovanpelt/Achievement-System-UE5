// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Achievement.h"
#include "Engine/DeveloperSettings.h"
#include "AchievementSystemSettings.generated.h"

/**
 * 
 */
UCLASS(config = AchievementSystem, DefaultConfig)
class ACHIEVEMENTSYSTEM_API UAchievementSystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UAchievementSystemSettings();

	UPROPERTY(config, EditAnywhere, Category="Achievements", meta = (TitleProperty = "Name"))
	TArray<FAchievement> Achievements;
};