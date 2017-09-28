#pragma once

#include "NSceneGraph.h"

class NBaseScene
{
public:
	NBaseScene(NSceneGraph* sceneGraph)
	{
		this->mSceneGraph = sceneGraph;
	}
	virtual ~NBaseScene() {}

	virtual void Initialize() {}
	virtual void Update(float dt) {}
	virtual void Draw(float dt) {}

	virtual void OnKeyDown(SDL_Keycode key) {}
	virtual void OnKeyUp(SDL_Keycode key) {}

private:
	NSceneGraph* mSceneGraph;
};

