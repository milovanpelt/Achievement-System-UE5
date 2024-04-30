// Fill out your copyright notice in the Description page of Project Settings.


#include "AchievementWidget.h"

void UAchievementWidget::NativeConstruct()
{
	Super::NativeConstruct();

    if (UGameInstance* GameInstance = GetWorld()->GetGameInstance())
    {
        UAchievementSubsystem* AchievementSubsystem = GameInstance->GetSubsystem<UAchievementSubsystem>();
        if (AchievementSubsystem)
        {
            AchievementSubsystem->OnAchievementUnlocked.AddDynamic(this, &UAchievementWidget::OnAchievementUnlocked);
        }
    }
}

void UAchievementWidget::OnAchievementUnlocked(const FAchievement& Achievement)
{
    if (Achievement.IsUnlocked && Icon && Name && Description)
    {
        FText NameText = FText::FromString(Achievement.Name);
        FText DescriptionText = FText::FromString(Achievement.Description);
        Icon->SetBrushFromTexture(Achievement.Icon);
        Name->SetText(NameText);
        Description->SetText(DescriptionText);
    }
}