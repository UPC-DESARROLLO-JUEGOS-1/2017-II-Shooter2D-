#pragma once

#include <UPCFramework\NSceneGraph.h>

#include "EnumAppScenes.h"
#include "GameScene.h"
#include "Shooter2DScene.h"

class AppSceneGraph : public NSceneGraph
{
public:
	AppSceneGraph() { }
	~AppSceneGraph() { }

	void GoToScene(int sceneId)
	{
		NBaseScene* result = nullptr;

		switch (sceneId)
		{
		case EnumAppScenes::MainMenu:
			break;
		case EnumAppScenes::Game:
			result = new GameScene(this);
			break;
		case EnumAppScenes::GameOver:
			break;
		case EnumAppScenes::Shooter2D:
			result = new Shooter2DScene(this);
			break;
		}

		if (result != nullptr)
		{
			NSceneGraph::GoToScene(sceneId);
			result->Initialize();
		}

		mCurrentScene = result;
	}
};

