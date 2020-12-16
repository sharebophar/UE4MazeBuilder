// Copyright Epic Games, Inc. All Rights Reserved.

#include "MazeBuilderEdMode.h"
//#include "MazeBuilderInspector.h"
#include "MazeBuilderEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"
#include "EngineUtils.h"
#include "LevelEditorViewport.h"
#include "Public/DrawDebugHelpers.h"

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
	//UE_LOG(LogTemp, Warning, TEXT("Mouse Enter"));
	return FEdMode::MouseEnter(ViewportClient, Viewport, x, y);
}

bool FMazeBuilderEdMode::MouseLeave(FEditorViewportClient* ViewportClient, FViewport* Viewport)
{
	BuildState = EBuildState::NotOverViewport;
	HoveredActor.Reset();
	//UE_LOG(LogTemp, Warning, TEXT("Mouse Leave"));
	return FEdMode::MouseLeave(ViewportClient, Viewport);
}

bool FMazeBuilderEdMode::MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y)
{
	/*
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
			AMazeBuilderBrushTemplate* stroke = (AMazeBuilderBrushTemplate*)(HoveredActor.Get());
			if (stroke)
			{
				UE_LOG(LogTemp, Warning, TEXT("HoverActor Exist!Paint stroke"));
				FMazeBuilderLogic::Paint(stroke);
			}
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
	*/
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
		if (Key == EKeys::LeftMouseButton)
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
					AActor* actor = ActorHit->Actor;
					/*
					if (Actor->IsChildActor())
					{
						Actor = Actor->GetParentActor();
					}*/
					AMazeBuilderBrushTemplate* stroke = (AMazeBuilderBrushTemplate*)(actor);
					if (stroke)
					{
						UE_LOG(LogTemp, Warning, TEXT("Mouse Left Button Clicked!Paint stroke"));
						if (FMazeBuilderLogic::paintType == EPaintType::PaintStroke)
						{
							FMazeBuilderLogic::Paint(stroke);
						}
						else if (FMazeBuilderLogic::paintType == EPaintType::PaintPath)
						{
							FMazeBuilderLogic::DrawPath(stroke->GetActorLocation());
						}
					}
				}
			}
			else if(Event == IE_Released)
			{
				UE_LOG(LogTemp, Warning, TEXT("Mouse Left Button Released!Paint end!"));
				MouseState = EMouseState::LeftMouseUp;
				FMazeBuilderLogic::startPaint = false;
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
		//MouseState = EMouseState::LeftMouseUp;
		//FMazeBuilderLogic::startPaint = false;
		//RequestDeletion();
	}

	return false;
}

void FMazeBuilderEdMode::Render(const FSceneView * View, FViewport * Viewport, FPrimitiveDrawInterface * PDI)
{
	//copy from FPaintModePainter::GetHitResult  and  MeshPaintHelpers::RetrieveViewportPaintRays
	checkf(View && Viewport && PDI, TEXT("Invalid Viewport data"));
	FEditorViewportClient* ViewportClient = (FEditorViewportClient*)Viewport->GetClient();
	checkf(ViewportClient != nullptr, TEXT("Unable to retrieve viewport client"));

	if (ViewportClient->IsPerspective() || ViewportClient->GetViewportType() == ELevelViewportType::LVT_OrthoXY)
	{
		// Else we're painting with mouse
		// Make sure the cursor is visible OR we're flood filling.  No point drawing a paint cue when there's no cursor.
		if (Viewport->IsCursorVisible())
		{
			if (!PDI->IsHitTesting())
			{
				// Grab the mouse cursor position
				FIntPoint MousePosition;
				Viewport->GetMousePos(MousePosition);

				// Is the mouse currently over the viewport? or flood filling
				if ((MousePosition.X >= 0 && MousePosition.Y >= 0 && MousePosition.X < (int32)Viewport->GetSizeXY().X && MousePosition.Y < (int32)Viewport->GetSizeXY().Y))
				{
					// Compute a world space ray from the screen space mouse coordinates
					/* //这段代码取自UE4引擎的写法，至于为什么不能在顶视图生效，暂不明原因
					FViewportCursorLocation MouseViewportRay(View, ViewportClient, MousePosition.X, MousePosition.Y);
					FHitResult HitResult;
					FVector start = MouseViewportRay.GetOrigin();
					FVector end = start + MouseViewportRay.GetDirection() * HALF_WORLD_MAX;
					*/
					FVector WorldOrigin;
					FVector WorldDirection;
					float HitResultTraceDistance = HALF_WORLD_MAX;
					Viewport->GetMousePos(MousePosition);
					FVector2D ScreenPosition = FVector2D(MousePosition);
					View->DeprojectFVector2D(ScreenPosition, WorldOrigin, WorldDirection);
					FVector start = WorldOrigin;
					FVector end = WorldOrigin + WorldDirection * HitResultTraceDistance;
					//FHitResult HitResult;
					TArray<FHitResult> outHits;
					FCollisionObjectQueryParams collisionObjectQueryParams;
					collisionObjectQueryParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);
					bool canHit = GetWorld()->LineTraceMultiByObjectType(outHits, start, end, collisionObjectQueryParams);
					//bool canHit = GetWorld()->LineTraceSingleByChannel(HitResult, start, end, ECollisionChannel::ECC_EngineTraceChannel2, FCollisionQueryParams::DefaultQueryParam);
					if (canHit && outHits.Num() > 0)
					{
						for (int i = 0; i < outHits.Num(); i++)
						{
							FHitResult HitResult = outHits[i];
							//PDI->DrawPoint(HitResult.Location, FLinearColor::White, 10.0, 1);
							FMazeBuilderLogic::curPoint = HitResult.Location;
							//UE_LOG(LogTemp, Warning, TEXT("hitLocation is: %s"), * HitResult.Location.ToString());
							return;
						}
					}
				}
			}
		}
	}
}

