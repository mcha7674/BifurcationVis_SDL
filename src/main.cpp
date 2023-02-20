#include <SDL.h>
#include <iostream>
#include "SDL2/App.h"

// With SDL, the main function must include the parameters.
int main(int arg, char* args[]) {

	std::unique_ptr<App> app = std::make_unique<App>("My First SDL Window", 800, 800, false);
	app->Run();

	return 0;
}

