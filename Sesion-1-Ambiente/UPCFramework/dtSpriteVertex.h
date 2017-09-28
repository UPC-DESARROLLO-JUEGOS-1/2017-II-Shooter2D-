#pragma once

#include <GL/glew.h>
#include "NColor.h"

struct V2 {
	float x;
	float y;
};

struct dtSpriteVertex
{
	V2 Position;
	NColor Color;
	V2 UV;

	void SetPosition(float x, float y) {
		Position.x = x;
		Position.y = y;
	}

	void SetColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		Color.R = r;
		Color.G = g;
		Color.B = b;
		Color.A = a;
	}

	void SetUV(float u, float v) {
		UV.x = u;
		UV.y = v;
	}
};