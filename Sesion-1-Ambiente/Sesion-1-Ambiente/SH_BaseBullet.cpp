#include "SH_BaseBullet.h"
#include "SH_World.h"

SH_BaseBullet::SH_BaseBullet() :
	Speed(300)
{
}

SH_BaseBullet::~SH_BaseBullet()
{
}

void SH_BaseBullet::Initialize(SH_World* world, float x, float y, std::string imagePath) {
	SH_BaseActor::Initialize(world, x, y, imagePath);
}

bool SH_BaseBullet::IsNotInScreenBoundaries() {
	float bw = mSprite.GetVisibleWidth();
	float bh = mSprite.GetVisibleHeight();
	float sw = mWorld->GetScreenWidth();
	float sh = mWorld->GetScreenHeight();

	return X < 0 || Y < 0 || (X >(sw - bw) || (Y >(sh + bh)));
}

void SH_BaseBullet::Update(float dt) {
	SH_BaseActor::Update(dt);

	if (!IsNotInScreenBoundaries()) {
		Y += Speed * dt;
	}
	else {
		IsWaitingForDelete = true;
	}
}

void SH_BaseBullet::Draw(float dt) {
	SH_BaseActor::Draw(dt);
}
