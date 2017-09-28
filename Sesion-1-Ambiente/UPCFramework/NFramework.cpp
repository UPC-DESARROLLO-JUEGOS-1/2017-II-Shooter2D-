#include "NFramework.h"

#include "NCamera2D.h"

NFramework* NFramework::M_FRAMEWORK;
NFramework* NFramework::GET_FRAMEWORK() { return M_FRAMEWORK; }

NFramework::NFramework() :
	mScreenWidth(0), mScreenHeight(0),
	mFrameworkState(NEnumFrameworkState::Running),
	mContentManagement(this),
	mShaderManagment(this)
{
	NFramework::M_FRAMEWORK = this;
}

NFramework::~NFramework()
{
}

void NFramework::Initialize(std::string windowName, int screenWidth,
	int screenHeight, unsigned int windowFlags) {

	mScreenWidth = screenWidth;
	mScreenHeight = screenHeight;

	mWindow.Create(windowName, mScreenWidth, mScreenHeight, windowFlags);
	mWindow.AddInputListener(std::bind(&NFramework::OnListenInputsFromWindow, this,
		std::placeholders::_1));

	mCamera = new NCamera2D();
	mCamera->Initialize(screenWidth, screenHeight);

	mContentManagement.Initialize();
	mShaderManagment.Initialize();

	mSceneGraph = new NSceneGraph();
	mSceneGraph->Initialize();
}

void NFramework::SetFrameworkState(NEnumFrameworkState state)
{
	mFrameworkState = state;
}

float NFramework::ComputeDeltaTime() {
	static float previousTick = SDL_GetTicks();

	float deltaTime = 0.0f;
	float currentTick = SDL_GetTicks();

	deltaTime = currentTick - previousTick;
	previousTick = currentTick;

	return deltaTime / 1000.0f;
}

void NFramework::OnListenInputsFromWindow(SDL_Event evnt) {
	if (mOnInput != nullptr) { mOnInput(evnt); }

	switch (evnt.type) {
	case SDL_QUIT:
		mFrameworkState = NEnumFrameworkState::Exit;
		break;
	case SDL_KEYDOWN:
		mSceneGraph->OnKeyDown(evnt.key.keysym.sym);
		break;
	case SDL_KEYUP:
		mSceneGraph->OnKeyUp(evnt.key.keysym.sym);
		break;
	}
}

void NFramework::DoGameLoop(std::function<void(float)> onUpdate,
	std::function<void(float)> onDraw) {

	mOnUpdate = onUpdate;
	mOnDraw = onDraw;

	while (mFrameworkState != NEnumFrameworkState::Exit) {
		float deltaTime = ComputeDeltaTime();

		mWindow.Update(deltaTime);
		Update(deltaTime);
		Draw(deltaTime);
	}
}

void NFramework::Update(float dt) {
	mCamera->Update(dt);
	mSceneGraph->Update(dt);
	mOnUpdate(dt);
}

void NFramework::Draw(float dt) {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mSceneGraph->Draw(dt);
	mOnDraw(dt);

	mWindow.Present();
}