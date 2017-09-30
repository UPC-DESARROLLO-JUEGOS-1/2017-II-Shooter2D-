#include "SH_BaseEnemy.h"
#include "SH_World.h"

SH_BaseEnemy::SH_BaseEnemy() :
	Speed(100)
{
}

SH_BaseEnemy::~SH_BaseEnemy()
{
}

void SH_BaseEnemy::Initialize(SH_World* world, float x, float y, std::string imagePath) {
	SH_BaseActor::Initialize(world, x, y, imagePath);
}

bool SH_BaseEnemy::IsNotInScreenBoundaries() {
	float bw = mSprite.GetVisibleWidth();
	float bh = mSprite.GetVisibleHeight();
	float sw = mWorld->GetScreenWidth();
	float sh = mWorld->GetScreenHeight();

	return X < 0 || Y < 0 || (X >(sw - bw) || (Y >(sh + bh)));
}

void SH_BaseEnemy::Update(float dt) {
	SH_BaseActor::Update(dt);

	if (!IsNotInScreenBoundaries()) {
		Y += Speed * dt;
	}
	else {
		IsWaitingForDelete = true;
	}
}

void SH_BaseEnemy::Draw(float dt) {
	SH_BaseActor::Draw(dt);
}