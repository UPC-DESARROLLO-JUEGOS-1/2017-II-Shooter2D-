#include "SH_BaseActor.h"

SH_BaseActor::SH_BaseActor()
{
}

SH_BaseActor::~SH_BaseActor()
{
}

void SH_BaseActor::Initialize(float x, float y, std::string imagePath) {
	mSprite.Initialize(x, y, imagePath);
}

void SH_BaseActor::Update(float dt) {
	mSprite.Update(dt);
}

void SH_BaseActor::Draw(float dt) {
	mSprite.SetX(X);
	mSprite.SetY(Y);
	mSprite.SetScaleX(ScaleX);
	mSprite.SetScaleY(ScaleY);
	mSprite.SetRotationZ(Rotation);

	mSprite.Draw(dt);
}
