#include "NGameApplication.h"
#include "AppSceneGraph.h"

#include <iostream>
#include <UPCFramework\NEnumWindowFlags.h>

NGameApplication::NGameApplication()
{
}

NGameApplication::~NGameApplication()
{
}

void NGameApplication::Start() {
	// Inicializar todo
	Initialize();

	// Comienzo el loop de juego
	mFramework.DoGameLoop(
		std::bind(&NGameApplication::Update, this,
			std::placeholders::_1),
		std::bind(&NGameApplication::Draw, this,
			std::placeholders::_1));
}

void NGameApplication::Initialize() {
	mFramework.Initialize("UPC Framework - 2017 II",
		NGameApplication::WIDTH, NGameApplication::HEIGHT,
		NEnumWindowFlags::Windowed);
	mFramework.OnInput(std::bind(&NGameApplication::OnInput, 
		this, std::placeholders::_1));

	mFramework.SetCustomSceneGraph(new AppSceneGraph());
	mFramework.GetSceneGraph()->GoToScene(EnumAppScenes::Shooter2D);
}

void NGameApplication::OnInput(SDL_Event evnt) {
	//std::cout << std::to_string(evnt.type);

	/*switch (evnt.type)
	{
	case SDL_MOUSEBUTTONDOWN:
	std::cout << std::to_string(evnt.button.x) << " " +
	std::to_string(evnt.button.y) << std::endl;
	break;
	case SDL_MOUSEBUTTONUP:
	break;
	default:
	break;
	} */
}

void NGameApplication::Update(float dt) {
	
}

void NGameApplication::Draw(float dt) {
	
}
