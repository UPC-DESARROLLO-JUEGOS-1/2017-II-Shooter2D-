#include "NSceneGraph.h"
#include "NBaseScene.h"

NSceneGraph::~NSceneGraph()
{
	if (mCurrentScene != nullptr)
	{
		mCurrentScene->~NBaseScene();
		mCurrentScene = nullptr;
	}
}

void NSceneGraph::Initialize()
{
}

void NSceneGraph::Update(float dt)
{
	if (mCurrentScene != nullptr) mCurrentScene->Update(dt);
}

void NSceneGraph::Draw(float dt)
{
	if (mCurrentScene != nullptr) mCurrentScene->Draw(dt);
}

void NSceneGraph::OnKeyDown(SDL_Keycode key)
{
	if (mCurrentScene != nullptr) mCurrentScene->OnKeyDown(key);
}

void NSceneGraph::OnKeyUp(SDL_Keycode key)
{
	if (mCurrentScene != nullptr) mCurrentScene->OnKeyUp(key);
}

void NSceneGraph::GoToScene(int sceneId)
{
	if (mCurrentScene != nullptr)
	{
		delete mCurrentScene;
		mCurrentScene = nullptr;
	}
}
