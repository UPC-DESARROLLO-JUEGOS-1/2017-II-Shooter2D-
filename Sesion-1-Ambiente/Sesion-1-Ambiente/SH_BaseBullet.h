#pragma once

#include "SH_BaseActor.h"

class SH_BaseBullet: public SH_BaseActor
{
public:
	SH_BaseBullet();
	~SH_BaseBullet();

	void Initialize(float x, float y, std::string imagePath);
	void Update(float dt);
	void Draw(float dt);
};

