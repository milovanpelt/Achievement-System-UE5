// Fill out your copyright notice in the Description page of Project Settings.


#include "AchievementListWidget.h"
#include "AchievementWidget.h"
#include "AchievementSubsystem.h"


void UAchievementListWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (UGameInstance* GameInstance = GetWorld()->GetGameInstance())
    {
        UAchievementSubsystem* AchievementSubsystem = GameInstance->GetSubsystem<UAchievementSubsystem>();
        if (AchievementSubsystem)
        {
            AchievementSubsystem->OnAchievementUnlocked.AddDynamic(this, &UAchievementListWidget::OnAchievementUnlocked);
        }
    }
}

void UAchievementListWidget::OnAchievementUnlocked(const FAchievement& Achievement)
{
    UGameInstance* GameInstance = GetWorld()->GetGameInstance();
    if (GameInstance)
    {
        UAchievementSubsystem* AchievementSubsystem = GameInstance->GetSubsystem<UAchievementSubsystem>();
        if (AchievementSubsystem)
        {
            if (VerticalBox)
            {
                VerticalBox->ClearChildren();
                for (const FAchievement* Achievement : AchievementSubsystem->GetAchievements())
                {
                    if (Achievement)
                    {
                        if (AchievementWidgetClass != nullptr)
                        {
                            UAchievementWidget* Widget = CreateWidget<UAchievementWidget>(this, AchievementWidgetClass);
                            if (Widget)
                            {
                                Widget->SetupAchievement(Achievement->Icon, Achievement->Name, Achievement->Description);
                                VerticalBox->AddChild(Widget);
                            }
                        }
                    }
                }
            }
        }
    }
}