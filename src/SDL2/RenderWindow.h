#pragma once
#include <SDL.h>

class RenderWindow
{
public:
	RenderWindow(const char* title, int w, int h);
	void cleanup();
	void clear();
	void render();
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

