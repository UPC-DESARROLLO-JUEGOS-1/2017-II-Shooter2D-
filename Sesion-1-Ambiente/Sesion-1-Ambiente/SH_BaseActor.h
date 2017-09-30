#pragma once

#include <string>
#include <UPCFramework\NSprite.h>

class SH_World;

class SH_BaseActor
{
public:
	SH_BaseActor();
	~SH_BaseActor();

	float X, Y;
	float ScaleX, ScaleY;
	float Rotation;
	bool IsWaitingForDelete;

	int GetSpriteWidth() { return mSprite.GetVisibleWidth(); }
	int GetSpriteHeight() { return mSprite.GetVisibleHeight(); }

	void virtual Initialize(SH_World* world, float x, float y, std::string imagePath);
	void virtual Update(float dt);
	void virtual Draw(float dt);

protected:
	NSprite mSprite;
	SH_World* mWorld;
};

