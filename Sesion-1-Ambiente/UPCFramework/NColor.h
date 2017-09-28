#pragma once

#include <GL\glew.h>

struct NColor
{
	GLubyte R;
	GLubyte G;
	GLubyte B;
	GLubyte A;

	static NColor White;
	static NColor Red;
	static NColor Green;
	static NColor Blue;

	NColor static CreateColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		NColor color;
		color.R = r;
		color.G = g;
		color.B = b;
		color.A = a;

		return color;
	}
};