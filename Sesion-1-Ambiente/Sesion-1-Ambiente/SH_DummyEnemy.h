#pragma once

#include "SH_BaseEnemy.h"

class SH_DummyEnemy : public SH_BaseEnemy
{
public:
	SH_DummyEnemy() {}
	~SH_DummyEnemy();

	void Initialize(SH_World* world, float x, float y, std::string imagePath);
	void Update(float dt);
	void Draw(float dt);

	bool IsNotInScreenBoundaries();
};

