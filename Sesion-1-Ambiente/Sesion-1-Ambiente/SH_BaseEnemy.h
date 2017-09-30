#pragma once

#include "SH_BaseActor.h"
#include "SH_EnumEnemy.h"

class SH_BaseEnemy : public SH_BaseActor
{
public:
	SH_BaseEnemy();
	~SH_BaseEnemy();

	SH_EnumEnemy GetEnemyType() { return mEnemyType; }

	void Initialize(SH_World* world, float x, float y, std::string imagePath);
	void Update(float dt);
	void Draw(float dt);

	bool virtual IsNotInScreenBoundaries();

protected:
	SH_EnumEnemy mEnemyType;
	float Speed;
};

