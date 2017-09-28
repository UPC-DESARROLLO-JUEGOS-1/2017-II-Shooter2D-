#pragma once

#include <string>
#include <UPCFramework\NSprite.h>

class SH_BaseActor
{
public:
	SH_BaseActor();
	~SH_BaseActor();

	float X, Y;
	float ScaleX, ScaleY;
	float Rotation;

	void Initialize(float x, float y, std::string imagePath);
	void Update(float dt);
	void Draw(float dt);

protected:
	NSprite mSprite;
};

