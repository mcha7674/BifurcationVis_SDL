#include <SDL.h>
#include <iostream>


//don't do this, this is just an example
SDL_Renderer* renderer;
SDL_Window* window;
bool isRunning;
bool fullscreen;
void handleEvents();
void update();
void render();


// With SDL, the main function must include the parameters.
int main(int arg, char* args[]) {

	fullscreen = false;
	int flags = 0;
	flags = SDL_WINDOW_RESIZABLE;
	if (fullscreen) {
		flags = flags | SDL_WINDOW_FULLSCREEN;
	}
	// Init_EVERYTHING flag will initialize ALL of SDL (Video, Audio, timer, etc)
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";

		// Window Creation
		window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, flags);
		if (window) {
			std::cout << "Window Created!\n";
			SDL_SetWindowMinimumSize(window, 100, 100);
		}
		/*Renderer Creation, needs window, driver specification(-1 means use the first one that 
		satisfies everything we need), and finally the last place is for any renderer flags.
		RendererFlags can include things like SDL_RENDER_ACCELERATED which tells sdl to use the graphics card
		instead of the cpu for rendering.
		*/ 
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
			std::cout << "Renderer created!\n";
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			isRunning = true;
		}
	}

	while (isRunning) {
		OnEvent();
		OnUpdate();
		OnRender();
	}

	//frees memory associated with renderer and window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);	//error here
	SDL_Quit();


	return 0;
}

//handles any events that SDL noticed.
void OnEvent() {
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