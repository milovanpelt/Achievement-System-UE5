// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AchievementSystemSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AchievementSubsystem.generated.h"

// Delegate declaration
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementUnlockedDelegate, const FAchievement&, Achievement);

UCLASS()
class ACHIEVEMENTSYSTEM_API UAchievementSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AchievementSubsystem")
	void Unlock(const FString& Name);

	FAchievementUnlockedDelegate OnAchievementUnlocked;
private:
	const UAchievementSystemSettings* m_Settings;
	TMap<FString, FAchievement*> m_Achievements;
};