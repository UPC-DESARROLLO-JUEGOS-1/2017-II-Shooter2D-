#pragma once

#include "SH_World.h"

class GameApp_Shooter2D;

class SH_Engine
{
public:
	SH_Engine();
	~SH_Engine() {}

	GameApp_Shooter2D* GetApp() { return mApp; }
	SH_World* GetWorld() { return mWorld; }

	void Initialize(GameApp_Shooter2D* app);
	void Update(float dt);
	void Draw(float dt);

private:
	GameApp_Shooter2D* mApp;
	SH_World* mWorld;
};

