#include "SH_PlayerBullet.h"
#include "SH_World.h"

SH_PlayerBullet::~SH_PlayerBullet()
{
}

void SH_PlayerBullet::Initialize(SH_World* world, float x, float y, std::string imagePath) {
	SH_BaseBullet::Initialize(world, x, y, imagePath);

	X = X + (world->GetPlayer()->GetSpriteWidth() * 0.5f) -
		mSprite.GetVisibleWidth() * 0.5;
	mSprite.SetX(X); // Forzamos actualizar el X de inicio del sprite

	mBulletType = SH_EnumBullet::Player;
	Speed = -300;
}

bool SH_PlayerBullet::IsNotInScreenBoundaries() {
	float bw = mSprite.GetVisibleWidth();
	float bh = mSprite.GetVisibleHeight();
	float sw = mWorld->GetScreenWidth();
	float sh = mWorld->GetScreenHeight();

	return X < 0 || Y < -bh || (X > (sw - bw) || (Y > sh));
}

void SH_PlayerBullet::Update(float dt) {
	SH_BaseBullet::Update(dt);
}

void SH_PlayerBullet::Draw(float dt) {
	SH_BaseBullet::Draw(dt);
}
