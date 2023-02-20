#include "App.h"

App::App(std::string winName, int winWidth, int winHeight, bool fullScreen)
{
	isRunning = false;
	// Init_EVERYTHING flag will initialize ALL of SDL (Video, Audio, timer, etc)
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";

		// Window Creation
		m_window = std::make_unique<Window>(winName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winWidth, winHeight, fullScreen);
		if (m_window->Create()) {
			std::cout << "Window Created!\n";
			SDL_SetWindowMinimumSize(m_window->getWindow(), 100, 100);
		}
		else {
			std::cout << "FAILED TO OPEN" << std::endl;
		}
		/*Renderer Creation, needs window, driver specification(-1 means use the first one that
		satisfies everything we need), and finally the last place is for any renderer flags.
		RendererFlags can include things like SDL_RENDER_ACCELERATED which tells sdl to use the graphics card
		instead of the cpu for rendering.
		*/
		renderer = SDL_CreateRenderer(m_window->getWindow(), -1, SDL_RENDERER_ACCELERATED);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
			std::cout << "Renderer created!\n";
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			isRunning = true;
		}
		else {
			std::cout << "Failed to create Renderer!" << std::endl;
		}
	}
}

App::~App()
{
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void App::Run()
{
	while (isRunning) {
		//handles any events that SDL noticed
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
		//simple render function
		// Prepare the Scene
		SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
		SDL_RenderClear(renderer);
		//your stuff to render would typically go here. - Display the Scene
		SDL_RenderPresent(renderer);
		// UPDATE
		//if things could update the code would go in here.
	}
}