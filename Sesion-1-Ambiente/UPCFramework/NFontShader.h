#pragma once

#pragma once

#include "NBaseShader.h"

class NFontShader : public NBaseShader
{
public:
	NFontShader() { NBaseShader::NBaseShader(); }
	~NFontShader() { NBaseShader::~NBaseShader(); }

protected:
	void CreateAttributes()
	{
		AddAttribute("vertexPosition");
		AddAttribute("vertexUV");
		AddAttribute("vertexColor");
	}
};