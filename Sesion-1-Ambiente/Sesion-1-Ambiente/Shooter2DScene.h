#pragma once

#include <UPCFramework\NBaseScene.h>

#include "GameApp_Shooter2D.h"

class Shooter2DScene : public NBaseScene
{
public:
	Shooter2DScene(NSceneGraph* sceneGraph) : 
		NBaseScene::NBaseScene(sceneGraph) {}
	~Shooter2DScene() {}

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

private:
	GameApp_Shooter2D mGameApp;
};

