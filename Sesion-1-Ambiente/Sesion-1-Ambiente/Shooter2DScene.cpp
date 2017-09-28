#include "Shooter2DScene.h"

void Shooter2DScene::Initialize() {
	mGameApp.Initialize();
}

void Shooter2DScene::OnKeyDown(SDL_Keycode key)
{
	mGameApp.OnKeyDown(key);
}

void Shooter2DScene::OnKeyUp(SDL_Keycode key)
{
	mGameApp.OnKeyUp(key);
}

void Shooter2DScene::Update(float dt)
{
	mGameApp.Update(dt);
}

void Shooter2DScene::Draw(float dt)
{
	mGameApp.Draw(dt);
}
