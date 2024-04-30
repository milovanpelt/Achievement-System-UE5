// Fill out your copyright notice in the Description page of Project Settings.


#include "AchievementSubsystem.h"
#include <iostream>

void UAchievementSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	m_Settings = GetDefault<UAchievementSystemSettings>();

	if (m_Settings)
	{
		for (const FAchievement& Element : m_Settings->Achievements)
		{
			FAchievement* NewAchievement = new FAchievement(Element);
			m_Achievements.Add(Element.Name, NewAchievement);
		}
	}
}

void UAchievementSubsystem::Deinitialize()
{
	for (auto& Element : m_Achievements)
	{
		delete Element.Value;
	}
	m_Achievements.Empty();
	Super::Deinitialize();
}

void UAchievementSubsystem::Unlock(const FString& Name)
{
	FAchievement** FoundAchievement = m_Achievements.Find(Name);
	if (FoundAchievement && !(*FoundAchievement)->IsUnlocked)
	{
		(*FoundAchievement)->IsUnlocked = true;

		OnAchievementUnlocked.Broadcast(**FoundAchievement);
		UE_LOG(LogTemp, Warning, TEXT("Achievement unlocked: '%s'"), *Name);
		
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Achievement already unlocked or does not exist: '%s'"), *Name);
	}
}