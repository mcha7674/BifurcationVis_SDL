#include "App.h"

App* App::s_Instance = nullptr;

App::App(std::string winName, int winWidth, int winHeight)
	:m_winName(winName), m_Width(winWidth), m_Height(winHeight), m_windowFlags(SDL_WINDOW_SHOWN)
{
	s_Instance = this;
	isRunning = true;
	// Init_EVERYTHING flag will initialize ALL of SDL (Video, Audio, timer, etc)
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";
		// Window Creation
		m_window = SDL_CreateWindow(winName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winWidth, winHeight, m_windowFlags);
		if (m_window) {
			std::cout << "Window Created!\n";
			SDL_SetWindowMinimumSize(m_window, 100, 100);
		}
		else {
			std::cout << "FAILED TO OPEN" << std::endl;
		}
	}
	
}

App::~App()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void App::Run()
{
	while (isRunning) {

		// Run Each Layer's Update Function
		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();

		SDL_Delay(0);
	}
}


void App::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}