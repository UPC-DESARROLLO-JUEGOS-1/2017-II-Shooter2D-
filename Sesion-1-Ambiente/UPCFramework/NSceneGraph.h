#pragma once

#include <SDL\SDL.h>

class NBaseScene;

class NSceneGraph
{
public:
	NSceneGraph() :
		mCurrentScene(nullptr)
	{}
	~NSceneGraph();

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

	virtual void GoToScene(int sceneId);
protected:
	NBaseScene* mCurrentScene;
};

