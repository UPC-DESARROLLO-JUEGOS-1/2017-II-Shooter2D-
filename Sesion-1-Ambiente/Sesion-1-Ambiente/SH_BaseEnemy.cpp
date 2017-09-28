#include "SH_BaseEnemy.h"

SH_BaseEnemy::SH_BaseEnemy()
{
}

SH_BaseEnemy::~SH_BaseEnemy()
{
}

void SH_BaseEnemy::Initialize(float x, float y, std::string imagePath) {
	SH_BaseActor::Initialize(x, y, imagePath);
}

void SH_BaseEnemy::Update(float dt) {
	SH_BaseActor::Update(dt);
}

void SH_BaseEnemy::Draw(float dt) {
	SH_BaseActor::Draw(dt);
}