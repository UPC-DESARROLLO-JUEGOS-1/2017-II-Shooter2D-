#pragma once

#include "SH_Engine.h"
#include "SH_GameHUD.h"

class GameApp_Shooter2D
{
public:
	GameApp_Shooter2D();
	~GameApp_Shooter2D() {}

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

private:
	SH_Engine* mEngine;
	SH_GameHUD* mHud;
};

