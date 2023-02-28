#include "RenderWindow.h"
#include <iostream>

RenderWindow::RenderWindow(const char* title, int w, int h)
	: window(nullptr), renderer(nullptr)
{
	// create the window
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
	if (!window) { std::cout << "Window Failed to Initialize!" << std::endl; }

	// Create Renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanup()
{
	// deallocate window memory
	SDL_DestroyWindow(window);
	// deallocate renderer memory
	SDL_DestroyRenderer(renderer);
}

void RenderWindow::clear()
{
	// clear the buffer 
	SDL_RenderClear(renderer);
}

void RenderWindow::display()
{
	// Render Objects
	SDL_RenderPresent(renderer);
}

void RenderWindow::render()
{
}