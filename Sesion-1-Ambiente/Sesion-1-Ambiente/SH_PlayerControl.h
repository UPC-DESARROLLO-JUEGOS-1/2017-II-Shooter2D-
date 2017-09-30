#pragma once

#include <SDL\SDL_keycode.h>

class SH_Player;
class SH_World;

class SH_PlayerControl
{
public:
	SH_PlayerControl() :
		mIsGoingUp(false),
		mIsGoingDown(false),
		mIsGoingRight(false),
		mIsGoingLeft(false) {}
	~SH_PlayerControl();

	void Initialize(SH_Player* player);
	void Update(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

	float Speed = 250;

private:
	SH_Player* mPlayer;
	SH_World* mWorld;
	bool mIsGoingUp, mIsGoingDown, mIsGoingRight, mIsGoingLeft;

	void ProcessScreenBoundaries();
};

