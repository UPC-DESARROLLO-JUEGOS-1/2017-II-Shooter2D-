#include "SH_Engine.h"
#include "GameApp_Shooter2D.h"

SH_Engine::SH_Engine()
{
	mWorld = new SH_World();
}

void SH_Engine::Initialize(GameApp_Shooter2D* app) {
	mApp = app;

	mWorld->Initialize(this);
}

void SH_Engine::Update(float dt) {
	mWorld->Update(dt);
}

void SH_Engine::Draw(float dt) {
	mWorld->Draw(dt);
}