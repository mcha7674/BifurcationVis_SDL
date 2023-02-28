#include <iostream>
<<<<<<< HEAD
#include "SDL2/RenderWindow.h"
=======
#include "SDL2/App.h"
#include "MandelBrot.h"


class MandelBrotApp : public App
{
public:
	MandelBrotApp() 
		:App("The MandelBrot Set", 800, 800)
	{
		PushLayer(new MandelBrot());
	}
};
>>>>>>> 95714da9398398c1187eed15583e1e1d2f244e72


// With SDL, the main function must include the parameters.
int main(int arg, char* args[]) {
<<<<<<< HEAD
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";
	}

	// Window and Renderer Creation and Initialization
	RenderWindow window("MandelBrot Visualizer", 1280, 720);

	bool isRunning;

	while (isRunning) {
		OnEvent(isRunning);
		OnUpdate();
		OnRender();
	}

	//frees memory associated with renderer and window
	window.cleanup();
	SDL_Quit();
=======

	std::unique_ptr<MandelBrotApp> app = std::make_unique<MandelBrotApp>();
	app->Run();
>>>>>>> 95714da9398398c1187eed15583e1e1d2f244e72

	return 0;
}

<<<<<<< HEAD
//handles any events that SDL noticed.
void OnEvent(bool &isRunning) {
	//the only event we'll check is the  SDL_QUIT event.
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

//simple render function
void OnRender() {
	// Prepare the Scene
	SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
	SDL_RenderClear(renderer);

	//your stuff to render would typically go here. - Display the Scene
	SDL_RenderPresent(renderer);
}

//simple update function
void OnUpdate() {
	//if things could update the code would go in here.
}
=======
>>>>>>> 95714da9398398c1187eed15583e1e1d2f244e72
