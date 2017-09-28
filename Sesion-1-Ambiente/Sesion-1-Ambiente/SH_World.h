#pragma once

#include "SH_Player.h"
#include "SH_EnemyController.h"
#include "SH_BulletController.h"

class SH_Engine;

class SH_World
{
public:
	SH_World();
	~SH_World() {}

	SH_Player* GetPlayer() { return mPlayer; }
	SH_Engine* GetEngine() { return mEngine; }
	SH_EnemyController* GetEnemmyController() { return mEnemmyController; }
	SH_BulletController* GetBulletController() { return mBulletController; }

	void Initialize(SH_Engine* engine);
	void Update(float dt);
	void Draw(float dt);

private:
	SH_Engine* mEngine;

	SH_Player* mPlayer;
	SH_EnemyController* mEnemmyController;
	SH_BulletController* mBulletController;
};

