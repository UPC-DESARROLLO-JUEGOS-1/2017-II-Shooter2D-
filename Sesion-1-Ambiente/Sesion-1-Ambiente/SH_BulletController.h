#pragma once

#include <vector>
#include "SH_EnumBullet.h"

class SH_World;
class SH_BaseBullet;

class SH_BulletController
{
public:
	SH_BulletController();
	~SH_BulletController() {}

	void Initialize(SH_World*  world);
	void Update(float dt);
	void Draw(float dt);

	SH_BaseBullet* CreateBullet(SH_EnumBullet bulletType, 
		float x, float y);

private:
	SH_World* mWorld;

	std::vector<SH_BaseBullet*> mBullets;
};

