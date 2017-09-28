#pragma once

#include <UPCFramework\NBaseScene.h>

#include <UPCFramework\NSprite.h>
#include <UPCFramework\NPrimitiveQuad.h>
#include <UPCFramework\NPrimitiveCircumference.h>
#include <UPCFramework\NTextfield2D.h>

#include <string>

class GameScene : public NBaseScene
{
public:
	GameScene(NSceneGraph* sceneGraph) : 
		NBaseScene::NBaseScene(sceneGraph) {}
	~GameScene() {
		
	}

	void Initialize();
	void Update(float dt);
	void Draw(float dt);

	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);

private:
	NTextfield2D* mTextfield;
	NPrimitiveQuad* mQuad;
	NPrimitiveCircumference* mCircle;
	NSprite* mSprite;

	std::string mCurrentText;


	std::vector<int> CastVecToIntPtr(std::vector<std::string> source) {
		int vecSize = source.size();
		std::vector<int> result;
		result.resize(vecSize);

		for (int i = 0; i < vecSize; i++) {
			result[i] = std::stoi(source[i]);
		}

		return result;
	}
};

