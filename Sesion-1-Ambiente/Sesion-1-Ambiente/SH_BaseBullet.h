#pragma once

#include "SH_BaseActor.h"
#include "SH_EnumBullet.h"

class SH_BaseBullet: public SH_BaseActor
{
public:
	SH_BaseBullet();
	~SH_BaseBullet();

	SH_EnumBullet GetBulletType() { return mBulletType; }

	void Initialize(SH_World* world, float x, float y, std::string imagePath);
	void Update(float dt);
	void Draw(float dt); 

	bool virtual IsNotInScreenBoundaries();

protected:
	SH_EnumBullet mBulletType;
	float Speed;
};

