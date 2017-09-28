#include "NFontContent.h"
#include "NBitmapFontParser.h"
#include "NContentManagement.h"

#include <codecvt>

NFontContent::NFontContent(NContentManagement* contentManager)
	: NBaseContent(contentManager)
{
}

NFontContent::~NFontContent() {}

void NFontContent::Initialize()
{
	NBaseContent::Initialize();
}

bool NFontContent::Load(const std::string path)
{
	NBaseContent::Load(path);

	mCharset = NBitmapFontParser::Load(path);

	int offset = path.find_last_of('/');
	std::string folderPath = path.substr(0, offset + 1);

	for (int i = 0; i < mCharset->pages; i++)
	{	
		std::string fontImagePath = folderPath + mCharset->fontPages[i].path;

		NImageContent* content = mContentManagement->LoadAndGetContent<NImageContent>(fontImagePath);

		if (content != nullptr) {
			mImageContents.push_back(content);
		}
	}

	return mCharset != nullptr;
}

Vector2 NFontContent::MeasureString(std::string text) {
	Vector2 textSize = Vector2::Zero;
	textSize.y += mCharset->Base; // this is done for the first line

	int phraseLength = text.size();
	int oldIndexAfterJumpLine = 0;
	float oldWidthAfterJumpLine = 0;
	std::string commandInsideString = "";

	for (int i = 0; i < phraseLength; i++) {
		//int unicodeCharFirst = char.ConvertToUtf32(text, i);
		int unicodeCharFirst = NCommon::UTF8ToUnicode(text[i]);
		
		if (unicodeCharFirst == EnumNCharacterASCII::JUMPLINE) {
			std::string newText = text.substr(oldIndexAfterJumpLine, (i - oldIndexAfterJumpLine));
			oldIndexAfterJumpLine = i + 1;
			float newTextLength = MeasureStringLineal(newText);

			if (newTextLength > oldWidthAfterJumpLine) {
				oldWidthAfterJumpLine = newTextLength;
				textSize.x = oldWidthAfterJumpLine;
			}

			textSize.y += mCharset->Base;
		}
	}

	// if there's no JUMPLINE
	if (textSize.x == 0 && phraseLength > 0) {
		textSize.x = MeasureStringLineal(text);
	}

	return textSize;
}

float NFontContent::MeasureStringLineal(std::string text) {
	float textSize = 0;

	int oldUnicodeChar = -1;
	int phraseLength = text.size();
	NBitmapFontCharDescriptor charDescriptor;

	for (int i = 0; i < phraseLength; i++) {
		float kerningAmount = 0;
		int unicodeCharFirst = NCommon::UTF8ToUnicode(text[i]);

		if (ExistChar(unicodeCharFirst)) {
			// RETRIEVE KERNING
			if (oldUnicodeChar != -1) {
				kerningAmount = GetKerning(oldUnicodeChar, unicodeCharFirst);
			}

			// RETRIEVE CHAR DESCRIPTOR
			charDescriptor = GetCharDescriptor(unicodeCharFirst);

			//textSize += (charDescriptor.xOffset + charDescriptor.xAdvance + kerningAmount);
			textSize += charDescriptor.xAdvance + kerningAmount;

			// STORING OLD VARIABLES
			oldUnicodeChar = unicodeCharFirst;
		}
	}

	return textSize;
}

float NFontContent::GetKerning(int unicodeFirst, int unicodeSecond) {
	float amount = mCharset->getKerning(unicodeFirst, unicodeSecond);
	return amount;
}

bool NFontContent::ExistChar(int charUnicode) {
	return mCharset->existsChar(charUnicode);
}

NImageContent* NFontContent::GetImageContent(int page) {
	return mImageContents[page];
}

NBitmapFontCharDescriptor NFontContent::GetCharDescriptor(int charUnicode) {
	NBitmapFontCharDescriptor _charDescriptor = mCharset->getCharDescriptor(charUnicode);
	_charDescriptor.width = _charDescriptor.textureU;
	_charDescriptor.height = _charDescriptor.textureV;
	_charDescriptor.xAdvance = _charDescriptor.xAdvance;
	_charDescriptor.xOffset = _charDescriptor.xOffset;
	_charDescriptor.yOffset = _charDescriptor.yOffset;

	return _charDescriptor;
}