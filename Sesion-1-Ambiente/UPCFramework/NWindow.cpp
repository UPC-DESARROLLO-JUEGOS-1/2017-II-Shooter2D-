#include "NWindow.h"
#include "NEnumWindowFlags.h"
#include "FatalError.h"

NWindow::NWindow() :
	mScreenWidth(0), mScreenHeight(0)
{
}

NWindow::~NWindow()
{
}

int NWindow::Create(const std::string windowName, int screeenWidth,
	int screenHeight, unsigned int windowFlags) {

	mScreenWidth = screeenWidth;
	mScreenHeight = screenHeight;

	Uint32 flags = SDL_WINDOW_OPENGL;

	if (windowFlags & NEnumWindowFlags::Invisible) { flags |= SDL_WINDOW_HIDDEN; }
	if (windowFlags & NEnumWindowFlags::Fullscreen) { flags |= SDL_WINDOW_FULLSCREEN_DESKTOP; }
	if (windowFlags & NEnumWindowFlags::Borderless) { flags |= SDL_WINDOW_BORDERLESS; }

	mWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, mScreenWidth, mScreenHeight, flags);

	if (mWindow == nullptr) {
		FatalError("SDL Window no pudo crearse!");
	}

	// Crear mi contexto de GL
	SDL_GLContext glContext = SDL_GL_CreateContext(mWindow);

	if (glContext == nullptr) {
		FatalError("El SDL_GL contexto no pudo crearse!");
	}

	// Inicializamos el GLEW
	GLenum glError = glewInit();

	if (glError != GLEW_OK) {
		FatalError("No se pudo inicializar el GLEW!");
	}

	// color de limpieza de pantalla
	glClearColor(0, 0, 1.0f, 1.0f);

	// Obtengo version de OpenGL
	std::printf("*** OpenGL Version: %s ***\n", 
		glGetString(GL_VERSION));

	// Configurar el V-Sync
	SDL_GL_SetSwapInterval(1);

	return 0;
}

void NWindow::Present() {
	// Swap buffers
	SDL_GL_SwapWindow(mWindow);
}

void  NWindow::ProcessInputs() {
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {
		if (mOnInputCallback != nullptr) {
			mOnInputCallback(evnt);
		}
	}
}

void NWindow::Update(float dt) {
	ProcessInputs();
}