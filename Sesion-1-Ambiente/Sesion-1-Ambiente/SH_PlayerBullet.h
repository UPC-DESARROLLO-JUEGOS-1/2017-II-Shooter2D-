#pragma once

#include "SH_BaseBullet.h"

class SH_PlayerBullet : public SH_BaseBullet
{
public:
	SH_PlayerBullet() {}
	~SH_PlayerBullet();

	void Initialize(SH_World* world, float x, float y, std::string imagePath);
	void Update(float dt);
	void Draw(float dt);

	bool IsNotInScreenBoundaries();
};

