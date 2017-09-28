#pragma once

#include "NDrawable2D.h"

class NPrimitiveCircumference : public NDrawable2D
{
public:
	NPrimitiveCircumference() {}
	~NPrimitiveCircumference() {}

	float GetRadius() { return mRadius; }
	float GetVisibleRadius() { return mRadius * mScaleX; }

	void Initialize(float x, float y, int radius,
		GLubyte r, GLubyte g, GLubyte b, GLubyte a);
	void Draw(float dt);

protected:
	float mRadius;
};

