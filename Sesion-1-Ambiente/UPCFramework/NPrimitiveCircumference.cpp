#include "NPrimitiveCircumference.h"
#include "NFramework.h"
#include "NShaderManagement.h"
#include "NPrimitiveShader.h"
#include "dtPrimitiveVertex.h"

void NPrimitiveCircumference::Initialize(float x, float y, int radius,
	GLubyte r, GLubyte g, GLubyte b, GLubyte a) {

	NDrawable2D::Initialize(x, y);

	NFramework* framework = NFramework::GET_FRAMEWORK();
	NContentManagement* contentManagement = framework->GetContentManagement();
	NShaderManagement* shaderManagement = framework->GetShaderManagment();

	const std::string baseShaderPath = "Content/Shaders/PrimitiveShader";
	mCurrentShader = shaderManagement->LoadAndGetShader<NPrimitiveShader>(baseShaderPath);

	mRadius = radius;
	
	const float TwoPI = 3.1416f * 2.0f;
	float quality = 8;
	float anglePart = TwoPI / quality;
	
	std::vector<dtPrimitiveVertex> vertexDataVector;

	for (int i = 0; i < quality; i++)
	{
		dtPrimitiveVertex vertex_0;
		vertex_0.SetPosition(0, 0);
		vertex_0.SetColor(r, g, b, a);

		dtPrimitiveVertex vertex_1;
		vertex_1.SetPosition(mRadius * cosf(anglePart * i), mRadius * sinf(anglePart * i));
		vertex_1.SetColor(r, g, b, a);

		dtPrimitiveVertex vertex_2;
		vertex_2.SetPosition(mRadius * cosf(anglePart * (i + 1)), mRadius * sinf(anglePart * (i + 1)));
		vertex_2.SetColor(r, g, b, a);

		vertexDataVector.push_back(vertex_0);
		vertexDataVector.push_back(vertex_1);
		vertexDataVector.push_back(vertex_2);
	}

	int size = ((sizeof(float) * 2) + (sizeof(GLbyte) * 4)) * vertexDataVector.size();

	glBindBuffer(GL_ARRAY_BUFFER, mVBO_ID);
	glBufferData(GL_ARRAY_BUFFER, size, &(vertexDataVector[0]), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void NPrimitiveCircumference::Draw(float dt) {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	mCurrentShader->Use();

	GLuint wvpLocation = mCurrentShader->GetUniformLocation("wvp");
	glm::mat4 cameraMatrix = mRenderCamera->GetResultMatrix();
	glm::mat4 resultMatrix = cameraMatrix * mWorldMatrix;
	// pasamos la data de la matrix al shader
	glUniformMatrix4fv(wvpLocation, 1, false, &(resultMatrix[0][0]));

	glBindBuffer(GL_ARRAY_BUFFER, mVBO_ID);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(dtPrimitiveVertex),
		(void*)offsetof(dtPrimitiveVertex, Position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(dtPrimitiveVertex),
		(void*)offsetof(dtPrimitiveVertex, dtPrimitiveVertex::Color));

	// Dibuja en pantalla
	glDrawArrays(GL_TRIANGLES, 0, 24);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	mCurrentShader->Unuse();
}