#pragma once

#include <SDL\SDL_keycode.h>

class SH_Player;

class SH_PlayerControl
{
public:
	SH_PlayerControl() {}
	~SH_PlayerControl();

	void Initialize(SH_Player* player);
	void Update(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

private:
	SH_Player* mPlayer;
};

