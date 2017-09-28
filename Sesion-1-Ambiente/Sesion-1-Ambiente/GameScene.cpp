#include "GameScene.h"


#include <UPCFramework\NFramework.h>
#include <UPCFramework\NCommon.h>
#include <UPCFramework\pugixml.hpp>
#include <UPCFramework\FatalError.h>

void GameScene::Initialize() {
	mQuad = new NPrimitiveQuad();
	mQuad->Initialize(100, 100, 40, 80, 255, 0, 0, 255);
	mQuad->SetRenderCamera(NFramework::GET_FRAMEWORK()->GetCamera());

	mCircle = new NPrimitiveCircumference();
	mCircle->Initialize(200, 100, 40, 255, 0, 0, 255);
	mCircle->SetRenderCamera(NFramework::GET_FRAMEWORK()->GetCamera());

	mSprite = new NSprite();
	mSprite->Initialize(300, 100, 80, 80, "Content/Sprites/mario.png");
	mSprite->SetRenderCamera(NFramework::GET_FRAMEWORK()->GetCamera());

	// Text
	mTextfield = new NTextfield2D();
	mTextfield->Initialize(50, 200, "Content/Fonts/kronika_32.fnt");
	mTextfield->SetText("Aloha soy una prueba,\n en UPC Bitch!");
	mTextfield->SetRenderCamera(NFramework::GET_FRAMEWORK()->GetCamera());
	mTextfield->SetScaleX(0.5f);
	mTextfield->SetScaleY(0.5f);
	//mTextfield->SetLetterColor(2, NColor::Red);
	//mTextfield->SetLetterColor(3, NColor::Blue);


	// XML Sample
	const char* xmlPath = "Content/Xml/TB3D_WorldConfig.xml";
	pugi::xml_document xDoc;
	pugi::xml_parse_result xmlResult = xDoc.load_file(xmlPath);

	if (xmlResult.status == pugi::status_ok) {
		pugi::xml_node xData = xDoc.child("data");
		pugi::xml_node xLevel = xData.child("level");

		while (xLevel != nullptr) {
			std::string xAttr_id = std::string(xLevel.attribute("id").as_string());
			float xAttr_tileSize = xLevel.attribute("tileSize").as_float();
			std::vector<std::vector<int>> xAttr_worldCollisions;

			pugi::xml_node xLevelRow = xLevel.child("row");

			while (xLevelRow != nullptr) {
				std::string xAttr_LevelRowData = std::string(xLevelRow.attribute("data").as_string());
				std::vector<std::string> splittedLevelRow = NCommon::SplitString(xAttr_LevelRowData, ',');
				std::vector<int> outputLevelRow = GameScene::CastVecToIntPtr(splittedLevelRow);

				// push it
				xAttr_worldCollisions.push_back(outputLevelRow);

				// Next node
				xLevelRow = xLevelRow.next_sibling();
			}

			// TODO: Do something with the data..

			// Next node
			xLevel = xLevel.next_sibling();
		}
	}
	else {
		std::string errorMessage = "TB3D_Configuration::Load Error: " +
			std::string(xmlResult.description());

		FatalError(errorMessage);
	}
}

void GameScene::OnKeyDown(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_BACKSPACE:
		if (mCurrentText.length() > 0) {
			mCurrentText.pop_back();
		}
		break;
	case SDLK_RETURN:
		mCurrentText += "\n";
		break;
	default:
		std::string letter = NCommon::UnicodeToUTF8(key);
		mCurrentText += letter;
		break;
	}

	mTextfield->SetText(mCurrentText);
}

void GameScene::OnKeyUp(SDL_Keycode key)
{
	
}

void GameScene::Update(float dt)
{
	mQuad->Update(dt);
	mCircle->Update(dt);
	mSprite->Update(dt);
	mTextfield->Update(dt);
}

void GameScene::Draw(float dt)
{
	mQuad->Draw(dt);
	mCircle->Draw(dt);
	mSprite->Draw(dt);
	mTextfield->Draw(dt);
}
