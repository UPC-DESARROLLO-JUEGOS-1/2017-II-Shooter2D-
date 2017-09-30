#include "SH_BaseActor.h"
#include "SH_World.h"

#include <UPCFramework\NFramework.h>

SH_BaseActor::SH_BaseActor() :
	X(0), Y(0),
	ScaleX(1.0), ScaleY(1.0),
	Rotation(0),
	IsWaitingForDelete(false)
{
}

SH_BaseActor::~SH_BaseActor()
{
	
}

void SH_BaseActor::Initialize(SH_World* world, float x, float y, std::string imagePath) {
	mWorld = world;
	X = x;
	Y = y;

	mSprite.Initialize(x, y, imagePath);
	mSprite.SetRenderCamera(NFramework::GET_FRAMEWORK()->GetCamera());
}

void SH_BaseActor::Update(float dt) {
	mSprite.SetX(X);
	mSprite.SetY(Y);
	mSprite.SetScaleX(ScaleX);
	mSprite.SetScaleY(ScaleY);
	mSprite.SetRotationZ(Rotation);
	mSprite.Update(dt);
}

void SH_BaseActor::Draw(float dt) {
	mSprite.Draw(dt);
}
