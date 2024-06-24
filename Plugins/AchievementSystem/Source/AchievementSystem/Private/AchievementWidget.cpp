// Fill out your copyright notice in the Description page of Project Settings.


#include "AchievementWidget.h"

void UAchievementWidget::ShowAchievement(UTexture2D* newIcon, const FString& newName, const FString& newDescription)
{
    FText NameText = FText::FromString(newName);
    FText DescriptionText = FText::FromString(newDescription);

    Icon->SetBrushFromTexture(newIcon);
    Name->SetText(NameText);
    Description->SetText(DescriptionText);
}

void UAchievementWidget::NativeConstruct()
{
    Super::NativeConstruct();
}