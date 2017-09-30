#include "SH_PlayerControl.h"
#include "SH_Player.h"
#include "SH_World.h"

SH_PlayerControl::~SH_PlayerControl()
{
}

void SH_PlayerControl::Initialize(SH_Player* player) {
	mPlayer = player;
	mWorld = mPlayer->GetWorld();
}

void SH_PlayerControl::OnKeyDown(SDL_Keycode key) {
	switch (key) {
	case SDLK_a:
	case SDLK_LEFT:
		mIsGoingLeft = true;
		break;
	case SDLK_w:
	case SDLK_UP:
		mIsGoingUp = true;
		break;
	case SDLK_s:
	case SDLK_DOWN:
		mIsGoingDown = true;
		break;
	case SDLK_d:
	case SDLK_RIGHT:
		mIsGoingRight = true;
		break;
	case SDLK_SPACE:
		mWorld->GetBulletController()->CreateBullet(SH_EnumBullet::Player,
			mPlayer->X, mPlayer->Y);
		break;
	}
}

void SH_PlayerControl::OnKeyUp(SDL_Keycode key) {
	switch (key) {
	case SDLK_a:
	case SDLK_LEFT:
		mIsGoingLeft = false;
		break;
	case SDLK_w:
	case SDLK_UP:
		mIsGoingUp = false;
		break;
	case SDLK_s:
	case SDLK_DOWN:
		mIsGoingDown = false;
		break;
	case SDLK_d:
	case SDLK_RIGHT:
		mIsGoingRight = false;
		break;
	}
}

void SH_PlayerControl::ProcessScreenBoundaries() {
	float px = mPlayer->X;
	float py = mPlayer->Y;
	float pw = mPlayer->GetSpriteWidth();
	float ph = mPlayer->GetSpriteHeight();
	float sw = mWorld->GetScreenWidth();
	float sh = mWorld->GetScreenHeight();

	if (px <= 0) { mPlayer->X = 0; }
	if (py <= 0) { mPlayer->Y = 0; }
	if (px >= (sw - pw)) { mPlayer->X = sw - pw; }
	if (py >= (sh - ph)) { mPlayer->Y = sh - ph; }
}

void SH_PlayerControl::Update(float dt) {
	if (mIsGoingDown) { mPlayer->Y += Speed * dt; }
	if (mIsGoingUp) { mPlayer->Y -= Speed * dt; }
	if (mIsGoingLeft) { mPlayer->X -= Speed * dt; }
	if (mIsGoingRight) { mPlayer->X += Speed * dt; }

	ProcessScreenBoundaries();
}