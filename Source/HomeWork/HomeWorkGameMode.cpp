// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "HomeWorkGameMode.h"
#include "HomeWorkHUD.h"
#include "HomeWorkCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHomeWorkGameMode::AHomeWorkGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHomeWorkHUD::StaticClass();
}
