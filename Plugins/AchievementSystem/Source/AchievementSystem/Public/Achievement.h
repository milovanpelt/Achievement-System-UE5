// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Achievement.generated.h"

USTRUCT(BlueprintType)
struct FAchievement
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = "Achievement")
    FString Name;

    UPROPERTY(EditAnywhere, Category = "Achievement")
    FString Description;

    UPROPERTY(EditAnywhere, Category = "Achievement")
    UTexture2D* Icon = nullptr;

    bool IsUnlocked = false;
};