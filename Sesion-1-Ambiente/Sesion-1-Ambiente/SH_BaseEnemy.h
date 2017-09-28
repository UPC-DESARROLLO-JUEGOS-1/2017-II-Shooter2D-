#pragma once

#include "SH_BaseActor.h"

class SH_BaseEnemy : public SH_BaseActor
{
public:
	SH_BaseEnemy();
	~SH_BaseEnemy();

	void Initialize(float x, float y, std::string imagePath);
	void Update(float dt);
	void Draw(float dt);
};

