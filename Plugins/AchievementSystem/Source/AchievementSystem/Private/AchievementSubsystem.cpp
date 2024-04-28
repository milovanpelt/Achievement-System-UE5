// Fill out your copyright notice in the Description page of Project Settings.


#include "AchievementSubsystem.h"
#include <iostream>

void UAchievementSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	m_Settings = NewObject<UAchievementSystemSettings>();

	if (m_Settings)
	{
		for (int i = 0; i < m_Settings->Achievements.Num(); i++)
		{
			FAchievement* NewAchievement = new FAchievement(m_Settings->Achievements[i]);
			m_Achievements.Add(m_Settings->Achievements[i].Name, NewAchievement);
		}
	}
}

void UAchievementSubsystem::Deinitialize()
{
	m_Achievements.Empty();
}

void UAchievementSubsystem::Unlock(const FString& Name)
{
	FAchievement** FoundAchievement = m_Achievements.Find(Name);
	if (FoundAchievement)
	{
		FAchievement* Achievement = *FoundAchievement;
		Achievement->IsUnlocked = true;
		if (Achievement->IsUnlocked)
		{
			UE_LOG(LogTemp, Warning, TEXT("Achievement unlocked: '%s'"), *Name);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Achievement already unlocked: '%s'"), *Name);
		}
		
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Achievement does not exist: '%s'"), *Name);
	}
}