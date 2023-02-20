#include "Window.h"


Window::Window(std::string winName, int winPosX, int winPosY, int winWidth, 
	int winHeight, bool fullScreen, int windowFlags)
	:m_winName(winName),m_winPosX(winPosX), m_winPosY(winPosY), m_winWidth(winWidth), 
	m_winHeight(winHeight), m_fullScreen(fullScreen), m_windowFlags(windowFlags)
{
	if (m_fullScreen) {
		m_windowFlags = m_windowFlags | SDL_WINDOW_FULLSCREEN;
	}
}
Window::~Window()
{
	SDL_DestroyWindow(m_SDLWindow);	//error here
}

bool Window::Create() 
{
	m_SDLWindow = SDL_CreateWindow(m_winName.c_str(), m_winPosX, m_winPosY, m_winWidth, m_winHeight, m_windowFlags);
	return m_SDLWindow;
}

