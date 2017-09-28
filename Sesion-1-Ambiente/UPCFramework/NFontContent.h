#pragma once

#include "Vector2.h"
#include "NBaseContent.h"
#include "NBitmapFontCharset.h"
#include "NImageContent.h"

class NFontContent : public NBaseContent
{
public:
	NFontContent(NContentManagement* contentManager);
	~NFontContent();

	NBitmapFontCharset* GetCharset() { return mCharset; }

	void Initialize();
	bool Load(const std::string path);

	Vector2 MeasureString(std::string text);
	float MeasureStringLineal(std::string text);
	float GetKerning(int unicodeFirst, int unicodeSecond);
	bool ExistChar(int charUnicode);
	NBitmapFontCharDescriptor GetCharDescriptor(int charUnicode);
	NImageContent* GetImageContent(int page);
private:
	NBitmapFontCharset* mCharset;
	std::vector<NImageContent*> mImageContents;
};

