#pragma once

#include <GL/glew.h>
#include "NColor.h"

struct Position {
	float x;
	float y;
};

struct dtPrimitiveVertex {
	Position Position;
	NColor Color;

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
};