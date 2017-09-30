#pragma once

#include "NImageContent.h"
#include "NDrawable2D.h"

#include <string>

class NSprite : public NDrawable2D
{
public:
	NSprite() { }
	~NSprite() { }

	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; }
	int GetVisibleWidth() { return abs(mWidth * mScaleX); }
	int GetVisibleHeight() { return abs(mHeight * mScaleY); }

	void Initialize(float x, float y, const std::string path);
	void Initialize(float x, float y, float width,
		float height, const std::string path);

	void SetColor(NColor color);

	void Draw(float dt);
protected:
	float mWidth;
	float mHeight;

	NImageContent* mContent;
};

