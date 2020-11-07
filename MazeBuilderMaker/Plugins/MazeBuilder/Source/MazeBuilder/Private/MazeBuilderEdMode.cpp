// Copyright Epic Games, Inc. All Rights Reserved.

#include "MazeBuilderEdMode.h"
#include "MazeBuilderEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"
#include "EngineUtils.h"
#include "LevelEditorViewport.h"

const FEditorModeID FMazeBuilderEdMode::EM_MazeBuilderEdModeId = TEXT("EM_MazeBuilderEdMode");

FMazeBuilderEdMode::FMazeBuilderEdMode()
{

}

FMazeBuilderEdMode::~FMazeBuilderEdMode()
{

}

void FMazeBuilderEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FMazeBuilderEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FMazeBuilderEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FMazeBuilderEdMode::MouseEnter(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y)
{
	BuildState = EBuildState::OverViewport;
	HoveredActor.Reset();
	UE_LOG(LogTemp, Warning, TEXT("Mouse Enter"));
	return FEdMode::MouseEnter(ViewportClient, Viewport, x, y);
}

bool FMazeBuilderEdMode::MouseLeave(FEditorViewportClient* ViewportClient, FViewport* Viewport)
{
	BuildState = EBuildState::NotOverViewport;
	HoveredActor.Reset();
	UE_LOG(LogTemp, Warning, TEXT("Mouse Leave"));
	return FEdMode::MouseLeave(ViewportClient, Viewport);
}

bool FMazeBuilderEdMode::MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y)
{
	if (ViewportClient == GCurrentLevelEditingViewportClient)
	{
		BuildState = EBuildState::OverViewport;
		HoveredActor.Reset();

		int32 HitX = Viewport->GetMouseX();
		int32 HitY = Viewport->GetMouseY();
		HHitProxy* HitProxy = Viewport->GetHitProxy(HitX, HitY);
		if (HitProxy != NULL && HitProxy->IsA(HActor::StaticGetType()))
		{
			HActor* ActorHit = static_cast<HActor*>(HitProxy);
			if (ActorHit->Actor != NULL)
			{
				AActor* Actor = ActorHit->Actor;
				while (Actor->IsChildActor())
				{
					Actor = Actor->GetParentActor();
				}
				HoveredActor = Actor;
				BuildState = IsActorValid(Actor) ? EBuildState::OverActor : EBuildState::OverIncompatibleActor;
			}
		}
		if (MouseState == EMouseState::LeftMouseDown)
		{
			UE_LOG(LogTemp, Warning, TEXT("Mouse Drag!"));

		}
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("Mouse Move!"));
		}
	}
	else
	{
		BuildState = EBuildState::NotOverViewport;
		HoveredActor.Reset();
	}

	return true;
}

bool FMazeBuilderEdMode::LostFocus(FEditorViewportClient* ViewportClient, FViewport* Viewport)
{
	if (ViewportClient == GCurrentLevelEditingViewportClient)
	{
		// Make sure actor picking mode is disabled once the active viewport loses focus
		//RequestDeletion();
		return true;
	}

	return false;
}

bool FMazeBuilderEdMode::InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event)
{
	if (ViewportClient == GCurrentLevelEditingViewportClient)
	{
		if (Key == EKeys::LeftMouseButton && Event == IE_Pressed)
		{
			if (Event == IE_Pressed)
			{
				// See if we clicked on an actor
				int32 HitX = Viewport->GetMouseX();
				int32 HitY = Viewport->GetMouseY();
				HHitProxy* HitProxy = Viewport->GetHitProxy(HitX, HitY);
				MouseState = EMouseState::LeftMouseDown;
				if (HitProxy != NULL && HitProxy->IsA(HActor::StaticGetType()))
				{
					HActor* ActorHit = static_cast<HActor*>(HitProxy);
					AActor* Actor = ActorHit->Actor;
					/*
					if (Actor->IsChildActor())
					{
						Actor = Actor->GetParentActor();
					}*/
					if (IsActorValid(Actor))
					{

					}
					UE_LOG(LogTemp, Warning, TEXT("Mouse Left Button Clicked!"));
				}
			}
			else if(Event == IE_Released)
			{
				MouseState = EMouseState::LeftMouseUp;
			}
			return true;
		}
		else if (Key == EKeys::Escape && Event == IE_Pressed)
		{
			Reset();
			RequestDeletion();
			return true;
		}
	}
	else
	{
		//RequestDeletion();
	}

	return false;
}

bool FMazeBuilderEdMode::IsActorValid(const AActor* const Actor) const
{
	bool bIsValid = true;

	return bIsValid;
}

void FMazeBuilderEdMode::Reset()
{
	MouseState = EMouseState::None;
	BuildState = EBuildState::NotOverViewport;
}

bool FMazeBuilderEdMode::UsesToolkits() const
{
	return true;
}




