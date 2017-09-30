#include "SH_BulletController.h"
#include "SH_World.h"
#include "SH_BaseBullet.h"
#include "SH_PlayerBullet.h"
#include "SH_EnemyBullet.h"
#include "SH_EnumBullet.h"

SH_BulletController::SH_BulletController()
{
}

void SH_BulletController::Initialize(SH_World*  world)
{
	mWorld = world;
}

SH_BaseBullet* SH_BulletController::CreateBullet(SH_EnumBullet bulletType, float x, float y) {
	SH_BaseBullet* result = nullptr;
	std::string imagePath = "";

	switch (bulletType)
	{
	case SH_EnumBullet::Player:
		result = new SH_PlayerBullet();
		imagePath = "Content/Sprites/spBullet.png";
		break;
	case SH_EnumBullet::Enemy:
		result = new SH_EnemyBullet();
		imagePath = "Content/Sprites/spBullet.png";
		break;
	}

	if (result != nullptr) {
		result->Initialize(mWorld, x, y, imagePath);
		// agregar la bala al vector
		mBullets.push_back(result);
	}

	return result;
}

void SH_BulletController::Update(float dt)
{
	for (std::vector<SH_BaseBullet*>::iterator it = mBullets.begin(); it != mBullets.end();)
	{
		if (!(*it)->IsWaitingForDelete)
		{
			(*it)->Update(dt);
			it++;	
		}
		else
		{
			delete (*it);
			it = mBullets.erase(it);
		}
	}
}

void SH_BulletController::Draw(float dt)
{
	for (std::vector<SH_BaseBullet*>::iterator it = mBullets.begin(); it != mBullets.end();)
	{
		if (!(*it)->IsWaitingForDelete)
		{
			(*it)->Draw(dt);
		}

		it++;
	}
}

