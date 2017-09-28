#include "SH_Player.h"
#include "SH_World.h"

SH_Player::SH_Player()
{
	mControl = new SH_PlayerControl();
}

SH_Player::~SH_Player()
{
}

void SH_Player::Initialize(SH_World* world) {
	SH_BaseActor::Initialize(0, 0, "");

	mWorld = world;

	mControl->Initialize(this);
}

void SH_Player::Update(float dt) {
	SH_BaseActor::Update(dt);

	mControl->Update(dt);

}

void SH_Player::Draw(float dt) {
	SH_BaseActor::Draw(dt);
}