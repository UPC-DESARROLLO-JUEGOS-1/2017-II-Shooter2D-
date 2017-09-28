#include "NCamera2D.h"

void NCamera2D::Initialize(int screenWidth, int screenHeight) {
	NBaseCamera::Initialize(screenWidth, screenHeight);

	mProjectionMatrix = glm::ortho(0.0f, (float)screenWidth, 
		(float)screenHeight, 0.0f);
}

void NCamera2D::Update(float dt) {
	NBaseCamera::Update(dt);
}