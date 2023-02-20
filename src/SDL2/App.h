#include <SDL.h>
#include <iostream>
#include "Window.h"

class App
{
public:
	App(std::string windowName, int winWidth, int winHeight, bool fullScreen);
	~App();
	void Run();

private:
	std::unique_ptr<Window> m_window;
	SDL_Renderer* renderer;

	bool isRunning;
};