#pragma once

#include "SH_PlayerControl.h"
#include "SH_BaseActor.h"

class SH_World;

class SH_Player : public SH_BaseActor
{
public:
	SH_Player();
	~SH_Player();

	SH_PlayerControl* GetControl() { return mControl; }
	SH_World* GetWorld() { return mWorld; }

	void Initialize(SH_World* world);
	void Update(float dt);
	void Draw(float dt);

private:
	SH_PlayerControl* mControl;
	SH_World* mWorld;
};

