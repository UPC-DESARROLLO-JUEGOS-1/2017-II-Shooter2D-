#pragma once

#include <vector>
#include "SH_EnumEnemy.h"
#include <UPCFramework\TimeInterval.h>
#include <UPCFramework\MathUtils.h>

class SH_World;
class SH_BaseEnemy;

class SH_EnemyController
{
public:
	SH_EnemyController();
	~SH_EnemyController() {}

	void Initialize(SH_World*  world);
	void Update(float dt);
	void Draw(float dt);

	void GenerateEnemies();
	void OnEndLoop_CreateEnemy();

	SH_BaseEnemy* CreateEnemy(SH_EnumEnemy enemyType,
		float x, float y);

private:
	SH_World* mWorld;
	TimeInterval* mTimeInterval;

	std::vector<SH_BaseEnemy*> mEnemies;
};

