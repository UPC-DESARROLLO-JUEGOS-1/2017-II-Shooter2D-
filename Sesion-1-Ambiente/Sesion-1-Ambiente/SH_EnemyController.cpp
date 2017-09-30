#include "SH_EnemyController.h"
#include "SH_World.h"
#include "SH_BaseEnemy.h"
#include "SH_DummyEnemy.h"

SH_EnemyController::SH_EnemyController()
{
}

void SH_EnemyController::Initialize(SH_World*  world)
{
	mWorld = world;

	GenerateEnemies();
}

void SH_EnemyController::GenerateEnemies() {
	mTimeInterval = new TimeInterval();
	mTimeInterval->Initialize(1.0f, 9999, true);
	mTimeInterval->onEndLoop = std::bind(&SH_EnemyController::OnEndLoop_CreateEnemy, this);
}

void SH_EnemyController::OnEndLoop_CreateEnemy() {
	float cx = MathUtils::RandomInt(0, mWorld->GetScreenWidth());
	float cy = -100;
	
	CreateEnemy(SH_EnumEnemy::Dummy, cx, cy);
}

SH_BaseEnemy* SH_EnemyController::CreateEnemy(SH_EnumEnemy enemyType, 
	float x, float y) {
	
	SH_BaseEnemy* result = nullptr;
	std::string imagePath = "";

	switch (enemyType)
	{
	case SH_EnumEnemy::Dummy:
		result = new SH_DummyEnemy();
		imagePath = "Content/Sprites/spSpaceship.png";
		break;
	}

	if (result != nullptr) {
		result->Initialize(mWorld, x, y, imagePath);
		// agregar la bala al vector
		mEnemies.push_back(result);
	}

	return result;
}


void SH_EnemyController::Update(float dt)
{
	if (mTimeInterval != nullptr) {
		mTimeInterval->Update(dt);
	}

	for (std::vector<SH_BaseEnemy*>::iterator it = mEnemies.begin(); it != mEnemies.end();)
	{
		if (!(*it)->IsWaitingForDelete)
		{
			(*it)->Update(dt);
			it++;
		}
		else
		{
			delete (*it);
			it = mEnemies.erase(it);
		}
	}
}

void SH_EnemyController::Draw(float dt)
{
	for (std::vector<SH_BaseEnemy*>::iterator it = mEnemies.begin(); it != mEnemies.end();)
	{
		if (!(*it)->IsWaitingForDelete)
		{
			(*it)->Draw(dt);
		}

		it++;
	}
}
