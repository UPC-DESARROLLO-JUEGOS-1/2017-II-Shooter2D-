#pragma once

class GameApp_Shooter2D;

class SH_GameHUD
{
public:
	SH_GameHUD() {}
	~SH_GameHUD() {}

	void Initialize(GameApp_Shooter2D* app);
	void Update(float dt);
	void Draw(float dt);

private:
	GameApp_Shooter2D* mApp;
};

