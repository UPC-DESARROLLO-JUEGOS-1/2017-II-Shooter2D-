#include "NSprite.h"
#include "NFramework.h"
#include "NSpriteShader.h"
#include "dtSpriteVertex.h"

void NSprite::Initialize(float x, float y, const std::string path)
{
	NDrawable2D::Initialize(x, y);

	NFramework* framework = NFramework::GET_FRAMEWORK();
	NContentManagement* contentManagment = framework->GetContentManagement();
	NShaderManagement* shaderManagment = framework->GetShaderManagment();

	const std::string baseShaderPath = "Content/Shaders/SpriteShader";
	mCurrentShader = (NBaseShader*)shaderManagment->LoadAndGetShader<NSpriteShader>(baseShaderPath);

	mContent = contentManagment->LoadAndGetContent<NImageContent>(path);
	mWidth = mContent->GetWidth();
	mHeight = mContent->GetHeight();

	dtSpriteVertex vertexData[6];
	// primer triangulo
	vertexData[0].SetPosition(mWidth, mHeight);
	vertexData[0].SetColor(255, 255, 255, 255);
	vertexData[0].SetUV(1.0f, 1.0f);

	vertexData[1].SetPosition(0, mHeight);
	vertexData[1].SetColor(255, 255, 255, 255);
	vertexData[1].SetUV(0.0f, 1.0f);

	vertexData[2].SetPosition(0, 0);
	vertexData[2].SetColor(255, 255, 255, 255);
	vertexData[2].SetUV(0.0f, 0.0f);
	// segundo triangulo
	vertexData[3].SetPosition(0, 0);
	vertexData[3].SetColor(255, 255, 255, 255);
	vertexData[3].SetUV(0.0f, 0.0f);

	vertexData[4].SetPosition(mWidth, 0);
	vertexData[4].SetColor(255, 255, 255, 255);
	vertexData[4].SetUV(1.0f, 0.0f);

	vertexData[5].SetPosition(mWidth, mHeight);
	vertexData[5].SetColor(255, 255, 255, 255);
	vertexData[5].SetUV(1.0f, 1.0f);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void NSprite::Initialize(float x, float y, float width,
	float height, const std::string path)
{
	NDrawable2D::Initialize(x, y);

	mWidth = width;
	mHeight = height;

	NFramework* framework = NFramework::GET_FRAMEWORK();
	NContentManagement* contentManagment = framework->GetContentManagement();
	NShaderManagement* shaderManagment = framework->GetShaderManagment();

	const std::string baseShaderPath = "Content/Shaders/SpriteShader";
	mCurrentShader = (NBaseShader*)shaderManagment->LoadAndGetShader<NSpriteShader>(baseShaderPath);

	mContent = contentManagment->LoadAndGetContent<NImageContent>(path);
	
	dtSpriteVertex vertexData[6];
	// primer triangulo
	vertexData[0].SetPosition(mWidth, mHeight);
	vertexData[0].SetColor(255, 255, 255, 255);
	vertexData[0].SetUV(1.0f, 1.0f);

	vertexData[1].SetPosition(0, mHeight);
	vertexData[1].SetColor(255, 255, 255, 255);
	vertexData[1].SetUV(0.0f, 1.0f);

	vertexData[2].SetPosition(0, 0);
	vertexData[2].SetColor(255, 255, 255, 255);
	vertexData[2].SetUV(0.0f, 0.0f);
	// segundo triangulo
	vertexData[3].SetPosition(0, 0);
	vertexData[3].SetColor(255, 255, 255, 255);
	vertexData[3].SetUV(0.0f, 0.0f);

	vertexData[4].SetPosition(mWidth, 0);
	vertexData[4].SetColor(255, 255, 255, 255);
	vertexData[4].SetUV(1.0f, 0.0f);

	vertexData[5].SetPosition(mWidth, mHeight);
	vertexData[5].SetColor(255, 255, 255, 255);
	vertexData[5].SetUV(1.0f, 1.0f);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void NSprite::Draw(float dt)
{
	// Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	mCurrentShader->Use();

	GLuint mvpLocation = mCurrentShader->GetUniformLocation("wvp");
	glm::mat4 cameraMatrix = mRenderCamera->GetResultMatrix();
	glm::mat4 resultMatrix = cameraMatrix * mWorldMatrix;

	glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, &(resultMatrix[0][0]));

	// Activo la textura
	glActiveTexture(GL_TEXTURE0);
	// Hago binding de la textura en GPU
	glBindTexture(GL_TEXTURE_2D, mContent->GetTextureId());

	glBindBuffer(GL_ARRAY_BUFFER, mVBO_ID);

	// Position
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
		sizeof(dtSpriteVertex),
		(void*)offsetof(dtSpriteVertex, dtSpriteVertex::Position));
	// Color
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE,
		sizeof(dtSpriteVertex),
		(void*)offsetof(dtSpriteVertex, dtSpriteVertex::Color));
	// UV
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE,
		sizeof(dtSpriteVertex),
		(void*)offsetof(dtSpriteVertex, dtSpriteVertex::UV));

	// Esto dibuja en Frame Buffer
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	mCurrentShader->Unuse();
}
