#pragma once

#include <functional>

#include "NBaseCamera.h"
#include "NWindow.h"
#include "NContentManagement.h"
#include "NShaderManagement.h"
#include "NSceneGraph.h"

enum NEnumFrameworkState {
	Running,
	Exit
};

class NFramework
{
public:
	static NFramework* GET_FRAMEWORK();
	static float GET_SCREEN_WIDTH();
	static float GET_SCREEN_HEIGHT();

	NFramework();
	~NFramework();

	NBaseCamera* GetCamera() { return mCamera; }
	NShaderManagement* GetShaderManagment() { return &mShaderManagment; }
	NContentManagement* GetContentManagement() { return &mContentManagement; }
	NSceneGraph* GetSceneGraph() { return mSceneGraph; }

	float GetScreenWidth() { return mScreenWidth; }
	float GetScreenHeight() { return mScreenHeight; }

	void Initialize(std::string windowName, int screenWidth, 
		int screenHeight, unsigned int windowFlags);

	void SetFrameworkState(NEnumFrameworkState state);
	void SetCustomSceneGraph(NSceneGraph* sceneGraph)
	{
		mSceneGraph = sceneGraph;
		mSceneGraph->Initialize();
	}
	void OnInput(std::function<void(SDL_Event)> onInput) { mOnInput = onInput; }

	void DoGameLoop(std::function<void(float)> onUpdate,
		std::function<void(float)> onDraw);
	void Update(float dt);
	void Draw(float dt);
private:
	static NFramework* M_FRAMEWORK;

	int mScreenWidth, mScreenHeight;
	NEnumFrameworkState mFrameworkState;
	NWindow mWindow;
	NContentManagement mContentManagement;
	NShaderManagement mShaderManagment;
	NSceneGraph* mSceneGraph;

	NBaseCamera* mCamera;

	std::function<void(SDL_Event)> mOnInput = NULL;
	std::function<void(float)> mOnUpdate = NULL;
	std::function<void(float)> mOnDraw = NULL;

	float ComputeDeltaTime();
	void OnListenInputsFromWindow(SDL_Event evnt);
};