void FMazeBuilderEdMode::Tick(FEditorViewportClient * ViewportClient, float DeltaTime)
{
	if (ViewportClient == GCurrentLevelEditingViewportClient)
	{
		BuildState = EBuildState::OverViewport;
		HoveredActor.Reset();

		int32 HitX = ViewportClient->Viewport->GetMouseX();
		int32 HitY = ViewportClient->Viewport->GetMouseY();
		HHitProxy* HitProxy = ViewportClient->Viewport->GetHitProxy(HitX, HitY);
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
				//FMazeBuilderLogic::curPoint = FMazeBuilderLogic::GetHitPoint(ViewportClient);
				BuildState = IsActorValid(Actor) ? EBuildState::OverActor : EBuildState::OverIncompatibleActor;
			}
		}
		if (MouseState == EMouseState::LeftMouseDown)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Mouse Drag!"));
			AMazeBuilderBrushTemplate* stroke = (AMazeBuilderBrushTemplate*)(HoveredActor.Get());
			if (stroke)
			{
				//UE_LOG(LogTemp, Warning, TEXT("HoverActor Exist!Paint stroke"));
				if (FMazeBuilderLogic::paintType == EPaintType::PaintStroke)
				{
					FMazeBuilderLogic::Paint(stroke);
				}
				else if (FMazeBuilderLogic::paintType == EPaintType::PaintPath)
				{
					FMazeBuilderLogic::DrawPath(stroke->GetActorLocation());
				}
			}
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
	// 绘制路径线
	if (FMazeBuilderLogic::paintType == EPaintType::PaintPath)
	{
		FMazeBuilderLogic::GetPathPointList(FMazeBuilderLogic::curPoint);

		DrawDebugLine(
			GetWorld(),
			FMazeBuilderLogic::gridPoint,
			FMazeBuilderLogic::nextPoint,
			FColor::Red,
			false,
			0.0f,
			0.0f,
			10.0f
		);
		// 测试起始点
		DrawDebugLine(
			GetWorld(),
			FMazeBuilderLogic::gridPoint,
			FVector::ZeroVector,
			FColor::Red,
			false,
			0.0f,
			0.0f,
			10.0f
		);
	}
}

bool FMazeBuilderEdMode::IsActorValid(const AActor* const Actor) const
{
	bool bIsValid = true;
	//AMazeBuilderBrushTemplate* stroke = (AMazeBuilderBrushTemplate*)(Actor);
	return bIsValid;
}

void FMazeBuilderEdMode::Reset()
{
	//MouseState = EMouseState::None;
	BuildState = EBuildState::NotOverViewport;
}

bool FMazeBuilderEdMode::UsesToolkits() const
{
	return true;
}




