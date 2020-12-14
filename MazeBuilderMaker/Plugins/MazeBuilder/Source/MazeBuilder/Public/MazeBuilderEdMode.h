// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdMode.h"
#include "MazeBuilderLogic.h"

namespace EBuildState
{
	enum Type
	{
		NotOverViewport,
		OverViewport,
		OverIncompatibleActor,
		OverActor,
	};
}

namespace EMouseState
{
	enum Type
	{
		None,
		LeftMouseDown,
		LeftMouseUp,
	};
}

class FMazeBuilderEdMode : public FEdMode
{
public:
	const static FEditorModeID EM_MazeBuilderEdModeId;
public:
	FMazeBuilderEdMode();
	virtual ~FMazeBuilderEdMode();

	// FEdMode interface
	virtual void Enter() override;
	virtual void Exit() override;
	virtual bool MouseEnter(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y) override;
	virtual bool MouseLeave(FEditorViewportClient* ViewportClient, FViewport* Viewport) override;
	virtual bool MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y) override;
	virtual bool LostFocus(FEditorViewportClient* ViewportClient, FViewport* Viewport) override;
	virtual bool InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event) override;
	virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;
	virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI) override;
	//virtual void ActorSelectionChangeNotify() override;
	bool UsesToolkits() const override;
	//TSharedPtr<MazeBuilderInspector> inspector;
	TWeakObjectPtr<AActor> HoveredActor;
	bool IsActorValid(const AActor* const Actor) const;
	EBuildState::Type BuildState;
	EMouseState::Type MouseState;

	void Reset();
	// End of FEdMode interface
};
