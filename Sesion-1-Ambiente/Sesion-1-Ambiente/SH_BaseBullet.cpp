#include "SH_BaseBullet.h"

SH_BaseBullet::SH_BaseBullet()
{
}

SH_BaseBullet::~SH_BaseBullet()
{
}

void SH_BaseBullet::Initialize(float x, float y, std::string imagePath) {
	SH_BaseActor::Initialize(x, y, imagePath);
}

void SH_BaseBullet::Update(float dt) {
	SH_BaseActor::Update(dt);
}

void SH_BaseBullet::Draw(float dt) {
	SH_BaseActor::Draw(dt);
}
