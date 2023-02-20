#pragma once
#include <SDL.h>
#include <iostream>
class Window
{
public:
	Window(std::string winName, int winPosX, int winPosY, int winWidth,
		int winHeight, bool fullScreen, int windowFlags = SDL_WINDOW_RESIZABLE);
	~Window();
	bool Create();
	inline SDL_Window* getWindow() { return m_SDLWindow; }

private:
	SDL_Window* m_SDLWindow;
	bool m_fullScreen;
	std::string m_winName;
	int m_windowFlags;
	int m_winWidth;
	int m_winHeight;
	int  m_winPosX;
	int  m_winPosY;
};

