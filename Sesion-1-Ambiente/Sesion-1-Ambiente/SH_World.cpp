#include "SH_World.h"
#include "SH_Engine.h"

SH_World::SH_World()
{
	mPlayer = new SH_Player();
	mEnemmyController = new SH_EnemyController();
	mBulletController = new SH_BulletController();
}

void SH_World::Initialize(SH_Engine* engine) {
	mEngine = engine;

	mPlayer->Initialize(this);
	mEnemmyController->Initialize(this);
	mBulletController->Initialize(this);
}

void SH_World::Update(float dt) {
	mPlayer->Update(dt);
	mEnemmyController->Update(dt);
	mBulletController->Update(dt);
}

void SH_World::Draw(float dt) {
	mPlayer->Draw(dt);
	mEnemmyController->Draw(dt);
	mBulletController->Draw(dt);
}