#include "GameApp_Shooter2D.h"

#include <SDL\SDL_keycode.h>

GameApp_Shooter2D::GameApp_Shooter2D() {
	mEngine = new SH_Engine();
	mHud = new SH_GameHUD();
}

void GameApp_Shooter2D::Initialize() {
	mEngine->Initialize(this);
	mHud->Initialize(this);
}

void GameApp_Shooter2D::OnKeyDown(SDL_Keycode key)
{
	mEngine->GetWorld()->GetPlayer()->GetControl()->OnKeyDown(key);
}

void GameApp_Shooter2D::OnKeyUp(SDL_Keycode key)
{
	mEngine->GetWorld()->GetPlayer()->GetControl()->OnKeyUp(key);
}

void GameApp_Shooter2D::Update(float dt)
{
	mEngine->Update(dt);
	mHud->Update(dt);
}

void GameApp_Shooter2D::Draw(float dt)
{
	mEngine->Draw(dt);
	mHud->Draw(dt);
}
