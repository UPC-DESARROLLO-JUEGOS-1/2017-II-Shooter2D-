#include "SH_DummyEnemy.h"
#include "SH_World.h"

SH_DummyEnemy::~SH_DummyEnemy()
{
}

void SH_DummyEnemy::Initialize(SH_World* world, float x, float y, std::string imagePath) {
	SH_BaseEnemy::Initialize(world, x, y, imagePath);
	
	mEnemyType = SH_EnumEnemy::Dummy;
	Speed = 100;
	ScaleY = -1;
	
	mSprite.SetColor(NColor::Red);
}

bool SH_DummyEnemy::IsNotInScreenBoundaries() {
	float sh = mWorld->GetScreenHeight() + GetSpriteHeight();

	return Y > sh;
}

void SH_DummyEnemy::Update(float dt) {
	SH_BaseEnemy::Update(dt);
}

void SH_DummyEnemy::Draw(float dt) {
	SH_BaseEnemy::Draw(dt);
}
