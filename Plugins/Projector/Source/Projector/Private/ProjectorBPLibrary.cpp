// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectorBPLibrary.h"
#include "Projector.h"
#include "Engine/Classes/Engine/TextureRenderTargetCube.h"

UProjectorBPLibrary::UProjectorBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

UTextureRenderTargetCube* UProjectorBPLibrary::CreateRenderTargetCube(UObject* WorldContextObject, int32 Width)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (Width > 0 && World)
	{
		UTextureRenderTargetCube* NewRenderTarget = NewObject<UTextureRenderTargetCube>(WorldContextObject);
		check(NewRenderTarget);
		NewRenderTarget->InitAutoFormat(Width);
		NewRenderTarget->UpdateResourceImmediate(true);
		return NewRenderTarget;
	}
	return nullptr;
}
