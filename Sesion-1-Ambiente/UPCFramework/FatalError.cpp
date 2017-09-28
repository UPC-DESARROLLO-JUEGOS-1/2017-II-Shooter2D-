#include "FatalError.h"

#include <iostream>
#include <SDL\SDL.h>

extern void FatalError(std::string errorString) {
	std::cout << errorString << std::endl;
	std::cout << "Presione cualquier tecla para terminar el programa...";

	int tmp;
	std::cin >> tmp;

	SDL_Quit();
	exit(100);
}